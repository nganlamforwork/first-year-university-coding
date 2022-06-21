#include <iostream>
using namespace std;
struct Node{
	int key;
	Node* left = nullptr;
	Node* right = nullptr;
};
Node* createNode(int data){
	Node* p = new Node;
	p->key = data;
}
int main()
{

}