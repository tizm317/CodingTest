#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

// 백준 문제 풀이
// 날짜		: 2023. 06. 05. 월
// 문제 번호	: #16987 
// 문제 이름	: 계란으로 계란치기
// 알고리즘	: 백 트래킹
// 시간복잡도: O()

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
		// brokenEggCnt 카운팅하고 다시 세는 것 무엇?

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

	// 들고 있는 계란이 깨진 경우 + 나머지 계란이 다 깨진 경우(N-1)
	if (v[cur].HP <= 0 || brokenEggCnt == N - 1)
	{
		func(cur + 1);
		return;
	}

	for (int target = 0; target < N; target++)
	{
		if (target == cur || v[target].HP <= 0) // 타겟 계란 HP 체크 놓침(이것 때문에 틀렸네)
			continue;

		// 타겟 계란 깨거나,
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
		
		// 안 깨거나
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