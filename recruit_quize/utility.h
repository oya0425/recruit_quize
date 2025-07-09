#pragma once
#include<vector>
#include<string>

//�z����V���b�t��
void Shuffle(std::vector<int>& indices);

//�����_���Ȕԍ��z����쐬����
std::vector<int>CreateRandomIndices(int n);


//�Ԉ�����ԍ��̔z����쐬����
//n		�쐬����ԍ��͈̔�
//correctIndex�@�����̔ԍ�
std::vector<int>CreateWronogIndices(int n, int correctIndex);

//s�@�����𕪊�����
//c�@��؂蕶��
std::vector<std::string>Split(const std::string& s, char c);


