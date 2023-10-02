#include<stdio.h>
int s[5]={0} , top = -1;

void push()
{
    int ele;
        if (top == 4)
               printf("\n stack is over flow");
        else
        {
            printf("\n Enter Element to Push");
            scanf("%d",&ele);
            push(ele);
        }
}
void pop()
{ 
      if (top == -1)
               printf("\n stack is under flow");
        else
        {
            printf("\n %d is poped Element!",top--);
        }
}
void peep()
{
       if (top == -1)
               printf("\n stack is Empty!");
        else
        {
            printf("\n %d is Elemment at Top",s[top]);
        }
}
void change()
{
    int num,pos;
  if (top == -1)
               printf("\n stack is Empty!");
        else
        {
            printf("\n Enter postion of Element do you want to change :");
            scanf("%d",&pos);
             if (pos<1 || pos> top+1)
             printf("Invalid Postion !");
             else{
                printf("Enter the number that do you want to change :");
                scanf("%d",&num);
                s[top - pos +1]= num;
             printf("Element has Changed!");
             }
        }
}
void display()
{       
if (top == -1)
    printf("\n stack is under flow!");    
 else
    {
    int i;
    for (i=top;i>=0;i++)
    printf("\n | %d |", s[i]);
    }
}
int main()
{
    int ch;
    do
    {
        printf("\n1.PUSH\n2.POP\n3.PEEP\n4.CHANGE\n5.DISPLAY\n6.EXIT");
        printf("\nEnter Your Choice:-");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: 
           push();
            break;
        case 2: 
             pop();
            break;
        case 3: 
             peep();
            break;
        case 4: 
             change();
            break;
        case 5: 
             display();
            break;
        case 6: 
            break;
        default:
         printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (ch!=6);
}