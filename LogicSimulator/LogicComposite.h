#pragma once
#include "LogicParts.h"

// �_����H���i
namespace LogicParts {

	// �����Z��(����:[A]������鐔, [B]������)(�o��:[0]�J��オ��, [1]�v�Z�l)
	std::vector<BaseParts*> HA(BaseParts* A, BaseParts* B);

	// �S���Z��(����:[A]������鐔, [B]������, [C]�J��オ���Ă�����)(�o��:[0]�J��オ��, [1]�v�Z�l)
	std::vector<BaseParts*> FA(BaseParts* A, BaseParts* B, BaseParts* C);

	// 4bit���Z��(����:[A0-A3]������鐔(LSB�`MSB�̏�), [B0-B3]������(LSB�`MSB�̏�))(�o��:[0-3]�v�Z�l(LSB�`MSB�̏�), [4]�J��オ��)
	std::vector<BaseParts*> Adder4bit(BaseParts* A0, BaseParts* A1, BaseParts* A2, BaseParts* A3, BaseParts* B0, BaseParts* B1, BaseParts* B2, BaseParts* B3);

	// 4bit�{1bit���Z��(����:[A0-A3]������鐔(LSB�`MSB�̏�), [B0]������)(�o��:[0-3]�v�Z�l(LSB�`MSB�̏�), [4]�J��オ��)
	std::vector<BaseParts*> Adder4bit1bit(BaseParts* A0, BaseParts* A1, BaseParts* A2, BaseParts* A3, BaseParts* B0);

	// 10�i1�����Z��(����:[A0-A3]������鐔(LSB�`MSB�̏�), [B0-B3]������(LSB�`MSB�̏�))(�o��:[0-3]�v�Z�l(LSB�`MSB�̏�), [4]�J��オ��)
	std::vector<BaseParts*> Adder10_1digit(BaseParts* A0, BaseParts* A1, BaseParts* A2, BaseParts* A3, BaseParts* B0, BaseParts* B1, BaseParts* B2, BaseParts* B3);

	// 10�i4�����Z��(����:[A]������鐔(LSB�`MSB�̏���4bit�i�[�������̂�4����(��̈ʁ`��̈�)), [B]������([A]���l))(�o��:[pair_first]�v�Z�l([A]���l), [pair_second]�J��オ��)
	std::pair<std::vector<std::vector<BaseParts*>>, BaseParts*> Adder10_4digit(std::vector<std::vector<BaseParts*>> A, std::vector<std::vector<BaseParts*>> B);

	// 10�i��2�i�G���R�[�_(����:[0-9]10�i��)(�o��:[0-3]2�i��(LSB�`MSB�̏�))
	std::vector<BaseParts*> encoder(std::vector<BaseParts*> input);

	// 7�Z�O�����gLED(����:[A-D]2�i��(MSB�`LSB�̏�))(�o��:[0-6]LED�_��(a�`g))
	std::vector<BaseParts*> led_7seg(BaseParts* A, BaseParts* B, BaseParts* C, BaseParts* D);

	// RS-�t���b�v�t���b�v(����:[S]�Z�b�g, [R]���Z�b�g)(�o��:[0]Q, [1]notQ)
	std::vector<BaseParts*> RS_FF(BaseParts* S, BaseParts* R);

	// ������RS-�t���b�v�t���b�v(����:[S]�Z�b�g, [R]���Z�b�g, [C]�N���b�N)(�o��:[0]Q, [1]notQ)
	std::vector<BaseParts*> RS_FF(BaseParts* S, BaseParts* R, BaseParts* C);

	// JK-�t���b�v�t���b�v(����:[J]�Z�b�g, [K]���Z�b�g, [C]�N���b�N)(�o��:[0]Q, [1]notQ)
	std::vector<BaseParts*> JK_FF(BaseParts* J, BaseParts* K, BaseParts* C);

	// D-�t���b�v�t���b�v(����:[D]�Z�b�g, [C]�N���b�N)(�o��:[0]Q, [1]notQ)
	std::vector<BaseParts*> D_FF(BaseParts* D, BaseParts* C);

	// T-�t���b�v�t���b�v(����:[C]�N���b�N)(�o��:[0]Q, [1]notQ)
	std::vector<BaseParts*> T_FF(BaseParts* C);

}
