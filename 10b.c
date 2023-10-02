#include <stdio.h>
void mergesort();
void merg();
void mergesort(int a[], int first, int last)  
{
    int mid;
    if (first < last)
    {
        mid = (first + last) / 2;
        mergesort(a, 0, mid);
        mergesort(a, mid + 1, last);
        merg(a, first, mid, last);
    }
}
void merg(int a[], int first, int mid, int last)
{
    int b[100];
    int i, j, k;
    i=first;
    j=mid+1;
    k=first;
    while (i<=mid&&j<=last)
    {
       if(a[i]<=a[j])
       b[k++]=a[i++];
       else
       b[k++]=a[j++];
    }
    if(i>mid)
    {
        while(j<=last)
        b[k++]=a[j++];
    }
        else
        {
            while(i<=mid)
            b[k++]=a[i++];
        }
    for(i=first;i<=last;i++)
    a[i]=b[i];

}
int main()
{
    int a[50], n, i;
    printf("Enter size of array:");
    scanf("%d", &n);
    printf("\nEnter Elements:");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    mergesort(a, 0, n - 1);
    printf("\nSorted Elements are:");
    for(i=0;i<n;i++)
    printf("%d",a[i]);
    return 0;
}
