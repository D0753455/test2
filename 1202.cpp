#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define MAX 50

struct Node
{
	char data;
	Node* llink;
	Node* rlink;
	Node()	
	{
		llink=NULL;
		rlink=NULL;
	}
};
struct Tree
{
	Node* root;
	int height;
	void PrintSpace(int);
	Tree(const char *filename);
	void LevelTraversal();			
};

struct Queue
{
	Node* seq[MAX];
	int front, rear;
	Queue()
	{
		front=0;
		rear=0;
	}
	bool IsFull();
	bool IsEmpty();
	void Add(Node*);
	Node* Del(); 
};

int main()
{
	Tree MyT("1202.txt"); 
	MyT.LevelTraversal(); 
	
	return 0;
} 
//=============================================================================
Tree::Tree(const char *filename)
{
	FILE *fptr=fopen(filename,"r");
	Node* tmp1, *tmp2;
	char s[MAX]="";	
	Queue MyQ;
	int i=0;
	int count=0;
	fscanf(fptr,"%s",s);
	height=1;
	

	root=(Node*)malloc(sizeof(Node));
	root->data=s[i];
	root->llink=NULL;
	root->rlink=NULL;
	i++;
	
	MyQ.Add(root);
		
	while(MyQ.IsEmpty()!=true)
	{
		count++;
		if(count==pow(2,height))
		{	
			height++;
		}

		tmp1=MyQ.Del();
		if(s[i]!='\0')
		{
			tmp2=(Node*)malloc(sizeof(Node));
			tmp2->data=s[i];
			tmp2->llink=NULL;
			tmp2->rlink=NULL;		
			i++;			
			tmp1->llink=tmp2;
			MyQ.Add(tmp2);
			printf("add %c\n",tmp2->data);
		}		
		if(s[i]!='\0')
		{
			tmp2=(Node*)malloc(sizeof(Node));
			tmp2->data=s[i];
			tmp2->llink=NULL;
			tmp2->rlink=NULL;		
			i++;			
			tmp1->rlink=tmp2;
			MyQ.Add(tmp2);
			printf("add %c\n",tmp2->data);
		}		 
	}	

}
//=============================================================================
void Tree::LevelTraversal()
{
	Node* tmp;	
	Queue MyQ;
	int level=1;
	int count=0;
	MyQ.Add(root);
	while(MyQ.IsEmpty()!=true)
	{
		tmp=MyQ.Del();	
		if(tmp!=NULL)
		{
			if(count==pow(2,level)-1)
			{
				printf("\n");
				level++;				
			}
			PrintSpace(level);
			printf("\b%c", tmp->data);
			PrintSpace(level);
			count++;
			MyQ.Add(tmp->llink);
			MyQ.Add(tmp->rlink);
		}
	}
	
	
}
//=============================================================================
bool Queue::IsFull()
{
	if((rear+1)%MAX==front)
		return true;
	else
		return false;
}
//=============================================================================
bool Queue::IsEmpty()
{
	if(rear==front)
		return true;
	else
		return false;
} 
//=============================================================================
void Queue::Add(Node* tmp)
{
	if(IsFull()!=true)
	{
		seq[rear%MAX]=tmp;
		rear++;
	}
	else
		printf("Queue is full!\n");
}
//=============================================================================
Node* Queue::Del()
{
	Node *tmp=NULL;
	if(IsEmpty()!=true)
	{
		tmp=seq[front%MAX];
		front++;
		return tmp;		
	}
	else
	{
		printf("Queue is Empty!\n");
		return NULL;
	}
	
}
//=============================================================================
void Tree::PrintSpace(int level)
{
	int i;
	for(i=0;i<pow(2, height-level);i++)
		printf(" ");
}

