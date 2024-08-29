#include<stdio.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node* create(int value)
{
    struct node* n=(struct node*)calloc(1,sizeof(struct node));
    n->data=value;
    n->next=n;
    n->prev=n;
    return n;
}
struct node* insert(struct node *head,int value)
{
    struct node *newnode=create(value);
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    else
    {
        struct node *temp=head->prev;
        newnode->next=head;
        head->prev=newnode;
        newnode->prev=temp;
        temp->next=newnode;
         return head;
    }
}
struct node* insertbeg(struct node *head,int value)
{
    struct node *newnode=create(value);
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    else
    {
        struct node *temp=head->prev;
        newnode->next=head;
        newnode->prev=head->prev;
        head->prev->next=newnode;
        head->prev=newnode;
        head=newnode;
        return head;
    }
}
void display(struct node *head)
{
    struct node *temp=head;
    do
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    while(temp->next!=head);
        printf("%d->",temp->data);
        printf("NULL\n");
}
int main()
{
    struct node* head=NULL;
    head=insertbeg(head,7);
    head=insertbeg(head,6);
    head=insertbeg(head,9);
    head=insertbeg(head,8);
    head=insertbeg(head,5);
    display(head);
}

