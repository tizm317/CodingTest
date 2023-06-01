//#include <iostream>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 05. 19. 금
//// 문제 번호	: #2999 
//// 문제 이름	: 비밀 이메일
//// 알고리즘	: 
//// 시간복잡도: O()
//
//int R, C, N;
//char matrix[100][100];
//
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	string str;
//	cin >> str;
//
//	// 1. R <= C 이고 R*C == N 찾기 + R 가장 큰 경우
//	N = str.size();
//	for (R = N; R >= 1; R--)
//	{
//		C = N / R;
//		if (R * C == N && R <= C)
//			break;
//	}
//
//	//for (R = N; R >= 1; R--)
//	//{
//	//	if (N % R != 0)
//	//		continue;
//
//	//	C = N / R;
//
//	//	if (R <= C)
//	//		break;
//	//}
//
//	//for (int i = 1; i < N; i++)
//	//{
//	//	if (N % i != 0)
//	//		continue;
//
//	//	if (N / i < i)
//	//		continue;
//	//	
//	//	R = i;
//	//	C = N / R;
//	//}
//
//	//cout << R << " " << C;
//
//	// 행렬에 column 우선순위로 저장
//	int cnt = 0;
//	for (int c = 0; c < C; c++)
//	{
//		for (int r = 0; r < R; r++)
//		{
//			matrix[r][c] = str[cnt++];
//		}
//	}
//
//	// 행렬 row 우선순위로 출력
//	for (int r = 0; r < R; r++)
//	{
//		for (int c = 0; c < C; c++)
//		{
//			cout << matrix[r][c];
//		}
//	}
//
//	return 0;
//}