#include <iostream>
#include <cstdio>
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
Node* createTree(int a[], int n)
{
	Node* root = nullptr;
	for (int i = 0; i < n; i++) {
		int tmp = a[i];
		insert(root, a[i]);
	}
	return root;
}
int countLessChild(Node* root, int x, int& res)
{
	if (root == nullptr) return 0;
	int ans = 0;
	ans += countLessChild(root->left, x, res);
	ans += countLessChild(root->right, x, res);
	if (ans < x) {
		cout << root->key << '\n';
		res++;
	}
	return ans+1;
}
bool checkSameShape(Node* root1, Node* root2)
{
	if (root1 == nullptr && root2 == nullptr) return 1;
	if (root1 == nullptr || root2 == nullptr) return 0;
	return checkSameShape(root1->left, root2->left) && checkSameShape(root1->right, root2->right);
}
int main()
{
	int res = 0;
	int a[] = { 1,2,34,32,43,4 };
	int b[] = { 1,2,34,32,43 };
	int n1 = 6, n2 = 5;
	Node* root1 = createTree(a, n1);
	Node* root2 = createTree(b, n2);
	cout << checkSameShape(root1, root2);
}