#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int X, Y;
int Answer;

int Rev(int num)
{
	int nValue = 0;
	string sNum = to_string(num);
	
	reverse(sNum.begin(), sNum.end());

	nValue = stoi(sNum);

	return nValue;
}

int main()
{
	cin >> X >> Y;

	Answer = Rev(Rev(X) + Rev(Y));

	cout << Answer << '\n';

	return 0;
}