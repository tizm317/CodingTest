//#include <iostream>
//#include <string>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 19. ��
//// ���� ��ȣ	: #9996 
//// ���� �̸�	: �ѱ��� �׸��� �� ������ ��������
//// �˰���	: ���ڿ�
//// �ð����⵵: O()
//
//int N;				// 1 ~ 100
//string pattern;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// ���� ����
//	cin >> N;
//
//	// ���� �Է�
//	cin >> pattern; 
//	
//	// ������ * �������� ��, �� 2���� �κй��ڿ��� �и�
//	// ex : ���� abc*def �� ���
//	int starIdx = pattern.find("*");
//	string first = pattern.substr(0, starIdx); // abc
//	string second = pattern.substr(starIdx + 1, pattern.size()); // def
//
//
//
//	for (int i = 0; i < N; i++)
//	{
//		// abceeedef
//		// ���� �̸� �Է�
//		string fileName;
//		cin >> fileName;
//
//		
//		// �ݷ�
//		// ab*ab
//		// ab 
//		// ab*ab �� abab ���� �ǵ�, ab�� �´� ������ �߻�
//		// -> �ذ� : �ּ� ���� üũ
//
//		// ����1) �����̸� ���� < * ���� ���� ���� -> �Ұ���
//		if (fileName.size() < pattern.size() - 1)
//		{
//			cout << "NE" << '\n';
//			continue;
//		}
//
//		// ����2) first �� �� ���� �ƴ� ��� + ���� ��� : ����
//		if (fileName.find(first) != 0)
//		{
//			cout << "NE" << '\n';
//			continue;
//		}
//
//		// first*second �κ� �� first ������ ���
//
//		// * + second �κ� üũ
//		// * �κ��� �ǳʶٰ�,
//		// �������� second �κи� ���ڸ��� ������ ���
//		bool success = false;
//		int secondPos = fileName.find(second);
//		while (secondPos != -1)
//		{
//			// second�� ù ���� ��ġ��(secondPos) �����̸� ũ�� - second �ܾ� ũ�� �� ��ġ�ؾ���.
//			if (secondPos == fileName.size() - second.size())
//				success = true;
//
//			// ���� ��ġ
//			secondPos = fileName.find(second, secondPos + second.size());
//		}
//
//		// �������� second �κи� ���ڸ��� ������ ���
//		if (success)
//			cout << "DA" << '\n';
//		else
//			cout << "NE" << '\n';
//	}
//
//	return 0;
//}