#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int N;
int Answer;

int main()
{
	cin >> N;

	unordered_map<char, int> hashNum;
	string sTemp = to_string(N);

	for (int i = 0; i <= 9; i++)
	{
		hashNum['0' + i] = 0;
	}

	for (int i = 0; i < sTemp.size(); i++)
	{
		hashNum[sTemp[i]]++;
	}

	for (auto iter : hashNum)
	{
		bool bSixNine = false;

		if ((iter.first == '6' || iter.first == '9') && iter.second > Answer)
		{
			bSixNine = true;			
		}

		else if (iter.second > Answer)
		{
			bSixNine = false;
			Answer = iter.second;
		}

		if (bSixNine == true)
		{
			int sum = hashNum['6'] + hashNum['9'];

			if (sum % 2 == 0)
			{
				Answer = sum / 2;
			}

			else
			{
				Answer = sum / 2 + 1;
			}
		}
	}

	cout << Answer << '\n';

	return 0;
}