/*
* ����Ʈ�����к� 2017203005 ������
* ���� ȯ��: MS Visual Studio Community 2019 ver 16.7.3
* ���� ȯ��: Windows ��� ������Ʈ(cmd)
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// sort�� ���� ���� ���� �Լ�: value(�ܾ� ���� Ƚ��) �������� ����
bool cmp(const pair<string, int>& p1, const pair<string, int>& p2)
{
	return p1.second > p2.second;
}

int main()
{
	size_t len;			// password�� ����
	string total_str;	// ��ü ���ڿ�(�ؽ�Ʈ)
	unordered_map<string, int> wordFreq;
	unordered_map<string, int>::iterator itr;

	ifstream input(stdin);
	input >> len >> total_str;
	stringstream ss(total_str);		// ��ü ���ڿ��� ��°�� ���� string stream

	char* buf = new char[len + 1];	// ss���� ���� n��ŭ split�� �ܾ�(���ڿ�)
	string word;					// buf�� �Űܴ��� string
	streamoff end = ss.str().length();
	streamoff next = 0;
	
	while (next != (end - len + 1)) {
		memset(buf, 0x00, len + 1);
		next = ss.tellg();		next++;	// �а� ��, ���ƿ� ���� ��ġ
	
		ss.read(buf, len);
		word = buf;
		wordFreq[word]++;

		ss.seekg(next);
	}

	// vector�� �ؽ��ʿ� ����� �����͵��� ��� ���� ��,
	// value ��(�ܾ� ���� Ƚ��)�� �������� �������� ����
	vector<pair<string, int>> wf_vector(wordFreq.begin(), wordFreq.end());
	sort(wf_vector.begin(), wf_vector.end(), cmp);

	cout << wf_vector[0].first << ", " << wf_vector[0].second << endl;

	delete[] buf;

	return 0;
}