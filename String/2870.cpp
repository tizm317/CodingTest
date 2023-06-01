//#include <iostream>
//#include <string>
//#include <cctype>	// isdigit
//#include <algorithm>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 05. 19. 금
//// 문제 번호	: #2870 
//// 문제 이름	: 수학숙제
//// 알고리즘	: 문자열
//// 시간복잡도: O()
//
//int N, M; // M : 찾은 숫자 개수
//int numArr[5005]; // 100줄 * (1줄당 최대 50) = 5000
//
//string strArr[5005];
//
//bool compare(string A, string B)
//{
//	// string 비교는 사전순 비교
//	if (A.size() == B.size())
//	{
//		return A < B;
//	}
//	else
//	{
//		return A.size() < B.size();
//	}
//
//
//	// 비내림차순 정렬(1 3 4 10 10 99)
//	// 1. 길이가 다를 경우, 짧은 문자열이 앞에 위치
//	// 2. 길이가 같을 경우, 같은 자리별로 비교 후, 작은 수 앞으로
//	// 2.1 길이 같고, 수 자체가 같은 경우 false 리턴 -> strict weak ordering
//
//	// 같은 길이,
//	//if (A.size() == B.size())
//	//{
//	//	// 높은 자리부터, 자리별 비교 // (= strcmp)
//	//	for (int i = 0; i < A.size(); i++)
//	//	{
//	//		if (A[i] == B[i])
//	//			continue;
//	//	
//	//		// A가 작을 때 true 리턴 -> 앞에 위치
//	//		return A[i] < B[i];
//	//	}
//
//	//	// A == B -> strict weak ordering
//	//	return false;
//	//}
//
//	//// 짧은 문자열이 앞에 위치
//	//// A가 짧으면 true 리턴 -> A가 앞에 위치
//	//return (A.size() < B.size());
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
//		string s;
//		cin >> s;
//
//		// 반례 : 10^99 입력받으면,,
//		// 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
//
//		// 1. 숫자 시작점 찾기
//		for (int numSt = 0; numSt < s.size(); numSt++)
//		{
//			// 숫자 아니면 pass
//			if (!isdigit(s[numSt]))
//				continue;
//
//			// (0~9) 숫자 빼는게 아니고 99 같은 수 추출 해야함.
//			// 2. 숫자 끝점 찾기
//			int numLast = numSt + 1; 
//			while (numLast < s.size() && isdigit(s[numLast]))
//			{
//				numLast++;
//			}
//			
//			// 3. 수 자릿수 계산
//			int numDigit = numLast - numSt; // num 자릿수 계산
//			//int num = stoi(s.substr(numSt, numDigit));			// out-of-range
//			// 큰 수 문제.. -> 문자열로 해결 <<
//			//numArr[M++] = num;
//
//			// 4. 큰 수 문제 -> 문자열 자체를 넣음
//			string sub = s.substr(numSt, numDigit);
//
//			// 예외처리 : 009 -> 9
//			while (sub.size() > 1 && sub[0] == '0')
//			{
//				sub.erase(0, 1);
//			}
//			
//
//			strArr[M++] = sub;
//
//			// 다음 시작점으로
//			numSt += numDigit;
//		}
//	}
//
//	// string 비교 정렬
//	sort(strArr, strArr + M, compare);
//
//	for (int i = 0; i < M; i++)
//		cout << strArr[i] << '\n';
//
//	return 0;
//}