#include<stdio.h>
#include<stdlib.h>

struct node{
	void *data;
	struct node* next;
};
typedef struct node node;

struct{
	int a;
	char b;
	float f;
}comp[]={{1,'e',1.1},{2,'f',2.2}};

void insert(node **root,void *dataa,unsigned int size){
	node *temp=malloc(sizeof(node));
	temp->data=malloc(size);
	for(int i=0;i<size;i++)
		*(char*)(temp->data+i)=*(char*)(dataa+i);
	temp->next=*root;
	*root=temp;
}

void printll(node*root,void(*p)(void*)){
	node *temp=root;
	while(temp){
		p(temp->data);
		temp=temp->next;
	}
}

void printint(void * intt){
	printf("%d ",*(int*)intt);
}

int main(void){
	int x=5;
	int y=3;
	node*l1=malloc(sizeof(node));
	l1->data=(void*)(&x);
	l1->next=NULL;
	insert(&l1,(void*)(&y),4);
	printll(l1,printint);
}
