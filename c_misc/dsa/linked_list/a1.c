#include<stdio.h>
#include<stdlib.h>


typedef struct node{
int val;
struct node* next;
}mynode;

mynode* head=NULL;

void insert(int val){
mynode *temp=(mynode*)malloc(sizeof(mynode));
temp->val=val;
temp->next=head;
head=temp;}


void print(mynode* head){
mynode* temp;
temp=head;
while(temp){
printf("%d->",temp->val);
temp=temp->next;
}
printf("\n");
}

mynode* findmid(mynode* head){
	if(!head)return head;
	mynode* slow=head;
	mynode* fast=head->next;
	while(fast && fast->next){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}

mynode* mergell(mynode* l1, mynode* l2){
	mynode* dummy=malloc(sizeof(mynode));
	dummy->next=NULL;
	dummy->val=-1;
	mynode* temp=dummy;
	mynode* t1=l1,*t2=l2;
	while(t1 && t2){
		if(t1->val<t2->val){
			temp->next=t1;
			t1=t1->next;
		}
		else{
			temp->next=t2;
			t2=t2->next;
		}
		temp=temp->next;
	}
	if(t1)temp->next=t1;
	else if(t2)temp->next=t2;
	return dummy->next;
}

mynode* mergesortll(mynode* head){
	if(head==NULL || head->next==NULL)return head;
	mynode* mid=findmid(head);
	mynode* leftnode=head;
	mynode* rightnode=mid->next;
	mid->next=NULL;
	leftnode=mergesortll(leftnode);
	rightnode=mergesortll(rightnode);
	return mergell(leftnode,rightnode);
}

void merge(int *arr,int lo,int hi){
	int mid=lo+(hi-lo)/2;
	int n1=mid-lo+1;
	int n2=hi-mid;
	int left[n1],right[n2];
	for(int i=0;i<n1;i++){
		left[i]=arr[lo+i];
	}
	for(int i=0;i<n2;i++){
		right[i]=arr[mid+i+1];
	}
	int i=0,j=0,k=0;
	while(i<n1 && j<n2){
		if(left[i]<right[j]){
			arr[lo+k]=left[i];
			i++;
		}
		else{
			arr[lo+k]=right[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		arr[lo+k]=left[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[lo+k]=right[j];
		j++;
		k++;
	}
}

void mergesort(int *arr,int lo,int hi){
	if(hi<=lo)return;
	int mid=lo+(hi-lo)/2;
	mergesort(arr,lo,mid);
	mergesort(arr,mid+1,hi);
	merge(arr,lo,hi);
}

int main(void){
	int arr[] = {2,1,4,3,3,5,4,9,6};
	mergesort(arr,0,9);
	for(int i=0;i<9;i++){
		printf("%d ",arr[i]);
	}
	insert(1);
	insert(3);
	insert(2);
	insert(5);
	insert(4);
	insert(1);
	print(findmid(head));
	print(head);
	mynode* sorted=mergesortll(head);
	print(sorted);
}

