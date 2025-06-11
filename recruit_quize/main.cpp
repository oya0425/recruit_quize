#include"question.h"
#include"exam_japanese.h"
#include"exam_english.h"
#include<iostream>
using namespace std;
#include<string>
#include<random>
#include<vector>


//�ő���񐔂����߂�
int gcd(int a, int b) {
	//�]�肪�O�ɂȂ������ɏ�����Ԃ�
	while (b) {
		int r = a % b;
		a = b;	//���������̔폜���ɂ���
		b = r;	//�]������̏����ɂ���
	}
	return a;
}

int main() {
	//Question questions[]{
	//	{"13x(-5)",13 * -5},
	//	{"(-21)��(-3)",-21 / -3},
	//	{"7-(4+2)��2",7 - (4 + 2) / 2},
	//};

	vector<Question> questions(3);

	random_device rd;
	mt19937 rand(rd());

	//�|���Z
	int x = uniform_int_distribution<>(1, 30)(rand);
	int y = uniform_int_distribution<>(1, 20)(rand);
	questions[0].q = to_string(x) + "x" + to_string(y)+"�����́H";
	
	questions[0].a = to_string(x * y);

	//����Z
	x = uniform_int_distribution<>(1, 30)(rand);
	y = uniform_int_distribution<>(1, 20)(rand);
	//questions[1].q = to_string(x) + "��" + to_string(y);
	//questions[1].a = x / y;
	questions[1].q = to_string(x*y) + "��" + to_string(y)+"�����́H";
	questions[1].a = to_string(x);

	//���G�Ȏ�
	x = uniform_int_distribution<>(1, 100)(rand);
	y = uniform_int_distribution<>(1, 10)(rand);
	int z = uniform_int_distribution<>(1, 10)(rand);
	int w = uniform_int_distribution<>(1, 10)(rand);
	questions[2].q = to_string(x) + "-("+ to_string(y)+"+" + to_string(z)+")��"+to_string(w);
	questions[2].q = to_string(x) + "-(" + to_string(y*w) + "+" + to_string(z*w) + ")��" + to_string(w)+"�̓����́H";

	//questions[2].a = x - (y + z) / w;
	questions[2].a = to_string(x - (y + z));

	//�O�p�`
	x = uniform_int_distribution<>(1, 10)(rand);
	y = uniform_int_distribution<>(1, 5)(rand) * 2;
	questions.push_back({ "�ʐ�" + to_string(x * y / 2) + "cm^2,���" + to_string(y) + "cm�̎O�p�`�̍��������߂�B",to_string(x) });

	//�~���̑̐�
	x = uniform_int_distribution<>(1, 10)(rand);
	y = uniform_int_distribution<>(1, 5)(rand);
	questions.push_back({ "��ӂ̔��a" + to_string(x) +"cm�A����"+ to_string(y) + "cm�̉~��������B\n" + "���̉~���̑̐ς�X��cm^3�Ƃ���BX�̒l�����߂�",
		to_string(x * x * y / 3) });

	//���̑̐�
	x = uniform_int_distribution<>(1, 10)(rand);
	y = uniform_int_distribution<>(1, 5)(rand);
	questions.push_back({ "�~�̔��a" + to_string(x) +"cm�̋�������B\n" + "���̋��̑̐ς�X��cm^3�Ƃ���BX�̒l�����߂�",
		to_string(x * x *x*  4/ 3) });

	//�T�C�R���̊m��
	x = uniform_int_distribution<>(1, 5)(rand);
	y = uniform_int_distribution<>(1, 6-x)(rand);
	z = gcd(y + 1, 6);
	questions.push_back({ "�T�C�R�����P�U���āA" + to_string(x) + "����" + to_string(x + y) + "���o��m�������߂�B",
		to_string((y + 1) / z) + "/" + to_string(6 / z) });

	//����@�K����g���@��A9�l�̂����V�l��I�ԁA�X�̊K���9*8�ɂȂ�V�͊܂܂Ȃ�
	x = uniform_int_distribution<>(3, 7)(rand);
	y = uniform_int_distribution<>(1, x)(rand);
	z = 1;
	for (int i = 0; i < y; i++) {
		z *= x - i;
	}
	questions.push_back({ to_string(x) + "�l�̂���" + to_string(y) + "�l��I��ŕ��ׂ���@�͉��ʂ肠�邩�H",
		to_string(z) });

	cout << "[���N���[�g�����΍�N�C�Y]\n";
	//cout << "13x(-5)�̓����́H\n";
	cout << "���Ȃ�I��ł�������\n1=���w\n2=����\n3=�p��\n";
	int subject;
	cin >> subject;
	if (subject == 2) {
		questions = CreateKanjiExam();
		const QuestionList idiomExam = CreateIdiomExam();
		questions.insert(questions.end(), idiomExam.begin(), idiomExam.end());

		QuestionList homophoneExam = CreateHomophoneExam();
		questions.insert(questions.end(), homophoneExam.begin(), homophoneExam.end());

		//�΋`��
		QuestionList antonymExam = CreateAntonymExam();
		questions.insert(questions.end(), antonymExam.begin(), antonymExam.end());

		//�ދ`��
		QuestionList synonymExam = CreateSynonymExam();
		questions.insert(questions.end(), synonymExam.begin(), synonymExam.end());
	}
	else if (subject == 3) {
		questions = CreateEnglishWordExam();
		QuestionList phraseExam = CreateEnglishPhraseExam();

	}
	

	for (const auto& e : questions) {
		cout << e.q << "\n";
		string answer;
		cin >> answer;

		if (answer == e.a) {
			cout << "����!\n";
		}
		else {
			cout << "�ԈႢ�I������" << e.a << "\n";
		}
	}
}