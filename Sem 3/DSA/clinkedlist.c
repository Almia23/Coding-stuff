
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();


struct node
{
        int data;
        struct node *next;
};
struct node *head=NULL;
int main()
{
        int choice;
        printf("\n                MENU                             \n");
                printf("\n 1.Display    \n");
                printf("\n 2.Insert at the beginning    \n");
                printf("\n 3.Insert at the end  \n");
                printf("\n 4.Insert at specified position       \n");
                printf("\n 5.Delete from beginning      \n");
                printf("\n 6.Delete from the end        \n");
                printf("\n 7.Delete from specified position     \n");
                printf("\n 8.Exit       \n");
                printf("\n--------------------------------------\n");
        while(1){


                printf("\nEnter your choice: \n");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        display();
                                        break;
                        case 2:
                                        insert_begin();
                                        break;
                        case 3:
                                        insert_end();
                                        break;
                        case 4:
                                        insert_pos();
                                        break;
                        case 5:
                                        delete_begin();
                                        break;
                        case 6:
                                        delete_end();
                                        break;
                        case 7:
                                        delete_pos();
                                        break;

                        case 8:
                                        exit(0);
                                        break;

                        default:
                                        printf("\n Wrong Choice:\n");
                                        break;
                }
        }
        return 0;
}

void display()
{
        struct node *ptr;
        if(head==NULL)
        {
                printf("\nList is empty\n");
                return;
        }
        else
        {
                ptr=head;
                printf("\nThe List elements are:\n");
                do
                {
                        printf("%d ",ptr->data );
                        ptr=ptr->next ;
                }while(ptr->next!=head);
        }
}
void insert_begin()
{
        struct node *link = (struct node*) malloc(sizeof(struct node));
        if(link==NULL)
        {
                printf("Overflow\n");
                return;
        }
        printf("\nEnter the data value for the node:" );
        scanf("%d",&link->data);
        if(head==NULL)
        {
                head=link;
                head->next=head;
        }
        else
        {
                link->next=head;
                head=link;
        }
}
void insert_end()
{
        struct node *ptr;
        struct node *link = (struct node*) malloc(sizeof(struct node));
        if(link==NULL)
        {
                printf("Overflow\n");
                return;
        }
        printf("\nEnter the data value for the node:" );
        scanf("%d",&link->data);
        
        if(head==NULL)
        {
                head=link;
                head->next=head;
        }
        else
        {
                ptr=head;
                
                while(ptr->next !=head)
                {
                        ptr=ptr->next ;
                }
                ptr->next=link;
                link->next=head;
        }
}
void insert_pos()
{
        struct node *ptr;
        int i,pos;
        struct node *link = (struct node*) malloc(sizeof(struct node));
        if(link==NULL)
        {
                printf("Overflow\n");
                return;
        }
        printf("\nEnter the position for the new node to be inserted:");
        scanf("%d",&pos);
        printf("\nEnter the data value of the node:");
        scanf("%d",&link->data) ;

        if(pos==0)
        {
                link->next=head;
                head=link;//do we update at end to new head?
        }
        else
        {
                for(i=0,ptr=head;i<pos-1;i++) {
                        ptr=ptr->next;
                        if(ptr==NULL)
                        {
                                printf("\nPosition not found\n");
                                return;
                        }
                }
                link->next =ptr->next ;
                ptr->next=link;
        }
}
void delete_begin()
{
        struct node *ptr;
        if(ptr==NULL)
        {
                printf("Underflow\n");
                return;
        }
        else
        {
                ptr=head;
                head=head->next ;
                printf("\nThe deleted element is :%d",ptr->data);
                free(ptr);
        }
}
void delete_end()
{
        struct node *link,*ptr;
        if(head==NULL)
        {
                printf("Underflow\n");
                return;
        }
        else if(head->next ==head)
        {
                ptr=head;
                head=NULL;
                printf("\nThe deleted element is:%d",ptr->data);
                free(ptr);
        }
        else
        {
                ptr=head;
                while(ptr->next!=head)
                {
                        link=ptr;
                        ptr=ptr->next;
                }
                link->next=head;
                printf("\nThe deleted element is:%d",ptr->data);
                free(ptr);
        }
}
void delete_pos()
{
        int i,pos;
        struct node *link,*ptr;
        if(head==NULL)
        {
                printf("Underflow\n");
                return;
        }
        else
        {
                printf("\nEnter the position of the node to be deleted:");
                scanf("%d",&pos);
                if(pos==0)
                {
                        ptr=head;
                        head=head->next ;
                        printf("\nThe deleted element is:%d",ptr->data);
                        free(ptr);
                }
                else
                {
                        ptr=head;
                        for(i=0;i<pos;i++) { 
                            link=ptr; 
                            ptr=ptr->next ;
                                if(ptr==head)
                                {
                                        printf("\nPosition not Found:\n");
                                        return;
                                }
                        }
                        link->next =ptr->next ;
                        printf("\nThe deleted element is:%d",ptr->data );
                        free(ptr);
                }
        }
}