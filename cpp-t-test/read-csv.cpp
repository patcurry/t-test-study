#include <iostream>
#include <fstream>
using namespace std;

int populate(double array[], int number);
void spit(double array1[], int number);
int main()
{
    //string maleWeight; // can I make this an array to populate?
    //string femaleWeight;

//    ifstream data("../height-data.csv");


 //   string value;

  //  if(!data.is_open()) cout << "Error: File is not open" << endl;

   // getline(data, value); // skip the header by skipping the first line

    // cycle through the rest of the values, separated by commas
    //while (getline(data, value, ',')){
    // cycle through the lines without a separator (I guess default is the newline)
    //while (getline(data, value)){
     //   cout << string(value) << endl;
    //}

    double bucky[5];
    populate(bucky, 5);
    spit(bucky, 5);
    system("pause");

    return 0;
}

int populate(double array1[], int number)
{
    double input;
    int i;
    for(i=0; i<number; i++){
        cout << "enter value for item " << (i+1) << endl;
        cin >> input;
        array1[i]=input;
    }
    return i;
}
void spit(double array1[], int number)
{
    int i;
    for(i=0;i<number;i++) {
        cout << "The value of item " << (i+1) << " is " << array1[i] << endl;
    }
}