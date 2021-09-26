#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>

using namespace std;

int N; // Ȧ��

bool cmp(pair<int, int>& left, pair<int, int>& right)
{
	if (left.second == right.second)
	{
		return left.first < right.first;
	}

	return left.second > right.second;
}

int main()
{
	cin >> N;

	vector<int> vecNum;
	vector<int> vecAnswer;	
	map<int, int> mapNum;

	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecNum.push_back(nTemp);
		mapNum[nTemp]++;
	}

	vector<pair<int, int>> vecMap(mapNum.begin(), mapNum.end());

	sort(vecMap.begin(), vecMap.end(), cmp);
	sort(vecNum.begin(), vecNum.end());

	double sum = 0;

	// ������ : N���� ������ ���� N���� ���� ��
	for (int i = 0; i < N; i++)
	{
		sum += vecNum[i];
	}

	sum /= (double)N;
	sum = round(sum);
	int nSum = sum;

	vecAnswer.push_back(nSum);

	// �߾Ӱ�: N���� ������ �����ϴ� ������ �������� ��� �� �߾ӿ� ��ġ�ϴ� ��
	int midIndex = N / 2;
	vecAnswer.push_back(vecNum[midIndex]);

	// �ֺ� : N���� ���� �� ���� ���� ��Ÿ���� ��
	int nManyValue = vecMap.front().first;
	int nManyValue_value = vecMap.front().second;

	if (vecMap.size() >= 2 && nManyValue_value == vecMap[1].second)
	{
		nManyValue = vecMap[1].first;
	}

	vecAnswer.push_back(nManyValue);

	// ����: N���� ���� �� �ִ񰪰� �ּڰ��� ����
	int nValue = abs(vecNum.back() - vecNum.front());
	vecAnswer.push_back(nValue);

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << '\n';
	}

	return 0;
}