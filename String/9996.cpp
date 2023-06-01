//#include <iostream>
//#include <string>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 05. 19. 금
//// 문제 번호	: #9996 
//// 문제 이름	: 한국이 그리울 땐 서버를 접속하지
//// 알고리즘	: 문자열
//// 시간복잡도: O()
//
//int N;				// 1 ~ 100
//string pattern;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 파일 갯수
//	cin >> N;
//
//	// 패턴 입력
//	cin >> pattern; 
//	
//	// 패턴을 * 기준으로 앞, 뒤 2개의 부분문자열로 분리
//	// ex : 패턴 abc*def 인 경우
//	int starIdx = pattern.find("*");
//	string first = pattern.substr(0, starIdx); // abc
//	string second = pattern.substr(starIdx + 1, pattern.size()); // def
//
//
//
//	for (int i = 0; i < N; i++)
//	{
//		// abceeedef
//		// 파일 이름 입력
//		string fileName;
//		cin >> fileName;
//
//		
//		// 반례
//		// ab*ab
//		// ab 
//		// ab*ab 는 abab 같은 건데, ab도 맞는 문제가 발생
//		// -> 해결 : 최소 길이 체크
//
//		// 예외1) 파일이름 길이 < * 제외 패턴 길이 -> 불가능
//		if (fileName.size() < pattern.size() - 1)
//		{
//			cout << "NE" << '\n';
//			continue;
//		}
//
//		// 예외2) first 가 맨 앞이 아닌 경우 + 없는 경우 : 실패
//		if (fileName.find(first) != 0)
//		{
//			cout << "NE" << '\n';
//			continue;
//		}
//
//		// first*second 부분 중 first 까지는 통과
//
//		// * + second 부분 체크
//		// * 부분은 건너뛰고,
//		// 마지막인 second 부분만 제자리에 있으면 통과
//		bool success = false;
//		int secondPos = fileName.find(second);
//		while (secondPos != -1)
//		{
//			// second의 첫 문자 위치는(secondPos) 파일이름 크기 - second 단어 크기 에 위치해야함.
//			if (secondPos == fileName.size() - second.size())
//				success = true;
//
//			// 다음 위치
//			secondPos = fileName.find(second, secondPos + second.size());
//		}
//
//		// 마지막인 second 부분만 제자리에 있으면 통과
//		if (success)
//			cout << "DA" << '\n';
//		else
//			cout << "NE" << '\n';
//	}
//
//	return 0;
//}