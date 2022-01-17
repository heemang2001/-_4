#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int T;
vector<int> vecAnswer;

int main()
{
	cin >> T;	

	for (int i = 0; i < T; i++)
	{		
		int answer = 0;
		string s;
		string p;

		cin >> s >> p;

		int size_p = p.size();
		int size_s = s.size();
		int cnt_p = 0;
		int FindIndex = 0;

		while (1)
		{
			FindIndex = s.find(p, FindIndex);			

			if (FindIndex == -1)
			{
				break;
			}

			FindIndex += size_p;
			cnt_p++;
		}

		size_s -= (cnt_p * size_p);
		answer = cnt_p + size_s;

		vecAnswer.push_back(answer);
	}

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << '\n';
	}

	return 0;
}