#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL, *ptr;
void Insert_At_End(int value)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL)
    {
        head = temp;
        temp->data = value;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->next = NULL;
    }
}

void insert_Before_specified_ele(int value, int pos)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL)
    {
        head = temp;
        temp->next = head;
    }
    else
    {
        struct Node*ptr = head;
        int count = 1;
        while (count < pos - 1 && ptr->next != head)
        {
            ptr = ptr->next;
            count++;
        }
        temp->next = ptr->next;
        ptr->next = temp;
        if (pos == 1)
        {
            head = temp;
        }
    }
}
void deletefirst()
{
    if (head == NULL)
    {
        printf("Linked list is empty, Delition is Not possible\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        if (head == ptr)
        {
            free(ptr);
            head = NULL;
        }
        else
        {
            ptr->next = head->next;
            free(head);
            head = ptr->next;
        }
    }
}
void delete_After_Position(int pos)
{
    if (head == NULL)
    {
        printf("Linked list is empty, Delition is Not possible\n");
    }
    else
    {
        struct Node*ptr = head;
        int count = 1;
        while (count < pos && ptr->next != head)
        {
            ptr = ptr->next;
            count++;
        }
        if (ptr->next == head)
        {
            printf("Position does not Exist.\n");
        }
        else
        {
           struct Node*temp = ptr->next;
            ptr->next = temp->next;
            free(temp);
        }
    }
}
void display()
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
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
    printf("1. Insert_At_end\n");
    printf("2. Insert_Before_specified_position \n");
    printf("3. Delete_First\n");
    printf("4. Delete_After_specified_position\n");
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
            Insert_At_End(value);
            display();
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d", &value);
            printf("Enter Position: ");
            scanf("%d", &pos);
            insert_Before_specified_ele(value, pos);
                display();
            break;
        case 3:
            deletefirst();
                display();
            break;
        case 4:
            printf("Enter Position at you want to delete: ");
            scanf("%d", &pos);
            delete_After_Position(pos);
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
