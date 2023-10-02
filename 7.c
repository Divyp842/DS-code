#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head=NULL;
void insert_At_Front(int value)
{struct Node*temp;
    temp=( struct Node*)malloc(sizeof( struct Node));
    temp->data=value;
    temp->prev=NULL;
    temp->next=head;
    if(head!=NULL)
    {
        head->prev=temp;
    }
    head=temp;
    printf("Node With Value %d insert at the front.\n",value);
}

void insert_At_End(int value)
{struct Node*temp;
    temp=( struct Node*)malloc(sizeof( struct Node));
    temp->data=value;
    temp->next=NULL;
     if (head == NULL)
     {
        temp->prev=NULL;
        head=temp;
        
     }
     else
    {struct Node*ptr;
        ptr= head;
        while (ptr->next !=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next=temp;
        temp->next=NULL;
    }
        printf("Node With Value %dinserted at the end.\n",value);
}
void Delete_At_Last()
{  if (head == NULL) {
        printf("Linked list is empty, Delition is Not possible\n");
    }
    else
    {
        struct Node *ptr;
            
        ptr=head;
        while (ptr->next !=NULL)
        {
            ptr=ptr->next;
        }
        if(ptr->prev!=NULL){
        ptr->prev->next=NULL;
        }else{
            head=NULL;
        }
        free(ptr);
    }
printf("Last Node deleted successfullu. \n");
}
void Delete_Before_Specified_position(int pos)
{    if (head == NULL)
    {
        printf("Linked list is empty, Delition is Not possible\n");
    }
        struct Node*ptr ;
        ptr=head;
        int count = 1;
        while (count < pos-1 && ptr->next != NULL)
        {
            ptr = ptr->next;
            count++;
        }
        if (count<pos-1 || ptr == head)
        {
            printf("Position does not Exist.\n");
        }
           struct Node*temp = ptr->next;
            ptr->next = temp->next;
            if(temp->next!=NULL){
             temp->next->prev=ptr;}
            free(temp);
            printf("Node before position%D deleted successfully.\n",pos);
    }

void display()
{
 if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        struct Node*ptr;
        ptr = head;
        while (ptr != NULL)
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}
int main()
{

    int ch, value, pos;
    printf("1. Insert_At_Front\n");
    printf("2. Insert_At_end\n");
    printf("3. Delete_Last\n");
    printf("4. Delete_Before_specified_position\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    {
        printf("Enter your choice: \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &value);
            insert_At_Front(value);
            display();
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d", &value);
            insert_At_End( value);
                display();
            break;
        case 3:
            Delete_At_Last();
                display();
            break;
        case 4:
            printf("Enter Position at you want to delete: ");
            scanf("%d", &pos);
            Delete_Before_Specified_position(pos);
            display();
            break;

        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
        while (ch != 6);
    }
}
