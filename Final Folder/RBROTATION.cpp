/** C++ implementation for 
Red-Black Tree Insertion 
This code is adopted from 
the code provided by 
Dinesh Khandelwal in comments **/
#include <bits/stdc++.h> 
using namespace std; 

enum Color {RED, BLACK}; 

struct Node 
{ 
	int data; 
	bool color; 
	Node *left, *right, *parent; 

	// Constructor 
	Node(int data) 
	{ 
	this->data = data; 
	left = right = parent = NULL; 
	this->color = RED; 
	} 
}; 

// Class to represent Red-Black Tree 
class RBTree 
{ 
private: 
	Node *root; 
protected: 
	void rotateLeft(Node *&, Node *&); 
	void rotateRight(Node *&, Node *&); 
	void fixViolation(Node *&, Node *&); 
public: 
	// Constructor 
	RBTree() { root = NULL; } 
	void insert(const int &n); 
	void inorder(); 
	void levelOrder(); 
}; 

// A recursive function to do inorder traversal 
void inorderHelper(Node *root) 
{ 
	if (root == NULL) 
		return; 

	inorderHelper(root->left); 
	cout << root->data << " "; 
	inorderHelper(root->right); 
} 

/* A utility function to insert 
	a new node with given key 
in BST */
Node* BSTInsert(Node* root, Node *pt) 
{ 
	/* If the tree is empty, return a new node */
	if (root == NULL) 
	return pt; 

	/* Otherwise, recur down the tree */
	if (pt->data < root->data) 
	{ 
		root->left = BSTInsert(root->left, pt); 
		root->left->parent = root; 
	} 
	else if (pt->data > root->data) 
	{ 
		root->right = BSTInsert(root->right, pt); 
		root->right->parent = root; 
	} 

	/* return the (unchanged) node pointer */
	return root; 
} 

// Utility function to do level order traversal 
void levelOrderHelper(Node *root) 
{ 
	if (root == NULL) 
		return; 

	std::queue<Node *> q; 
	q.push(root); 

	while (!q.empty()) 
	{ 
		Node *temp = q.front(); 
		cout << temp->data << " "; 
		q.pop(); 

		if (temp->left != NULL) 
			q.push(temp->left); 

		if (temp->right != NULL) 
			q.push(temp->right); 
	} 
} 

void RBTree::rotateLeft(Node *&root, Node *&Current_Node) 
{ 
    // Get the right child of the cuurent node 
	Node *Right_Child = Current_Node->right; 
    // Set the new right child of the current node to the left child of Right_Child
     // 
     //   x 
     //  / \
     // a   z
     //    / \
     //    b  g 
     //
     // For example, in the diagram above x's right child now becomes b 
     
     // Set Right_Child's left to current nodes right child, if null that's fine
	Current_Node->right = Right_Child->left; 

     // This action makes sure to cuurent as parent of Right_Child's left node (b)
	if (Current_Node->right != NULL) 
		Current_Node->right->parent = Current_Node; 

     // set both the RightChild and current pointer as siblings (z and x)  
	Right_Child->parent = Current_Node->parent; 
 
    // If they point to nothing do the actual rotation and make Right the root (z becomes root) 
	if (Current_Node->parent == NULL) 
		root = Right_Child; 
     // Or if one layer down then just make RIGHTChild the left child of parent  
       // (meaning z takes x's place) 
	else if (Current_Node == Current_Node->parent->left) 
		Current_Node->parent->left = Right_Child; 
      // If those are both not true then  make RIGHTChild the right child of parent  
	else
		Current_Node->parent->right = Right_Child; 

     // After that set the current pointer to be the left child of the RIGHTCHILD 
     // (make x have parent of Z) 
	Right_Child->left = Current_Node; 
	Current_Node->parent = Right_Child; 
} 

