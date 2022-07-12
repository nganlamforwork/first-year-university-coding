#include <iostream>
#include <queue>
using namespace std;
struct Node {
	int key;
	Node* left;
	Node* right;
	int height;
};
Node* createNode(int data)
{
	Node* p = new Node;
	p->key = data;
	p->left = nullptr;
	p->right = nullptr;
	p->height = 1;
	return p;
}
int height(Node* root)
{
	if (root == nullptr) return 0;
	return root->height;
}

int getBalance(Node* root)
{
	if (root == nullptr) return 0;
	return height(root->left) - height(root->right);
}

Node* rightRotate(Node* y)
{
	Node* x = y->left;
	Node* T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return x;
}

Node* leftRotate(Node* x)
{
	Node* y = x->right;
	Node* T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	return y;
}

Node* insert(Node* root, int key)
{
	if (root == nullptr) return createNode(key);
	if (key < root->key)
		root->left = insert(root->left, key);
	else if (key > root->key)
		root->right = insert(root->right, key);
	else
		return root;

	root->height = 1 + max(height(root->left), height(root->right));

	int balance = getBalance(root);

	// Left-left Case
	if (balance > 1 && key < root->left->key)
		return rightRotate(root);

	// Right-right Case
	if (balance < -1 && key > root->right->key)
		return leftRotate(root);

	// Left-right Case
	if (balance > 1 && key > root->left->key) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right-left Case
	if (balance < -1 && key < root->right->key) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void NLR(Node* root)
{
	if (root != nullptr) {
		cout << root->key << ' ';
		NLR(root->left);
		NLR(root->right);
	}
}

Node* createAVLTree(int a[], int n)
{
	Node* root = nullptr;
	for (int i = 0; i < n; i++)
		root = insert(root, a[i]);
	return root;
}
int main()
{
	int a[] = { 10, 20, 30, 40, 50, 25 };
	int n = 6;
	Node* root = createAVLTree(a, n);
	NLR(root);
	return 0;
}