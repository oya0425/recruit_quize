#include<iostream>
using namespace std;
#include<string>

//問題文と答えをまとめる構造体
struct Question
{
	string q;	//問題文
	int a;		//答え
};

int main() {
	Question questions[]{
		{"13x(-5)",13 * -5},
		{"(-21)÷(-3)",-21 / -3},
		{"7-(4+2)÷2",7 - (4 + 2) / 2},
	};

	cout << "[リクルート試験対策クイズ]\n";
	//cout << "13x(-5)の答えは？\n";
	
	for (const auto& e : questions) {
		cout << e.q << "の答えは？\n";
		int answer;
		cin >> answer;

		if (answer == e.a) {
			cout << "正解!\n";
		}
		else {
			cout << "間違い！正解は" << e.a << "\n";
		}
	}
}