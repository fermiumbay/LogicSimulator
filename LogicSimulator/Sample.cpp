#include <iostream>
#include <string>
#include <vector>
#include "Products.h"

using namespace std;
using namespace LogicParts;

static void sample1(), sample2(), sample3(), sample4(), sample5(), sample6(), sample7(), sample8(), sample9();

void run() {
	vector<void(*)()> samples = { sample1, sample2, sample3, sample4, sample5, sample6, sample7, sample8, sample9 };
	cout << "サンプル番号[1-" << (int)samples.size() << "] : ";
	int sampleID;
	cin >> sampleID;
	
	if (sampleID <= 0 || sampleID > (int)samples.size()) {
		cout << "サンプル番号が範囲外です。" << endl;
	}
	else {
		samples[sampleID - 1]();
	}
}

int main() {
	char c;
	do {
		run();
		cout << "続ける？(y/n): ";
		cin >> c;
	} while (c == 'y');
}

static void input_value(string terminal_str, _Terminal* parts) {
	int value;
	cout << terminal_str << " = ";
	cin >> value;
	parts->set(value != 0);
}

static void sample1() {
	auto A = Terminal();
	auto B = Terminal();
	auto C = Nand(Not(A), B);

	cout << "C = Nand(Not(A), B)の論理回路です。" << endl;

	input_value("A", A);
	input_value("B", B);

	cout << "C = " << C->get() << endl;
}

static void sample2() {
	auto A = Terminal();
	auto B = Terminal();
	auto C = Terminal();
	auto D = FA(A, B, C);

	cout << "D = FullAdder(A, B, C)の論理回路です。" << endl;

	input_value("A", A);
	input_value("B", B);
	input_value("C", C);
	cout << "D_繰り上がり = " << D[0]->get() << endl;
	cout << "D_答え = " << D[1]->get() << endl;
}

static void sample3() {
	auto A0 = Terminal();
	auto A1 = Terminal();
	auto A2 = Terminal();
	auto A3 = Terminal();
	auto B0 = Terminal();
	auto B1 = Terminal();
	auto B2 = Terminal();
	auto B3 = Terminal();
	auto C = Adder4bit(A0, A1, A2, A3, B0, B1, B2, B3);

	cout << "A3A2A1A0 ＋ B3B2B1B0 の4ビット加算器です。" << endl;

	input_value("A3", A3);
	input_value("A2", A2);
	input_value("A1", A1);
	input_value("A0", A0);
	input_value("B3", B3);
	input_value("B2", B2);
	input_value("B1", B1);
	input_value("B0", B0);

	cout << "C4 = " << C[4]->get() << endl;
	cout << "C3 = " << C[3]->get() << endl;
	cout << "C2 = " << C[2]->get() << endl;
	cout << "C1 = " << C[1]->get() << endl;
	cout << "C0 = " << C[0]->get() << endl;
}

static void sample4() {
	cout << "7セグメントLED表示テストです。" << endl;
	cout << "順にa, b, c, d, e, f, gのLEDを点灯しています。" << endl;
	disp_led({
		{ 1, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 1 }
	});
	cout << "a～gのLEDの値をセットしてください。" << endl;

	int a, b, c, d, e, f, g;
	cout << "a = ";	cin >> a;
	cout << "b = ";	cin >> b;
	cout << "c = ";	cin >> c;
	cout << "d = ";	cin >> d;
	cout << "e = ";	cin >> e;
	cout << "f = ";	cin >> f;
	cout << "g = ";	cin >> g;

	disp_led({ { a != 0, b != 0, c != 0, d != 0, e != 0, f != 0, g != 0 } });
}

static void sample5() {
	cout << "10進1桁→2進4桁 エンコーダ回路です。" << endl;
	cout << "0～9のいずれかの値をセットしてください。" << endl;
	int id;
	cin >> id;
	if (id < 0 || id > 9) {
		cout << "範囲外です。" << endl;
		return;
	}
	auto sw_data = sw_set(id);

	cout << "入力:";
	for (auto p : sw_data) {
		cout << (p->get() ? "1" : "0");
	}
	cout << endl;

	auto encode_ret = encoder(sw_data);
	cout << "10進→2進エンコード結果:" << endl;
	auto A = Terminal(encode_ret[3]->get());
	auto B = Terminal(encode_ret[2]->get());
	auto C = Terminal(encode_ret[1]->get());
	auto D = Terminal(encode_ret[0]->get());
	cout << "A = " << A->get() << endl;
	cout << "B = " << B->get() << endl;
	cout << "C = " << C->get() << endl;
	cout << "D = " << D->get() << endl;

	auto led = led_7seg(A, B, C, D);
	disp_led({ { led[0]->get(), led[1]->get(), led[2]->get(), led[3]->get(), led[4]->get(), led[5]->get(), led[6]->get() } });

}

