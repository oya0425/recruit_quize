#include "exam_politics.h"
#include"utility.h"
#include<fstream>
#include<iostream>
#include<random>
#include<unordered_map>
using namespace std;

//政治の問題を作成する
QuestionList CreatePoliticsExam()
{
	struct PoliticsData
	{
		string genre;	//ジャンル
		string text;	//問題
		vector<string>answers;	//空欄に入る答えの配列
	};
	unordered_map<string, vector<PoliticsData>>data;

	{//政治問題データを読み込む
		
		constexpr char filename[] = "japanese_politics.txt"; 
		ifstream ifs(filename);
		if (!ifs) {
			cerr << "エラー" << filename << "読み込めません\n";
			return {};
		}
		while (true) {
			string s;

			getline(ifs, s);	//１行読み取る
			if (!ifs) {
				break;			//ファイル終端に達したので終了
			}
			const vector<string> v = Split(s, ',');
			const string& genre = v[0];	//ジャンルを取得
			data[genre].push_back({genre,v[1],vector<string>(v.begin() + 2,v.end())});
			
		}

	}//政治問題をデータを読み込む

	constexpr int genreCount = 2;	//出題するジャンル数
	constexpr int quizCount = 5;	//各ジャンルの出題数
	QuestionList questions;
	questions.reserve(genreCount* quizCount);
	random_device rd;

	//ランダムに選んだ２つのジャンルから、ジャンル内でランダムに選んだ５問を出題する
	const vector<int>genreIndices = CreateRandomIndices((int)data.size());
	for (int i = 0; i < genreCount; i++) {
		//出題するジャンルを選択
		auto itr = data.begin();
		advance(itr, genreIndices[i]);	//参照位置を指定したところまで進める
		const auto& genre = itr->second;	//値（ジャンルのデータ配列）を取り出す

		const vector<int>questionIndices = CreateRandomIndices((int)genre.size());

		for (int j = 0; j < quizCount; j++) {
			const auto& question = genre[questionIndices[j]];	//選んだ問題データ

			//空欄の位置と数を調べる
			//空欄は「空き括弧」と「閉じ括弧」のペア、つまり{}で表される
			vector<int> blanks;	//空欄の位置の配列
			for (int k = 0; k < question.text.size(); k++) {
				if (question.text[k] == '{' && question.text[k + 1] == '}') {
					blanks.push_back(k);
				}
			}

			//空欄のうち１つをランダムに選ぶ
			const int index = uniform_int_distribution<>(0, (int)blanks.size() - 1)(rd);

			//問題文のコピーを作成しつつ、選ばれなかった空欄を「答え」に置き換える
			string s = "[" + question.genre + "]次の文章の[?]に入る単語を答えよ\n";
			int from = 0;	//コピー元の先頭位置
			for (int k = 0; k < blanks.size(); k++) {
				const int end = blanks[k];	//空欄の位置
				s.append(question.text, from, end - from);//空欄の手前までの範囲をコピー

				if (k != index) {
					s += question.answers[k];	//選ばれなかった空欄の場合は答えをコピー
				}
				else {
					s.append("[ ? ]");
				}

				from = end + 2;	//コピー元の位置を更新
			}
			s.append(question.text, from);	//問題文の末尾部分をコピー

			questions.push_back({ s,question.answers[index] });

		}//for j < quizCount

	}//for i <genreCount

	return questions;
}
