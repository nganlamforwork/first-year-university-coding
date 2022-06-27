#include <iostream>
#include <queue>
using namespace std;
struct Node {
	int key;
	Node* left = nullptr;
	Node* right = nullptr;
};
Node* createNode(int data)
{
	Node* p = new Node;
	p->key = data;
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
	if (root == nullptr)
		return;
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
	if (root == nullptr)
		return;
	LRN(root->left);
	LRN(root->right);
	cout << root->key << ' ';
}
void LevelOrder(Node* root)
{
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node* front = q.front();
		q.pop();
		cout << front->key << ' ';
		q.push(front->left);
		q.push(front->right);
	}
}
int Height(Node* root)
{
	if (root == nullptr)
		return 0;
	int h = 0;
	h = max(Height(root->left), Height(root->right)) + 1;
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
//Node* Search(Node* root, int x)
//{
//	if (root == nullptr)
//		return nullptr;
//	if (root->key == x)
//		return root;
//	Node* p = Search(root->left, x);
//	if (!p) return p;
//	p = Search(root->right, x);
//	if (!p) return p;
//	return nullptr;
//}
int main()
{

}