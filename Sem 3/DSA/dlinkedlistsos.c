#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *start = NULL;

void insert_start(){
    int info;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("overflow\n");
    }else if(start == NULL){
        printf("enter number:");
        scanf("%d",&info);
        newnode -> data = info;
        newnode -> next =  NULL;
        newnode -> prev = NULL;
        start = newnode;
    }else{
        printf("enter number:");
        scanf("%d",&info);
        newnode -> data = info;
        start -> prev = newnode;
        newnode -> next = start;
        newnode -> prev = NULL;
        start = newnode;
    }
}

void insert_end(){
    int info;
    struct node *temp;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("overflow\n");
    }else if(start == NULL){
        printf("enter number:");
        scanf("%d",&info);
        newnode -> data = info;
        newnode -> next =  NULL;
        newnode -> prev = NULL;
        start = newnode;
    }else{
        printf("enter number:");
        scanf("%d",&info);
        newnode -> data = info;
        temp = start;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newnode;
        newnode -> prev = temp;
        newnode -> next = NULL;
    }
}

void insert_pos(){
    int info,pos,i = 1;
    struct node *temp;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter position:");
    scanf("%d",&pos);
    if(newnode == NULL){
        printf("overflow\n");
    }else if(pos == 1){
        insert_start();
    }else{
        temp = start;
        while(i<pos-1){
            temp = temp -> next;
            i++;
        }
        if(temp -> next == NULL){
            insert_end();
        }else{
            printf("enter number:");
            scanf("%d",&info);
            newnode -> data = info;
            newnode -> next = temp -> next;
            newnode -> prev =  temp;
            temp -> next -> prev = newnode;
            temp -> next = newnode;
        }
    }
}

void delete_start(){
    struct node *temp;
    if(start == NULL){
        printf("underflow\n");
    }else if(start -> next == NULL){
        temp = start;
        start = NULL;
        free(temp);
    }else{
        temp = start;
        start = start -> next;
        start -> prev = NULL;
        free(temp);
    }
}

void delete_end(){
    struct node *temp,*ptr;
    if(start == NULL){
        printf("underflow\n");
    }else if(start -> next == NULL){
        temp = start;
        start = NULL;
        free(temp);
    }else{
        temp = start;
        while(temp -> next != NULL){
            ptr = temp;
            temp = temp -> next;
        }
        ptr -> next = NULL;
        free(temp);
    }
}

void delete_pos(){
    int pos, i =1;
    struct node *temp,*ptr;
    printf("enter position:");
    scanf("%d",&pos);
    if(start == NULL){
        printf("underflow\n");
    }else if(pos == 1){
        delete_start();
    }else{
        ptr = start;
        while(i<pos-1){
            ptr = ptr -> next;
            i++;
        }
        temp = ptr -> next;
        if(temp -> next == NULL){
            delete_end();
        }else{
            temp -> next -> prev = ptr;
            ptr -> next = temp -> next;
            free(temp);
        }
    }
}

void search(){
    int n, i = 1;
    struct node *temp;
    if(start ==  NULL){
        printf("underflow\n");
    }else{
        printf("enter number:");
        scanf("%d",&n);
        temp =  start;
        while(temp != NULL){
            if(temp->data == n){
                printf("number found at position %d\n",i);
                break;
            }else{
                temp = temp -> next;
                i++;
            }
            
        }
    }
}

void display(){
    struct node *temp;
    if(start ==  NULL){
        printf("underflow\n");
    }else{
        temp = start;
        while(temp != NULL){
            printf("%d\n",temp -> data);
            temp = temp -> next;
        }
    }
}

int main(){
    int choice;
    
    while(1){
        printf("enter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insert_start();
                break;
            case 2:
                insert_end();
                break;
            case 3:
                insert_pos();
                break;
            case 4:
                delete_start();
                break;
            case 5:
                delete_end();
                break;
            case 6:
                delete_pos();
                break;
            case 7:
                search();
                break;
            case 8:
                display();
                break;
        }
    }
    return 0;
}