static void sample6() {
	cout << "10進1桁加算器です。" << endl;

	cout << "A: 0～9のいずれかの値をセットしてください。" << endl;
	int A_id;
	cin >> A_id;
	if (A_id < 0 || A_id > 9) {
		cout << "範囲外です。" << endl;
		return;
	}

	cout << "B: 0～9のいずれかの値をセットしてください。" << endl;
	int B_id;
	cin >> B_id;
	if (B_id < 0 || B_id > 9) {
		cout << "範囲外です。" << endl;
		return;
	}

	auto A = encoder(sw_set(A_id));
	auto B = encoder(sw_set(B_id));

	cout << "10進→2進エンコード結果:" << endl;
	auto A0 = Terminal(A[0]->get());
	auto A1 = Terminal(A[1]->get());
	auto A2 = Terminal(A[2]->get());
	auto A3 = Terminal(A[3]->get());
	auto B0 = Terminal(B[0]->get());
	auto B1 = Terminal(B[1]->get());
	auto B2 = Terminal(B[2]->get());
	auto B3 = Terminal(B[3]->get());
	cout << "A3 = " << A3->get() << endl;
	cout << "A2 = " << A2->get() << endl;
	cout << "A1 = " << A1->get() << endl;
	cout << "A0 = " << A0->get() << endl;
	cout << "B3 = " << B3->get() << endl;
	cout << "B2 = " << B2->get() << endl;
	cout << "B1 = " << B1->get() << endl;
	cout << "B0 = " << B0->get() << endl;

	auto C = Adder10_1digit(A0, A1, A2, A3, B0, B1, B2, B3);
	cout << "C4 = " << C[4]->get() << endl;
	cout << "C3 = " << C[3]->get() << endl;
	cout << "C2 = " << C[2]->get() << endl;
	cout << "C1 = " << C[1]->get() << endl;
	cout << "C0 = " << C[0]->get() << endl;

	auto led10 = led_7seg(Terminal(0), Terminal(0), Terminal(0), C[4]);
	auto led1 = led_7seg(C[3], C[2], C[1], C[0]);
	disp_led({
		{ led10[0]->get(), led10[1]->get(), led10[2]->get(), led10[3]->get(), led10[4]->get(), led10[5]->get(), led10[6]->get() },
		{ led1[0]->get(), led1[1]->get(), led1[2]->get(), led1[3]->get(), led1[4]->get(), led1[5]->get(), led1[6]->get() }
	});
}

static void sample7(){
	cout << "10進4桁加算器です。" << endl;

	cout << "A: 0～9999のいずれかの値をセットしてください。" << endl;
	int a;
	cin >> a;
	if (a < 0 || a > 9999) {
		cout << "範囲外です。" << endl;
		return;
	}

	cout << "B: 0～9999のいずれかの値をセットしてください。" << endl;
	int b;
	cin >> b;
	if (b < 0 || b > 9999) {
		cout << "範囲外です。" << endl;
		return;
	}

	vector<vector<BaseParts*>> tA, tB;
	for (int i = 0; i < 4; i++) {
		tA.push_back(encoder(sw_set(a % 10)));
		tB.push_back(encoder(sw_set(b % 10)));
		a /= 10;
		b /= 10;
	}
	vector<vector<BaseParts*>> A, B;
	for (int i = 0; i < 4; i++) {
		vector<BaseParts*> tmpA, tmpB;
		for (int j = 0; j < 4; j++) {
			tmpA.push_back(Terminal(tA[i][j]->get()));
			tmpB.push_back(Terminal(tB[i][j]->get()));
		}
		A.push_back(tmpA);
		B.push_back(tmpB);
	}
	auto C = Adder10_4digit(A, B);

	vector<vector<BaseParts*>> led;
	for (int i = 0; i < 4; i++) {
		led.push_back(led_7seg(C.first[i][3], C.first[i][2], C.first[i][1], C.first[i][0]));
	}
	led.push_back(led_7seg(Terminal(0), Terminal(0), Terminal(0), Terminal(C.second->get() ? 1 : 0)));
	vector<vector<bool>> led_data;
	for (int i = 4; i >= 0; i--) {
		vector<bool> tmp;
		for (int j = 0; j < 7; j++) {
			tmp.push_back(led[i][j]->get());
		}
		led_data.push_back(tmp);
	}
	disp_led(led_data);
}

static void sample8() {
	cout << "RS-FFのサンプルです。" << endl;

	auto S = Terminal();
	auto R = Terminal();
	BaseParts *Q, *notQ;
	Q = Nand(Not(S), 0);
	notQ = Nand(Not(R), Q);
	Q->input[1] = notQ;

	cout << "0:どちらもOFF　1:S(セット)をON　2:R(リセット)をON　3:終了" << endl;
	int cmd;
	do {
		cin >> cmd;
		switch (cmd) {
		case 0:	S->set(0); R->set(0);	break;
		case 1:	S->set(1); R->set(0);	break;
		case 2:	S->set(0); R->set(1);	break;
		}
		cout << "S=" << S->get() << "  R=" << R->get() << "  Q=" << Q->get() << endl;

	} while (cmd >= 0 && cmd <= 2);
}

static void sample9() {
	cout << "D-FFのサンプルです。" << endl;

	auto D = Terminal();
	auto C = Terminal();
	auto Q = D_FF(D, C)[0];

	cout << "0, 1の変化を文字列として入力してください。" << endl;
	cout << "1字毎にクロックが反転します。" << endl;
	cout << "例）0000000111111111000000000011111110000000" << endl;
	cout << endl;
	cout << "C = 01010101010101010101010101010101..." << endl;
	cout << "D = ";
	string D_str;
	cin >> D_str;

	cout << "Q = ";
	for (int i = 0; i < (int)D_str.size(); i++) {
		D->set(D_str.c_str()[i] != '0');
		C->set(i % 2 != 0);

		cout << Q->get();
	}
	cout << endl;

}
