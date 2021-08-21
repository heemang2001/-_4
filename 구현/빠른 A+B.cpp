#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	vector<int> vecAnswer;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int A;
		int B;

		cin >> A >> B;

		vecAnswer.push_back(A + B);
	}

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << '\n';
	}

	return 0;
}