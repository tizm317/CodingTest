//#include <iostream>
//#include <string>
//#include <vector>
//#include <cctype> // toupper
//#include <locale> // isupper
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 05. 19. 금
//// 문제 번호	: #3613 
//// 문제 이름	: Java vs C++
//// 알고리즘	: 문자열
//// 시간복잡도: O()
//
//vector<string> chunks;
//string ans;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 변수명 입력
//	string str;
//	cin >> str;
//
//	// java style -> C++
//	// 첫 단어 : 소문자 / 나머지 : 첫글자만 대문자
//	// longAndMnemonicIdentifier
//	
//	// C++ style -> java
//	// 모든 단어 : 소문자 / '_' : 단어 구분
//	// long_and_mnemonic_identifier
//
//	// 그 외 <- 이걸 찾는것이 관건!!!
//	// Error 출력
//
//	/*
//	*	1. 첫 단어 : 소문자 , 나머지 : 첫글자만 대문자 -> java
//		javaIdentifier -> java/Identifier
//		aBCDEF -> a/B/C/D/E/F
//		
//		2. 모든 단어 : 소문자, '_' 로 단어 구분 -> C++
//		c_identifier
//		b_a_e_k_j_o_o_n
//
//		3. 첫 글자 : 대문자 -> java , c++ 둘 다 X
//		Abcdef
//		ABCDEF
//		B_a_e_k_j_o_o_n
//
//		==============> '_' 가 단어를 구분해야 한다는 c++ 위반
//		4. _ 로 시작
//		_java_aaa
//
//		5. __ 연속
//		__java
//		c__identifier
//
//		6. _ 로 마무리
//		java_
//
//	*/
//
//
//	// 모든 문자 소문자 여부 체크
//	bool isAllLowerCh = true;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (isupper(str[i]))
//		{
//			isAllLowerCh = false;
//			break;
//		}
//	}
//
//	// _ 로 시작, _ 로 끝 나는 예외 처리
//	if (str[0] == '_' || str[str.size() - 1] == '_')
//	{
//		cout << "Error!";
//		return 0;
//	}
//
//	int pos = str.find("_");
//	// 첫 단어 소문자 + (다음 단어부터는 첫 문자 대문자) + _ 없음 => java
//	if (islower(str[0]) && pos == -1)
//	{
//		//cout << "java style" << '\n';
//
//		// 1. java -> C++
//		// 대문자 위치 찾고, 그 앞에 _ 삽입
//		int st = 0;
//		for (int i = 0; i < str.size(); i++)
//		{
//			if (isupper(str[i]))
//			{
//				ans += str.substr(st, i - st);
//				ans += "_";
//				str[i] = tolower(str[i]);
//				st = i;
//			}
//		}
//		// 마지막글자
//		ans += str.substr(st, str.size());
//		
//	}
//	// 모든 문자 소문자 + (_ 있을 수 있음) => C++
//	else if (isAllLowerCh)
//	{
//		//cout << "C++ style" << '\n';
//
//		// 1. C++ -> java
//		int st = 0;
//		while (pos != -1)
//		{
//			// _abc -> abc
//			string sub = str.substr(st, pos - st);
//			if(sub != "")
//				chunks.push_back(sub);
//			st = pos + 1;
//
//			int before = pos;
//			pos = str.find("_", st);
//			
//			// __ 연속
//			if (before + 1 == pos)
//			{
//				cout << "Error!";
//				return 0;
//			}
//		}
//
//		// 마지막 글자
//		chunks.push_back(str.substr(st, str.size()));
//
//		ans += chunks[0];
//		for (int i = 1; i < chunks.size(); i++)
//		{
//			chunks[i][0] = toupper(chunks[i][0]); // 대문자로
//			ans += chunks[i];
//		}
//		
//	}
//	// 그 외 => 오류
//	else
//	{
//		cout << "Error!";
//		return 0;
//	}
//
//	if (ans != "")
//		cout << ans;
//	else
//		cout << "Error!";
//
//	return 0;
//}
//
///*
////맨 뒤 문자가 '_' 이면 에러 -> c++ 위반
//asd_
//Error!
//
////맨 앞 문자가 '_' 이면 에러 -> C++ 위반
//_asd
//Error!
//
////'_' 연속 두개면 에러 -> C++ 위반
//as__asd
//Error!
//
////맨 앞 문자가 대문자면 에러 -> C++ , java 위반
//Aasd
//Error!
//
////대문자와 '_'가 혼종이면 에러 -> C++, java 위반
//asdAasd_asd
//Error!
//
////소문자만 입력 될 경우 정상 -> 단어 1개 취급 (c++, java 모두)
//fadfadfadsf
//fadfadfadsf
//
//// 대문자 연속일 경우 정상 -> java에서 각 대문자 하나씩 단어 1개 취급
//asdasdASDASD
//asdasd_a_s_d_a_s_d
//*/