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

		// ���ڸ�
		if (nTemp >= 0)
		{
			Alphabet.push_back(sTemp);
		}

		// ���ڸ�
		else
		{
			// ���ڰ��� ����
			nTemp = stoi(sTemp);
			nAdd += nTemp;
		}
	}

	// ���ڸ� ���ڿ���
	string sNum = to_string(nAdd);

	// ���ĺ� ����
	sort(Alphabet.begin(), Alphabet.end());

	// �� �ڿ� ����(���ڿ�) ����
	Alphabet.push_back(sNum);

	// ���
	for (int i = 0; i < Alphabet.size(); i++)
	{
		cout << Alphabet[i];
	}
	
	return 0;
}