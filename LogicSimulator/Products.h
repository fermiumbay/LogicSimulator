#pragma once
#include "LogicComposite.h"

// �_����H���i
namespace LogicParts {

	// 0�`9��10�̃X�C�b�`�iid�ɑΉ�����X�C�b�`�݂̂��������A�c���OFF����j
	std::vector<BaseParts*> sw_set(unsigned int id);

	// LED�_���p�^�[���ɉ�����7�Z�O�����gLED��\���i�z��œ��͂��A�����̐�����\���j
	void disp_led(std::vector<std::vector<bool>> led);

}