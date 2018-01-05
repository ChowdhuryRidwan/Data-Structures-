#include <iostream>
#include<math.h>
#define MAX(a,b) (a>b) ?a:b

using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

void printTreeLevelRec(node* node,int desired);

int height(node* root)
{
	if(root==NULL)
	{
		return 0;
	}
//	if(!root->left && !root->right)
//		return 1;
	int lheight=height(root->left);
	int rheight=height(root->right);
	if(lheight > rheight)
	{
//		cout <<"LHeight: "<<lheight<<" RHeight "<<rheight<< " Height: "<< lheight +1<<"  "<<root->data<<endl;
		return (lheight+1);
	}
	else
	{
//		cout <<"LHeight: "<<lheight<<" RHeight "<<rheight<< " Height: "<< rheight +1<<"  "<<root->data<<endl;
		return (rheight+1);
	}
	//return (MAX(lheight,rheight)+1);
}

void printTreeLevel(node* root)
{
	int h=height(root);
	for(int i=1; i<=h; i++)
	{
		cout <<"\nLevel "<<i<<": ";
		printTreeLevelRec(root,i);
		cout <<endl;
	}
}

void printTreeLevelRec(node* node,int desired)
{
	if(node==NULL)
	{
		return;
	}
	if(desired==1)
	{
		cout <<node->data<<" ";
	}
	printTreeLevelRec(node->left,desired-1);
	printTreeLevelRec(node->right,desired-1);
}

int findMin(node* root)
{
	if(root==NULL)
	{
		cout <<"Error!!!"<<endl;
	}
	node* current=root;
	while(current->left!=NULL)
	{
		current=current->left;
	}
	return (current->data);
}

int findMax(node* root)
{
	if(root==NULL)
	{
		cout <<"Error!!!"<<endl;
	}
	node* current=root;
	while(current->right!=NULL)
	{
		current=current->right;
	}
	return (current->data);
}

node* GetNewNode(node* root, int data)
{
	node* newNode=new node();
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

node* Insert(node* root,int data)
{
	if(root==NULL)
	{
		root=GetNewNode(root, data);
	}
	else if(data<=root->data)
	{
		root->left=Insert(root->left,data);
	}
	else
	{
		root->right=Insert(root->right,data);
	}
	return root;
}

node* findMinNode(node* root)
{
    if(root==NULL)
        return root;
    else
    {
        node* current=root;
        while(current->left!=NULL)
        {
            current=current->left;
        }
        return current;
    }
}

node* del(node* root,int x)
{
	node* temp = new node();	//changed
    if(root==NULL)
        return root;
    else if(x<root->data)
    {
         root->left=del(root->left,x);
    }
    else if(x>root->data)
    {
        root->right=del(root->right,x);
    }
    else if(x==root->data)
    {
        //one child and no other
        if(root->left==NULL)
        {
            temp=root->right;
           // root->data=temp->data;//they r doing root=temp, doesnt the links get disrupted then???
            //delete temp;
            delete root;
            return temp;
        }
        else if(root->right==NULL)	//changed, you have written "=" instead of "=="
        {
            temp=root->left;
          //  root->data=temp->data;
            //delete temp;
            delete root;
            return temp;
        }
        //two child case
        else if(root->left!=NULL && root->right!=NULL)
        {
            temp=findMinNode(root->right);
            cout<<"Temp data "<<temp->data<<endl;
            root->data=temp->data;
            root->right=del(root->right,temp->data);
        }
    }
    return root;
}

int main()
{
	node* root=NULL;
	root=Insert(root,20);
	root=Insert(root,28);
	root=Insert(root,23);
	root=Insert(root,16);
	root=Insert(root,19);
	root=Insert(root,22);
	root=Insert(root,24);
	root=Insert(root,14);
	root=Insert(root,17);
	root=Insert(root,18);
    root=Insert(root,15);
    root=Insert(root,10);
    cout<<height(root)<<endl;
	cout <<"The minimum term in the tree is: "<<findMin(root)<<endl;
	cout <<"The maximum term in the tree is: "<<findMax(root)<<endl;
	printTreeLevel(root);
	int x;
	cout <<"Enter a number that you want to delete from the tree: ";
	cin >>x;
	root=del(root,x);
	cout <<"The new tree in level order traversal: "<<endl;
	printTreeLevel(root);
	return 0;
}
