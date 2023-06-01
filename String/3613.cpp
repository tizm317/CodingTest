//#include <iostream>
//#include <string>
//#include <vector>
//#include <cctype> // toupper
//#include <locale> // isupper
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 19. ��
//// ���� ��ȣ	: #3613 
//// ���� �̸�	: Java vs C++
//// �˰���	: ���ڿ�
//// �ð����⵵: O()
//
//vector<string> chunks;
//string ans;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	// ������ �Է�
//	string str;
//	cin >> str;
//
//	// java style -> C++
//	// ù �ܾ� : �ҹ��� / ������ : ù���ڸ� �빮��
//	// longAndMnemonicIdentifier
//	
//	// C++ style -> java
//	// ��� �ܾ� : �ҹ��� / '_' : �ܾ� ����
//	// long_and_mnemonic_identifier
//
//	// �� �� <- �̰� ã�°��� ����!!!
//	// Error ���
//
//	/*
//	*	1. ù �ܾ� : �ҹ��� , ������ : ù���ڸ� �빮�� -> java
//		javaIdentifier -> java/Identifier
//		aBCDEF -> a/B/C/D/E/F
//		
//		2. ��� �ܾ� : �ҹ���, '_' �� �ܾ� ���� -> C++
//		c_identifier
//		b_a_e_k_j_o_o_n
//
//		3. ù ���� : �빮�� -> java , c++ �� �� X
//		Abcdef
//		ABCDEF
//		B_a_e_k_j_o_o_n
//
//		==============> '_' �� �ܾ �����ؾ� �Ѵٴ� c++ ����
//		4. _ �� ����
//		_java_aaa
//
//		5. __ ����
//		__java
//		c__identifier
//
//		6. _ �� ������
//		java_
//
//	*/
//
//
//	// ��� ���� �ҹ��� ���� üũ
//	bool isAllLowerCh = true;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (isupper(str[i]))
//		{
//			isAllLowerCh = false;
//			break;
//		}
//	}
//
//	// _ �� ����, _ �� �� ���� ���� ó��
//	if (str[0] == '_' || str[str.size() - 1] == '_')
//	{
//		cout << "Error!";
//		return 0;
//	}
//
//	int pos = str.find("_");
//	// ù �ܾ� �ҹ��� + (���� �ܾ���ʹ� ù ���� �빮��) + _ ���� => java
//	if (islower(str[0]) && pos == -1)
//	{
//		//cout << "java style" << '\n';
//
//		// 1. java -> C++
//		// �빮�� ��ġ ã��, �� �տ� _ ����
//		int st = 0;
//		for (int i = 0; i < str.size(); i++)
//		{
//			if (isupper(str[i]))
//			{
//				ans += str.substr(st, i - st);
//				ans += "_";
//				str[i] = tolower(str[i]);
//				st = i;
//			}
//		}
//		// ����������
//		ans += str.substr(st, str.size());
//		
//	}
//	// ��� ���� �ҹ��� + (_ ���� �� ����) => C++
//	else if (isAllLowerCh)
//	{
//		//cout << "C++ style" << '\n';
//
//		// 1. C++ -> java
//		int st = 0;
//		while (pos != -1)
//		{
//			// _abc -> abc
//			string sub = str.substr(st, pos - st);
//			if(sub != "")
//				chunks.push_back(sub);
//			st = pos + 1;
//
//			int before = pos;
//			pos = str.find("_", st);
//			
//			// __ ����
//			if (before + 1 == pos)
//			{
//				cout << "Error!";
//				return 0;
//			}
//		}
//
//		// ������ ����
//		chunks.push_back(str.substr(st, str.size()));
//
//		ans += chunks[0];
//		for (int i = 1; i < chunks.size(); i++)
//		{
//			chunks[i][0] = toupper(chunks[i][0]); // �빮�ڷ�
//			ans += chunks[i];
//		}
//		
//	}
//	// �� �� => ����
//	else
//	{
//		cout << "Error!";
//		return 0;
//	}
//
//	if (ans != "")
//		cout << ans;
//	else
//		cout << "Error!";
//
//	return 0;
//}
//
///*
////�� �� ���ڰ� '_' �̸� ���� -> c++ ����
//asd_
//Error!
//
////�� �� ���ڰ� '_' �̸� ���� -> C++ ����
//_asd
//Error!
//
////'_' ���� �ΰ��� ���� -> C++ ����
//as__asd
//Error!
//
////�� �� ���ڰ� �빮�ڸ� ���� -> C++ , java ����
//Aasd
//Error!
//
////�빮�ڿ� '_'�� ȥ���̸� ���� -> C++, java ����
//asdAasd_asd
//Error!
//
////�ҹ��ڸ� �Է� �� ��� ���� -> �ܾ� 1�� ��� (c++, java ���)
//fadfadfadsf
//fadfadfadsf
//
//// �빮�� ������ ��� ���� -> java���� �� �빮�� �ϳ��� �ܾ� 1�� ���
//asdasdASDASD
//asdasd_a_s_d_a_s_d
//*/