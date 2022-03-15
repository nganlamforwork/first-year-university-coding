#include <iostream>
#include <ctime>
using namespace std;
struct Node{
    int key;
    Node* p_next;
};
struct List{
    Node* p_head = nullptr;
    //Node* p_tail = nullptr;
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
    Node *p = pHead;
    Node *tmp;
    while (p!=nullptr){
        tmp = p;
        p=p->p_next;
        delete tmp;
    }
    pHead = nullptr;
}
bool addPos(Node* &pHead, int data, int pos)
{
    if (pos == 0 || pHead == nullptr){
        addHead(pHead,data);
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
        cnt+=(p->key)==value;
        p=p->p_next;
    }
    return cnt;
}
List* reverseList(Node* &pHead)
{
    List *newList = new List;

    Node *p = pHead;
    while (p!=nullptr){
        addHead(newList->p_head,p->key);
        p=p->p_next;
    }

    return newList;
}
void removeDuplicate(Node* &pHead)
{
    Node *i, *j, *dup;
    i = pHead;
    while (i!=nullptr && i->p_next!=nullptr){
        j = i;
        while (j->p_next!=nullptr){
            if (i->key==j->p_next->key){
                dup=j->p_next;
                j->p_next=j->p_next->p_next;
                delete dup;
            }
            else
                j=j->p_next;
        }
        i=i->p_next;
    }
}
bool removeElement(Node* &pHead, int key)
{
    Node *i, *tmp;
    i=pHead;
    while (pHead!=nullptr && pHead->key == key){
        removeHead(pHead);
    }
    while (i!=nullptr && i->p_next!=nullptr){
        if (i->p_next->key == key){
            tmp=i->p_next;
            i->p_next=i->p_next->p_next;
            delete tmp;
        }
        else
            i=i->p_next; //tricky
    }
    return 0;
}
int main()
{
    List *listNumber = new List;

    srand(time(NULL));
    int n=rand()%20;
    for (int i=0;i<n;i++)
        addTail(listNumber->p_head,rand()%5);

    cout<<"Before: ";
    printList(listNumber->p_head);
    cout<<'\n';

    int m = rand()%5;
    cout<<"Remove: "<<m<<'\n';

    cout<<"After: ";
    removeElement(listNumber->p_head,m);
    printList(listNumber->p_head);

    return 0;
}
