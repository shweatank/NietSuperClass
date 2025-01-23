//program to implement linked list

#include<stdio.h>
#include<stdlib.h>
#define p(x) printf("%d\n", x)
#define pf(x) printf("%f\n", x)
#define ps(x) printf("%s", x)
#define s(x) scanf("%d", &x)

typedef struct node{
    int data;
   struct node *next;
}node;

node* create(int data) {
    node* new = (node*)malloc(sizeof(node));
    if (new == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    new->data = data; // Set the data of the new node
    new->next = NULL; // Initialize the next pointer to NULL
    return new;
}

void insert_at_end(node* const start,const int data){
    node* n=create(data);
    node* temp=start;
    while(temp->next!=NULL){
        temp=temp->next;
        continue;
    }
    temp->next=n;
    n->next=NULL;
}

node* insert_at_beginning(node* const start,const int data){
    node* n=create(data);
    n->next=start;
    return n;
}

void insert_at_position(node** start,const int data,const int pos){
    node* n=create(data);
    node* temp=*start;
    if(pos==0){
        n->next=*start;
        *start=n;
        return;
    }
    for(int i=1;i<pos;i++){
        if(temp->next==NULL){
            ps("Position not found\n");
            return;
        }
        temp=temp->next;
    }
    if(temp->next==NULL){
        temp->next=n;
        n->next=NULL;
        return;
    }
    n->next=temp->next;
    temp->next=n;
}

void printll(const node* start) {
    const node* current = start;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next; // Move to the next node
    }
    printf("\n");
}

void freell(node* start){
    node *temp=start;
    while(temp!=NULL){
        node* next=temp->next;
        free(temp);
        temp=next;
    }
}

void delete_node(node** start,int key){
    node*temp=*start;
     if(temp->data==key){
            if(temp->next){
                *start=temp->next;
                free(temp);
                return;
            }
            else{
                free(temp);
                *start=NULL;
                return;
            }
        }
    while(temp){
        if(temp->next && temp->next->data==key){
            if(temp->next->next){
                node* tempp=temp->next;
                temp->next=temp->next->next;
                free(tempp);
                return;
            }
            else{
                free(temp->next);
                temp->next=NULL;
                return;
            }
        }
        temp=temp->next;
    }
    return;
}

void update_node(node** start,int key,int new_data){
    node*temp=*start;
    while(temp){
        if(temp->data==key){
            temp->data=new_data;
            return;
        }
        temp=temp->next;
    }
    ps("Key not found\n");
    return;
}

void reverse(node** start){
    node* temp=NULL;
    node* prev=NULL;
    node* current=*start;
    while(current!=NULL){
        temp=current->next;
        current->next=prev;
        prev=current;
        current=temp;
    }
    *start=prev;
}

void reverserec(node** start,node* temp,node* prev, node* current){
    if(current==NULL){
      *start=prev;
      return;
    }
    temp=current->next;
    current->next=prev;
    prev=current;
    current=temp;
    reverserec(start,temp,prev,current);
}

node *findmid(node*start){
	if(start==NULL)return start;
	node *tortoise=start;node*hare=start->next;
	while(hare!=NULL && hare->next!=NULL){
		tortoise=tortoise->next;
		hare=hare->next->next;
	}
	return tortoise;
}

node* mergell(node *l1,node* l2){
	node* dummy=create(-1);
	node* temp= dummy;
	while(l1 && l2){
		if(l1->data<l2->data){
			temp->next=l1;
			temp=l1;
			l1=l1->next;
		}
		else{
			temp->next=l2;
			temp=l2;
			l2=l2->next;
		}
	}
	if(l1)temp->next=l1;
	if(l2)temp->next=l2;
	return dummy->next;
}

node *sortll(node *head){
	if(head==NULL || head->next==NULL)return head;
	node *mid=findmid(head);
	node *left=head;
	node *right=mid->next;
	mid->next=NULL;
	left=sortll(left);
	right=sortll(right);
	return mergell(left,right);
}

int main(void){
    node*start1=insert_at_beginning(NULL,5);
    insert_at_end(start1,6);
    insert_at_end(start1,2);
    insert_at_end(start1,3);
    insert_at_end(start1,4);
    insert_at_end(start1,1);
    insert_at_end(start1,8);
    insert_at_end(start1,9);
    insert_at_position(&start1,7,0);
    //node *sorted=sortll(start1);
    //update_node(&start1,7,10);
    //reverserec(&start1,NULL,NULL,start1);
    p(findmid(start1)->data);
    printll(start1);
    //freell(start1);
    node*start2=insert_at_beginning(NULL,2);
    insert_at_end(start2,3);
    insert_at_end(start2,4);
    //insert_at_end(start1,9);
    insert_at_position(&start2,7,0);
    //update_node(&start1,7,10);
    //reverserec(&start1,NULL,NULL,start1);
    //p(findmid(start1)->data);
    printll(start2);
    node* merged=mergell(start1,start2);
    node *sorted=sortll(merged);
    //update_node(&start1,7,10);
    printll(sorted);
    //freell(start1);
}
