#include <iostream>

using namespace std;

struct tNode
{
   int data;
   tNode* left;
   tNode* right;
};


void MorrisTraversalinOrder(tNode *root)
{
  tNode *current,*pre;

  if(root == NULL)
     return;

  current = root;
  while(current != NULL)
  {
    if(current->left == NULL)
    {
      cout <<current->data<<" ";
      current = current->right;
    }
    else
    {
      /* Find the inorder predecessor of current */
      pre = current->left;
      while(pre->right != NULL && pre->right != current)
        pre = pre->right;

      /* Make current as right child of its inorder predecessor */
      if(pre->right == NULL)
      {
        pre->right = current;
        current = current->left;
      }

      /* Revert the changes made in if part to restore the original
        tree i.e., fix the right child of predecssor */
      else
      {
        pre->right = NULL;
        cout <<current->data<<" ";
        current = current->right;
      }
    }
  }
}


void MorrisTraversalPreOrder(tNode *root)
{
  tNode *current,*pre;

  if(root == NULL)
     return;

  current = root;
  while(current != NULL)
  {
    if(current->left == NULL)
    {
      cout <<current->data<<" ";
      current = current->right;
    }
    else
    {
      /* Find the inorder predecessor of current */
      pre = current->left;
      while(pre->right != NULL && pre->right != current)
        pre = pre->right;

      /* Make current as right child of its inorder predecessor */
      if(pre->right == NULL)
      {
        pre->right = current;
        cout <<current->data<<" ";
        current = current->left;
      }

      /* Revert the changes made in if part to restore the original
        tree i.e., fix the right child of predecssor */
      else
      {
        pre->right = NULL;
        current = current->right;
      }
    }
  }
}


tNode* newtNode(int data)
{
  tNode* newNode = new tNode();
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return(newNode);
}

/* Driver program to test above functions*/
int main()
{

  tNode *root = newtNode(10);
  root->left = newtNode(5);
  root->right = newtNode(30);
  root->left->left  = newtNode(-2);
  root->right->right  = newtNode(40);
  root->left->right= newtNode(6);
  root->left->right->right = newtNode(8);
  root->left->left->right  = newtNode(2);
  root->left->left->right->left = newtNode(-1);

  cout <<"Inorder traversal of the tree is: "<<endl;
  MorrisTraversalinOrder(root);
  cout <<"\n\nPreorder traversal of the tree is: "<<endl;
  MorrisTraversalPreOrder(root);
  return 0;
}
