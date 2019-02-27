#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
}*root=NULL,*temp;
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
int max(int a, int b)
{
    return (a > b)? a : b;
}
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
    return x;
}
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    return y;
}
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
struct Node* insert(struct Node* node, int key)
{
    if (node == NULL)
        return(newNode(key));
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else 
        return node;
    node->height = 1 + max(height(node->left),height(node->right));
	int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
	if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
	if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void inorder(struct Node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
		printf("%d ", root->key);
       	inorder(root->right);
    }
}
struct Node* min(struct Node* root)
{
	if(root==NULL)
		return 0;
	else if(root->left!=NULL)
		return min(root->left);
	else
		return root;
}
struct Node* inordersucc(struct Node* temp,struct Node* x)
{
	if(x->right!=NULL)
		return min(x->right);
	struct Node* succ=NULL;
	while(temp!=NULL)
	{
		if(x->key<temp->key)
		{
			succ=temp;
			temp=temp->left;
		}
		else if(x->key>temp->key)
			temp=temp->right;
		else
			break;
	}
	return succ;
}
struct Node* find(struct Node* root,int ele)
{
	if(root==NULL)
		return 0;
	else if(ele<root->key)
		return find(root->left,ele);
	else if(ele>root->key)
		return find(root->right,ele);
	else
		return root;
}
main()
{
	int n,ele;
	do
	{
		printf("Enter the choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1 : printf("Enter the element : ");scanf("%d",&ele);root=insert(root,ele);break;
			case 2 : printf("The Inorder traversal : \n");inorder(root);printf("\n");break;
			case 3 : printf("Enter the element to find Inorder successor : ");scanf("%d",&ele);
					temp=find(root,ele);temp=inordersucc(root,temp);printf("Inorder successor is %d\n",temp->key);break;
		}
	}while(n<4 && n>0);
}

