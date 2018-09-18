#include <iostream>
#include <iterator>
#include <numeric>

using namespace std;


int findSumIter(int nums[], int n)
{
    if (n <= 0)
        return 0;
    return (findSumIter(nums, n - 1) + nums[n - 1]);
}

int findSum(int d[])
{
    int n = sizeof(d) / sizeof(d[0]);
    return findSumIter(d, n);
}

int main()
{
    //double test[5] = {12.1, 14.0, 16.45, 18.33, 19.9};
    //int N = sizeof(test) / sizeof(test[0]); // 
    int  arr[] = {1, 2, 3, 4, 5, 6};
    //printf("%f", findSum(arr));
    printf("%d\n", findSum(arr));
    return 0;
}

