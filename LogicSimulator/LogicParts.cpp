#include "LogicParts.h"

#include <algorithm>

using namespace std;
using namespace LogicParts;

void BaseParts::Eraser::add_parts(BaseParts* parts) {
	del_list.push_back(parts);
}

BaseParts::Eraser::~Eraser() {
	for (auto p : del_list) {
		delete p;
	}
}

BaseParts::Eraser BaseParts::eraser;
std::vector<BaseParts*> BaseParts::gotten_input_list;

BaseParts::BaseParts(vector<BaseParts*> input) {
	eraser.add_parts(this);
	for (auto p : input) {
		this->input.push_back(p);
	}
}

bool BaseParts::get() {
	gotten_input_list.clear();
	return get_func(this);
}

bool LogicParts::get_func(BaseParts* parts) {
	if (find(BaseParts::gotten_input_list.begin(), BaseParts::gotten_input_list.end(), parts) == BaseParts::gotten_input_list.end()) {
		BaseParts::gotten_input_list.push_back(parts);
		parts->prev_value = parts->get_func_main();
	}
	return parts->prev_value;
}

_Terminal::_Terminal(bool value) : BaseParts({}) {
	this->value = value;
}

bool _Terminal::get_func_main() {
	return value;
}

void _Terminal::set(bool value) {
	this->value = value;
}

_Terminal* LogicParts::Terminal(bool value) {
	return new _Terminal(value);
}

bool _Not::get_func_main() {
	return !get_func(input[0]);
}

_Not* LogicParts::Not(BaseParts* A) {
	return new _Not({ A });
}

bool _And::get_func_main() {
	return get_func(input[0]) && get_func(input[1]);
}

_And* LogicParts::And(BaseParts* A, BaseParts* B) {
	return new _And({ A, B });
}

bool _Or::get_func_main() {
	return get_func(input[0]) || get_func(input[1]);
}

_Or* LogicParts::Or(BaseParts* A, BaseParts* B) {
	return new _Or({ A, B });
}

bool _Nand::get_func_main() {
	return !(get_func(input[0]) && get_func(input[1]));
}

_Nand* LogicParts::Nand(BaseParts* A, BaseParts* B) {
	return new _Nand({ A, B });
}

bool _Nor::get_func_main() {
	return !(get_func(input[0]) || get_func(input[1]));
}

_Nor* LogicParts::Nor(BaseParts* A, BaseParts* B) {
	return new _Nor({ A, B });
}

bool _Xor::get_func_main() {
	return (!get_func(input[0]) && get_func(input[1])) || (get_func(input[0]) && !get_func(input[1]));
}

_Xor* LogicParts::Xor(BaseParts* A, BaseParts* B) {
	return new _Xor({ A, B });
}
