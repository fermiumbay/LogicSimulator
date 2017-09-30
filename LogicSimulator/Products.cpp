#include "Products.h"

#include <iostream>
#include <string>
using namespace std;
using namespace LogicParts;

// LED表示用の文字列を作成（数字1個分）
static vector<string> get_disp_led_str(vector<bool> led);

vector<BaseParts*> LogicParts::sw_set(unsigned int id) {
	vector<BaseParts*> ret;
	for (int i = 0; i <= 9; i++) {
		ret.push_back(Terminal(i == id));
	}
	return ret;
}

static vector<string> get_disp_led_str(vector<bool> led) {
	auto seg = [](bool a) -> string {
		return a ? "■" : "□";
	};
	vector<string> ret;
	ret.push_back("　" + seg(led[0]) + seg(led[0]) + seg(led[0]) + seg(led[0]) + "　");
	ret.push_back(seg(led[5]) + "　" + "　" + "　" + "　" + seg(led[1]));
	ret.push_back(seg(led[5]) + "　" + "　" + "　" + "　" + seg(led[1]));
	ret.push_back(seg(led[5]) + "　" + "　" + "　" + "　" + seg(led[1]));
	ret.push_back("　" + seg(led[6]) + seg(led[6]) + seg(led[6]) + seg(led[6]) + "　");
	ret.push_back(seg(led[4]) + "　" + "　" + "　" + "　" + seg(led[2]));
	ret.push_back(seg(led[4]) + "　" + "　" + "　" + "　" + seg(led[2]));
	ret.push_back(seg(led[4]) + "　" + "　" + "　" + "　" + seg(led[2]));
	ret.push_back("　" + seg(led[3]) + seg(led[3]) + seg(led[3]) + seg(led[3]) + "　");
	return ret;
}

void LogicParts::disp_led(vector<vector<bool>> led) {
	vector<string> disp_str;
	for (int i = 0; i < 9; i++) {
		disp_str.push_back("");
	}
	for (auto p : led) {
		auto tmp = get_disp_led_str(p);
		for (int i = 0; i < 9; i++) {
			disp_str[i] += tmp[i] + "　";
		}
	}
	for (auto p : disp_str) {
		cout << p << endl;
	}
}
