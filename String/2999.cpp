//#include <iostream>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 19. ��
//// ���� ��ȣ	: #2999 
//// ���� �̸�	: ��� �̸���
//// �˰���	: 
//// �ð����⵵: O()
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
//	// 1. R <= C �̰� R*C == N ã�� + R ���� ū ���
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
//	// ��Ŀ� column �켱������ ����
//	int cnt = 0;
//	for (int c = 0; c < C; c++)
//	{
//		for (int r = 0; r < R; r++)
//		{
//			matrix[r][c] = str[cnt++];
//		}
//	}
//
//	// ��� row �켱������ ���
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