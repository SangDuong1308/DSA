#include<iostream>
#include<time.h>
using namespace std;
void merge(int arr[], int first, int mid, int last)
{
    int first1 = first,last1 = mid;
    int first2 = mid + 1,last2 = last;
    int tempArr[1000];
    int index = first1;
    while ((first1<=last1) && (first2<=last2))
    {
        if (arr[first1]<=arr[first2])
        {
            tempArr[index++] = arr[first1++];
        }
        else 
        {
            tempArr[index++] = arr[first2++];
        }
    }
    while (first1<=last1)
    {
        tempArr[index++] = arr[first1++];
    }
    while (first2<=last2)
    {
        tempArr[index++] = arr[first2++];
    }
    for (index = first;index<=last;++index)
    {
        arr[index] = tempArr[index];
    }   
}
void mergesort(int arr[], int first, int last)
{
    if (first<last)
    {
        int mid = (first+last)/2;
        mergesort(arr,first,mid);
        mergesort(arr,mid+1,last);
        merge(arr,first,mid,last);
    }
}
int main()
{
    int a[1000],n;
    cin>>n;
    srand(time(NULL));
    for (int i=0;i<n;i++)
    {
        a[i]=rand()%100;
    }
    mergesort(a,0,n-1);
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    system("pause");
    return 0;
}