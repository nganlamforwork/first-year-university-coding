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
	if (root == nullptr)
		return 0;
	int h = 0;
	h = max(height(root->left), height(root->right)) + 1;
	return h;
}
int countNode(Node* root)
{
	if (root == nullptr)
		return 0;
	int cnt = 1;
	cnt += countNode(root->left);
	cnt += countNode(root->right);
	return cnt;
}
int sumNode(Node* root)
{
	if (root == nullptr)
		return 0;
	int sum = root->key;
	sum += sumNode(root->left);
	sum += sumNode(root->right);
	return sum;
}
Node* search(Node* root, int x)
{
	if (root == nullptr)
		return nullptr;
	if (root->key == x)
		return root;
	if (root->key < x)
		return search(root->right, x);
	return search(root->left, x);
}
Node* createTree(int a[], int n)
{
	Node* root = new Node;
	for (int i = 0; i < n; i++) 
		insert(root, a[i]);
	return root;
}
void removeTree(Node* &root)
{
	if (root == nullptr) return;
	removeTree(root->left);
	removeTree(root->right);
	delete root;
}
int heightNode(Node* root, int val, int& h)
{
	if (root == nullptr) return -1;
	int leftHeight = heightNode(root->left, val, h);
	int rightHeight = heightNode(root->right, val, h);
	int ans = max(leftHeight, rightHeight) + 1;
	if (root->key == val)
		h = ans;
	return ans;
}
int level(Node* root, Node* p)
{
	if (root == nullptr) return -1;
	int ans = -1;
	if ((root == p) ||
		 (ans = level(root->left, p))>=0 ||
		 (ans = level(root->right,p))>=0) {
		return ans + 1;
	}
	return ans;
}
int countLeaf(Node* root)
{
	if (root == nullptr) return 0;
	if (root->left == nullptr && root->right == nullptr) return 1;
	int ans = 0;
	ans += countLeaf(root->right);
	ans += countLeaf(root->left);
	return ans;
}
int countLess(Node* root, int x)
{
	if (root == nullptr) return 0;
	if (root->key >= x) return countLess(root->left, x);
	return countLess(root->right, x);
}
Node* findMin(Node* root)
{
	if (root->left == nullptr)
		return root;
	return findMin(root->left);
}
void remove(Node* &root, int x)
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

}