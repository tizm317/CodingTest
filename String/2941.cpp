//#include <iostream>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 19. ��
//// ���� ��ȣ	: #2941 
//// ���� �̸�	: ũ�ξ�Ƽ�� ���ĺ�
//// �˰���	: ���ڿ�
//// �ð����⵵: O()
//
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// ���ĺ� + '-' + '='
//	string str;
//	cin >> str;
//
//
//	// string �� � �޼��� ���?
//	// ljes=njak -> lj , e , s= , nj , a , k
//	string Croatia[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
//
//	// replace Ȱ�� (erase Ȱ���, ddz=z= �� ���, dz= �� �������鼭 d, z= �� dz= �� �������鼭 ������ȭ�� ����)
//	// ũ�ξ�Ƽ�� ���ĺ��� 1���ڷ� �ٲ� ��
//	for (int i = 0; i < 8; i++)
//	{
//		string cAlphabet = Croatia[i];
//
//		int pos = str.find(cAlphabet);
//		while (pos != -1)
//		{
//			str.replace(pos, cAlphabet.size(), "X"); // 1���ڷ� �ٲ�
//
//			pos = str.find(cAlphabet);
//		}
//	}
//
//	// ���� ���� ���
//	cout << str.size();
//
//	return 0;
//}