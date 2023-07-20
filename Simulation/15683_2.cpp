//#include <iostream>
//#include <vector>
//#include <utility>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 07. 19. 수
//// 문제 번호	: #15683 
//// 문제 이름	: 감시
//// 알고리즘	: 시뮬레이션
//// 시간복잡도: O()
//
//int ROW, COL; // 1 <= x <= 8
//vector<vector<int>> mapVec;
//vector<vector<int>> sightVec; // 시야 표시 1(볼 수 있는곳+벽,CCTV위치) , 0 사각지대
//vector<pair<int, int>> cctvVec; // CCTV 위치
//
//// 북->동->남->서
//const int dROW[4] = {-1, 0, 1, 0};
//const int dCOL[4] = {0, 1, 0, -1};
//
//int minBlindSpotCnt = 64;
//
//bool isInArrBounds(const int row, const int col)
//{
//	if (row < 0 || row >= ROW || col < 0 || col >= COL)
//		return false;
//	else
//		return true;
//}
//
//void cctv1(const int curRow, const int curCol, const int dir, vector<vector<int>>& vec)
//{
//	//cout << &vec << '\n';
//	//cout << &vec[0][0] << '\n';
//
//	// CCTV 1
//	// dir 방향으로 벽, 배열 끝까지 진행
//	
//	int nRow = curRow;
//	int nCol = curCol;
//
//	while (true)
//	{
//		/*if (dir < 0 || dir >= 4)
//			cout << dir << '\n'; */
//
//		nRow += dROW[dir % 4];
//		nCol += dCOL[dir % 4];
//
//		// 배열 범위 벗어나거나, 벽 만나면 탈출
//		if (isInArrBounds(nRow, nCol) == false || mapVec[nRow][nCol] == 6)
//			break;
//
//		// 시야 표시
//		vec[nRow][nCol] = 1;
//	}
//
//}
//void cctv2(const int curRow, const int curCol, const int dir, vector<vector<int>>& vec)
//{
//	//cout << &vec << '\n';
//	//cout << &vec[0][0] << '\n';
//
//	// CCTV 2
//	// dir 방향, -dir 방향으로 벽, 배열 끝까지 진행
//	//const initializer_list<int> il = (dir % 2 == 0) ? initializer_list<int>{ 0,2 } : initializer_list<int>{ 1,3 };
//
//	//cout << &il;
//	//cout << il.begin() << " " << (il.begin() + 1);
//	//cout << *il.begin() << " " << *(il.begin() + 1);
//
//	// 정방향, 역방향 총 2번
//	//for (int d : il)
//	int d = dir;
//	for(int i = 0; i < 2; i++)
//	{
//		if (i == 1)
//		{
//			d = dir + 2;
//		}
//
//		int nRow = curRow;
//		int nCol = curCol;
//
//		while (true)
//		{
//			/*if (d < 0 || d >= 4)
//				cout << d << '\n';*/
//			nRow += dROW[d];
//			nCol += dCOL[d];
//
//			// 배열 범위 벗어나거나, 벽 만나면 탈출
//			if (isInArrBounds(nRow, nCol) == false || mapVec[nRow][nCol] == 6)
//				break;
//
//			// 시야 표시
//			vec[nRow][nCol] = 1;
//		}
//	}
//
//}
//void cctv3(const int curRow, const int curCol, const int dir, vector<vector<int>>& vec)
//{
//	//cout << &vec << '\n';
//	//cout << &vec[0][0] << '\n';
//
//	// CCTV 3 (2방향)
//	// dir 방향, dir 의 우측 수직인 방향으로 벽, 배열 끝까지 진행
//	// 0 -> 0,1
//	// 1 -> 1,2
//	// 2 -> 2,3
//	// 3 -> 3,4 -> 3,0
//	//const initializer_list<int> il = (dir == 0) ? initializer_list<int>{ 0, 1 } 
//	//: (dir == 1) ? initializer_list<int>{ 1, 2 }
//	//: (dir == 2) ? initializer_list<int>{ 2, 3 }
//	//: initializer_list<int>{ 3, 0 };
//
//	//for (int d : il)
//	for(int d = dir; d <= dir + 1; d++)
//	{
//		int nRow = curRow;
//		int nCol = curCol;
//
//		while (true)
//		{
//			/*if (d < 0 || d >= 4)
//				cout << d << '\n';*/
//			nRow += dROW[d % 4];
//			nCol += dCOL[d % 4];
//
//			// 배열 범위 벗어나거나, 벽 만나면 탈출
//			if (isInArrBounds(nRow, nCol) == false || mapVec[nRow][nCol] == 6)
//				break;
//
//			// 시야 표시
//			vec[nRow][nCol] = 1;
//		}
//	}
//}
//void cctv4(const int curRow, const int curCol, const int dir, vector<vector<int>>& vec)
//{
//	//cout << &vec << '\n';
//	//cout << &vec[0][0] << '\n';
//
//	// CCTV 4 (3방향)
//	// dir 방향, dir 에 수직인 방향 양쪽 2개 로 벽, 배열 끝까지 진행
//	//const initializer_list<int> il = (dir == 0) ? initializer_list<int>{ 3, 0, 1}
//	//: (dir == 1) ? initializer_list<int>{ 0, 1, 2 }
//	//: (dir == 2) ? initializer_list<int>{ 1, 2, 3 }
//	//: initializer_list<int>{ 2, 3, 0 };
//
//	//for (int d : il)
//	for(int d = 0; d < 4; d++)
//	{
//		if (dir == 0 && d == 2) continue;
//		if (dir == 1 && d == 3) continue;
//		if (dir == 2 && d == 0) continue;
//		if (dir == 3 && d == 1) continue;
//
//		int nRow = curRow;
//		int nCol = curCol;
//
//		while (true)
//		{
//			/*if (d < 0 || d >= 4)
//				cout << d << '\n';*/
//			nRow += dROW[d];
//			nCol += dCOL[d];
//
//			// 배열 범위 벗어나거나, 벽 만나면 탈출
//			if (isInArrBounds(nRow, nCol) == false || mapVec[nRow][nCol] == 6)
//				break;
//
//			// 시야 표시
//			vec[nRow][nCol] = 1;
//		}
//	}
//}
//void cctv5(const int curRow, const int curCol, const int dir, vector<vector<int>>& vec)
//{
//	//cout << &vec << '\n';
//	//cout << &vec[0][0] << '\n';
//
//	// CCTV 5 (4방향)
//	// 모든 방향으로 벽, 배열 끝까지 진행
//	//const initializer_list<int> il = { 0,1,2,3 };
//
//	//for (int d : il)
//	for(int d = 0; d < 4; d++)
//	{
//		int nRow = curRow;
//		int nCol = curCol;
//
//		while (true)
//		{
//			/*if(d < 0 || d >= 4)
//				cout << d << '\n';*/
//			nRow += dROW[d];
//			nCol += dCOL[d];
//
//			// 배열 범위 벗어나거나, 벽 만나면 탈출
//			if (isInArrBounds(nRow, nCol) == false || mapVec[nRow][nCol] == 6)
//				break;
//
//			// 시야 표시
//			vec[nRow][nCol] = 1;
//		}
//	}
//}
//
//void myfunc(const int cctvIdx, const vector<vector<int>>& curSightVec)
//{
//	// idx 가 넘어가면 리턴
//	if (cctvIdx >= cctvVec.size())
//	{
//		// 사각지대 카운팅
//		int blindSpotCnt = 0;
//		for (auto row : curSightVec)
//		{
//			for (auto x : row)
//			{
//				if (x == 0)
//					blindSpotCnt++;
//			}
//		}
//
//		minBlindSpotCnt = std::min(minBlindSpotCnt, blindSpotCnt);
//
//		return;
//	}
//
//	// 현재 cctv 의 방향 설정
//	const pair<int, int> curPos = *(cctvVec.begin() + cctvIdx);
//
//	// cctv Type 을 mapVec 에서 가져옴
//	const int cctvTypeNum = mapVec[curPos.first][curPos.second];
//
//	// 4방향에 대해서...
//	vector<vector<int>> nxtSightVec;
//	for (int dir = 0; dir < 4; dir++)
//	{
//		// sightVec 원래대로 설정
//		nxtSightVec = curSightVec;
//
//		// Type별로 방향 설정
//		switch (cctvTypeNum)
//		{
//		case 1:
//			//cout << &tmpVec << '\n';
//			//cout << &tmpVec[0][0] << '\n';
//			cctv1(curPos.first, curPos.second, dir, nxtSightVec);
//			break;
//		case 2:
//			if(dir < 2)
//				cctv2(curPos.first, curPos.second, dir, nxtSightVec);
//			break;
//		case 3:
//			cctv3(curPos.first, curPos.second, dir, nxtSightVec);
//			break;
//		case 4:
//			cctv4(curPos.first, curPos.second, dir, nxtSightVec);
//			break;
//		case 5:
//			if(dir == 0)
//				cctv5(curPos.first, curPos.second, dir, nxtSightVec);
//			break;
//		default:
//			cout << "WRONG" << '\n';
//			break;
//		}
//
//		// 다음 cctv의 방향 설정
//		myfunc(cctvIdx + 1, nxtSightVec);
//	}
//	
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 사무실 map 입력
//	cin >> ROW >> COL;
//	for (int r = 0; r < ROW; r++)
//	{
//		vector<int> tmpVec;
//		vector<int> tmpVec2;
//
//		for (int c = 0; c < COL; c++)
//		{
//			int x;
//			cin >> x;
//
//			tmpVec.push_back(x);
//
//			// 빈공간만 시야 0으로 채움
//			if (x == 0)
//				tmpVec2.push_back(0);
//			else
//			{
//				// cctv, 벽 시야 1로 채움
//				tmpVec2.push_back(1);
//
//				// cctv 위치 저장
//				if (x != 6)
//				{
//					cctvVec.push_back({ r,c });
//				}
//			}
//		}
//		mapVec.push_back(tmpVec);
//		sightVec.push_back(tmpVec2);
//	}
//
//	myfunc(0, sightVec);
//
//	cout << minBlindSpotCnt;
//
//	return 0;
//}
//
//
//// 뭐야 시발 그러면 결국 그냥 initialize_list 썼더니 뭔가(이 뭔가가 뭐임???) 가 문제가 생겼던거네?
//// 뭐가 문젠지 찾기
//// 1) initialize_list -> 정확히는 모르겠으나! for문으로 명시적으로 사용하지 말것. (초기화 용으로 만 사용하자..)
////	- 임시 배열을 가리키는 객체
////  - 초기화 후 임시 배열 사라짐
////  - 복사가 안됨
////  - [] 연산자 사용 불가
////  - 기본 배열은 const T[N] 유형 의 임시 배열이며 , 
//// 여기서 각 요소는 원래 초기화 목록의 해당 요소에서 복사 초기화 됩니다(축소 변환이 유효하지 않음 제외). 
//// 기본 배열의 수명은 배열에서 initializer_list 객체를 초기화하는 것이 임시에 대한 참조를 바인딩하는 것과 똑같이 배열의 수명을 연장한다는 점을 제외하면
////  다른 임시 객체 와 동일합니다(비 -정적 클래스 멤버). 
//// 기본 배열은 읽기 전용 메모리에 할당될 수 있습니다. const T[N]
//// std::initializer_list 의 명시 적 또는 부분 특수화 가 선언 되면 프로그램이 잘못 구성됩니다 . -> 명시적, 부분 특수화가 뭐냐?
//// https://runebook.dev/ko/docs/cpp/utility/initializer_list
//
//// 2) 3항 연산자 -> 일단 이건 아님, 잘 사용하고 있었음