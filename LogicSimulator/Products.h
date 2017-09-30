#pragma once
#include "LogicComposite.h"

// 論理回路製品
namespace LogicParts {

	// 0～9の10個のスイッチ（idに対応するスイッチのみを押下し、残りをOFFする）
	std::vector<BaseParts*> sw_set(unsigned int id);

	// LED点灯パターンに応じて7セグメントLEDを表示（配列で入力し、複数個の数字を表示）
	void disp_led(std::vector<std::vector<bool>> led);

}