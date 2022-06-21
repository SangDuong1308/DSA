#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int partition1(int a[], int l, int r)
{
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (a[j] <= pivot)
        {
            ++i;
            swap(a[i], a[j]);
        }
    }
    ++i;
    swap(a[i], a[r]);
    return i;
}
int partition2(int a[], int l, int r)
{
    int pivot = a[l];
    int i = l - 1, j = r + 1;
    while (1)
    {
        do
        {
            ++i;
        } while (a[i] < pivot);
        do
        {
            --j;
        } while (a[j] > pivot);
        if (i < j)
        {
            swap(a[i], a[j]);
        }
        else
            return j;
    }
}
void quicksortlomuto(int a[], int l, int r)
{
    if (l >= r)
        return;
    int p = partition1(a, l, r);
    quicksortlomuto(a, l, p - 1);
    quicksortlomuto(a, p + 1, r);
}
void quicksorthoare(int a[], int l, int r)
{
    if (l >= r)
        return;
    int p = partition2(a, l, r);
    quicksorthoare(a, l, p);
    quicksorthoare(a, p + 1, r);
}
void quicksortV3(int a[], int l, int r)
{
    int pivot = a[(l + r) / 2];
    int i = l, j = r;
    do
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            ++i;
            --j;
        }
    } while (i < j);
    if (l < j)
        quicksortV3(a, l, j);
    if (i < r)
        quicksortV3(a, i, r);
}
int main()
{
    int a[1000], n;
    cin >> n;
    // srand(time(NULL));
    // for (int i = 0; i < n; i++)
    // {
    //     a[i] = rand() % 1000;
    // }
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quicksortlomuto(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}