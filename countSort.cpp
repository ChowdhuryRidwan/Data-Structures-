#include <iostream>
#include <string.h>
#include <cstring>
# define RANGE 255
using namespace std;

void countSort(int arr[],int n)
{
    cout <<"Size of array"<<n;
    int output[n];
    int coun[RANGE];
    cout <<"Coming here" <<endl;
    for(int i=0; i<RANGE; i++)
    {
        coun[i]=0;
    }
    //How is it storing the count
    for(int i=0; arr[i]; ++i)
    {
        cout <<"Storing count"<<" ";
        ++coun[arr[i]];
    }
    for(int i=0; i<RANGE; ++i)//why ++i and not i++
    {
        cout <<"Adding prev count"<<endl;
        coun[i]+=coun[i-1];
    }
    //How is it forming the output array
    for(int i=0; arr[i]; ++i)
    {
        output[coun[arr[i]]-1]=arr[i];
        --coun[arr[i]];
        cout <<"forming output array"<<endl;
    }
    for(int i=0; arr[i];++i)
    {
        arr[i]=output[i];
    }
}

int main()
{
    int n;
    int a[10];
    cout <<"Enter the amount of random numbers you want to insert in array: ";
    cin >>n;
    cout <<"Enter the numbers: ";
    for(int i=0; i<n; i++)
    {
        cin >>a[i];
    }
    countSort(a,n);
    cout <<"The sorted array is: ";
    for(int i=0; i<n; i++)
    {
        cout <<a[i]<<" ";
    }
    return 0;
}
