//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//void insert(int idx, int num, int arr[], int& len) 
//{
//	// idx ��ġ�� num �����ϴ� �Լ�
//
//	// 1. std::copy ���
//	
//	// idx ��ġ���� ������ ���ұ��� �����ؼ� �� ĭ�� �ڷ� �̵�
//	copy(arr + idx, arr + len, arr + idx + 1);
//
//	// idx ��ġ�� num ��ü
//	arr[idx] = num;
//
//	// �迭 ���� ����
//	len++;
//
//	// 2. �ݺ��� ���
//	
//	//// �ݺ�������, ������ ���Һ��� idx ��ġ ���ұ��� �� ĭ�� �ڷ� �̵�
//	// ������ ���Һ��� �Ųٷ� �ݺ��ϴ� ���� : arr[i+1] �� arr[i] �� �ٲ�� ����
//	//for (int i = len - 1; i >= idx; i--)
//	//{
//	//	arr[i + 1] = arr[i];
//	//}
//
//	//// idx ��ġ�� num
//	//arr[idx] = num;
//
//	//len++;
//}
//
//void erase(int idx, int arr[], int& len) 
//{
//	// idx ��ġ ���� ���� �Լ�
//
//	// 1. std::copy �Լ� Ȱ��
//	// idx + 1 ��ġ ���Һ��� ������ ���ұ��� �����ؼ� �� ĭ�� ������ �̵�
//	copy(arr + idx + 1, arr + len, arr + idx);
//
//	// �迭 ���� ����
//	len--;
//
//	// 2. �ݺ���
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
