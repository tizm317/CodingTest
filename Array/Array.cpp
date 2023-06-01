//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//void insert(int idx, int num, int arr[], int& len) 
//{
//	// idx 위치에 num 삽입하는 함수
//
//	// 1. std::copy 사용
//	
//	// idx 위치부터 마지막 원소까지 복사해서 한 칸씩 뒤로 이동
//	copy(arr + idx, arr + len, arr + idx + 1);
//
//	// idx 위치에 num 교체
//	arr[idx] = num;
//
//	// 배열 길이 증가
//	len++;
//
//	// 2. 반복문 사용
//	
//	//// 반복문으로, 마지막 원소부터 idx 위치 원소까지 한 칸씩 뒤로 이동
//	// 마지막 원소부터 거꾸로 반복하는 이유 : arr[i+1] 이 arr[i] 로 바뀌기 때문
//	//for (int i = len - 1; i >= idx; i--)
//	//{
//	//	arr[i + 1] = arr[i];
//	//}
//
//	//// idx 위치에 num
//	//arr[idx] = num;
//
//	//len++;
//}
//
//void erase(int idx, int arr[], int& len) 
//{
//	// idx 위치 원소 삭제 함수
//
//	// 1. std::copy 함수 활용
//	// idx + 1 위치 원소부터 마지막 원소까지 복사해서 한 칸씩 앞으로 이동
//	copy(arr + idx + 1, arr + len, arr + idx);
//
//	// 배열 길이 감소
//	len--;
//
//	// 2. 반복문
//	//for (int i = idx; i < len - 1; i++)
//	//{
//	//	arr[i] = arr[i + 1];
//	//}
//
//	//len--;
//}
//
//void printArr(int arr[], int& len) 
//{
//	for (int i = 0; i < len; i++) 
//		cout << arr[i] << ' ';
//	
//	cout << "\n\n";
//}
//
//void insert_test() 
//{
//	cout << "***** insert_test *****\n";
//	int arr[10] = { 10, 20, 30 };
//	int len = 3;
//
//	insert(3, 40, arr, len); // 10 20 30 40
//	printArr(arr, len);
//	
//	insert(1, 50, arr, len); // 10 50 20 30 40
//	printArr(arr, len);
//	
//	insert(0, 15, arr, len); // 15 10 50 20 30 40
//	printArr(arr, len);
//}
//
//void erase_test() 
//{
//	cout << "***** erase_test *****\n";
//	int arr[10] = { 10, 50, 40, 30, 70, 20 };
//	int len = 6;
//	
//	erase(4, arr, len); // 10 50 40 30 20
//	printArr(arr, len);
//	
//	erase(1, arr, len); // 10 40 30 20
//	printArr(arr, len);
//	
//	erase(3, arr, len); // 10 40 30
//	printArr(arr, len);
//}
//
//int main(void) 
//{
//	insert_test();
//	erase_test();
//
//	return 0;
//}
//
