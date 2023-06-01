#include <iostream>
#include <vector>

int func1(int N)
{
	// 3 배수 or 5배수 합한 값 반환
	int res = 0; // 1
	
	// O(N)
	for (int i = 1; i <= N; i++) 
	{
		if (i % 3 == 0 || i % 5 == 0) 
		{
			res += i; 
		}
	}

	return res;
}

int func2(int* arr, int N)
{
	// O(N^2)
	//for (int i = 0; i < N - 1; i++)
	//{
	//	for (int j = i + 1; j < N; j++)
	//	{
	//		if (arr[i] + arr[j] == 100)
	//			return 1;
	//	}
	//}

	// O(N)

	// 0, 1 ~ 99
	int num[100] = { 0, };
	for (int i = 0; i < N; i++)
	{
		// 이미 상대방이 있는지 체크, 있으면 return 1;
		if (num[arr[i]] == 1)
			return 1;

		// 내 상대방 +1 해줌
		num[100 - arr[i]]++;
	}


	return 0;
}

int func3(int N)
{
	// n : 100
	// 1 ~ 10
	// n : 10000
	// 1 ~ 100
	// O(루트N)
	for (int i = 1; i * i <= N; i++)
	{
		if (i * i == N)
			return 1;
	}

	return 0;
}

int func4(int N)
{
	// O(logN)
	// 1 2 4 <= 5
	// 1 2 4 8 <= 10
	int res = 1;
	for (int i = 1; i <= N; i *= 2)
	{
		res = i;
	}

	return res;
}

void test(std::vector<int>& v)
{
	v[10] = 7;
}

int main()
{
	std::cout << func1(27639) << std::endl;

	int arr1[3] = { 1,52,48 };
	int arr2[2] = { 50,42 };
	int arr3[4] = { 4,13,63,87 };
	std::cout << func2(arr3, 4) << std::endl;

	std::cout << func3(100) << std::endl;

	std::cout << func4(97615282) << std::endl;

	std::vector<int> v(100);
	test(v);
	std::cout << v[10] << std::endl;

	return 0;
}
