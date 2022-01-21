#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;

void Solution(int cnt)
{
	string cur_str = "";

	for (int i = 0; i < cnt; i++)
	{
		cur_str += "____";		
	}

	if (cnt == N)
	{		
		cout << cur_str << "\"����Լ��� ������?\"\n";						   
		cout << cur_str << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";							  
		cout << cur_str << "��� �亯�Ͽ���.\n";
	}
	
	else
	{
		cout << cur_str << "\"����Լ��� ������?\"\n";
		cout << cur_str << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
		cout << cur_str << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
		cout << cur_str << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";

		Solution(cnt + 1);		

		cout << cur_str << "��� �亯�Ͽ���.\n";
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";

	Solution(0);

	return 0;
}