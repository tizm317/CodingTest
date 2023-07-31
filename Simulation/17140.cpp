//#include <iostream>
//#include <vector>
//#include <algorithm> // sort, swap
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 07. 31. 월
//// 문제 번호	: #17140 
//// 문제 이름	: 이차원 배열과 연산
//// 알고리즘	시뮬레이션
//// 시간복잡도: O()
//
//int r, c;
//int k;
//
//// 배열 크기 3 초기화
//int R = 3, C = 3;
//int arr[105][105];
//
//int freq[105];
//
//bool compare(int x, int y);
//void operationR();
//void operationC();
//
//void transpose();
//
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> r >> c >> k;
//
//	// 3x3 초기 배열 입력
//	for (int i = 0; i < R; i++)
//	{
//		for (int j = 0; j < C; j++)
//		{
//			cin >> arr[i][j];
//		}
//	}
//
//	int tick = 0;
//	while (tick <= 100) // 100초 일 때도 확인해야지!!!!!!!!!!
//	{
//		// 결과 출력
//			// 문제에서 배열 인덱스 1부터 시작한다고 해서 -1 해줌
//		if (arr[r-1][c-1] == k)
//		{
//			cout << tick;
//			return 0;
//		}
//
//		// R, C 크기에 따라 R연산, C연산
//		if (R >= C)
//		{
//			operationR();
//		}
//		else 
//		{
//			//operationC();
//
//			// 전치 행렬
//			transpose();
//			operationR();
//
//			// 행렬 원래대로
//			transpose();
//		}
//
//		// 시간 증가
//		tick++;
//	}
//
//	// 100초 이내 못 찾은 경우 -1 출력
//	cout << -1;
//
//	return 0;
//}
//
//bool compare(int x, int y)
//{
//	// 빈도수가 커지는 순서로 정렬
//		// 빈도수가 같으면, 수의 크기가 커지는 순서로 정렬
//	return (freq[x] != freq[y]) ? (freq[x] < freq[y]) : (x < y);
//
//	/*
//	if (freq[x] < freq[y])
//		return true;
//	else if (freq[x] > freq[y])
//		return false;
//	else
//	{
//		return (x < y);
//	}
//	*/
//}
//
//void operationR()
//{
//	// R 연산
//
//	// R 연산 후 변경된 C 값 담는 변수 선언
//	int nextC = 0;
//
//	for (int r = 0; r < R; r++)
//	{
//		// freq 배열 초기화
//		fill(freq, freq + 105, 0);
//
//		vector<int> numVec;
//		for (int c = 0; c < C; c++)
//		{
//			const int num = arr[r][c];
//			
//			// 0은 무시 <<  '수를 정렬할 때 0은 무시해야 한다.' ***
//			if (num == 0)
//				continue;
//
//			// 벡터에 1번만 들어가도록 하기 위함(중복 제거)
//			if (freq[num] == 0)
//			{
//				numVec.push_back(num);
//			}
//
//			// 빈도수 증가
//			freq[num]++;
//		}
//
//		// 정렬
//		sort(numVec.begin(), numVec.end(), compare);
//
//		// C 크기 변화 (수, 빈도수) 같이 들어오니까 2배
//		// 100 넘어가는 거 버리기 위해 clamp 사용 (c++17)
//		const int tempC = std::clamp(int(numVec.size() * 2), 0, 100); 
//
//		// r별로 tempC 구하고, 가장 큰 값을 nextC에 저장
//		nextC = max(tempC, nextC);
//
//		// (수, 빈도수) 1쌍씩 새로운 범위의 arr에 넣음
//			// 2개씩 집어넣기 때문에 범위 tempC/2 
//		for (int i = 0; i < tempC / 2; i++)
//		{
//			const int idx = 2 * i;
//			const int num = numVec[i];
//
//			arr[r][idx] = num;
//			arr[r][idx + 1] = freq[num];
//		}
//
//		// 뒤쪽 0 으로 초기화! ***
//		fill(&arr[r][tempC], &arr[r][105], 0);
//	}
//
//	// C를 nextC 대입
//		// 바뀐 열 크기 중에서 가장 큰 열 기준으로 바꿈
//	C = nextC;
//}
//
//void operationC()
//{
//	// C 연산
//
//	// C 연산 후 변경된 R 값 담는 변수 선언
//	int nextR = 0;
//	for (int c = 0; c < C; c++)
//	{
//		// freq 배열 초기화
//		fill(freq, freq + 105, 0);
//
//		vector<int> numVec;
//		for (int r = 0; r < R; r++)
//		{
//			const int num = arr[r][c];
//			// 0은 무시
//			if (num == 0)
//				continue;
//
//			if (freq[num] == 0)
//			{
//				numVec.push_back(num);
//			}
//
//			freq[num]++;
//		}
//
//		// 정렬
//		sort(numVec.begin(), numVec.end(), compare);
//
//		// R 크기 변화 (수, 빈도수) 같이 들어오니까 2배
//		const int tempR = std::clamp(int(numVec.size() * 2), 0, 100); // 100 넘어가는 거 버림
//		nextR = max(tempR, nextR);
//
//		for (int i = 0; i < tempR / 2; i++)
//		{
//			const int idx = 2 * i;
//			const int num = numVec[i];
//
//			arr[idx][c] = num;
//			arr[idx + 1][c] = freq[num];
//		}
//
//		// 뒤쪽 0 으로 초기화! ***
//		for (int r = tempR; r < 105; r++)
//			arr[r][c] = 0;
//
//	}
//
//	// 바뀐 열 크기 중에서 가장 큰 열 기준
//	R = nextR;
//}
//
//void transpose()
//{
//	// 배열의 전치
//	const int N = max(R, C);
//	for (int r = 0; r < N; r++)
//	{
//		for (int c = r; c < N; c++)
//		{
//			swap(arr[r][c], arr[c][r]);
//		}
//	}
//
//	swap(R, C);
//}