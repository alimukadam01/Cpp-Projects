#include<iostream>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int lb, int ub)
{
    int pivot = A[lb];

    while (A[lb] < A[ub])
    {
        while (A[lb] <= pivot)
        {
            lb++;
        }

        while(A[ub] > pivot)
        {
            ub--;
        }

        if(A[lb] < A[ub])
        {
            swap(&A[lb], &A[ub]);
        }
    }

    swap(&A[ub], &pivot);
    return A[ub];

}

void quickSort(int a[], int lb, int ub)
{
    int loc = partition(a, lb, ub);
    quickSort(a, lb, loc - 1);
    quickSort(a, loc + 1, ub);
    
}

int main()
{
    int a[] = {2, 24, 45, 1, 13, 10, 44, 11, 0, 2, 15};
    int lb = 0;
    int ub = 10;

    quickSort(a, lb, ub);

    for (int i=0; i < 11; i++)
    {
        cout << a[i] << " ";
    }

    cout << "hello world" << endl;

    return 0;    
}
