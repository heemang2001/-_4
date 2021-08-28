#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
int answer;

int main()
{
	cin >> N;	

	int curBird = 1;

	while (1)
	{
		if (N - curBird < 0)
		{
			curBird = 1;			
		}

		N -= curBird;

		curBird++;
		answer++;

		if (N == 0)
		{
			break;
		}
	}

	cout << answer << '\n';

	return 0;
}