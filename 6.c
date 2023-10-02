#include<stdio.h>
#include<stdlib.h>
 struct Node
{
    int data;
    struct Node* next;
};
 struct Node *head=NULL,*ptr;
void insert_Front(int value)
{
    struct Node*temp;
    temp=( struct Node*)malloc(sizeof( struct Node));
    temp->data=value;
    temp->next=NULL;
     if (head == NULL)
    {
        head=temp;
    }
    else
    {
    temp->next=head;
    head = temp;
    }
}
void insert_end(int value)
{
    struct Node*temp;
    temp=( struct Node*)malloc(sizeof( struct Node));
    temp->data=value;
     if (head == NULL)
    {
        head=temp;
    }
    else
    {
        ptr= head;
        while (ptr->next !=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next=temp;
        temp->next=NULL;
    }
}

void insert_at_specified_ele(int value,int ele)
{
    struct Node*temp;
    temp=( struct Node*)malloc(sizeof( struct Node));
    temp->data=value;
     if (head == NULL)
    {
        head=temp;
    }
    else
    {
        ptr=head;
        while (ptr->data != ele)
        {
            ptr=ptr->next;
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }
}
void delete_Front( )
 {
    if (head == NULL) {
        printf("Linked list is empty, Delition is Not possible\n");
    }
    else
    {
    ptr=head;
     head = (head)->next;
     ptr->next=NULL;
    free(ptr);
    }
 }
 void delete_End( )
 {
    if (head == NULL) {
        printf("Linked list is empty, Delition is Not possible\n");
    }
    else
    {
        struct Node *p;
        ptr=head;
        while (ptr->next !=NULL)
        {
            p=ptr;
            ptr=ptr->next;
        }
        p->next=NULL;
        free(ptr);
    }
 }
 void delete_at_specified_ele(int ele )
 {
    if (head == NULL) {
        printf("Linked list is empty, Delition is Not possible\n");
    }
    else
    {
         struct Node *p;
        ptr=head;
        while (ptr->next != ele)
        {
            p=ptr;
            ptr=ptr->next;
        }
        p->next=ptr->next;
        free(ptr);
    }
}
 void display()
 {
    if (head == NULL) {
        printf("Linked list is empty\n");
    }
    else
    {
        ptr=head;
        while (ptr != NULL)
        {
        printf("%d -> ", ptr->data);
        ptr= ptr->next;
        }
        printf("NULL\n");
    }
 }
void main()
{
    int ch,value,ele;
        printf("1. Insert_front\n");
        printf("2. Insert_end\n");
        printf("3. Insert_At_specified_position \n");
        printf("4. Delete_bfront\n");
        printf("5. Delete_end\n");
        printf("6. Delete_At_specified_position\n");
        printf("7. Exit\n");

        while (7)
        {
             printf("Enter your choice: \n");
        scanf("%d", &ch);
         switch (ch)
         {
             case 1:
                printf("Enter the value: ");
                scanf("%d", & value);
                void insert_Front(int  value);
                display();
                break;
             case 2:
                printf("Enter the value: ");
                scanf("%d", & value);
                void insert_end(int value);
                display();
                break;
             case 3:
                printf("Enter the value: ");
                scanf("%d", & value);
                void insert_at_specified_ele( int value, int ele);
                display();
                break;
             case 4:
                delete_Front();
                display();
                break;
             case 5:
                delete_End();
                display();
                break;

             case 6:
                printf("Enter the element you want to delete: ");
                scanf("%d", & ele);
                delete_at_specified_ele(ele );
                display();
                break;
             case 7:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
         }
        }
        
}