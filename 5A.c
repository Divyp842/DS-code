#include <stdio.h>
int isempty();
int isfull();
void enqueue(int);
int dequeue();
void display();

int q[5] = {0};
int front = -1;
int rear = -1;

int main()
{
    int ch, ele;
    do
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.exit");
        printf("Enter Your Choice:-");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (isfull())
                printf("\n Queue is Full");
            else
            {
                printf("\n Enter Element :-");
                scanf("%d", &ele);
                enqueue(ele);
            }
            break;
        case 2:
            if (isempty())
                printf("\nQueue Is Empty ");
            else
            {
                ele = dequeue();
                printf("\n %d is Deleted element", ele);
            }
            break;
        case 3:
            if (isempty())
                printf("\nQueue Is Empty ");
            else
                display();
            break;
        }
    } while (ch != 4);
}

int isempty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}
int isfull()
{
    if (rear == 4)
        return 1;
    else
        return 0;
}
void enqueue(int ele)
{
    if (rear == -1)
        front = front + 1;
    rear = rear + 1;
    q[rear] = ele;
}
int dequeue()
{
    int ele;
    ele = q[front];
    front = front + 1;
    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
    return ele;
}
void display()
{
    int i;
    printf("\n Queue =");
    for (i = rear; i >= front; i--)
        printf("| %d |", q[i]);
}
