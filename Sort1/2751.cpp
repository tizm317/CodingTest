//#include <iostream>
//#include <algorithm> // swap
//
//using namespace std;
//
//void MergeSort(int* ar, int k)
//{
//	if (k == 1)
//		return;
//
//	// k -> k/2 크기 배열 두 개로 자름
//	// ar[0]~ar[k/2-1]
//	MergeSort(ar, k / 2);
//
//	// ar[k/2]~ar[k]
//	MergeSort(ar + k / 2, k - k / 2);
//
//
//	// 임시 배열
//	int* addedArr = new int[k];
//
//	int aPos = 0;
//	int bPos = k / 2;
//	int cnt = 0;
//
//	while (aPos < k / 2 && bPos < k)
//	{
//		if (ar[aPos] <= ar[bPos])
//		{
//			addedArr[cnt++] = ar[aPos++];
//		}
//		else
//		{
//			addedArr[cnt++] = ar[bPos++];
//		}
//	}
//
//	// 남은 거
//	for (; aPos < k / 2; aPos++)
//		addedArr[cnt++] = ar[aPos];
//
//	for (; bPos < k; bPos++)
//		addedArr[cnt++] = ar[bPos];
//
//
//	copy(addedArr, addedArr + cnt, ar);
//}
//
//int N;
//
//int arr[1'000'005];
//
//int main()
//{
//	cin >> N;
//	for (int i = 0; i < N; i++)
//		cin >> arr[i];
//
//	// Merge Sort
//	MergeSort(arr, N);
//
//	for (int i = 0; i < N; i++)
//		cout << arr[i] << '\n';
//
//	return 0;
//}
