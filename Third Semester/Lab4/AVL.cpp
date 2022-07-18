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

void levelOrder(Node* root)
{
	if (root == nullptr) return;
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node* front = q.front();
		q.pop();
		cout << front->key << ' ';
		if (front->left != nullptr) q.push(front->left);
		if (front->right != nullptr) q.push(front->right);
	}
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

Node* minValueNode(Node* root)
{
	Node* p = root;
	while (p->left != nullptr)
		p = p->left;
	return p;
}

Node* Remove(Node*& root, int x)
{
	if (root == nullptr)
		return root;
	
	if (x < root->key)
		root->left = Remove(root->left, x);
	else if (x > root->key)
		root->right = Remove(root->right, x);
	else {
		if ((root->left == nullptr) || (root->right == nullptr)) {
			Node* tmp = root->left ? root->left : root->right;
			if (tmp == nullptr) {
				tmp = root;
				root = nullptr;
			}
			else
				*root = *tmp;
			delete tmp;
		}
		else {
			Node* tmp = minValueNode(root->right);
			swap(root->key,tmp->key);
			root->right = Remove(root->right, x);
		}
	}
	if (root == nullptr) return root;

	root->height = 1 + max(height(root->left), height(root->right));
	int balance = getBalance(root);
	// Left Left Case
	if (balance > 1 &&
		getBalance(root->left) >= 0)
		return rightRotate(root);

	// Left Right Case
	if (balance > 1 && getBalance(root->left) < 0) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Right Case
	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	// Right Left Case
	if (balance < -1 && getBalance(root->right) > 0) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

bool isAVL(Node* root)
{
	if (root == nullptr) return 1;
	if (abs(getBalance(root)) > 1) return 0;
	return isAVL(root->right) && isAVL(root->left);
}

int main()
{
	int a[] = { 10, 20, 30, 40, 50, 25 };
	int n = 6;
	Node* root = createAVLTree(a, n);
	Remove(root, 20);
	levelOrder(root);
	return 0;
}