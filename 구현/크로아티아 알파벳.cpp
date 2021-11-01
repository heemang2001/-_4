#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool isCroatia(string str1)
{
	if (str1 == "c=" || str1 == "c-" || str1 == "dz=" || str1 == "d-" || str1 == "lj" || str1 == "nj" || str1 == "s=" || str1 == "z=")
	{
		return true;
	}

	return false;
}

int main()
{
	string str = "";
	int Answer = 0;

	cin >> str;	

	for (int i = 0; i < str.size(); i++)
	{
		string sTemp1 = "";		
		string sTemp2 = "";

		if (i + 1 < str.size())
		{
			sTemp1 += str[i];
			sTemp1 += str[i + 1];

			if (isCroatia(sTemp1))
			{
				Answer++;
				i++;
				continue;
			}
		}
		
		if (i + 2 < str.size())
		{
			sTemp2 += str[i];
			sTemp2 += str[i + 1];
			sTemp2 += str[i + 2];

			if (isCroatia(sTemp2))
			{
				Answer++;
				i += 2;
				continue;
			}
		}
		
		Answer++;
	}

	cout << Answer << '\n';

	return 0;
}