#include <iostream>
#include <fstream>
#include <math.h>
#include <sstream>
#include <vector>
using namespace std;

// lifted the math from geeksforgeeks.com

// prototype functions. why? I donno, imperative programming.
// should these be in a class?
float mean(vector <float> vec, int n);
float standard_deviation(vector <float> vec, int n);
float t_test(vector <float> vec1, int n, vector <float> vec2, int m); // This is not giving me a result that make sense with the two test arrays

vector <float> male;
vector <float> female;

int main()
{
    string line;
    ifstream myfile("./height-data.csv");

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
        // the male vector, and the values from the
        // odd column into the female vector 
        for (int col=0; col < 2; col++) {
            string val;
            getline(iss, val, ',');
            if (col % 2 == 0) {
                male.push_back(stof(val));
            } else {
                female.push_back(stof(val));
            }
        }
    }

    int n = male.size();
    int m = female.size();
    int dof = n + m - 2;
    float result = t_test(male, n, female, m);

    cout << "T-Score: " << result << ", dof: " << dof << endl;
    return 0;
}

float mean(vector <float> vec, int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + vec[i];
    return sum / n;
}

float standard_deviation(vector <float> vec, int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + ((vec[i] - mean(vec, n)) * 
                     (vec[i] - mean(vec, n)));
    return sqrt(sum / (n - 1));
}

float t_test(vector <float> vec1, int n,
              vector <float> vec2, int m)
{
    float mean1 = mean(vec1, n);
    float mean2 = mean(vec2, m);
    float denom1 = standard_deviation(vec1, n) / n;
    float denom2 = standard_deviation(vec2, m) / m;

    float numerator = mean1 - mean2;
    float denominator = sqrt(denom1 + denom2);

    float result = numerator / denominator;
    return result;
}