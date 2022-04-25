#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
struct List {
	Node* head;
};
int Count(List ls)
{
	int ans = 0;
	Node* p = ls.head;
	Node* mid = new Node, *pre = new Node, *next = new Node;
	while (p != nullptr && p->next != nullptr) {
		mid = p->next;
		if (mid->next == nullptr) break;
		else next = mid->next;
		pre = p;
		if (mid->data == abs(pre->data - next->data)) ans++;
		p = p->next;
	}
	return ans;
}
void buildList(List &ls)
{
	int n = 6;
	//int a[6] = {12,10,2,3,5,8};
	int a[6] = {8,11,14,17,20,23};
	for (int i = n-1; i >= 0; i--) {
		Node* tmp = new Node;
		tmp->data = a[i];
		tmp->next = nullptr;
		if (ls.head == nullptr) ls.head = tmp;
		else {
			tmp->next = ls.head;
			ls.head = tmp;
		}
	}
}
bool checkIncrease(Node* h)
{
	if (h == nullptr || h->next == nullptr) return 1;
	if (h->data > h->next->data) return 0;
	return checkIncrease(h->next);
}
int main()
{
	List ls;
	ls.head = nullptr;
	buildList(ls);
	if (checkIncrease(ls.head)) cout << "True";
	else cout << "False";
	return 0;
}