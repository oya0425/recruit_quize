#include<iostream>
using namespace std;
#include<string>
#include<random>
#include<vector>

//��蕶�Ɠ������܂Ƃ߂�\����
struct Question
{
	string q;	//��蕶
	int a;		//����
};

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
	questions[0].q = to_string(x) + "x" + to_string(y);
	questions[0].a = x * y;

	x = uniform_int_distribution<>(1, 30)(rand);
	y = uniform_int_distribution<>(1, 20)(rand);
	//questions[1].q = to_string(x) + "��" + to_string(y);
	//questions[1].a = x / y;
	questions[1].q = to_string(x*y) + "��" + to_string(y);
	questions[1].a = x;

	x = uniform_int_distribution<>(1, 100)(rand);
	y = uniform_int_distribution<>(1, 10)(rand);
	int z = uniform_int_distribution<>(1, 10)(rand);
	int w = uniform_int_distribution<>(1, 10)(rand);
	questions[2].q = to_string(x) + "-("+ to_string(y)+"+" + to_string(z)+")��"+to_string(w);
	questions[2].q = to_string(x) + "-(" + to_string(y*w) + "+" + to_string(z*w) + ")��" + to_string(w);

	//questions[2].a = x - (y + z) / w;
	questions[2].a = x - (y + z);

	//�O�p�`
	x = uniform_int_distribution<>(1, 10)(rand);
	y = uniform_int_distribution<>(1, 5)(rand) * 2;
	questions.push_back({ "�ʐ�" + to_string(x * y / 2) + "cm^2,���" + to_string(y) + "cm�̎O�p�`�̍��������߂�B",+x });

	//�|���Z

	cout << "[���N���[�g�����΍�N�C�Y]\n";
	//cout << "13x(-5)�̓����́H\n";
	
	for (const auto& e : questions) {
		cout << e.q << "\n";
		int answer;
		cin >> answer;

		if (answer == e.a) {
			cout << "����!\n";
		}
		else {
			cout << "�ԈႢ�I������" << e.a << "\n";
		}
	}
}