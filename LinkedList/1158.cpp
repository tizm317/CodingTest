#include <iostream>
#include <list>
#include <iterator>
using namespace std;

// 백준 문제 풀이
// 날짜		: 2023. 04. 24. 월
// 문제 번호	: #1158
// 문제 이름	: 요세푸스 문제
// 알고리즘	: 연결 리스트
// 시간복잡도: O()

int N, K;
list<int> intList;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 1. STL list 풀이
	cin >> N >> K;					// 7 3

	// <1, 2, 3, 4, 5, 6, 7>
	for (int i = 1; i <= N; i++)
	{
		intList.push_back(i);
	}

	// 출력 형식 <A, B, C, ...>
	cout << '<';

	// iterator 초기화
	list<int>::iterator it = intList.begin();

	// list 빌 때까지 반복
	while (!intList.empty())
	{
		// k번째 원소 = 현재 원소에서 k-1번 이동한 원소
		for (int i = 1; i < K; i++)
		{
			it++;

			// 원형 리스트
			if (it == intList.end())
				it = intList.begin();
		}

		// k번째 원소 출력 후 삭제
		cout << *it;					// <3, 6, 2, 7, 5, 1, 4>

		// 지워진 원소 다음 위치 반환
		it = intList.erase(it);
		
		// 지워진 원소 다음 위치가 end 면 begin으로 바꿔줌 (원형 리스트)
		if (it == intList.end())
		{
			it = intList.begin();
		}


		// list 비어있으면 탈출
		if (intList.empty())
			break;
		
		// 출력 형식
		cout << ", ";
	}

	// 출력 형식
	cout << '>';

	return 0;
}