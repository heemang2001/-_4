#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>

using namespace std;

int N; // 홀수

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

	// 산술평균 : N개의 수들의 합을 N으로 나눈 값
	for (int i = 0; i < N; i++)
	{
		sum += vecNum[i];
	}

	sum /= (double)N;
	sum = round(sum);
	int nSum = sum;

	vecAnswer.push_back(nSum);

	// 중앙값: N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
	int midIndex = N / 2;
	vecAnswer.push_back(vecNum[midIndex]);

	// 최빈값 : N개의 수들 중 가장 많이 나타나는 값
	int nManyValue = vecMap.front().first;
	int nManyValue_value = vecMap.front().second;

	if (vecMap.size() >= 2 && nManyValue_value == vecMap[1].second)
	{
		nManyValue = vecMap[1].first;
	}

	vecAnswer.push_back(nManyValue);

	// 범위: N개의 수들 중 최댓값과 최솟값의 차이
	int nValue = abs(vecNum.back() - vecNum.front());
	vecAnswer.push_back(nValue);

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << '\n';
	}

	return 0;
}