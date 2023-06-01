#include <iostream>
#include <stack>
#include <queue>
#include <utility> // pair
using namespace std;

// 백준 문제 풀이
// 날짜		: 2023. 05. 09. 화
// 문제 번호	: #2493 
// 문제 이름	: 탑
// 알고리즘	: 
// 시간복잡도: O()

#define HEIGHT first
#define IDX second

int N;
stack<pair<int, int>> S;
//queue<int> temp;
int building[500005];

pair<int, int> isUsed[500005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 탑 개수 입력
	cin >> N;

	// N개
	// 최대
	// 0번, 1번, 2번, ... N-1번
	// N * (N-1)/2
	// O(N^2) -> X

	// pair<int, int> 로 이전 위치 저장하면 될거 같은데...

	// 현재 빌딩 보다 큰 빌딩의 인덱스를 같이 저장
	// 비교했는데, 전 빌딩이 현재 빌딩보다 크다면 -> 막힘
	// 작다면 -> 전 빌딩보다 큰 빌딩이 있어야 막힘
	//  6 9  5 7 4
	// -1 -1 1 1 2

	for (int i = 0; i < N; i++)
	{
		cin >> building[i];
	}

	// 시작점
	isUsed[0] = { building[0], -1 };
	cout << isUsed[0].IDX + 1 << " ";

	//S.push({ building[0], -1 });
	//cout << S.top().second + 1 << " ";

	// index랑 순서 헷갈리게 되었음;; <<<<<<<<<<<<<<<<<<<<<<< 수정 필요!

	for (int i = 1; i < N; i++)
	{
		//pair<int, int> prev = S.top();
		pair<int, int> prev = isUsed[i - 1];
		int curIdx = i - 1;

		while (true)
		{
			// 직전 빌딩(i - 1)이 현재 빌딩(i)보다 큰 경우
			if (prev.HEIGHT > building[i])
			{
				isUsed[i] = { building[i], curIdx};
				cout << curIdx + 1<< " ";
				break;

				//S.push({ building[i], i - 1 }); // 인덱스	
				//cout << i << " ";				// 순서(인덱스 + 1)
			}

			// 전 빌딩보다 큰 빌딩이 없는 경우
			if (prev.IDX == -1)
			{
				isUsed[i] = { building[i], -1 };
				cout << 0 << " ";
				break;
			}

			// 작은 경우, 전 빌딩보다 큰 빌딩 IDX
			curIdx = prev.IDX;
			prev = isUsed[curIdx];
		}
		
	}

	return 0;
}