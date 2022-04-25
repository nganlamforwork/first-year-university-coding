#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
void buildList(Node*&head)
{
	int n = 6;
	//int a[6] = {12,10,2,3,5,8};
	int a[6] = {1,3,6,3,1,5};
	for (int i = n-1; i >= 0; i--) {
		Node* tmp = new Node;
		tmp->data = a[i];
		tmp->next = nullptr;
		if (head == nullptr) head = tmp;
		else {
			tmp->next = head;
			head = tmp;
		}
	}
}
void deleteRightDuplicates(Node*&head)
{
    Node* p = head;
    Node* q = new Node;
    while (p!=nullptr && p->next!=nullptr){
        q = p;
        while (q!=nullptr && q->next!=nullptr){
            if (q->next->data == p->data){
                Node *tmp = q->next;
                q->next = tmp->next;
                delete tmp;
            }else q = q->next;
        }
        p = p->next;
    }

    //---------JUST FOR TESTING---------
    p = head;
    while (p != nullptr){
        cout<<p->data<<' ';
        p = p->next;
    }
    //------------END TESTING------------
}
int main()
{
	Node* head = new Node;
	head = nullptr;
	buildList(head);
	deleteRightDuplicates(head);
	return 0;
}
