#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *Lchild;
	int data;
	struct node *Rchild;
};
typedef struct node BST;
BST *insert(BST *tree,int element){
	if(tree == NULL){
		tree=(BST*)malloc(sizeof(BST));
		tree->data=element;
		tree->Lchild=NULL;
		tree->Rchild=NULL;
		}
	else{
		if(element<tree->data)
			tree->Lchild=insert(tree->Lchild,element);
		else if(element>tree->data)
			tree->Rchild=insert(tree->Rchild,element);
		else
			printf("\nElement exists already");
	}
return tree;
}
void traversal(BST *tree){
	if(tree!=NULL){
		traversal(tree->Lchild);
		printf("%d\t",tree->data);
		traversal(tree->Rchild);}
}
void main(){
	BST* root=NULL;
	int size,i,element;
	printf("\nEnter number of elements to be inserted");
	scanf("%d",&size);
	for(i=0;i<size;i++){
		scanf("%d",&element);
		root=insert(root,element);
}

traversal(root);
}

