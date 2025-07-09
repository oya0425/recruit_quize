#pragma once
#include<vector>
#include<string>

//配列をシャッフル
void Shuffle(std::vector<int>& indices);

//ランダムな番号配列を作成する
std::vector<int>CreateRandomIndices(int n);


//間違った番号の配列を作成する
//n		作成する番号の範囲
//correctIndex　正解の番号
std::vector<int>CreateWronogIndices(int n, int correctIndex);

//s　文字を分割する
//c　区切り文字
std::vector<std::string>Split(const std::string& s, char c);


