//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 06. 01. 목
//// 문제 번호	: #11652 
//// 문제 이름	: 카드
//// 알고리즘	: 정렬
//// 시간복잡도: O()
//
//int N; // <= 100'000
//// -2^62 ~ 2^62
//
//string arr[100'005];
//int idx[100'005];
//int freq[100'005];
//
//bool cmp(const string& a, const string& b)
//{
//	// 둘 중 하나는 음수, 하나는 양수인 경우
//	if (a[0] == '-' && b[0] != '-')
//		return true;
//	if (a[0] != '-' && b[0] == '-')
//		return false;
//
//	// 둘 다 음수거나, 양수거나..
//	// 1. 자릿수로 비교
//	if (a[0] != '-')
//	{
//		if (a.size() != b.size())
//			return a.size() < b.size();
//	}
//	else
//	{
//		// -999 -1
//		if (a.size() != b.size())
//			return a.size() > b.size();
//	}
//	
//
//	// 2. 각 자릿수마다 비교
//	for (int i = 0; i < a.size(); i++)
//	{
//		if (a[i] != b[i])
//		{
//			// 둘 다 양수인 경우,
//			if(a[0] != '-')
//				return a[i] < b[i];
//			// 둘 다 음수인 경우,
//			else
//				return a[i] > b[i];
//		}
//	}
//
//	// 3. 아예 같은 경우
//	return false;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> arr[i];
//	}
//
//	// 3 2 2 1 3 3 1 3 1
//	sort(arr, arr + N, cmp);
//
//	// 1 1 1 2 2 3 3 3 3
//
//	// 인덱스 담는 배열과, 빈도수 담는 배열 2개 준비
//	//int cnt = 0;
//	//freq[cnt] = 1;
//	//idx[cnt] = 0;
//
//	//// 정렬된 배열을 순회하다가, 이전 값하고 달라지면 인덱스 배열에 새로운 값을 넣고, 아니면 빈도수를 증가시키는 것을 반복
//	//for (int i = 1; i < N; i++)
//	//{
//	//	if (arr[i - 1] != arr[i])
//	//	{
//	//		idx[++cnt] = i;
//	//	}
//
//	//	freq[cnt]++;
//	//}
//
//	//int maxfreqIdx = max_element(freq, freq + cnt + 1) - freq;
//	//cout << arr[idx[maxfreqIdx]];
//
//	//4611686018427387904
//
//	// 다른 풀이
//	// 처음 정렬 O(NlogN) , 이후 처리 O(N) => 결론적으로 O(NlogN)
//	// 
//	// i가 0일 때 초기화
//	int cnt = 1; // 현재 카운트
//	int mxcnt = 1; // 최대 카운트
//	string mxval = arr[0]; // 최대 카운트일 때 값
//
//	// 2 2 2 3 5 5 7 7
//	for (int i = 1; i < N; i++)
//	{
//		if (arr[i] != mxval)
//		{
//			cnt = 1;
//		}
//		else
//		{
//			cnt++;
//			if (cnt > mxcnt)
//			{
//				mxcnt = cnt;
//				mxval = arr[i];
//			}
//			
//		}
//	}
//
//	cout << mxval;
//
//	return 0;
//}