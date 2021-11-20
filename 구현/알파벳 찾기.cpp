#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
	string StrInput;
	int Alphabet[26];
	memset(Alphabet, -1, sizeof(Alphabet));

	cin >> StrInput;

	for (int i = 0; i < StrInput.size(); i++)
	{
		int index = StrInput[i] - 'a';

		if (Alphabet[index] == -1)
		{
			Alphabet[index] = i;
		}		
	}

	for (auto answer : Alphabet)
	{
		cout << answer << " ";
	}

	return 0;
}