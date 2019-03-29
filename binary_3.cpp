#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node * left;
	node * right;
	node * parent;
//constuctor
	node(int value){
		data = value;
		left = NULL;
		right = NULL;
		parent = NULL;
		}
};
//class bst
class bst{
	public:
	node * root;
	bst(){
		root = NULL;
	}
//insert
	node * insert(int val){
		insert2(root, val);
	}
//insert2
	node * insert2(node * curr, int val){
		if(root ==NULL){
			root = new node(val);
		}
		else if (val < curr->data)  {

            	if (curr->left == NULL) {
                	curr->left = new node(val);
                	curr->left->parent = curr;
            	}
             //recursive call
            	else insert2(curr->left, val);
        	}
        	else {

            	if (curr->right == NULL) {
            	    	curr->right = new node(val);
                	curr->right->parent = curr;
            }

            else insert2(curr->right, val);
        }
	}
//display the data
	void display(){
		display2(root);
		cout<<endl;
	}
//displaying the data
	void display2(node * curr){
		if(curr == NULL)
			return;
		display2(curr->left);
		cout<<curr->data<<",";
		display2(curr->right);
	}
//search
	node * search(int val){
		search2(root,val);
	}
	node * search2(node * curr, int val){
		if(curr == NULL)
			return curr;
		else if(curr->data == val)
			return curr;
		else if(val >= curr->data)
			search2(curr->right,val);
		else
			search2(curr->left, val);
	}
// minimum of subtree
	node * find_min(node * parent){
		node * curr = parent;
		while(curr->left != NULL){
			curr = curr->left;
		}
		return curr;
	}
	//height function
	int height(node * curr){
		if(curr == NULL )
			return -1;
		else
    	{
        /* compute the height of each subtree */
        int lh = height(curr->left);
        int rh = height(curr->right);

        /* use the larger one */
        if (lh > rh)
            return(lh + 1);
        else return(rh + 1);
    	}
	}
	//count function
	int count(node * curr){
		if(curr == NULL)
				return 0;
			else
				return count(curr->left) + 1 + count(curr->right);
	}
	int rangeSearch(node*current,int k1,int k2){
			if (current==NULL) return 0;
			if (current->data == k2 && current->data == k1){
				cout<<current->data<<","<<endl;
				return 1;
			}
			if (current->data <= k2 && current->data >= k1){
				//print the data
				cout<<current->data<<",";
				//count the nodes
				return 1 + rangeSearch(current->left, k1, k2) + rangeSearch(current->right, k1, k2);
			}
			else if (current->data < k2){
				return rangeSearch(current->right, k1, k2);
			}
			else {
				cout<<endl;
				return rangeSearch(current->left, k1, k2);
			}
		}
};
int main(){
bst b1;
b1.insert(2);
b1.insert(8);
b1.insert(4);
b1.insert(12);
b1.insert(6);
b1.insert(20);
b1.insert(24);
b1.insert(16);
b1.insert(18);
b1.insert(10);
b1.insert(8);
b1.insert(4);
b1.insert(12);
b1.insert(60);
b1.insert(22);
b1.insert(24);
b1.insert(23);
b1.insert(18);
b1.insert(17);
b1.display();
cout<<"height in the tree are "<<b1.height(b1.root)<<endl;
cout<<"no. of elements in the tree is"<<b1.count(b1.root)<<endl;
cout<<"no of elements between the given range is "<<b1.rangeSearch(b1.root,4,11)<<endl;;
return 0;
}
