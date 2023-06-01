#include <iostream>
#include <algorithm> // swap

using namespace std;

//int arr[10] = { 3,2,7,116,62,235,1,23,55,77 };
int arr2[8] = { 3,2,7,116,62,235,1,23 };
int arr3[8] = { 6,-8, 1,12,8,15,7,-7 };

int arr[1000001] = { 3,2,7,116,62,235,1,23,55,77 };
int tmp[1000001];

// arr[st:en] 정렬하는 함수
// 조건, arr[st:mid] , arr[mid, en] 정렬되어 있어야함
void merge(int st, int en)
{
	int mid = (st + en) / 2;

	int aPos = st;
	int bPos = mid;
	int cnt = 0;

	while (aPos < mid && bPos < en)
	{
		if (arr[aPos] <= arr[bPos])
		{
			tmp[cnt++] = arr[aPos++];
		}
		else
		{
			tmp[cnt++] = arr[bPos++];
		}
	}

	for (; aPos < mid; aPos++)
		tmp[cnt++] = arr[aPos];

	for (; bPos < en; bPos++)
		tmp[cnt++] = arr[bPos];

	copy(tmp, tmp + (en - st), arr + st);

	// 중간과정 출력
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << '\n';
}

// arr[st:en] 정렬하는 함수
void merge_sort(int st, int en)
{
	if (en - st == 1)
		return;
	int mid = (st + en) / 2;
	merge_sort(st, mid);
	merge_sort(mid, en);
	merge(st, en);
}

void MergeSort(int* ar, int k)
{
	if (k == 1)
		return;

	// k -> k/2 크기 배열 두 개로 자름
	// ar[0]~ar[k/2-1]
	MergeSort(ar, k / 2);
	
	// ar[k/2]~ar[k]
	MergeSort(ar + k / 2, k / 2);


	// 임시 배열
	int* addedArr = new int[k];

	int aPos = 0;
	int bPos = k / 2;
	int cnt = 0;

	while (aPos < k / 2 && bPos < k)
	{
		if (ar[aPos] <= ar[bPos])
		{
			addedArr[cnt++] = ar[aPos++];
		}
		else
		{
			addedArr[cnt++] = ar[bPos++];
		}
	}

	// 남은 거
	for (; aPos < k / 2; aPos++)
		addedArr[cnt++] = ar[aPos];

	for (; bPos < k; bPos++)
		addedArr[cnt++] = ar[bPos];


	copy(addedArr, addedArr + cnt, ar);
}


void badQuickSort(int st, int en)
{
	if (en - st <= 1)
		return;

	// 담아둘 임시 배열
	int tmp2[8];

	// 인덱스 설정
	int idx = 0;
	int pivotIdx = 0;

	// 피벗 설정
	int pivot = arr2[st];
	
	// 1. 피벗보다 작은 값 왼쪽에 넣기
	for (int i = st + 1; i < en; i++)
	{
		if (arr2[i] < pivot)
			tmp2[idx++] = arr2[i];
	}

	// 2. 피벗 제자리에 위치
	pivotIdx = st + idx;
	tmp2[idx++] = pivot;

	// 3. 피벗 보다 큰 값 오른쪽에 넣기
	for (int i = st; i < en; i++)
	{
		if (arr2[i] > pivot)
			tmp2[idx++] = arr2[i];
	}

	// 정렬된 배열로 바꾸기
	copy(tmp2, tmp2 + idx, arr2 + st);

	// 왼쪽 정렬
	badQuickSort(0, pivotIdx);
	// 오른쪽 정렬
	badQuickSort(pivotIdx + 1, en);
}

int quick(int st, int en)
{
	int pivot = arr[st];

	//int cnt = 0;
	//for (int i = 0; i < en; i++)
	//{
	//	if (arr[i] >= pivot)
	//		continue;

	//	tmp[cnt++] = arr[i];
	//}

	//int pivotIdx = cnt;
	//tmp[cnt++] = pivot;

	//for (int i = 0; i < en; i++)
	//{
	//	if (arr[i] <= pivot)
	//		continue;

	//	tmp[cnt++] = arr[i];
	//}

	//copy(tmp, tmp + en, arr);

	int l = st + 1;
	int r = en - 1;

	if (l >= r)
		return st;

	while (l < r)
	{
		while (arr[l] < pivot)
			l++;

		while (arr[r] > pivot)
			r--;

		if (l >= r)
			break;

		swap(arr[l++], arr[r--]);
	}

	

	swap(arr[st], arr[r]);

	int pivotIdx = r;

	return pivotIdx;
}

