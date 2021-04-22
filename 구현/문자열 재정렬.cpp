#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;
	int nAdd = 0;
	
	vector<string> Alphabet;	

	cin >> S;

	for (int i = 0; i < S.size(); i++)
	{
		int nTemp = 0;
		string sTemp = "";

		nTemp = S[i] - 'A';
		sTemp = S[i];

		// 문자면
		if (nTemp >= 0)
		{
			Alphabet.push_back(sTemp);
		}

		// 숫자면
		else
		{
			// 숫자값을 더함
			nTemp = stoi(sTemp);
			nAdd += nTemp;
		}
	}

	// 숫자를 문자열로
	string sNum = to_string(nAdd);

	// 알파벳 정렬
	sort(Alphabet.begin(), Alphabet.end());

	// 그 뒤에 숫자(문자열) 붙임
	Alphabet.push_back(sNum);

	// 출력
	for (int i = 0; i < Alphabet.size(); i++)
	{
		cout << Alphabet[i];
	}
	
	return 0;
}