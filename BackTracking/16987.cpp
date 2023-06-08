#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

// ���� ���� Ǯ��
// ��¥		: 2023. 06. 05. ��
// ���� ��ȣ	: #16987 
// ���� �̸�	: ������� ���ġ��
// �˰���	: �� Ʈ��ŷ
// �ð����⵵: O()

#define HP first
#define ATTACK second

int N;
vector<pair<int, int>> v;
int ans = 0;
int brokenEggCnt = 0;

void func(int cur)
{
	if (cur >= v.size()) // cur == N
	{
		// brokenEggCnt ī�����ϰ� �ٽ� ���� �� ����?

		/*int cnt = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].HP <= 0)
				cnt++;
		}
		ans = max(ans, cnt);*/

		ans = max(ans, brokenEggCnt);

		return;
	}

	// ��� �ִ� ����� ���� ��� + ������ ����� �� ���� ���(N-1)
	if (v[cur].HP <= 0 || brokenEggCnt == N - 1)
	{
		func(cur + 1);
		return;
	}

	for (int target = 0; target < N; target++)
	{
		if (target == cur || v[target].HP <= 0) // Ÿ�� ��� HP üũ ��ħ(�̰� ������ Ʋ�ȳ�)
			continue;

		// Ÿ�� ��� ���ų�,
		v[cur].HP -= v[target].ATTACK;
		v[target].HP -= v[cur].ATTACK;
		
		if (v[cur].HP <= 0)
			brokenEggCnt++;
		if (v[target].HP <= 0)
			brokenEggCnt++;

		func(cur + 1);

		if (v[cur].HP <= 0)
			brokenEggCnt--;
		if (v[target].HP <= 0)
			brokenEggCnt--;
		
		// �� ���ų�
		v[cur].HP += v[target].ATTACK;
		v[target].HP += v[cur].ATTACK;
	}

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}

	func(0);

	cout << ans;

	return 0;
}