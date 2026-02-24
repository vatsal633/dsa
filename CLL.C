#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
};

struct node *head;
struct node *tail;
struct node *temp;

struct node *create(int val){
   struct node *newNode =  (struct node*) malloc(sizeof(struct node));

   if(newNode==NULL){
      printf("Allocation failed\n");
      return NULL;
   }

   newNode->data = val;
   newNode->next = NULL;

   return newNode;
}


void pushFront(){
   int val;
   struct node *newNode;

   printf("enter the val");
   scanf("%d",&val);
     newNode = create(val);

   if(head==NULL){
      head = tail = newNode;
      tail->next = newNode;
   }else{
      newNode->next = head;
      head = newNode;
      tail->next = head;
   }
}

void pushBack(){
   int val;
   struct node *newNode;

   printf("enter the value");
   scanf("%d",&val);

   newNode = create(val);

   if(head==NULL){
      head = tail = newNode;
      tail->next = head;
   }
   else{
      tail->next = newNode;
      newNode->next = head;
      tail = newNode;
   }
}


void deleteFront(){
   temp = head;
   if(head==NULL){
      printf("list is empty\n");
      return;
   }else{
      head = head->next;
      tail->next = head;
      free(temp);
   }
}


void deleteBack(){
   struct node *t = tail;
   temp = head;

   if(head==NULL){
      printf("list is empty\n");
      return;
   }
   if(temp->next == head){
      head = tail = NULL;
      return;
   }

   while(temp->next->next!=head){
       temp = temp->next;
   }

  // tail = temp;
   temp->next = head;
   tail=temp;
   free(t);
}


void display(){
   temp = head;

   if(head==NULL){
     printf("list is empty\n");
     return;
   }

   while(temp->next!=head){
      printf(" %d ",temp->data);
      temp=temp->next;
   }

   printf(" %d ",temp->data);
}

void main(){
   int choice;
   clrscr();
   while(choice!=0){
     printf("\n0.exit\n1.push front\n2.push back\n3.delete front\n4.delete back\n5.display\n");
     printf("enter the choice:");
     scanf("%d",&choice);

     switch(choice){
	case 0:
	   printf("exiting....\n");
	   break;
	case 1:
	   pushFront();
	   break;
	case 2:
	   pushBack();
	   break;
	case 3:
	   deleteFront();
	   break;
	case 4:
	   deleteBack();
	   break;
	case 5:
	   display();
	   break;
	default:
	   printf("invalid\n");
	   break;
     }
   }
   getch();
}