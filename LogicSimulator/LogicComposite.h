#pragma once
#include "LogicParts.h"

// 論理回路部品
namespace LogicParts {

	// 半加算器(入力:[A]足される数, [B]足す数)(出力:[0]繰り上がり, [1]計算値)
	std::vector<BaseParts*> HA(BaseParts* A, BaseParts* B);

	// 全加算器(入力:[A]足される数, [B]足す数, [C]繰り上がってきた数)(出力:[0]繰り上がり, [1]計算値)
	std::vector<BaseParts*> FA(BaseParts* A, BaseParts* B, BaseParts* C);

	// 4bit加算器(入力:[A0-A3]足される数(LSB～MSBの順), [B0-B3]足す数(LSB～MSBの順))(出力:[0-3]計算値(LSB～MSBの順), [4]繰り上がり)
	std::vector<BaseParts*> Adder4bit(BaseParts* A0, BaseParts* A1, BaseParts* A2, BaseParts* A3, BaseParts* B0, BaseParts* B1, BaseParts* B2, BaseParts* B3);

	// 4bit＋1bit加算器(入力:[A0-A3]足される数(LSB～MSBの順), [B0]足す数)(出力:[0-3]計算値(LSB～MSBの順), [4]繰り上がり)
	std::vector<BaseParts*> Adder4bit1bit(BaseParts* A0, BaseParts* A1, BaseParts* A2, BaseParts* A3, BaseParts* B0);

	// 10進1桁加算器(入力:[A0-A3]足される数(LSB～MSBの順), [B0-B3]足す数(LSB～MSBの順))(出力:[0-3]計算値(LSB～MSBの順), [4]繰り上がり)
	std::vector<BaseParts*> Adder10_1digit(BaseParts* A0, BaseParts* A1, BaseParts* A2, BaseParts* A3, BaseParts* B0, BaseParts* B1, BaseParts* B2, BaseParts* B3);

	// 10進4桁加算器(入力:[A]足される数(LSB～MSBの順で4bit格納したものを4桁分(一の位～千の位)), [B]足す数([A]同様))(出力:[pair_first]計算値([A]同様), [pair_second]繰り上がり)
	std::pair<std::vector<std::vector<BaseParts*>>, BaseParts*> Adder10_4digit(std::vector<std::vector<BaseParts*>> A, std::vector<std::vector<BaseParts*>> B);

	// 10進→2進エンコーダ(入力:[0-9]10進数)(出力:[0-3]2進数(LSB～MSBの順))
	std::vector<BaseParts*> encoder(std::vector<BaseParts*> input);

	// 7セグメントLED(入力:[A-D]2進数(MSB～LSBの順))(出力:[0-6]LED点灯(a～g))
	std::vector<BaseParts*> led_7seg(BaseParts* A, BaseParts* B, BaseParts* C, BaseParts* D);

	// RS-フリップフロップ(入力:[S]セット, [R]リセット)(出力:[0]Q, [1]notQ)
	std::vector<BaseParts*> RS_FF(BaseParts* S, BaseParts* R);

	// 同期式RS-フリップフロップ(入力:[S]セット, [R]リセット, [C]クロック)(出力:[0]Q, [1]notQ)
	std::vector<BaseParts*> RS_FF(BaseParts* S, BaseParts* R, BaseParts* C);

	// JK-フリップフロップ(入力:[J]セット, [K]リセット, [C]クロック)(出力:[0]Q, [1]notQ)
	std::vector<BaseParts*> JK_FF(BaseParts* J, BaseParts* K, BaseParts* C);

	// D-フリップフロップ(入力:[D]セット, [C]クロック)(出力:[0]Q, [1]notQ)
	std::vector<BaseParts*> D_FF(BaseParts* D, BaseParts* C);

	// T-フリップフロップ(入力:[C]クロック)(出力:[0]Q, [1]notQ)
	std::vector<BaseParts*> T_FF(BaseParts* C);

}
