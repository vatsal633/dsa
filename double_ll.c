#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head;
struct node *tail;
int size = 0;

struct node *create(int val)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL)
    {
        printf("allocation failed!\n");
        return 0;
    }

    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void push_back(int val)
{
    struct node *newNode = create(val);

    if (head == NULL)
    {
        head = tail = newNode;
        size++;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        size++;
    }
}

void push_front(int val)
{
    struct node *newNode = create(val);

    if (head == NULL)
    {
        head = tail = newNode;
        size++;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        size++;
    }
}

void insertAt(int val, int pos)
{
    struct node *newNode = create(val);
    struct node *temp = head;
    int i = 0;

    if(pos==0){
        push_front(val);
        return;
    }

    if (pos>size)
    {
        push_back(val);
    }
    
    
    while (temp != NULL && i != pos - 1);
    {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}

void display()
{
    struct node *temp = head;
    if (temp == NULL)
    {
        printf("the list is empty\n");
        return;
    }

    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            printf("%d", temp->data);
        }
        else
        {
            printf("%d <->", temp->data);
        }
        temp = temp->next;
    }
}

void main()
{
    push_front(1);
    push_front(2);
    push_front(3);
    push_front(4);
    display();
    getch();
}