void RBTree::rotateRight(Node *&root, Node *&pt) 
{ 
	Node *pt_left = pt->left; 

	pt->left = pt_left->right; 

	if (pt->left != NULL) 
		pt->left->parent = pt; 

	pt_left->parent = pt->parent; 

	if (pt->parent == NULL) 
		root = pt_left; 

	else if (pt == pt->parent->left) 
		pt->parent->left = pt_left; 

	else
		pt->parent->right = pt_left; 

	pt_left->right = pt; 
	pt->parent = pt_left; 
} 

// This function fixes violations 
// caused by BST insertion 
void RBTree::fixViolation(Node *&root, Node *&pt) 
{ 
	Node *parent_pt = NULL; 
	Node *grand_parent_pt = NULL; 

	while ((pt != root) && (pt->color != BLACK) && 
		(pt->parent->color == RED)) 
	{ 

		parent_pt = pt->parent; 
		grand_parent_pt = pt->parent->parent; 

		/* Case : A 
			Parent of pt is left child 
			of Grand-parent of pt */
		if (parent_pt == grand_parent_pt->left) 
		{ 

			Node *uncle_pt = grand_parent_pt->right; 

			/* Case : 1 
			The uncle of pt is also red 
			Only Recoloring required */
			if (uncle_pt != NULL && uncle_pt->color == 
												RED) 
			{ 
				grand_parent_pt->color = RED; 
				parent_pt->color = BLACK; 
				uncle_pt->color = BLACK; 
				pt = grand_parent_pt; 
			} 

			else
			{ 
				/* Case : 2 
				pt is right child of its parent 
				Left-rotation required */
				if (pt == parent_pt->right) 
				{ 
					rotateLeft(root, parent_pt); 
					pt = parent_pt; 
					parent_pt = pt->parent; 
				} 

				/* Case : 3 
				pt is left child of its parent 
				Right-rotation required */
				rotateRight(root, grand_parent_pt); 
				swap(parent_pt->color, 
						grand_parent_pt->color); 
				pt = parent_pt; 
			} 
		} 

		/* Case : B 
		Parent of pt is right child 
		of Grand-parent of pt */
		else
		{ 
			Node *uncle_pt = grand_parent_pt->left; 

			/* Case : 1 
				The uncle of pt is also red 
				Only Recoloring required */
			if ((uncle_pt != NULL) && (uncle_pt->color == 
													RED)) 
			{ 
				grand_parent_pt->color = RED; 
				parent_pt->color = BLACK; 
				uncle_pt->color = BLACK; 
				pt = grand_parent_pt; 
			} 
			else
			{ 
				/* Case : 2 
				pt is left child of its parent 
				Right-rotation required */
				if (pt == parent_pt->left) 
				{ 
					rotateRight(root, parent_pt); 
					pt = parent_pt; 
					parent_pt = pt->parent; 
				} 

				/* Case : 3 
				pt is right child of its parent 
				Left-rotation required */
				rotateLeft(root, grand_parent_pt); 
				swap(parent_pt->color, 
						grand_parent_pt->color); 
				pt = parent_pt; 
			} 
		} 
	} 

	root->color = BLACK; 
} 

// Function to insert a new node with given data 
void RBTree::insert(const int &data) 
{ 
	Node *pt = new Node(data); 

	// Do a normal BST insert 
	root = BSTInsert(root, pt); 

	// fix Red Black Tree violations 
	fixViolation(root, pt); 
} 

// Function to do inorder and level order traversals 
void RBTree::inorder()	 { inorderHelper(root);} 
void RBTree::levelOrder() { levelOrderHelper(root); } 

// Driver Code 
int main() 
{ 
	RBTree tree; 

	tree.insert(7); 
	tree.insert(6); 
	tree.insert(5); 
	tree.insert(4); 
	tree.insert(3); 
	tree.insert(2); 
	tree.insert(1); 

	cout << "Inoder Traversal of Created Tree\n"; 
	tree.inorder(); 

	cout << "\n\nLevel Order Traversal of Created Tree\n"; 
	tree.levelOrder(); 

	return 0; 
} 

