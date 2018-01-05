#include <iostream>
using namespace std;

void counting_sort(int A[], int k, int n)
{
    int i, j;
    int B[15], C[100];
    for (i = 0; i <= k; i++)
        C[i] = 0;
    for (j = 1; j <= n; j++)
        C[A[j]] = C[A[j]] + 1;
    for (i = 1; i <= k; i++)
        C[i] = C[i] + C[i-1];
    for (j = n; j >= 1; j--)
    {
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
    cout <<"The Sorted array is : "<<endl;
    for (i = 1; i <= n; i++)
        cout <<B[i]<<" ";
}

int main()
{
    int n, k = 0, A[15], i;
    cout <<"Enter the amount of numbers: ";
    cin >>n;
    cout <<"\nEnter the elements to be sorted :\n";
    for (i = 1; i <= n; i++)
    {
        cin >>A[i];
        if (A[i] > k) {
            k = A[i];
        }
    }
    counting_sort(A, k, n);
    cout <<endl;
    return 0;
}
