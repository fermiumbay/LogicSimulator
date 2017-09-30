#pragma once
#include <vector>

// �_����H�f�q
namespace LogicParts {

	// �_����H�f�q�̊��
	class BaseParts {
	public:

		// ���͑f�q���g���ď�����
		BaseParts(std::vector<BaseParts*> input);

		// ���͑f�q
		std::vector<BaseParts*> input;

		// �v�Z�l�̎擾
		bool get();

	protected:

		// �����ŌĂ΂��v�Z�l�̎擾�֐��̖{��
		friend bool get_func(BaseParts* parts);

		// �v�Z�l�̎擾�{�̓��e
		virtual bool get_func_main() = 0;

	private:

		// �O��擾�l
		bool prev_value = false;

		// �������J���@
		class Eraser {
		public:

			// �V�����f�q��ǉ��o�^
			void add_parts(BaseParts* parts);

			// �������J���@�폜���ɓo�^�ς̑f�q��S�J��
			~Eraser();

		private:

			// �o�^���̑f�q���X�g
			std::vector<BaseParts*> del_list;
		};

		// �������J���@
		static Eraser eraser;

		// �擾���̓��͑f�q���X�g�iget���ɍĂь��ꂽ�ꍇ�͑O��l��p����j
		static std::vector<BaseParts*> gotten_input_list;

	};

	// �[�q
	class _Terminal : public BaseParts {
	public:

		// �[�q�̏����l��ݒ��
		_Terminal(bool value = false);

		// �l�̃Z�b�g
		virtual void set(bool value);

	protected:

		// �l�̎擾
		virtual bool get_func_main() override;

	private:

		// �l
		bool value;

	};

	// �[�q�I�u�W�F�N�g�̎擾
	_Terminal* Terminal(bool value = false);

	// Not�f�q
	class _Not : public BaseParts {
	public:
		_Not(std::vector<BaseParts*> input) : BaseParts(input) {}
	protected:
		virtual bool get_func_main() override;
	};

	// Not�I�u�W�F�N�g�̎擾
	_Not* Not(BaseParts* A);

	// And�f�q
	class _And : public BaseParts {
	public:
		_And(std::vector<BaseParts*> input) : BaseParts(input) {}
	protected:
		virtual bool get_func_main() override;
	};

	// And�I�u�W�F�N�g�̎擾
	_And* And(BaseParts* A, BaseParts* B);

	// Or�f�q
	class _Or : public BaseParts {
	public:
		_Or(std::vector<BaseParts*> input) : BaseParts(input) {}
	protected:
		virtual bool get_func_main() override;
	};

	// Or�I�u�W�F�N�g�̎擾
	_Or* Or(BaseParts* A, BaseParts* B);

	// Nand�f�q
	class _Nand : public BaseParts {
	public:
		_Nand(std::vector<BaseParts*> input) : BaseParts(input) {}
	protected:
		virtual bool get_func_main() override;
	};

	// Nand�I�u�W�F�N�g�̎擾
	_Nand* Nand(BaseParts* A, BaseParts* B);

	// Nor�f�q
	class _Nor : public BaseParts {
	public:
		_Nor(std::vector<BaseParts*> input) : BaseParts(input) {}
	protected:
		virtual bool get_func_main() override;
	};

	// Nor�I�u�W�F�N�g�̎擾
	_Nor* Nor(BaseParts* A, BaseParts* B);

	// Xor�f�q
	class _Xor : public BaseParts {
	public:
		_Xor(std::vector<BaseParts*> input) : BaseParts(input) {}
	protected:
		virtual bool get_func_main() override;
	};

	// Xor�I�u�W�F�N�g�̎擾
	_Xor* Xor(BaseParts* A, BaseParts* B);

}
