#include <iostream>
#include <list>
#include <iterator>
using namespace std;

// ���� ���� Ǯ��
// ��¥		: 2023. 04. 24. ��
// ���� ��ȣ	: #1158
// ���� �̸�	: �似Ǫ�� ����
// �˰���	: ���� ����Ʈ
// �ð����⵵: O()

int N, K;
list<int> intList;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 1. STL list Ǯ��
	cin >> N >> K;					// 7 3

	// <1, 2, 3, 4, 5, 6, 7>
	for (int i = 1; i <= N; i++)
	{
		intList.push_back(i);
	}

	// ��� ���� <A, B, C, ...>
	cout << '<';

	// iterator �ʱ�ȭ
	list<int>::iterator it = intList.begin();

	// list �� ������ �ݺ�
	while (!intList.empty())
	{
		// k��° ���� = ���� ���ҿ��� k-1�� �̵��� ����
		for (int i = 1; i < K; i++)
		{
			it++;

			// ���� ����Ʈ
			if (it == intList.end())
				it = intList.begin();
		}

		// k��° ���� ��� �� ����
		cout << *it;					// <3, 6, 2, 7, 5, 1, 4>

		// ������ ���� ���� ��ġ ��ȯ
		it = intList.erase(it);
		
		// ������ ���� ���� ��ġ�� end �� begin���� �ٲ��� (���� ����Ʈ)
		if (it == intList.end())
		{
			it = intList.begin();
		}


		// list ��������� Ż��
		if (intList.empty())
			break;
		
		// ��� ����
		cout << ", ";
	}

	// ��� ����
	cout << '>';

	return 0;
}