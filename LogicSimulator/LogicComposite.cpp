#include "LogicComposite.h"

using namespace std;
using namespace LogicParts;

vector<BaseParts*> LogicParts::HA(BaseParts* A, BaseParts* B) {
	return{
		And(A, B),
		Xor(A, B)
	};
}

vector<BaseParts*> LogicParts::FA(BaseParts* A, BaseParts* B, BaseParts* C) {
	auto D = HA(A, B);
	auto E = HA(D[1], C);
	return{
		Or(D[0], E[0]),
		E[1]
	};
}

vector<BaseParts*> LogicParts::Adder4bit(BaseParts* A0, BaseParts* A1, BaseParts* A2, BaseParts* A3, BaseParts* B0, BaseParts* B1, BaseParts* B2, BaseParts* B3) {
	auto A = HA(A0, B0);
	auto B = FA(A1, B1, A[0]);
	auto C = FA(A2, B2, B[0]);
	auto D = FA(A3, B3, C[0]);
	return{
		A[1],
		B[1],
		C[1],
		D[1],
		D[0]
	};
}

vector<BaseParts*> LogicParts::Adder4bit1bit(BaseParts* A0, BaseParts* A1, BaseParts* A2, BaseParts* A3, BaseParts* B0) {
	auto A = HA(A0, B0);
	auto B = HA(A1, A[0]);
	auto C = HA(A2, B[0]);
	auto D = HA(A3, C[0]);
	return{
		A[1],
		B[1],
		C[1],
		D[1],
		D[0]
	};
}

vector<BaseParts*> LogicParts::Adder10_1digit(BaseParts* A0, BaseParts* A1, BaseParts* A2, BaseParts* A3, BaseParts* B0, BaseParts* B1, BaseParts* B2, BaseParts* B3){
	auto A = Adder4bit(A0, A1, A2, A3, B0, B1, B2, B3);
	auto B = Or(And(Or(A[1], A[2]), A[3]), A[4]);
	auto C = HA(A[1], B);
	auto D = FA(A[2], B, C[0]);
	return{
		A[0],
		C[1],
		D[1],
		Xor(A[3], D[0]),
		B
	};
}

pair<vector<vector<BaseParts*>>, BaseParts*> LogicParts::Adder10_4digit(vector<vector<BaseParts*>> A, vector<vector<BaseParts*>> B) {
	pair<vector<vector<BaseParts*>>, BaseParts*> ret;
	vector<BaseParts*> add_ret;
	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			add_ret = Adder10_1digit(A[i][0], A[i][1], A[i][2], A[i][3], B[i][0], B[i][1], B[i][2], B[i][3]);
		}
		else {
			auto add_src = Adder4bit1bit(B[i][0], B[i][1], B[i][2], B[i][3], add_ret[4]);
			add_ret = Adder10_1digit(A[i][0], A[i][1], A[i][2], A[i][3], add_src[0], add_src[1], add_src[2], add_src[3]);
		}
		ret.first.push_back({ add_ret[0], add_ret[1], add_ret[2], add_ret[3] });
	}
	ret.second = add_ret[4];
	return ret;
}

vector<BaseParts*> LogicParts::encoder(vector<BaseParts*> input) {
	return{
		Or(input[1], Or(input[3], Or(input[5], Or(input[7], input[9])))),
		Or(Or(input[2], input[3]), Or(input[6], input[7])),
		Or(Or(input[4], input[5]) , Or(input[6], input[7])),
		Or(input[8], input[9])
	};
}

vector<BaseParts*> LogicParts::led_7seg(BaseParts* A, BaseParts* B, BaseParts* C, BaseParts* D) {
	return{
		Or(Or(A, C), Not(Xor(B, D))),
		Nand(Xor(C, D), B),
		Or(Or(B, Not(C)), D),
		Or(Or(Or(And(C, Nand(B, D)), Nor(B, D)), And(And(Not(C), B), D)), A),
		And(Not(D), Or(Not(B), C)),
		Or(Or(Nor(C, D), B), A),
		Or(Or(And(Not(D), C), Xor(B, C)), A)
	};
}

vector<BaseParts*> LogicParts::RS_FF(BaseParts* S, BaseParts* R) {
	auto Q = Nand(Not(S), 0);
	auto notQ = Nand(Not(R), Q);
	Q->input[1] = notQ;
	return{
		Q,
		notQ
	};
}

vector<BaseParts*> LogicParts::RS_FF(BaseParts* S, BaseParts* R, BaseParts* C) {
	auto Q = Nand(Nand(S, C), 0);
	auto notQ = Nand(Nand(R, C), Q);
	Q->input[1] = notQ;
	return{
		Q,
		notQ
	};
}

vector<BaseParts*> LogicParts::JK_FF(BaseParts* J, BaseParts* K, BaseParts* C) {
	auto S = And(J, 0);
	auto R = And(K, 0);
	auto FF1 = RS_FF(S, R, C);
	auto FF2 = RS_FF(FF1[0], FF1[1], Not(C));
	S->input[1] = FF2[1];
	R->input[1] = FF2[0];
	return{
		FF2[0],
		FF2[1]
	};
}

vector<BaseParts*> LogicParts::D_FF(BaseParts* D, BaseParts* C) {
	auto A = Nand(D, Not(C));
	auto B = Nand(A, 0);
	auto E = Nand(B, Nand(A, Not(C)));
	B->input[1] = E;
	auto F = Nand(B, C);
	auto Q = Nand(F, 0);
	auto notQ = Nand(Q, Nand(F, C));
	Q->input[1] = notQ;
	return{
		Q,
		notQ
	};
}

vector<BaseParts*> LogicParts::T_FF(BaseParts* C) {
	auto one = Terminal(1);
	auto Q = JK_FF(one, one, Not(C));
	return{
		Q[0],
		Q[1]
	};
}
