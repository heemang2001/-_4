#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	int arrCount[10] = {0,};

	int A, B, C;

	cin >> A >> B >> C;

	int Num = A * B * C;
	string sNum = to_string(Num);

	for (int i = 0; i < sNum.size(); i++)
	{
		arrCount[sNum[i] - '0']++;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arrCount[i] << '\n';
	}

	//unordered_map<char, int> hashNum;

	//for (int i = 0; i <= 9; i++)
	//{
	//	char cTemp = i + '0';
	//	hashNum.insert({ cTemp , 0 });
	//}

	//for (int i = 0; i < sNum.size(); i++)
	//{
	//	hashNum[sNum[i]]++;
	//}

	//for (auto iter : hashNum)
	//{
	//	cout << iter.second << '\n';
	//}

	return 0;
}