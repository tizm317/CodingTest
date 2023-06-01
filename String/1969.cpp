//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 05. 19. 금
//// 문제 번호	: #1969 
//// 문제 이름	: DNA
//// 알고리즘	: 문자열
//// 시간복잡도: O()
//
//int N, M, ans;
//string DNA[1005];
//string s;
//
//char acgt[4] = { 'A', 'C', 'G', 'T' };
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> DNA[i];
//	}
//
//	for (int i = 0; i < M; i++)
//	{
//		// Hamming Distance 합을 줄이기 위해,
//		// 주어진 DNA 의 각 자리에서, (A,C,G,T) 몇번 씩 나왔는 지 저장하고,
//		// 많이 나온 글자 선택
//
//		// (a,c,g,t) 빈도 배열
//		int freq[4] = { 0, }; // 사전순 ACGT
//		
//		// 자리별로 돌면서 저장
//		for (int j = 0; j < N; j++)
//		{
//			char c = DNA[j][i];
//
//			switch (c)
//			{
//			case 'A':
//				freq[0]++;
//				break;
//			case 'C':
//				freq[1]++;
//				break;
//			case 'G':
//				freq[2]++;
//				break;
//			case 'T':
//				freq[3]++;
//				break;
//			}
//		}
//
//		for (int i = 0; i < 4; i++)
//		{
//			// 이미 acgt 순서로 사전순 정렬되어 있어서,
//			// 찾으면 break 하면 됨.
//			if (freq[i] == *max_element(freq, freq + 4))
//			{
//				// DNA s 
//				s += acgt[i];
//
//				// Hamming Distance 더해줌
//				ans += (N - freq[i]); // 전체 개수 - 같은 거 갯수 = 다른 거 갯수
//				break;
//			}
//		}
//
//		//bool alreadyFound = false; // 사전순 우선순위 때문
//		//for (int i = 0; i < 4; i++)
//		//{
//		//	if (alreadyFound == false && freq[i] == *max_element(freq, freq + 4))
//		//	{
//		//		s += acgt[i];
//		//		alreadyFound = true;
//		//	}
//		//	else
//		//	{
//		//		ans += freq[i];
//		//	}
//		//}
//	}
//
//	cout << s << '\n';
//	cout << ans << '\n';
//
//	return 0;
//}