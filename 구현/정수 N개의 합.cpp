#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long sum(vector<int>& a)
{
	long long Value = 0;

	for (int i = 0; i < a.size(); i++)
	{
		Value += a[i];
	}

	return Value;
}

int main()
{
	

	return 0;
}