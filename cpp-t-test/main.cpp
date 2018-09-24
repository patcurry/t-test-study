#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

// lifted the math from geeksforgeeks.com
// I was trying to get too crazy with functional stuff
// mean function
float Mean(float arr[], int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + arr[i];
    return sum / n;
}

float standardDeviation(float arr[], int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + ((arr[i] - Mean(arr, n)) * (arr[i] - Mean(arr, n)));
    return sqrt(sum / (n - 1));
}

float tTest(float arr1[], int n,
            float arr2[], int m)
{
    float mean1 = Mean(arr1, n);
    float mean2 = Mean(arr2, m);
    float sd1 = standardDeviation(arr1, n);
    float sd2 = standardDeviation(arr2, m);

    //cout << mean1 << endl;
    //cout << mean2 << endl;
    //cout << sd1 << endl;
    //cout << sd2 << endl;

    // something is wrong here, this does not seem
    // to be returning a float
    float t_test = (mean1 - mean2) / 
                    sqrt(
                         ((sd1 * sd1) / n) + 
                         ((sd2 * sd2) / m)
                    );
    return t_test;

}

int main()
{
    float arr1[] = {1, 2, 3, 4, 5.1};
    float arr2[] = {3, 4, 5, 6, 7};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    int dof = n + m - 2;

    float result = tTest(arr1, n, arr2, m);
    
    cout << "T Score: <THIS IS WRONG> " << tTest(arr1, n, arr2, m) << endl;
    cout << "dof: " << dof << endl;
    
    return 0;
}