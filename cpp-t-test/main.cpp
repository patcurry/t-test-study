
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
float mean(float arr[], int n);
float standard_deviation(float arr[], int n);
float t_test(float arr1[], int n, float arr2[], int m); // This is not giving me a result that make sense with the two test arrays

int main()
{
    // I would rather not do it this way, but
    // because I know how large the csv file is
    // I am just going to make two arrays that 
    // are the correct lengths for the csv file
    // first get the program working, then refactor
    float male[10];
    float female[10];

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
                //male[col] = stof(val.c_str());
                male[col] = stof(val);
                //cout << "m " << male[col] << endl;
            } else {
                //female[col] = stof(val.c_str());
                female[col] = stof(val);
                //cout << "f " << female[col] << endl;
            }
        }
    }

    // something is really wrong here, this is printing out crazy numbers
    for (int i=0; i < 10 ; i++){
        cout << "m " << male[i] << endl;
        cout << "f " << female[i] << endl;
    }


    int n = sizeof(male) / sizeof(male[0]);
    int m = sizeof(female) / sizeof(female[0]);

    int dof = n + m - 2;

    float result = t_test(male, n, female, m);

    // return result
    cout << "T-Score: " << result << ", dof: " << dof << endl;
    return 0;
}

float mean(float arr[], int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + arr[i];
    return sum / n;
}

float standard_deviation(float arr[], int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + ((arr[i] - mean(arr, n)) * 
                     (arr[i] - mean(arr, n)));
    return sqrt(sum / (n - 1));
}

float t_test(float arr1[], int n,
              float arr2[], int m)
{
    float mean1 = mean(arr1, n);
    float mean2 = mean(arr2, m);
    float sd1 = standard_deviation(arr1, n);
    float sd2 = standard_deviation(arr2, m);

    float result = (mean1 - mean2) / sqrt(((sd1 * sd1) / n) + ((sd2 * sd2) / m));
    return result;

}
