#include <iostream>

using namespace std;

struct node
{
  int data;
  node* left;
  node* right;
};

/* Prototypes for utility functions */
int Search(int arr[], int strt, int End, int value);
struct node* newNode(int data);

struct que
{
    node* element[25];
    int fr,rear;
    que()
    {
        fr=rear=-1;
    }
};

bool isEmpty(que &q)
{
    if(q.fr==-1 && q.rear==-1)
        return true;
    else
        return false;
}

bool isFull(que &q)
{
    if((q.rear+1)%25==q.fr)
        return true;
    else
        return false;
}

void eq(node* n, que &q)
{
    int x;
    if(isFull(q))
    {
        cout <<"Queue is full"<<endl;
        return;
    }
    else if(isEmpty(q))

    {
        q.rear=q.fr=0;
        q.element[q.rear]=n;
    }
    else
    {
        q.rear=(q.rear+1)%25;
        q.element[q.rear]=n;
    }

}




node* dq(que &q)
{
    node* x;
    if(isEmpty(q))
    {
        cout <<"Queue is empty"<<endl;
        return NULL;
    }
    else if(q.fr==q.rear)
    {
        x =q.element[q.rear];
        q.fr=q.rear=-1;
        return x;
    }
    else
    {
        x=q.element[q.fr];
        q.fr=(q.fr+1)%25;
        return x;
    }
}

node* buildTree(int in[], int pre[], int inStrt, int inEnd)
{
  static int preIndex = 0;

  if(inStrt > inEnd)//when will dis condition occur?????
     return NULL;

  /* Pick current node from Preorder traversal using preIndex
    and increment preIndex */
  struct node *tNode = newNode(pre[preIndex++]);

  /* If this node has no children then return */
  if(inStrt == inEnd)
    return tNode;

  /* Else find the index of this node in Inorder traversal */
  int inIndex = Search(in, inStrt, inEnd, tNode->data);

  /* Using index in Inorder traversal, construct left and
     right subtress */
  tNode->left = buildTree(in, pre, inStrt, inIndex-1);
  tNode->right = buildTree(in, pre, inIndex+1, inEnd);

  return tNode;
}

/* UTILITY FUNCTIONS */
/* Function to find index of value in arr[start...end]
   The function assumes that value is present in in[] */
int Search(int arr[], int strt, int End, int value)
{
  int i;
  for(i = strt; i <= End; i++)
  {
    if(arr[i] == value)
      return i;
  }
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
  struct node* tnode = new node();
  tnode->data = data;
  tnode->left = NULL;
  tnode->right = NULL;

  return(tnode);
}

void printLevelOrder(node* root)
{
    if(root==NULL)
        return;
    que q;
    cout <<"Reached here with root add: "<<root<<endl;
    eq(root,q);
    eq(NULL,q);
    while(!isEmpty(q))
    {
        //node* nod=root;
        //eq(nod->left->data,q);
       // node* nod=fr;
        //cout <<nod->data<<" ";
        node* x=dq(q);
        if(x!= NULL)
        {
            cout <<x->data<<" ";
            if(x->left!=NULL)
            {
            eq(x->left,q);
            }
            if(x->right!=NULL)
            {
            eq(x->right,q);
            }
        }
        else if(!isEmpty(q))//since after dequeing the queue might get empty.
        {
            cout<<endl;
            eq(NULL,q);
        }
    }
}

/* Driver program to test above functions */
int main()
{
  int in[] = {15,30,35,40,45,50,60,70,72,75,77,80};
  int pre[] = {50,30,15,40,35,45,70,60,80,75,72,77};
  int len = 12;
  struct node *root = buildTree(in, pre, 0, len - 1);

  /* Let us test the built tree by printing Insorder traversal */
  cout <<"Level order traversal of the constructed tree is: "<<endl;
  printLevelOrder(root);
  return 0;
}
