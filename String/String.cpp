//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//// string s �� sep �� �и�
//// ���� : sep �� 1���� �̻�.
//
//vector<string> split(string& s, string& sep)
//{
//	vector<string> ret;
//
//	//int pos = 0;
//	//while (pos < s.size())
//	//{
//	//	int nextPos = s.find(sep, pos);
//
//	//	// ���� ����
//	//	if (nextPos == -1)
//	//		nextPos = s.size();
//	//	
//	//	ret.push_back(s.substr(pos, nextPos - pos));
//
//	//	pos = nextPos + sep.size();
//	//}
//
//	// 2. find �Լ� Ȱ��
//	//for (int st = 0; st < s.size();)
//	//{
//	//	int pos = s.find(sep, st); // at st or after st
//	//	int wordSize = pos - st;
//
//	//	// ���� ������ ���
//	//	if (pos == -1)
//	//	{
//	//		wordSize = s.size() - st;
//	//	}
//
//	//	string sub = s.substr(st, wordSize);
//
//	//	if (sub != "")
//	//	{
//	//		ret.push_back(sub);
//	//	}
//
//	//	st += (wordSize + sep.size());
//	//}
//	//
//
//	// 1. substr Ȱ��
//	// ������, ũ�Ⱑ �ʿ���
//	/*
//	int st = 0;
//
//	for (int i = 0; i < s.size(); i++)
//	{
//		// ù���ڰ� ���� ������ pass
//		if (s[i] != sep[0])
//			continue;
//
//		// last �� �� �� �ִ� �ĺ�
//		int last = i;
//
//		// sep�� ��� ���ڶ� ������ üũ
//		bool success = true;
//		for (int j = 1; j < sep.size(); j++)
//		{
//			if (s[i + j] != sep[j])
//			{
//				success = false;
//				break;
//			}
//		}
//
//		if (success)
//		{
//			// last - st ==  size
//			int subSize = last - st;
//			if(subSize > 0) // "" ����
//				ret.push_back(s.substr(st, subSize));
//
//			// ������ �Ű���
//			st = i + sep.size();
//		}
//	}
//
//	// ������ ���� �߰�
//	int subSize = s.size() - st;
//	if (subSize > 0)
//		ret.push_back(s.substr(st, s.size()));
//
//	*/
//
//	return ret;
//}
//
//int main()
//{
//	// String ����
//	string s = "Hello";
//	s += " BKD!"; // Hello BKD!
//	cout << s.size() << '\n'; // 10
//	cout << s.substr(2, 3) << '\n'; // llo , [2, 2+3) , 2��°���� 3����
//	cout << s[4] << '\n'; // o
//	
//	s.replace(6, 4, "guys"); // Hello guys
//	cout << s << '\n';
//	
//	int it = s.find("guys");
//	s.replace(it, 4, "everyone"); // Hello everyone
//	cout << s << '\n';
//	
//	s.erase(7, 6); // Hello ee
//	cout << s << '\n';
//	
//	s[6] = 'm'; // Hello me
//	cout << s << '\n';
//	
//	s.insert(0, "Say "); // Say Hello me
//	cout << s << '\n';
//
//	if (s.find("to") == string::npos) // npos == -1
//		cout << "'to' is not in string 's'\n";
//	cout << '\n';
//
//	// Split �Լ�
//
//	string s1 = "welcome to the black parade"; // welcome/to/the/black/parade/
//	string sep1 = " ";
//	vector<string> chunks1 = split(s1, sep1);
//	for (auto chunk : chunks1)
//		cout << chunk << '/';
//	cout << '\n';
//
//	string s2 = "b*!*ac*!**!*e*!*y*!*"; // b/ac//e/y// -> b/ac/e/y/
//	string sep2 = "*!*";
//	vector<string> chunks2 = split(s2, sep2);
//	for (auto chunk : chunks2)
//		cout << chunk << '/';
//	cout << '\n';
//
//	return 0;
//}
//
