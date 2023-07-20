//#include <iostream>
//using namespace std;
//
//// 백준 문제 풀이
//// 날짜		: 2023. 07. 20. 목
//// 문제 번호	: #14499 
//// 문제 이름	: 주사위 굴리기
//// 알고리즘	: 시뮬레이션
//// 시간복잡도: O()
//
//// 지도
//int R, C; // 1 <= R,C <= 20
//int map[30][30];
//
//// 주사위 시작 좌표
//int x, y;
//
//// 이동 횟수
//int K;
//
//// 동서북남 좌표 이동
//const int dRow[4] = {0, 0, -1, 1};
//const int dCol[4] = {1, -1, 0, 0};
//
//// 주사위 칸 숫자 배열
//// idx  : 0  1  2  3  4  5
//// 위치 : 밑 동 북 남  서 위
//const int diceSideCnt = 6;
//int dice[diceSideCnt];
//
//// 배열 2개로 할 수도 있음
//// dice1[0] = dice2[0]
//// dice1[2] = dice2[2]
//int dice1[4]; // 동서 방향 (밑,동,위,서)
//int dice2[4]; // 남북 방향 (밑,북,위,남)
//
//enum Edice
//{
//	BOTTOM,
//	EAST,
//	NORTH,
//	SOUTH,
//	WEST,
//	TOP,
//};
//
//void diceMove(int dir);
//void diceRotate(int dir);
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// 지도 크기, 주사위 좌표, 이동 횟수 입력
//	cin >> R >> C >> x >> y >> K;
//
//	// 지도 입력
//	for (int r = 0; r < R; r++)
//	{
//		for (int c = 0; c < C; c++)
//		{
//			cin >> map[r][c];
//		}
//	}
//
//	// 이동
//	while (K--)
//	{
//		// 이동 명령 방향
//		int dir;
//		cin >> dir;
//
//		// 다음 좌표 계산
//		int nRow = x + dRow[dir - 1];
//		int nCol = y + dCol[dir - 1];
//
//		// 배열 범위 체크 -> 회전 먼저 하느라, 이 부분에서 체크 해줘야 함. (안 그러면 회전은 하고 이동은 안 하는 오류가 생김)
//		if (nRow < 0 || nRow >= R || nCol < 0 || nCol >= C)
//			continue;
//
//		// dir은 1-based -> 0-based idx 로 변환 (dir - 1)
//		
//		// 1. 주사위 회전
//		diceRotate(dir - 1);
//
//		// 2. 주사위 이동
//		diceMove(dir - 1); 
//		
//		// 3. 회전 후, 주사위 윗면 출력
//		//cout << dice[diceSideCnt - 1] << '\n';
//		cout << dice1[2] << '\n';
//		//cout << "주사위 윗면 : " << dice[5] << '\n';
//	}
//
//	return 0;
//}
//
//void diceMove(int dir)
//{
//	// 다음 좌표 계산
//	int nRow = x + dRow[dir];
//	int nCol = y + dCol[dir];
//
//	// 배열 범위 체크
//	if (nRow < 0 || nRow >= R || nCol < 0 || nCol >= C)
//		return;
//
//	// 지도가 0인 경우
//	if (map[nRow][nCol] == 0)
//	{
//		// 주사위 바닥면의 수가 지도 위로 복사
//			// map[nRow][nCol] = 회전 후 주사위 아랫면;
//		//map[nRow][nCol] = dice[Edice::BOTTOM];
//		map[nRow][nCol] = dice1[0];
//
//	}
//	else // 지도의 수가 0이 아닌 다른 수인 경우
//	{
//		// 지도 위의 수가 주사위로 복사
//			// 회전 후!(회전 먼저하도록 순서 변경) 주사위 아랫면 = map[nRow][nCol];
//		//dice[Edice::BOTTOM] = map[nRow][nCol];
//		dice1[0] = map[nRow][nCol];
//		dice2[0] = dice1[0];
//
//		// 지도 위의 수는 0이 됨.
//		map[nRow][nCol] = 0;
//	}
//
//	// 주사위 좌표 이동
//	x = nRow;
//	y = nCol;
//}
//
//void diceRotate(int dir)
//{
//	// 회전한 결과를 담을 임시 배열 초기화
//	//int tmp[diceSideCnt];
//	//for (int i = 0; i < diceSideCnt; i++)
//	//	tmp[i] = dice[i];
//
//
//
//	// <<< 이 부분 정리해보자! >>>
//	// >> enum 사용해서 수정 하긴 했는데, 가독성이야 조금 올랐다 하더라도, 
//	// >> 중복된 부분이 너무 많다.
//	// >> >> 사실 이 dir 을 enum 으로 바꾸는 것이 좋아보이는데..
//
//	// >> 다른 방법으로 바꿔봤는데 그래도 많이 겹침.
//
//	int tmp;
//	switch (dir)
//	{
//		// 동, 서 회전 dice1 이용
//	case 0:
//		tmp = dice1[0];
//		copy(dice1 + 1, dice1 + 4, dice1);
//		dice1[3] = tmp;
//
//		// 결과 dice1, dice2 동기화
//		dice2[0] = dice1[0];
//		dice2[2] = dice1[2];
//		break;
//	case 1:
//		tmp = dice1[3];
//		copy(dice1, dice1 + 3, dice1 + 1);
//		dice1[0] = tmp;
//
//		// 결과 dice1, dice2 동기화
//		dice2[0] = dice1[0];
//		dice2[2] = dice1[2];
//		break;
//		// 북, 남 회전 dice2 이용
//	case 2:
//		tmp = dice2[0];
//		copy(dice2 + 1, dice2 + 4, dice2);
//		dice2[3] = tmp;
//
//		// 결과 dice1, dice2 동기화
//		dice1[0] = dice2[0];
//		dice1[2] = dice2[2];
//		break;
//	case 3:
//		tmp = dice2[3];
//		copy(dice2, dice2 + 3, dice2 + 1);
//		dice2[0] = tmp;
//
//		// 결과 dice1, dice2 동기화
//		dice1[0] = dice2[0];
//		dice1[2] = dice2[2];
//		break;
//	}
//
//	
//
//
//	/*
//	switch (dir)
//	{
//		// 동, 서 회전 (북/남 고정)
//	case 0:
//		tmp[Edice::WEST] = dice[BOTTOM];
//		tmp[EAST] = dice[TOP];
//		tmp[TOP] = dice[WEST];
//		tmp[BOTTOM] = dice[EAST];
//		break;
//	case 1:
//		tmp[EAST] = dice[BOTTOM];
//		tmp[WEST] = dice[TOP];
//		tmp[BOTTOM] = dice[WEST];
//		tmp[TOP] = dice[EAST];
//		break;
//
//		// 북, 남 회전 (동/서 고정)
//	case 2:
//		tmp[SOUTH] = dice[BOTTOM];
//		tmp[NORTH] = dice[TOP];
//		tmp[BOTTOM] = dice[NORTH];
//		tmp[TOP] = dice[SOUTH];
//		break;
//	case 3:
//		tmp[NORTH] = dice[BOTTOM];
//		tmp[SOUTH] = dice[TOP];
//		tmp[TOP] = dice[NORTH];
//		tmp[BOTTOM] = dice[SOUTH];
//		break;
//	}
//
//	// 결과 배열로 dice 배열 덮어줌
//	for (int i = 0; i < diceSideCnt; i++)
//		dice[i] = tmp[i];
//	*/
//	
//}