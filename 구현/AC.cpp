#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int T;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		string sOrder;
		int cnt_Num;
		string sNums;
		deque<int> dqNum;
		bool bError = false;
		bool bReverse = false;

		cin >> sOrder >> cnt_Num >> sNums;
				
		string Number = "";
		for (int i = 0; i < sNums.size(); i++)
		{
			if (sNums[i] == '[')
			{
				continue;
			}

			else if (sNums[i] == ']')
			{
				if (Number != "")
				{
					dqNum.push_back(stoi(Number));
				}
			}

			else if (sNums[i] != ',')
			{
				Number += sNums[i];
			}

			else if(sNums[i] == ',')
			{
				dqNum.push_back(stoi(Number));
				Number = "";
			}
		}
		
		for (int i = 0; i < sOrder.size(); i++)
		{
			// R은 배열에 있는 수의 순서를 뒤집는 함수
			if (sOrder[i] == 'R')
			{
				bReverse = !bReverse;
			}

			// D는 첫 번째 수를 버리는 함수
			else if (sOrder[i] == 'D')
			{
				if (bReverse == false)
				{
					if (dqNum.size() > 0)
					{
						dqNum.pop_front();
					}

					else
					{
						bError = true;
						break;
					}
				}

				else if (bReverse == true)
				{
					if (dqNum.size() > 0)
					{
						dqNum.pop_back();
					}

					else
					{
						bError = true;
						break;
					}
				}
			}
		}
				
		string Answer = "";

		if (bError)
		{
			Answer = "error";
			cout << Answer << '\n';
		}

		else
		{
			if (bReverse == false)
			{
				int cnt = 0;

				while (1)
				{
					if (Answer == "")
					{
						Answer += "[";
						continue;
					}

					if (cnt == dqNum.size())
					{
						Answer += "]";
						break;
					}

					else
					{
						Answer += to_string(dqNum[cnt]);
						cnt++;

						if (cnt < dqNum.size())
						{
							Answer += ",";
						}
					}
				}

				cout << Answer << '\n';
			}

			else
			{
				int cnt = dqNum.size() - 1;

				while (1)
				{
					if (Answer == "")
					{
						Answer += "[";
						continue;
					}

					if (cnt == -1)
					{
						Answer += "]";
						break;
					}

					else
					{
						Answer += to_string(dqNum[cnt]);
						cnt--;

						if (cnt < dqNum.size())
						{
							Answer += ",";
						}
					}
				}

				cout << Answer << '\n';
			}			
		}
	}

	return 0;
}