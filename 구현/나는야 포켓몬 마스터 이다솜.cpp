#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

#define MAX 100001

int N, M;
unordered_map<string, int> hashPokemon;
string Pokemon[MAX];

int main()
{
	ios::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		string sTemp;
		cin >> sTemp;
		hashPokemon.insert({ sTemp, i });
		Pokemon[i] = sTemp;
	}

	for (int i = 0; i < M; i++)
	{
		string sTemp;
		cin >> sTemp;		

		bool bNum = false;

		// 문자
		if (isdigit(sTemp.front()) == 0)
		{
			bNum = false;
		}

		// 숫자
		else
		{
			bNum = true;
		}

		// 문자
		if (!bNum)
		{
			cout << hashPokemon[sTemp] << '\n';
		}

		// 숫자
		else
		{
			int index = stoi(sTemp);

			cout << Pokemon[index] << '\n';
		}
	}

	return 0;
}