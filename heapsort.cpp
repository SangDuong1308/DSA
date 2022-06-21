#include <iostream>
using namespace std;
void heapRebuild(int start, int arr[], int n)
{
    int leftChild = 2 * start + 1;
    if (leftChild >= n) return;
    int largerChild = leftChild;
    int rightChild = 2 * start + 2;
    if (rightChild < n)
    {
        if (arr[rightChild] > arr[leftChild])
        {
            largerChild = rightChild;
        }
    }
    if (arr[start] < arr[largerChild])
    {
        swap(arr[largerChild], arr[start]);
        heapRebuild(largerChild, arr, n);
    }
}   
void heapSort(int arr[], int n)
{
    // Build initial heap
    for (int index = (n - 1) / 2; index >= 0; index--)
        heapRebuild(index, arr, n);
    swap(arr[0], arr[n - 1]); // swap the largest element to the end
    int heapSize = n - 1;     // Heap region size decreases by 1
    while (heapSize > 1)
    {
        heapRebuild(0, arr, heapSize);
        heapSize--;
        swap(arr[0], arr[heapSize]);
    }
}
int main()
{
    int a[1000],n;
    cin>>n;
    for (int i=0 ;i<n;i++)
    {
        cin>>a[i];
    }
    heapSort(a,n);
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}