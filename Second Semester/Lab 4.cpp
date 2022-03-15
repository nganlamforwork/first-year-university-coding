#include <iostream>

using namespace std;
struct NODE{
    int key;
    NODE* p_next;
};
struct List{
    NODE* p_head;
    NODE* p_tail;
};
NODE* createNode(int data)
{
    NODE * tmp = new NODE;
    tmp->key = data;
    tmp->p_next = nullptr;
    return tmp;
}
void addHead(NODE* &pHead, int data)
{
    NODE * tmp = createNode(data);
    if (pHead == nullptr)
        pHead = tmp;
    else{
        tmp->p_next = pHead;
        pHead = tmp;
    }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
