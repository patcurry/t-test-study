#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


/*
int main() {
    string line;
    ifstream myfile("../height-data.csv");

    if (!myfile.is_open()) {
        cout << "Unable to open file" << endl;
    }
    
    while (getline (myfile, line)) {
        cout << line << endl;
    }
    

    return 0;
}
*/

/*
void Core::parseCSV()
{
    std::ifstream  data("height-data.csv");
    std::string line;
    std::vector<std::vector<std::string> > parsedCsv;
    while(std::getline(data,line))
    {
        std::stringstream lineStream(line);
        std::string cell;
        std::vector<std::string> parsedRow;
        while(std::getline(lineStream,cell,','))
        {
            parsedRow.push_back(cell);
        }

        parsedCsv.push_back(parsedRow);
    }
};
*/


/*
int main()
{

    float data[2][11];
    ifstream file("../height-data.csv");

    for (int row = 0; row < 2; row++) {
        string line;
        getline(file, line);
        if ( !file.good() )
            break;
        
        stringstream iss(line);

        for (int col = 0; col < 11; col++) {
            string val;
            getline(iss, val, ',');
            if ( !iss.good() )
                break;

            stringstream converter(val);
            converter >> data[row][col];
        }
    }

    cout << data[1][2] << endl;

    return 0;
}
*/


/*
int populate(double array[], int number);
void spit(double array1[], int number);
int main()
{
    //double maleWeight[]; // can I make this an array to populate?
    //double femaleWeight[];

    ifstream data("../height-data.csv");


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
*/