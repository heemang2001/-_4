#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int Answer;

int main()
{
	string sInput;

	cin >> sInput;

	Answer = sInput.size();

	cout << Answer << '\n';

	return 0;
}