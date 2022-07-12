#include <iostream>
#include <queue>
using namespace std;
struct Node {
	int key = 0;
	Node* left = nullptr;
	Node* right = nullptr;
};
Node* createNode(int data)
{
	Node* p = new Node;
	p->key = data;
	return p;
}
void insert(Node*& root, int x)
{
	if (root == nullptr) {
		Node* p = createNode(x);
		root = p;
		return;
	}
	if (root->key < x)
		insert(root->right, x);
	else if (root->key > x)
		insert(root->left, x);
}
void NLR(Node* root)
{
	if (root == nullptr) return;
	cout << root->key << ' ';
	NLR(root->left);
	NLR(root->right);
}
void LNR(Node* root)
{
	if (root == nullptr)
		return;
	LNR(root->left);
	cout << root->key << ' ';
	LNR(root->right);
}
void LRN(Node* root)
{
	if (root == nullptr) return;
	LRN(root->left);
	LRN(root->right);
	cout << root->key << ' ';
}
int height(Node* root)
{
	if (root == nullptr)
		return 0;
	int h = 0;
	h = max(height(root->left), height(root->right)) + 1;
	return h;
}
Node* createTree(int a[], int n)
{
	Node* root = nullptr;
	for (int i = 0; i < n; i++) {
		int tmp = a[i];
		insert(root, a[i]);
	}
	return root;
}

Node* findMin(Node* root)
{
	if (root->left == nullptr)
		return root;
	return findMin(root->left);
}
void remove(Node*& root, int x)
{
	if (root == nullptr) return;

	if (root->key < x) remove(root->left, x);
	else if (root->key > x)remove(root->right, x);
	if (root->left == nullptr && root->right == nullptr) {
		root = nullptr;
		return;
	}
	if (root->left == nullptr) {
		Node* tmp = root;
		root = root->right;
		delete tmp;
		return;
	}
	if (root->right == nullptr) {
		Node* tmp = root;
		root = root->left;
		delete tmp;
		return;
	}
	//2 children
	Node* tmp = findMin(root->right);
	root->key = tmp->key;
	remove(root->right, tmp->key);
}
int main()
{
	int a[] = { 1,2,34,3,62 };
	int n = 5;
}