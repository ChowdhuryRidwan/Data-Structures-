#include <iostream>

using namespace std;

int Partition(int *A, int start, int End)
{
    int pivot=A[End];
    int pIndex=start;
    for(int i=start; i<End; i++)
    {
        if(A[i]<=pivot)
        {
        swap(A[i],A[pIndex]);
        pIndex++;
        }
    }
    swap(A[pIndex],A[End]); //Swap pivot with element at partition index;
    return pIndex; //returns the index of the pivot
}

void quickSort(int *A, int start, int End)
{
    if(start<End)
    {
        int pIndex=Partition(A,start,End);
        quickSort(A,start,pIndex-1);
        quickSort(A,pIndex+1,End);
    }
}

int main()
{
    int A[]={7,2,1,6,8,5,3,4};
    quickSort(A,0,7);
    cout <<"The sorted numbers are now: ";
    for(int i=0; i<8; i++)
    {
        cout <<A[i]<<" ";
    }
    return 0;
}
