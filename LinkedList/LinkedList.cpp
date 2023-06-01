//#include <iostream>
//using namespace std;
//
//const int MX = 1000005;
//int dat[MX], pre[MX], nxt[MX];
//int unused = 1;
//
//void insert(int addr, int num) 
//{
//    // 새로 추가한 노드 값 넣고
//    dat[unused] = num;
//    // prev 에 이전 위치 넣고
//    pre[unused] = addr;
//    // nxt 에 이전 노드가 가리키는 nxt[addr] 값 넣음
//    nxt[unused] = nxt[addr];
//
//
//    // 다음 노드의 pre 수정
//    if(nxt[addr] != -1) // 마지막 위치에 추가하려는 경우
//        pre[nxt[addr]] = unused;
//
//    // 이전 노드의 nxt 수정
//    nxt[addr] = unused;
//
//    unused++;
//}
//
//void erase(int addr)
//{
//    // 이전 노드의 nxt 를 지우려는 노드의 nxt로 수정
//    nxt[pre[addr]] = nxt[addr];
//    
//    // 다음 노드의 pre 를 지우려는 노드의 pre로 수정
//    if(nxt[addr] != -1)
//        pre[nxt[addr]] = pre[addr];
//}
//
//void traverse()
//{
//    int cur = nxt[0];
//    while (cur != -1) 
//    {
//        cout << dat[cur] << ' ';
//        cur = nxt[cur];
//    }
//    cout << "\n\n";
//}
//
//void insert_test() 
//{
//    cout << "****** insert_test *****\n";
//    insert(0, 10); // 10(address=1)
//    traverse();
//    insert(0, 30); // 30(address=2) 10
//    traverse();
//    insert(2, 40); // 30 40(address=3) 10
//    traverse();
//    insert(1, 20); // 30 40 10 20(address=4)
//    traverse();
//    insert(4, 70); // 30 40 10 20 70(address=5)
//    traverse();
//}
//
//void erase_test() 
//{
//    cout << "****** erase_test *****\n";
//    erase(1); // 30 40 20 70
//    traverse();
//    erase(2); // 40 20 70
//    traverse();
//    erase(4); // 40 70
//    traverse();
//    erase(5); // 40
//    traverse();
//}
//
//int main(void) 
//{
//    fill(pre, pre + MX, -1);
//    fill(nxt, nxt + MX, -1);
//    insert_test();
//
//    erase_test();
//
//    return 0;
//}