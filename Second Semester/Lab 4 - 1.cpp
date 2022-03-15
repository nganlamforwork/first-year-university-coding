#include <iostream>

using namespace std;
struct Node{
    int key;
    Node* p_next;
};
struct List{
    Node* p_head;
    Node* p_tail;
};
Node* createNode(int data)
{
    Node * tmp = new Node;
    tmp->key = data;
    tmp->p_next = nullptr;
    return tmp;
}
void addHead(Node* &pHead, int data)
{
    Node * tmp = createNode(data);
    if (pHead == nullptr)
        pHead = tmp;
    else{
        tmp->p_next = pHead;
        pHead = tmp;
    }
}
void addTail(Node* &pHead, int data)
{
    Node *tmp, *p;
    tmp = createNode(data);
    if (pHead == nullptr)
        pHead = tmp;
    else {
        p = pHead;
        while (p->p_next != nullptr)
            p = p->p_next;
        p->p_next = tmp;
    }
}
void removeHead(Node* &pHead)
{
    if (pHead == nullptr) return;
    pHead = pHead->p_next;
}
void removeTail(Node* &pHead)
{
    if (pHead == nullptr) return;
    if (pHead->p_next == nullptr) return removeHead(pHead);
    Node *p = pHead;
    while (p->p_next->p_next != nullptr) //back-1
        p = p->p_next;
    p->p_next = nullptr;
}
 void removeAll(Node* &pHead)
{
    pHead->p_next=nullptr;
}
bool addPos(Node* &pHead, int data, int pos)
{
    if (pos == 0 || pHead == nullptr){
        pHead = addHead(pHead,data);
        return 1;
    }

    int i = 0;
    Node* p = pHead;
    while (p!=nullptr && i!=pos-1){
        p=p->p_next;
        ++i;
    }

    if (i!=pos-1) return 0;

    Node *tmp = createNode(data);
    tmp->p_next = p->p_next;
    p->p_next = tmp;
    return 1;
}
void RemovePos(Node* &pHead, int pos)
{
    if (pos == 0 || pHead == nullptr)
        removeHead(pHead);

    int i = 0;
    Node* p = pHead;
    while (p->p_next->p_next!=nullptr && i!=pos-1){
        p = p->p_next;
        ++i;
    }

    if (i!=pos-1) return; //Not found

    p->p_next = p->p_next->p_next;
}
void printList(Node* &pHead)
{
    Node *p=pHead;
    while (p!=nullptr){
        cout<<p->key<<' ';
        p=p->p_next;
    }
}
int countElements(Node* &pHead)
{
    Node *p = pHead;
    int cnt=0;
    while (p!=nullptr){
        cnt++;
        p=p->p_next;
    }
    return cnt;
}
int countAppearance(Node* &pHead, int value)
{
    Node *p = pHead;
    int cnt=0;
    while (p!=nullptr){
        cnt+=p->key;
        p=p->p_next;
    }
    return cnt;
}
Node* reverseList(Node* &pHead)
{

}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
