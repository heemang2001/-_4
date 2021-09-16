#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

long long Answer;

unordered_map<string, pair<string, long long>> hashColor;

void MakeColor()
{
	hashColor.insert({ "black",		{"0",1} });
	hashColor.insert({ "brown",		{"1",10} });
	hashColor.insert({ "red",		{"2",100} });
	hashColor.insert({ "orange",	{"3",1000} });
	hashColor.insert({ "yellow",	{"4",10000} });
	hashColor.insert({ "green",		{"5",100000} });
	hashColor.insert({ "blue",		{"6",1000000} });
	hashColor.insert({ "violet",	{"7",10000000} });
	hashColor.insert({ "grey",		{"8",100000000} });
	hashColor.insert({ "white",		{"9",1000000000} });
}

int main()
{
	MakeColor();

	string sTemp1;
	string sTemp2;
	string sTemp3;

	cin >> sTemp1 >> sTemp2 >> sTemp3;

	pair<string, long long> One = hashColor[sTemp1];
	pair<string, long long> Two = hashColor[sTemp2];
	pair<string, long long> Three = hashColor[sTemp3];

	string sSumOneTwo = One.first + Two.first;
	long long nSumOneTwo = stoi(sSumOneTwo);

	Answer = nSumOneTwo * Three.second;

	cout << Answer << '\n';

	return 0;
}