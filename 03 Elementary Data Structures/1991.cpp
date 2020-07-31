#include <iostream>
using namespace std;

struct node {
	char val;
	node *left, *right;
};

int N;
node* tree;

void preorder(int idx);
void inorder(int idx);
void postorder(int idx);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	cin.get();

	tree = new node[N];
	for (int i = 0; i < N; i++)
		tree[i].left = tree[i].right = NULL;

	char name, lc, rc;
	while (N--) {
		cin >> name >> lc >> rc;

		tree[name - 'A'].val = name;
		if(lc != '.')
			tree[name - 'A'].left = tree + (lc - 'A');
		if(rc != '.')
			tree[name - 'A'].right = tree + (rc - 'A');
	}

	preorder(0); cout << endl;
	inorder(0); cout << endl;
	postorder(0); cout << endl;

	return 0;
}

void preorder(int idx) {
	cout << tree[idx].val;
	if (tree[idx].left) preorder(tree[idx].left->val - 'A');
	if (tree[idx].right) preorder(tree[idx].right->val - 'A');
}

void inorder(int idx) {
	if (tree[idx].left) inorder(tree[idx].left->val - 'A');
	cout << tree[idx].val;
	if (tree[idx].right) inorder(tree[idx].right->val - 'A');
}

void postorder(int idx) {
	if (tree[idx].left) postorder(tree[idx].left->val - 'A');
	if (tree[idx].right) postorder(tree[idx].right->val - 'A');
	cout << tree[idx].val;
}