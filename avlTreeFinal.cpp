#include <iostream>

using namespace std;

struct node
{
    int key;
    node *left;
    node *right;
    int height;
};

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
            cout <<x->key<<" ";
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


// A utility function to get maximum of two integers
int max(int a, int b);

// A utility function to get height of the tree
int height(node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}

/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
node* newNode(int key)
{
    node* newnode = new node();
    newnode->key   = key;
    newnode->left   = NULL;
    newnode->right  = NULL;
    newnode->height = 1;  // new node is initially added at leaf
    return(newnode);
}


    node *rightRotate(node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
    node *leftRotate(node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

    node* insert(node* node, int key)
{
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    /* 2. Update height of this ancestor node */
    node->height = max(height(node->left), height(node->right)) + 1;

    /* 3. Get the balance factor of this ancestor node to check whether
       this node became unbalanced */
    int balance = getBalance(node);


    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

struct node * minValueNode(node* node)
{
    struct node* current = node;


    while (current->left != NULL)
        current = current->left;

    return current;
}

node* deleteNode(node* root, int key)
{


    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if ( key < root->key )
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if( key > root->key )
        root->right = deleteNode(root->right, key);

    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct node *temp = root->left ? root->left : root->right;

            // No child case
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of the non-empty child

            delete(temp);
        }
        else
        {
            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
      return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = max(height(root->left), height(root->right)) + 1;

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether
    //  this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main()
{
  int n;
  node *root = NULL;

  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);


  cout <<"Level Order traversal of the constructed tree is: "<<endl;
  printLevelOrder(root);
  cout <<"\nEnter a number that you want to delete from the AVL tree: ";
  cin >>n;
  root=deleteNode(root,n);
  cout <<"The new tree after the deletion with level order traversal looks like: "<<endl;
  printLevelOrder(root);

  return 0;
}