void quick_sort(int st, int en)
{
	if (en - st <= 1)
		return;

	int pivotIdx = quick(st, en);
	quick_sort(st, pivotIdx);
	quick_sort(pivotIdx + 1, en);
}

void quick_sort2(int st, int en)
{
	// 배열 원소 1개 이하 일때
	if (en - st <= 1)
		return;

	// 피벗
	int pivot = arr[st];

	// l,r 포인터
	int l = st + 1;
	int r = en - 1;

	// l, r 교차할 때까지 반복
	while (true)
	{
		// l은 피벗보다 큰 값 나올 때까지 오른쪽 이동
		while (l <= r && arr[l] <= pivot) l++;
		
		// r은 피벗보다 작은 값 나올 때까지 왼쪽 이동
		while (l <= r && arr[r] >= pivot) r--;
		
		if (l > r) break;
		
		// 
		swap(arr[l], arr[r]);
	}

	// 마지막으로 r 위치한 원소와 피벗 위치한 원소 교환
	swap(arr[st], arr[r]);

	// 왼쪽 부분 정렬
	quick_sort2(st, r);

	// 오른쪽 부분 정렬
	quick_sort2(r + 1, en);
}


int main()
{
	// 1. Selection Sort

	//for (int i = 0; i < 9; i++)
	//{
	//	// i + 1 이후, 최소 원소 찾기
	//	int minIdx = i;
	//	for (int j = i + 1; j < 10; j++)
	//	{
	//		if (arr[j] < arr[minIdx])
	//			minIdx = j;
	//	}

	//	// i번째 원소랑 최소 원소 교체
	//	swap(arr[i], arr[minIdx]);
	//}

	//for (int i = 0; i < 10; i++)
	//	cout << arr[i] << " ";

	// 2. min_element
	//for (int i = 0; i < 9; i++)
	//{
	//	// i + 1 이후, 최소 원소 찾기
	//	int* minPtr = min_element(arr + i + 1, arr + 10);

	//	// i번째 원소랑 최소 원소 교체
	//	swap(arr[i], *minPtr);
	//}

	//for (int i = 0; i < 10; i++)
	//	cout << arr[i] << " ";

	// 2. Bubble sort

	//for(int i = 0; i < 10; i++)
	//{
	//	for (int j = 0; j < 10 - i - 1; j++) //  j < 10 - 1
	//	{
	//		// 인접한 두 원소 비교 후 큰 값을 오른쪽으로 이동
	//		if (arr[j] > arr[j + 1])
	//			swap(arr[j], arr[j + 1]);
	//	}
	//}
	//
	//for (int i = 0; i < 10; i++)
	//	cout << arr[i] << " ";

	// 3. Insertion sort

	// 0번째는 이미 정렬된 셈.
	//for (int i = 1; i < 10; i++)
	//{
	//	// i번째와 i-1번째 비교

	//	int j = i - 1;
	//	for (; j >= 0; j--)
	//	{
	//		if (arr[j] <= arr[i])
	//			break;
	//	}

	//	j++;
	//	int temp = arr[i];

	//	// j번째에 넣기 위해 한칸씩 뒤로 밀기 (i번째 까지)
	//	copy(arr + j, arr + i, arr + j + 1);

	//	arr[j] = temp;
	//}

	//for (int i = 0; i < 10; i++)
	//	cout << arr[i] << " ";

	// Merge Sort
	/*MergeSort(arr3, 8);

	for (int i = 0; i < 8; i++)
		cout << arr3[i] << " ";*/

	//
	//for (int i = 0; i < 10; i++)
	//	cout << arr[i] << " ";
	//cout << '\n';
	//merge_sort(0, 10);
	//for (int i = 0; i < 10; i++)
	//	cout << arr[i] << " ";

	// Quick Sort
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << '\n';
	//quick_sort(0, 10);
	quick_sort2(0, 10);
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << '\n';

	//
	for (int i = 0; i < 8; i++)
		cout << arr2[i] << " ";
	cout << '\n';

	badQuickSort(0, 8);
	for (int i = 0; i < 8; i++)
		cout << arr2[i] << " ";

	return 0;
}
