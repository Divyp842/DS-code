// Introduction to pointer ,Call By Value and Call By reference
#include<stdio.h>
void callByVal(int x, int y);
void callByRef(int *x, int *y);


void callByVal(int x ,int y)
{
int temp =x;
x=y;
y=temp;
printf("value after swapping : \nX=%d , Y=%d ,x,y");
}
void callByRef(int *x,int *y)
{
int temp =*x;
*x=*y;
*y=temp;
printf("value after swapping : \nX=%d , Y=%d ,*x,*y");
}
int main()
{
    int x,y;
    printf("Enter the value of X and Y:");
    scanf("%d %d", &x ,&y);
    printf("Call By Reference Swapping :\n");
    callByRef(&x,&y);
    printf("\nCall By Value Swapping :\n");
    callByVal(x,y);
    return 0;
}