
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
using namespace std;

// lifted the math from geeksforgeeks.com

// prototype functions. why? I donno
// should these be in a class?
double mean(double arr[], int n);
double standard_deviation(double arr[], int n);
double t_test(double arr1[], int n, double arr2[], int m); // This is not giving me a result that make sense with the two test arrays

int main()
{
    // I would rather not do it this way, but
    // because I know how large the csv file is
    // I am just going to make two arrays that 
    // are the correct lengths for the csv file
    // first get the program working, then refactor
    double male[10];
    double female[10];

    string line;
    ifstream myfile("../height-data.csv");

    if (!myfile.is_open()) {
        cout << "Unable to open file" << endl;
    }
    // skip the first line
    getline(myfile, line);

    // loop through the rest of the lines
    while (getline(myfile, line)) {
        stringstream iss(line);

        // loop through the columns (only 2 of them)
        // and put the data from the even column into
        // the male array, and the values from the
        // odd column into the female array
        for (int col=0; col < 2; col++) {
            string val;
            getline(iss, val, ',');

            if (col % 2 == 0) {
                male[col] = atof(val.c_str());
                cout << "m " << male[col] << endl;
            } else {
                female[col] = atof(val.c_str());
                cout << "f " << female[col] << endl;
            }
        }
    }


    //double arr1[] = { 10, 20, 30, 40, 50 };
    //double arr2[] = { 1, 29, 46, 78, 99 };

    //int n = sizeof(arr1) / sizeof(arr1[0]);
    //int m = sizeof(arr2) / sizeof(arr2[0]);
    int n = sizeof(male) / sizeof(male[0]);
    int m = sizeof(female) / sizeof(female[0]);

    int dof = n + m - 2;

    //double result = t_test(arr1, n, arr2, m);
    double result = t_test(male, n, female, m);

    // return result
    cout << "T-Score: " << result << ", dof: " << dof << endl;
    return 0;
}

double mean(double arr[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + arr[i];
    return sum / n;
}

double standard_deviation(double arr[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + ((arr[i] - mean(arr, n)) * 
                     (arr[i] - mean(arr, n)));
    return sqrt(sum / (n - 1));
}

double t_test(double arr1[], int n,
              double arr2[], int m)
{
    double mean1 = mean(arr1, n);
    double mean2 = mean(arr2, m);
    double sd1 = standard_deviation(arr1, n);
    double sd2 = standard_deviation(arr2, m);

    double result = (mean1 - mean2) / sqrt(((sd1 * sd1) / n) + ((sd2 * sd2) / m));
    return result;

}
