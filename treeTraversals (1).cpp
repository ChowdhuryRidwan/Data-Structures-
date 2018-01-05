#include<iostream>
#include<math.h>
#define MAX(a,b) a>b ?a:b

using namespace std;

struct node
{
	char data;
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
	if(!root->left && !root->right)
		return 1;
	int lheight=height(root->left);
	int rheight=height(root->right);
	return MAX(lheight,rheight)+1;
}

void printTreeLevel(node* root)
{
	int h=height(root);
	for(int i=1; i<=h; i++)
	{
		cout <<"\nLevel"<<i<<": ";
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
		cout <<node->data;
	}
	printTreeLevelRec(node->left,desired-1);
	printTreeLevelRec(node->right,desired-1);
}
void preorder(node* root)
{
	if(root==NULL)
		return;
	else
	{
		cout <<root->data<<" ";
		//cout <<"root->left "<<root->left->data<<endl;
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(node* root)
{
	if(root==NULL)
		return;
	else
	{
		inorder(root->left);
		cout <<root->data<<" ";
		inorder(root->right);
	}
}

void postorder(node* root)
{
	if(root==NULL)
		return;
	else
	{
		postorder(root->left);
		postorder(root->right);
		cout <<root->data<<" ";
	}
}

void Insert(node *&root,char data)
{
	if(root==NULL)
	{
		
		node *temp=new node();
		temp->data=data;
		temp->left=NULL;
		temp->right=NULL;
		root=temp;
		//cout<<data<<endl<<root->data<<endl;
	}
	else if(data<=root->data)
	{
		Insert(root->left,data);
	}
	else if(data>root->data)
	{
		Insert(root->right,data);
	}
	//cout << root->data<<endl;
	
}

int main()
{
	node* root=NULL;
	Insert(root,'M');
	cout<<"root data is "<<root->data<<endl;
	Insert(root,'B');
	Insert(root,'Q');
	Insert(root,'Z');
	Insert(root,'A');
	Insert(root,'C');
	cout <<"Pre Order list is: ";
	preorder(root);
	cout <<"\nInorder list is: ";
	inorder(root);
	cout <<"\nPost Order list is: ";
	postorder(root);
	printTreeLevel(root);
	return 0;
}

