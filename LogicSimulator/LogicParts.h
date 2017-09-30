#pragma once
#include <vector>

// 論理回路素子
namespace LogicParts {

	// 論理回路素子の基底
	class BaseParts {
	public:

		// 入力素子を使って初期化
		BaseParts(std::vector<BaseParts*> input);

		// 入力素子
		std::vector<BaseParts*> input;

		// 計算値の取得
		bool get();

	protected:

		// 内部で呼ばれる計算値の取得関数の本体
		friend bool get_func(BaseParts* parts);

		// 計算値の取得本体内容
		virtual bool get_func_main() = 0;

	private:

		// 前回取得値
		bool prev_value = false;

		// メモリ開放機
		class Eraser {
		public:

			// 新しい素子を追加登録
			void add_parts(BaseParts* parts);

			// メモリ開放機削除時に登録済の素子を全開放
			~Eraser();

		private:

			// 登録中の素子リスト
			std::vector<BaseParts*> del_list;
		};

		// メモリ開放機
		static Eraser eraser;

		// 取得中の入力素子リスト（get中に再び現れた場合は前回値を用いる）
		static std::vector<BaseParts*> gotten_input_list;

	};

	// 端子
	class _Terminal : public BaseParts {
	public:

		// 端子の初期値を設定可
		_Terminal(bool value = false);

		// 値のセット
		virtual void set(bool value);

	protected:

		// 値の取得
		virtual bool get_func_main() override;

	private:

		// 値
		bool value;

	};

	// 端子オブジェクトの取得
	_Terminal* Terminal(bool value = false);

	// Not素子
	class _Not : public BaseParts {
	public:
		_Not(std::vector<BaseParts*> input) : BaseParts(input) {}
	protected:
		virtual bool get_func_main() override;
	};

	// Notオブジェクトの取得
	_Not* Not(BaseParts* A);

	// And素子
	class _And : public BaseParts {
	public:
		_And(std::vector<BaseParts*> input) : BaseParts(input) {}
	protected:
		virtual bool get_func_main() override;
	};

	// Andオブジェクトの取得
	_And* And(BaseParts* A, BaseParts* B);

	// Or素子
	class _Or : public BaseParts {
	public:
		_Or(std::vector<BaseParts*> input) : BaseParts(input) {}
	protected:
		virtual bool get_func_main() override;
	};

	// Orオブジェクトの取得
	_Or* Or(BaseParts* A, BaseParts* B);

	// Nand素子
	class _Nand : public BaseParts {
	public:
		_Nand(std::vector<BaseParts*> input) : BaseParts(input) {}
	protected:
		virtual bool get_func_main() override;
	};

	// Nandオブジェクトの取得
	_Nand* Nand(BaseParts* A, BaseParts* B);

	// Nor素子
	class _Nor : public BaseParts {
	public:
		_Nor(std::vector<BaseParts*> input) : BaseParts(input) {}
	protected:
		virtual bool get_func_main() override;
	};

	// Norオブジェクトの取得
	_Nor* Nor(BaseParts* A, BaseParts* B);

	// Xor素子
	class _Xor : public BaseParts {
	public:
		_Xor(std::vector<BaseParts*> input) : BaseParts(input) {}
	protected:
		virtual bool get_func_main() override;
	};

	// Xorオブジェクトの取得
	_Xor* Xor(BaseParts* A, BaseParts* B);

}
