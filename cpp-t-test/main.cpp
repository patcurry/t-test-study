#include <iostream>

using namespace std;

// write the math first
// how do I pass an array into here?
double mean(double d[], int size)
{
    // declare variables
    int i;
    double sum = 0;
    double avg;

    for (i = 0; i < size; i++) {
        sum += d[i];
    }
    avg = sum / size;

    return avg;
}



// main program
int main()
{
    double test[5] = {12.1, 14.0, 16.4, 18.3, 19.9};
    double avg;

    avg = mean( test, 5 );

    cout << avg << endl;
    return 0;
}