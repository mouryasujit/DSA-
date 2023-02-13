// By sujitkumar mourya
#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivotIndex = (start + count);
    swap(arr[pivotIndex], arr[start]);
    int k = start;
    int j = end;
    while ((k < pivotIndex) && (j > pivotIndex))
    {
        while (arr[k] <= pivot)
        {
            k++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (k < pivotIndex && j > pivotIndex)
        {
            swap(arr[j--], arr[k++]);
        }
    }
    return pivotIndex;
}
void quickSort(int arr[], int s, int e)
{
    if (s > e)
        return;

    int pi = partition(arr, s, e);

    quickSort(arr, s, pi - 1);
    quickSort(arr, pi + 1, e);
}
int main()
{
    int arr[7] = {10, 80, 30, 90, 40, 50, 70};
    quickSort(arr, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
