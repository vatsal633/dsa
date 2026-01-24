#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head;
struct node *tail;

struct node *create(){
    struct node *newNode;
    newNode = (struct node*) malloc(sizeof(struct node));

    if(newNode==NULL){
        printf("allocation failed!\n");
        return 0;
    }

    return newNode;
}

void push_back(){
    int val;
    struct node *newNode = create();

    printf("enter the value");
    scanf("%d",&val);

    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(head==NULL){
        head = tail = newNode;
    }else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}


void display(){
    struct node *temp = head;
    if (temp==NULL)
    {
        printf("the list is empty\n");
        return;
    }
    
    while (temp!=NULL)
    {
        if(temp->next==NULL){
            printf("%d",temp->data);
        }
        else{
            printf("%d <->",temp->data);
        }
        temp = temp->next;
    }
    
}
void main(){
    push_back();
    push_back();
    push_back();
    push_back();
    push_back();
    display();
    getch();
}
