#include <iostream>
#include <stack>
using namespace std;

// ���� ���� Ǯ��
// ��¥		: 2023. 06. 28. ��.
// ���� ��ȣ	: #9012 
// ���� �̸�	: ��ȣ
// �˰���	: ������ ��ȣ��
// �ð����⵵: O()

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	while (N--)
	{
		string s;
		cin >> s;

		// (, ) ��ȣ�� �Ѱ��� ���̶� , �� �� �����ϰ� Ǯ��

		stack<char> psStack;
		bool vps = true;

		for (auto c : s)
		{
			// ���� ��ȣ ���ÿ� �߰�
			if (c == '(')
			{
				psStack.push(c);
			}
			// �ݴ� ��ȣ
			else // if ')'
			{
				// ������ ����ִ� ���, �ùٸ��� ���� ��ȣ��
				if (psStack.empty())
				{
					vps = false;
					break;
				}
				// pop
				else
				{
					psStack.pop();
				}
			}
		}

		// ��� ������ ���� ��, ���ÿ� ��ȣ�� ����������, �ùٸ��� ���� ��ȣ��
		if (!psStack.empty())
			vps = false;

		// ��� ���
		if (vps)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}


	}

	return 0;
}