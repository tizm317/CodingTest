//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//// ���� ���� Ǯ��
//// ��¥		: 2023. 05. 19. ��.
//// ���� ��ȣ	: #9536 
//// ���� �̸�	: ����� ��� ����?
//// �˰���	: ���ڿ�
//// �ð����⵵: O()
//
//int T;
//vector<string> soundVec;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> T;
//	
//	cin.ignore(); // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//
//	for (int i = 0; i < T; i++)
//	{
//		// 1. ���� ���� �Ҹ�
//		string sound;
//		getline(cin, sound);
//		
//		// split ���
//		{
//			// " " �� �����ؼ�, �� �����Ҹ� string �� ���Ϳ� ����
//			int st = 0;
//			int pos = sound.find(" ");
//			while (pos != -1)
//			{
//				soundVec.push_back(sound.substr(st, pos - st));
//
//				st = pos + 1;
//				pos = sound.find(" ", st);
//			}
//
//			// ������ ���� ���Ϳ� ����
//			soundVec.push_back(sound.substr(st, sound.size()));
//		}
//
//		// 2. what does the fox say �Է¹��� ������ �ݺ�
//		// �� ������ ���� �Ҹ�
//		string s = "";
//		while (s != "what does the fox say?")
//		{
//			getline(cin, s);
//
//			// "<����> goes <�Ҹ�>" ���� �̹Ƿ�, �ι�° " " ��ġ�� ã���� �ȴ� (2�� find)
//			int pos = s.find(" ");
//			pos = s.find(" ", pos + 1);
//
//			// �����Ҹ� ����
//			string animalSound = s.substr(pos + 1, s.size());
//
//			// ���� ���� �Ҹ� ���� ��ȸ�ϸ鼭, ���� �� ����
//			for (auto it = soundVec.begin(); it != soundVec.end(); )
//			{
//				if (*it == animalSound)
//				{
//					// �����, ���� ��ġ��,
//					it = soundVec.erase(it);
//				}
//				else
//				{
//					it++;
//				}
//			}
//		}
//
//		// ���� �Ҹ��� ���� ���� �Ҹ��̹Ƿ�, ���� ��ȸ�ϸ鼭 ���
//		for (auto it = soundVec.begin(); it != soundVec.end(); it++)
//		{
//			cout << *it << " ";
//		}
//		cout << '\n';
//
//		// ���� ������, Ŭ����
//		soundVec.clear();
//	}
//
//
//	return 0;
//}