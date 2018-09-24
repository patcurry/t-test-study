#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

// lifted the math from geeksforgeeks.com
// I was trying to get too crazy with functional stuff
// mean function
double Mean(double arr[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + arr[i];
    return sum / n;
}

double standardDeviation(double arr[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + ((arr[i] - Mean(arr, n)) * (arr[i] - Mean(arr, n)));
    return sqrt(sum / (n - 1));
}

double tTest(double arr1[], int n,
            double arr2[], int m)
{
    double mean1 = Mean(arr1, n);
    double mean2 = Mean(arr2, m);
    double sd1 = standardDeviation(arr1, n);
    double sd2 = standardDeviation(arr2, m);

    //cout << mean1 << endl;
    //cout << mean2 << endl;
    //cout << sd1 << endl;
    //cout << sd2 << endl;

    // something is wrong here, this does not seem
    // to be returning a double
    double t_test = (mean1 - mean2) / 
                    sqrt(
                         ((sd1 * sd1) / n) + 
                         ((sd2 * sd2) / m)
                    );
    return t_test;

}

int main()
{
    double arr1[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double arr2[] = {3.0, 4.0, 5.0, 6.0, 7.0};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    int dof = n + m - 2;

    double result = tTest(arr1, n, arr2, m);
    
    cout << "T Score: <THIS IS WRONG> " << tTest(arr1, n, arr2, m) << endl;
    cout << "dof: " << dof << endl;
    
    return 0;
}