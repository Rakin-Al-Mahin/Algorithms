#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int loc = low - 1;

    for(int i = low; i <= high-1; i++)
    {
        if(a[i] <= pivot)
        {
            loc++;
            swap(a[loc], a[i]);
        }
    }
    swap(a[loc+1], a[high]);
    return loc + 1;
}

void quickSort(int a[], int low, int high)
{
    if(low < high)
    {
        int pos = partition(a, low, high);

        quickSort(a, low, pos-1);
        quickSort(a, pos+1, high);
    }
}

void disply(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int a[] = {15, 20, 5, 7, 29, 11, 1};
	int n = sizeof(a)/sizeof(a[0]);

	quickSort(a, 0, n-1);
	cout << "The sorted array is: ";
	disply(a, n);

    return 0;
}
