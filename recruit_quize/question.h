#pragma once
#include<string>
#include<vector>
//ヘッダーファイルにはusing namespace stdを書かない
//問題文と答えをまとめる構造体
struct Question
{
	std::string q;	//問題文
	//int a;		//答え
	std::string a;
};
using QuestionList = std::vector<Question>;  //usingはTypedefでもいいらしい今はusingになっている
