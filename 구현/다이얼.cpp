#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <unordered_map>

using namespace std;

string sInput;
int Answer;

int main()
{
	cin >> sInput;

	unordered_map<char, int> hashAlphaNum;

	hashAlphaNum.insert({ 'A',2 });
	hashAlphaNum.insert({ 'B',2 });
	hashAlphaNum.insert({ 'C',2 });

	hashAlphaNum.insert({ 'D',3 });
	hashAlphaNum.insert({ 'E',3 });
	hashAlphaNum.insert({ 'F',3 });

	hashAlphaNum.insert({ 'G',4 });
	hashAlphaNum.insert({ 'H',4 });
	hashAlphaNum.insert({ 'I',4 });

	hashAlphaNum.insert({ 'J',5 });
	hashAlphaNum.insert({ 'K',5 });
	hashAlphaNum.insert({ 'L',5 });

	hashAlphaNum.insert({ 'M',6 });
	hashAlphaNum.insert({ 'N',6 });
	hashAlphaNum.insert({ 'O',6 });

	hashAlphaNum.insert({ 'P',7 });
	hashAlphaNum.insert({ 'Q',7 });
	hashAlphaNum.insert({ 'R',7 });
	hashAlphaNum.insert({ 'S',7 });

	hashAlphaNum.insert({ 'T',8 });
	hashAlphaNum.insert({ 'U',8 });
	hashAlphaNum.insert({ 'V',8 });

	hashAlphaNum.insert({ 'W',9 });
	hashAlphaNum.insert({ 'X',9 });
	hashAlphaNum.insert({ 'Y',9 });
	hashAlphaNum.insert({ 'Z',9 });

	for (int i = 0; i < sInput.size(); i++)
	{
		Answer += hashAlphaNum[sInput[i]] + 1;
	}

	cout << Answer << '\n';

	return 0;
}