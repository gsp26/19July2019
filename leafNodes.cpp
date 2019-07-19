// C++ program to print the nodes of binary 
// tree as they become the leaf node 

#include <bits/stdc++.h> 
using namespace std; 

// Binary tree node 
struct Node { 
	int data; 
	int order; 
	struct Node* left; 
	struct Node* right; 
}; 

// Utiltiy function to allocate a new node 
struct Node* newNode(int data, int order) 
{ 
	struct Node* node = new Node; 
	node->data = data; 
	node->order = order; 
	node->left = NULL; 
	node->right = NULL; 

	return (node); 
} 

// Function for postorder traversal of tree and 
// assigning values to nodes 
void Postorder(struct Node* node, vector<pair<int, int> >& v) 
{ 
	if (node == NULL) 
		return; 

	/* first recur on left child */
	Postorder(node->left, v); 

	/* now recur on right child */
	Postorder(node->right, v); 

	// If current node is leaf node, it's order will be 1 
	if (node->right == NULL && node->left == NULL) { 
		node->order = 1; 

		// make pair of assigned value and tree value 
		v.push_back(make_pair(node->order, node->data)); 
	} 
	else { 
		// otherwise, the order will be: 
		// max(left_child_order, right_child_order) + 1 
		node->order = max((node->left)->order, (node->right)->order) + 1; 

		// make pair of assigned value and tree value 
		v.push_back(make_pair(node->order, node->data)); 
	} 
} 

// Function to print leaf nodes in 
// the given order 
void printLeafNodes(int n, vector<pair<int, int> >& v) 
{ 
	// Sort the vector in increasing order of 
	// assigned node values 
	sort(v.begin(), v.end()); 

	for (int i = 0; i < n; i++) { 
		if (v[i].first == v[i + 1].first) 
			cout << v[i].second << " "; 

		else
			cout << v[i].second << "\n"; 
	} 
} 

// Driver Code 
int main() 
{ 
	struct Node* root = newNode(8, 0); 
	root->left = newNode(3, 0); 
	root->right = newNode(10, 0); 
	root->left->left = newNode(1, 0); 
	root->left->right = newNode(6, 0); 
	root->right->left = newNode(14, 0); 
	root->right->right = newNode(4, 0); 
	root->left->left->left = newNode(7, 0); 
	root->left->left->right = newNode(13, 0); 

	int n = 9; 

	vector<pair<int, int> > v; 

	Postorder(root, v); 
	printLeafNodes(n, v); 

	return 0; 
} 
