#include <iostream>
using namespace std;
class DST{
	struct Node  
	{ 
  		int key; 
  		struct Node *left; 
  		struct Node *right; 
  		Node(int k){
      			key=k;
      			left=right=NULL;
  		}
	};
	Node *root; 
	public:
	DST() {
    root = NULL; // Constructor to initialize root to NULL
  }
	Node *insert(Node *root, int x){
    		Node *temp=new Node(x);
    		Node *parent=NULL,*curr=root;
    		while(curr!=NULL){
           		parent=curr;
        		if(curr->key>x)
            		curr=curr->left;
        		else if(curr->key<x)
            		curr=curr->right;
        		else
            		return root;
    		}
    		if(parent==NULL)
        	return temp;
    		if(parent->key>x)
        	parent->left=temp;
    		else
        	parent->right=temp;
    		return root;
	} 

	void inorder(Node *root){
    		if(root!=NULL){
        	inorder(root->left);
        	cout<<root->key<<" ";
        	inorder(root->right);    
    		}
	} 
	bool search(Node *root, int x){
    		while(root!=NULL){
        		if(root->key==x)
            		return true;
        		else if(root->key<x)
            		root=root->right;
        		else
            		root=root->left;
    		}
    		return false;
	} 
	Node *getSuccessor(Node *curr){
    		curr=curr->right;
    		while(curr!=NULL && curr->left!=NULL)
        	curr=curr->left;
    		return curr;
	}

	Node *delNode(Node *root, int x){
    		if(root==NULL)
        	return root;
    		if(root->key>x)
        	root->left=delNode(root->left,x);
    		else if(root->key<x)
        	root->right=delNode(root->right,x);
    		else{
        	if(root->left==NULL){
        	    Node *temp=root->right;
        	    delete root;
        	    return temp;
        	}
        	else if(root->right==NULL){
        	    Node *temp=root->left;
        	    delete root;
        	    return temp;
        	}
        	else{
        	    Node *succ=getSuccessor(root);
        	    root->key=succ->key;
        	    root->right=delNode(root->right,succ->key);
        	}
    		}
    		return root;
	} 
  int main() {
   
    while (true) {
      int choice, element;
      cout << "Binary Tree Operations Menu:\n";
      cout << "1. Insert an element\n";
      cout << "2. Delete an element\n";
      cout << "3. Display the tree\n";
      cout << "4. Search an element\n";
      cout << "5. Exit\n";
      cout << "Enter your choice: ";
      cin >> choice;

      switch (choice) {

      case 1: {
        cout << "Enter the element to insert: ";
        cin >> element;
        insert(root, element);
        break;
      }

      case 2:
        cout << "Enter the element to delete: ";
        cin >> element;
        root = delNode(root, element);
        break;

      case 3:
        cout << "Binary Tree Inorder Traversal: ";
        inorder(root);
        break;

      case 4:
        cout << "Enter the element to search:";
        cin >> element;
        if (search(root, element))
          cout << "Found";
        else
          cout << "Not Found";
        break;

      case 5:
        return 0;
        break;

      default:
        cout << "Invalid choice. Please try again.\n";
      }
    }

    return 0;
  }
};
int main() {
  DST dst; // Create an instance of the DST class
  return dst.main(); // Call the main function within the class
}


