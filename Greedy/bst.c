#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
	struct node *next;
}*temp,*root=NULL;
typedef struct node BST;
BST *Insert(BST *tree,int ele);
BST *display(BST *tree);
BST *inorder(BST *tree);
BST *preorder(BST *tree);
BST *postorder(BST *tree);
BST *findmin(BST *tree);
BST *findmax(BST *tree);
BST *find(BST *tree,int key);
void main()
{
	int ch,x,con,key;
	do
	{
	printf("Enter choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		{
		printf("Enter the element to insert\n");
		scanf("%d",&x);
		root=Insert(root,x);
		break;
		}
		case 2:
		{
		printf("Display\n");	
		display(root);
		break;
		}
		case 3:
		{
			if(root==NULL)
			{
			printf("Tree empty\n");
			}
			else
			{
			printf("INORDER");
			inorder(root);
			break;
			}
		}
		case 4:
		{
			if(root==NULL)
			{
			printf("Tree empty\n");
			}
			else
			{
			printf("PREORDER");
			preorder(root);
			break;
			}
		}
		case 5:
		{
			if(root==NULL)
			{
			printf("Tree empty\n");
			}
			else
			{
			printf("POSTORDER");
			postorder(root);
			break;
			}
		}
		case 6:
		{
			temp=findmin(root);
			if(temp==NULL)
			{
			printf("Tree empty\n");
			}
			else
			{
			printf("minimum is : %d\n",temp->data);
			}
			break;	
		}
		case 7:
		{
			temp=findmax(root);
			if(temp==NULL)
			{
			printf("Tree empty\n");
			}
			else
			{
			printf("maximum is : %d\n",temp->data);
			}	
			break;
		}
		case 8:
		{
			printf("Enter key :\n");
			scanf("%d",&key);
			temp=find(root,key);
			if(temp==NULL)
				printf("Not found\n");
			else 
				printf("found%d\n",temp->data);
		}
	}
	printf("Enter 1 to continue : \n");
	scanf("%d",&con);
	}while(con==1);	
}
BST *Insert(BST *tree,int ele)
{
	if(tree==NULL)
	{
		tree=(BST*)malloc(sizeof(BST));
		tree->data=ele;	
		tree->lchild=NULL;
		tree->rchild=NULL;
	
	}
	else
	{
		if(ele<tree->data)
			tree->lchild=Insert(tree->lchild,ele);
		else if(ele>tree->data)
			tree->rchild=Insert(tree->rchild,ele);
		else
			printf("Elements already exists\n");	
	}
	return tree;
}
BST *display(BST *tree)
{
	while(tree!=NULL)	
	{
		printf("%d\n",tree->data);	
		tree=tree->next;
	}
}
BST *inorder(BST *tree)
{
	if(tree!=NULL)
	{
		inorder(tree->lchild);
		printf("%d\n",tree->data);
		inorder(tree->rchild);
	}
}
BST *preorder(BST *tree)
{
	if(tree!=NULL)
	{
		printf("\n%d\n",tree->data);
		preorder(tree->lchild);
		preorder(tree->rchild);
	}
}
BST *postorder(BST *tree)
{
	if(tree!=NULL)
	{
		postorder(tree->lchild);
		postorder(tree->rchild);
		printf("\n%d\n",tree->data);
	}
}
BST *findmin(BST *tree)
{
	if(tree==NULL)
	{
		return 0;
	}
	else
	{
		if(tree->lchild!=NULL)
		{
			return findmin(tree->lchild);
		}
		else
		{
			return tree;	
		}
	}
}
BST *findmax(BST *tree)
{
	if(tree==NULL)
	{
		return 0;
	}
	else
	{
		if(tree->rchild!=NULL)
		{
			return findmin(tree->rchild);
		}
		else
		{
			return tree;	
		}
	}
}
BST *find(BST *tree,int key)	
{
	if(tree==NULL)
	{	
		return 0;
	}
	else if(key<tree->data)	
	{
		return find(tree->lchild,key);
	}
	else if(key>tree->data)	
	{
		return find(tree->rchild,key);
	}
	else
		return tree;
}
