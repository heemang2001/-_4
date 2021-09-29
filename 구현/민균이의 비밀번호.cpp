#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
int Answer_Lenth;
char Answer_char;

int main()
{
	cin >> N;

	vector<string> vecString;	
	vector<string> vecReverseString;

	for (int i = 0; i < N; i++)
	{
		string sTemp;	
		string reverse_string;

		cin >> sTemp;	
		vecString.push_back(sTemp);		

		reverse_string = sTemp;
		reverse(reverse_string.begin(), reverse_string.end());
		vecReverseString.push_back(reverse_string);
	}

	for (int i = 0; i < vecString.size(); i++)
	{
		for (int j = 0; j < vecReverseString.size(); j++)
		{
			if (vecString[i] == vecReverseString[j])
			{
				Answer_Lenth = vecString[i].size();
				Answer_char = vecString[i][Answer_Lenth/2];
			}
		}
	}

	cout << Answer_Lenth << " " << Answer_char << '\n';

	return 0;
}