#pragma once
#include<string>
#include<vector>
//�w�b�_�[�t�@�C���ɂ�using namespace std�������Ȃ�
//��蕶�Ɠ������܂Ƃ߂�\����
struct Question
{
	std::string q;	//��蕶
	//int a;		//����
	std::string a;
};
using QuestionList = std::vector<Question>;  //using��Typedef�ł������炵������using�ɂȂ��Ă���
