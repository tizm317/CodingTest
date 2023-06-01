//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 05. 19. 금.
//// 문제 번호	: #9536 
//// 문제 이름	: 여우는 어떻게 울지?
//// 알고리즘	: 문자열
//// 시간복잡도: O()
//
//int T;
//vector<string> soundVec;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> T;
//	
//	cin.ignore(); // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//
//	for (int i = 0; i < T; i++)
//	{
//		// 1. 섞인 울음 소리
//		string sound;
//		getline(cin, sound);
//		
//		// split 기능
//		{
//			// " " 로 구분해서, 각 울음소리 string 을 벡터에 넣음
//			int st = 0;
//			int pos = sound.find(" ");
//			while (pos != -1)
//			{
//				soundVec.push_back(sound.substr(st, pos - st));
//
//				st = pos + 1;
//				pos = sound.find(" ", st);
//			}
//
//			// 마지막 글자 벡터에 넣음
//			soundVec.push_back(sound.substr(st, sound.size()));
//		}
//
//		// 2. what does the fox say 입력받을 때까지 반복
//		// 각 동물별 울음 소리
//		string s = "";
//		while (s != "what does the fox say?")
//		{
//			getline(cin, s);
//
//			// "<동물> goes <소리>" 형태 이므로, 두번째 " " 위치를 찾으면 된다 (2번 find)
//			int pos = s.find(" ");
//			pos = s.find(" ", pos + 1);
//
//			// 울음소리 추출
//			string animalSound = s.substr(pos + 1, s.size());
//
//			// 섞인 울음 소리 벡터 순회하면서, 같은 거 지움
//			for (auto it = soundVec.begin(); it != soundVec.end(); )
//			{
//				if (*it == animalSound)
//				{
//					// 지우고, 다음 위치로,
//					it = soundVec.erase(it);
//				}
//				else
//				{
//					it++;
//				}
//			}
//		}
//
//		// 남은 소리가 여우 울음 소리이므로, 벡터 순회하면서 출력
//		for (auto it = soundVec.begin(); it != soundVec.end(); it++)
//		{
//			cout << *it << " ";
//		}
//		cout << '\n';
//
//		// 테케 여러개, 클리어
//		soundVec.clear();
//	}
//
//
//	return 0;
//}