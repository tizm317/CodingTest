//#include <iostream>
//#include <vector>
//#include <utility>
//#include <tuple>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 07. 21. 금
//// 문제 번호	: #14500 
//// 문제 이름	: 테트로미노
//// 알고리즘	: 
//// 시간복잡도: O()
//
//// 종이 크기
//int R, C; // 4 <= <= 500
//int paper[505][505];
//
//// 테트로미노 7개 좌표 미리 담아둔 배열
//vector<vector<pair<int, int>>> tetrominoVec = 
//{ 
//	{{0,0}, {0,1}, {0,2}, {0,3}},		// I 0, 90
//	{{0,0}, {0,-1}, {0, 1}, {-1, 1}},	// L 0,90,180,270 <-> J
//	{{0,0}, {0,-1}, {0, 1}, {1, 1}},	// J
//	{{0,0}, {0,-1}, {-1,0}, {-1, 1}},	// S <-> Z
//	{{0,0}, {0,-1}, {1,0}, {1, 1}},		// Z
//	{{0,0}, {0,-1}, {0,1}, {1,0}},		// T
//	{{0,0}, {0,1}, {1,0}, {1,1}}		// O 0
//};
//
//int maxScore;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 종이 점수 입력
//	cin >> R >> C;
//	for (int r = 0; r < R; r++)
//	{
//		for (int c = 0; c < C; c++)
//		{
//			cin >> paper[r][c];
//		}
//	}
//
//	// 모든 테트로미노 종류에 대해서
//	//for (vector<pair<int, int>> tetromino : tetrominoVec)
//	for(int idx = 0; idx < tetrominoVec.size(); idx++)
//	{
//		vector<pair<int, int>> tetromino = tetrominoVec[idx];
//
//		// 시작점 찾기
//		for (int r = 0; r < R; r++)
//		{
//			for (int c = 0; c < C; c++)
//			{
//				// 회전
//				for (int rot = 0; rot < 4; rot++)
//				{
//					int score = 0;
//					// 테트로미노의 각 좌표별로 확인
//					for (auto& p : tetromino)
//					{
//						// I 의 경우 [r][c] -> [c][r]
//						if (idx == 0)
//						{
//							swap(p.first, p.second);
//						}
//						else if (idx == 6) // O 의 경우
//						{
//							// O 는 회전 안해도 됨
//						}
//						// L, J, S, Z, T 의 경우
//						// 90도 회전
//						else
//						{
//							int tmp = p.first;
//							p.first = p.second;
//							//p.second = 3 - 1 - tmp;
//							p.second = -tmp;
//						}
//
//						// 시작 위치로부터 테트로미노 좌표만큼 이동한 좌표
//						const int nr = r + p.first;
//						const int nc = c + p.second;
//
//						// paper 배열 범위 벗어나면 x
//						if (nr < 0 || nr >= R || nc < 0 || nc >= C)
//							continue;
//
//						score += paper[nr][nc];
//					}
//					maxScore = max(maxScore, score);
//				}
//			}
//		}
//	}
//
//	// 최고 점수 출력
//	cout << maxScore;
//
//	return 0;
//}