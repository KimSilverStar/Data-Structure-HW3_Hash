/*
* 소프트웨어학부 2017203005 김은성
* 개발 환경: MS Visual Studio Community 2019 ver 16.7.3
* 실행 환경: Windows 명령 프롬프트(cmd)
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// sort를 위한 정렬 기준 함수: value(단어 등장 횟수) 내림차순 정렬
bool cmp(const pair<string, int>& p1, const pair<string, int>& p2)
{
	return p1.second > p2.second;
}

int main()
{
	size_t len;			// password의 길이
	string total_str;	// 전체 문자열(텍스트)
	unordered_map<string, int> wordFreq;
	unordered_map<string, int>::iterator itr;

	ifstream input(stdin);
	input >> len >> total_str;
	stringstream ss(total_str);		// 전체 문자열을 통째로 담은 string stream

	char* buf = new char[len + 1];	// ss에서 길이 n만큼 split할 단어(문자열)
	string word;					// buf를 옮겨담을 string
	streamoff end = ss.str().length();
	streamoff next = 0;
	
	while (next != (end - len + 1)) {
		memset(buf, 0x00, len + 1);
		next = ss.tellg();		next++;	// 읽고난 후, 돌아올 다음 위치
	
		ss.read(buf, len);
		word = buf;
		wordFreq[word]++;

		ss.seekg(next);
	}

	// vector에 해쉬맵에 저장된 데이터들을 모두 저장 후,
	// value 값(단어 등장 횟수)을 기준으로 내림차순 정렬
	vector<pair<string, int>> wf_vector(wordFreq.begin(), wordFreq.end());
	sort(wf_vector.begin(), wf_vector.end(), cmp);

	cout << wf_vector[0].first << ", " << wf_vector[0].second << endl;

	delete[] buf;

	return 0;
}