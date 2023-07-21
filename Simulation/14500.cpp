//#include <iostream>
//#include <vector>
//#include <utility>
//#include <tuple>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 07. 21. ��
//// ���� ��ȣ	: #14500 
//// ���� �̸�	: ��Ʈ�ι̳�
//// �˰���	: 
//// �ð����⵵: O()
//
//// ���� ũ��
//int R, C; // 4 <= <= 500
//int paper[505][505];
//
//// ��Ʈ�ι̳� 7�� ��ǥ �̸� ��Ƶ� �迭
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
//	// ���� ���� �Է�
//	cin >> R >> C;
//	for (int r = 0; r < R; r++)
//	{
//		for (int c = 0; c < C; c++)
//		{
//			cin >> paper[r][c];
//		}
//	}
//
//	// ��� ��Ʈ�ι̳� ������ ���ؼ�
//	//for (vector<pair<int, int>> tetromino : tetrominoVec)
//	for(int idx = 0; idx < tetrominoVec.size(); idx++)
//	{
//		vector<pair<int, int>> tetromino = tetrominoVec[idx];
//
//		// ������ ã��
//		for (int r = 0; r < R; r++)
//		{
//			for (int c = 0; c < C; c++)
//			{
//				// ȸ��
//				for (int rot = 0; rot < 4; rot++)
//				{
//					int score = 0;
//					// ��Ʈ�ι̳��� �� ��ǥ���� Ȯ��
//					for (auto& p : tetromino)
//					{
//						// I �� ��� [r][c] -> [c][r]
//						if (idx == 0)
//						{
//							swap(p.first, p.second);
//						}
//						else if (idx == 6) // O �� ���
//						{
//							// O �� ȸ�� ���ص� ��
//						}
//						// L, J, S, Z, T �� ���
//						// 90�� ȸ��
//						else
//						{
//							int tmp = p.first;
//							p.first = p.second;
//							//p.second = 3 - 1 - tmp;
//							p.second = -tmp;
//						}
//
//						// ���� ��ġ�κ��� ��Ʈ�ι̳� ��ǥ��ŭ �̵��� ��ǥ
//						const int nr = r + p.first;
//						const int nc = c + p.second;
//
//						// paper �迭 ���� ����� x
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
//	// �ְ� ���� ���
//	cout << maxScore;
//
//	return 0;
//}