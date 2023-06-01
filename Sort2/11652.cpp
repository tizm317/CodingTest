//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 06. 01. ��
//// ���� ��ȣ	: #11652 
//// ���� �̸�	: ī��
//// �˰���	: ����
//// �ð����⵵: O()
//
//int N; // <= 100'000
//// -2^62 ~ 2^62
//
//string arr[100'005];
//int idx[100'005];
//int freq[100'005];
//
//bool cmp(const string& a, const string& b)
//{
//	// �� �� �ϳ��� ����, �ϳ��� ����� ���
//	if (a[0] == '-' && b[0] != '-')
//		return true;
//	if (a[0] != '-' && b[0] == '-')
//		return false;
//
//	// �� �� �����ų�, ����ų�..
//	// 1. �ڸ����� ��
//	if (a[0] != '-')
//	{
//		if (a.size() != b.size())
//			return a.size() < b.size();
//	}
//	else
//	{
//		// -999 -1
//		if (a.size() != b.size())
//			return a.size() > b.size();
//	}
//	
//
//	// 2. �� �ڸ������� ��
//	for (int i = 0; i < a.size(); i++)
//	{
//		if (a[i] != b[i])
//		{
//			// �� �� ����� ���,
//			if(a[0] != '-')
//				return a[i] < b[i];
//			// �� �� ������ ���,
//			else
//				return a[i] > b[i];
//		}
//	}
//
//	// 3. �ƿ� ���� ���
//	return false;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> arr[i];
//	}
//
//	// 3 2 2 1 3 3 1 3 1
//	sort(arr, arr + N, cmp);
//
//	// 1 1 1 2 2 3 3 3 3
//
//	// �ε��� ��� �迭��, �󵵼� ��� �迭 2�� �غ�
//	//int cnt = 0;
//	//freq[cnt] = 1;
//	//idx[cnt] = 0;
//
//	//// ���ĵ� �迭�� ��ȸ�ϴٰ�, ���� ���ϰ� �޶����� �ε��� �迭�� ���ο� ���� �ְ�, �ƴϸ� �󵵼��� ������Ű�� ���� �ݺ�
//	//for (int i = 1; i < N; i++)
//	//{
//	//	if (arr[i - 1] != arr[i])
//	//	{
//	//		idx[++cnt] = i;
//	//	}
//
//	//	freq[cnt]++;
//	//}
//
//	//int maxfreqIdx = max_element(freq, freq + cnt + 1) - freq;
//	//cout << arr[idx[maxfreqIdx]];
//
//	//4611686018427387904
//
//	// �ٸ� Ǯ��
//	// ó�� ���� O(NlogN) , ���� ó�� O(N) => ��������� O(NlogN)
//	// 
//	// i�� 0�� �� �ʱ�ȭ
//	int cnt = 1; // ���� ī��Ʈ
//	int mxcnt = 1; // �ִ� ī��Ʈ
//	string mxval = arr[0]; // �ִ� ī��Ʈ�� �� ��
//
//	// 2 2 2 3 5 5 7 7
//	for (int i = 1; i < N; i++)
//	{
//		if (arr[i] != mxval)
//		{
//			cnt = 1;
//		}
//		else
//		{
//			cnt++;
//			if (cnt > mxcnt)
//			{
//				mxcnt = cnt;
//				mxval = arr[i];
//			}
//			
//		}
//	}
//
//	cout << mxval;
//
//	return 0;
//}