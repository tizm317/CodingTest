//#include <iostream>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 05. 19. 금
//// 문제 번호	: #2941 
//// 문제 이름	: 크로아티아 알파벳
//// 알고리즘	: 문자열
//// 시간복잡도: O()
//
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 알파벳 + '-' + '='
//	string str;
//	cin >> str;
//
//
//	// string 의 어떤 메서드 사용?
//	// ljes=njak -> lj , e , s= , nj , a , k
//	string Croatia[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
//
//	// replace 활용 (erase 활용시, ddz=z= 인 경우, dz= 가 지워지면서 d, z= 가 dz= 로 합쳐지면서 갯수변화가 생김)
//	// 크로아티아 알파벳을 1글자로 바꾼 뒤
//	for (int i = 0; i < 8; i++)
//	{
//		string cAlphabet = Croatia[i];
//
//		int pos = str.find(cAlphabet);
//		while (pos != -1)
//		{
//			str.replace(pos, cAlphabet.size(), "X"); // 1글자로 바꿈
//
//			pos = str.find(cAlphabet);
//		}
//	}
//
//	// 글자 갯수 출력
//	cout << str.size();
//
//	return 0;
//}