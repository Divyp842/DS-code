#include<stdio.h>
void insert(int *a,int n)
{
    int idx,val,i;
     printf("\n Enter index position :-");
     scanf("%d", &idx);
     idx--;
     printf("\n Enter the value:-");
     scanf("%d", &val);
     for(i=(n-2);i!=idx;i--)
     a[i+1]=a[i];
     a[i+1]=val;
}
void delete(int *a,int n)
{
    int pst;
    printf("\n Enter which position do you want to delete the number :-");
    scanf("%d", &pst);
    for(int i=pst; i<=n ; i++)
         a[i]=a[i+1];
}
void search(int *a,int n)
{
    int val;
    printf("\n Enter the value do you want to search :-");
    scanf("%d", &val);
     for(int i=0; i<n;i++)
     {
        if (a[i] == val)
            printf("Value found at index %d",i);
     }
}
void display(int *a,int n)
{
     for(int i=0; i<n;i++)
        printf("[%d] %d",i,a[i]);
}
void INT(int*a,int n)
{
    printf("Enter Array Elements :-");
    for(int i=0; i< n; i++)
          scanf("%d",&a[i]);
}
int main()
{
    int a[100],n,ch;
    printf("Enter 10 element of array :- ");
    scanf("%d",n);
    INT(a,n);
    do
    {
        printf("\n1.insert\n2.delete\n3.search\n4.display\n5.exit");
        printf("Enter Your Choice:-");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
              n++;
              insert(a,n); 
            break;
        case 2:   
              n--;
              delete(a,n); 
             
            break;
        case 3:

            search(a,n);
            break;
        case 4: 
            display(a,n);
            break;
        case 5: 
             break; 
          default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (ch!=5);
}