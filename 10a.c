#include<stdio.h>
int main()
{
    int a[20],n,i,j,temp,p,k;
    printf("Entre the size of array:");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
    printf("Enter element:");
    scanf("%d",&a[i]);
    }
for(p=0;p<n-1;p++)
{
for(k=0;k<n-1;k++)
{
    
    if(a[k]>a[k+1])
    {
        temp=a[k];
        a[k]=a[k+1];
        a[k+1]=temp;
    }
}
}
    for(j=0;j<n;j++)
    {
        printf("%d",a[j]);
    }
    return 0;
}
