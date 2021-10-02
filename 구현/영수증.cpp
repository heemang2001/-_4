#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int Answer;
int MaxPrice;
int SumPrice;

int main()
{	
	cin >> MaxPrice;	

	for (int i = 0; i < 9; i++)
	{
		int nTemp;
		cin >> nTemp;
		SumPrice += nTemp;
	}

	Answer = MaxPrice - SumPrice;

	cout << Answer << '\n';

	return 0;
}