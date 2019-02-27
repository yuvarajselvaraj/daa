#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	int end_string;
	struct node* next[26];
}*root=NULL;

void insert(struct node*tree,char str[])
{
	int i,j;
	for(i=0;i<strlen(str);i++)
	{
		if(tree->next[str[i]-'a']==NULL)
		{
			struct node *n;
			n=(struct node*)malloc(sizeof(struct node));
			for(j=0;j<26;j++)
				n->next[j]=NULL;
			n->end_string=0;
			tree->next[str[i]-'a']=n;
			tree=n;
		}
		else
			tree=tree->next[str[i]-'a'];
	}
	tree->end_string=1;
}

int check(struct node* tree,char str[])
{
	int i;
	for(i=0;i<strlen(str);i++)
	{
		if(tree->next[str[i]-'a']==NULL)
			return 0;
		else
			tree=tree->next[str[i]-'a'];
	}
	if(tree->end_string==1)
		return 1;
	else
		return 0;
}

int main()
{
	int n,m,i;
	char str[100];
	root=(struct node*)malloc(sizeof(struct node));
	for(i=0;i<26;i++)
		root->next[i]=NULL;
	root->end_string=0;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",str);
		insert(root,str);
	}
	scanf("%d",&m);
	while(m--)
	{
		scanf("%s",str);
		if(check(root,str))
			printf("Present\n");
		else
			printf("Not present\n");
	}
	return 0;
}
