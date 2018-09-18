#include <iostream>
#include <iterator>
#include <numeric>

using namespace std;

// write the math first
// how do I pass an array into here?
/*
        << std::accumulate(std::begin(nums),
                           std::end(nums),
                           0.0)
                           */


// how do I get length of the array?
double mean(double nums[])
{
      return std::accumulate(std::begin(nums),
                             std::end(nums),
                             0.0);
}


// main program
int main()
{
    double test[5] = {12.1, 14.0, 16.4, 18.3, 19.9};
    double avg;

    avg = mean(test);

    cout << avg << endl;
    return 0;
}



/*
int main()
{
    double nums[] = {1.1,5.2,3.0,2.8,7.9,8.4,100.49,3.0};
    std::cout
        << std::accumulate(std::begin(nums),
                           std::end(nums),
                           0.0)
        << '\n';
}
*/
