#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
};

struct node *head;
struct node *tail;
int size=0;

struct node *create(){

  struct node *temp;

  temp = (struct node*) malloc(sizeof(struct node));

  if(temp==NULL){
    printf("allocation failed!\n");
    return 0;
  }

  return temp;
}

void push_front(){
  int val;
  struct node *newNode = create();

  printf("\nenter the value");
  scanf("%d",&val);

  newNode->data = val;
  newNode->next = NULL;

  if(head==NULL){
     head = tail = newNode;
  }else{
     newNode->next = head;
     head=newNode;
  }
}

void push_back(){
   int val;
   struct node *newNode = create();

   printf("\nenter the value");
   scanf("%d",&val);

   newNode->data = val;
   newNode->next = NULL;

   if(head==NULL){
      head = tail = newNode;
   }else{
      tail->next = newNode;
      tail = newNode;
   }
}

void insert_index(){
   int val,index,i=0;
   struct node *temp;
   struct node *newNode = create();
   temp = head;

   printf("\nenter the value of node");
   scanf("%d",&val);

   newNode->data = val;
   newNode->next = NULL;

   printf("\nenter the index");
   scanf("%d",&index);

   while(temp!=NULL && i!=index-1){
       temp = temp->next;
       i++;
   }

   newNode->next =  temp->next;
   temp->next = newNode;

}

void  display_list(){
  struct node *temp;
  temp = head;

  while(temp!=NULL){
     printf(" %d ",temp->data);
     temp = temp->next;
     size++;
  }
}

void count_node(){
  display_list();
  printf("\nsize of list is %d",size);
}

void search_val(){
   int val,isFound,i=0;
   struct node *temp = head;
   printf("enter the value you want to search\n");
   scanf("%d",&val);

   while(temp!=NULL){
      if(temp->data==val){
	isFound=1;
	break;
      }

      temp = temp->next;
      i++;
   }

   if(isFound==1){
     printf("index:%d\n",&i);
   }
   else{
     printf("not found!\n");
   }
}

void reverse(){
  struct node *prev = NULL;
  struct node *curr = head;
  struct node *next = NULL;

  tail = head;

  while(curr!=NULL){
     next = curr->next;
     curr->next = prev;

     prev = curr;
     curr = next;

  }
  head = prev;

}

void sort(){
  struct node *i = head;
  struct node *j = head;
  struct node *temp;

  for(i=head;i->next!=NULL;i=i->next){
    for(j=i->next;j!=NULL;j=j->next){
       if(i->data>j->data){
	  temp->data = i->data;
	  i->data = j->data;
	  j->data = temp->data;
       }
    }
  }
}

void main(){
    int choice;
    clrscr();
    while(choice!=0){
      printf("\n0.exit\n1.push front\n2.push back\n3.display list\n4.insert at index\n5.count list\n6.reverse\n");


      printf("enter your choice");
      scanf("%d",&choice);

      switch(choice){
       case 1:
	  push_front();
	  break;
       case 2:

	  push_back();
	  break;
       case 3:
	  display_list();
	   break;
       case 4:
	  insert_index();
	  break;
       case 5:
	   count_node();
	   break;
       case 6:
	   reverse();
	   break;
       case 7:
	   sort();
	   break;
       default:
	  printf("\ninvalid\n");
	  break;
      }
    }
    getch();
}
