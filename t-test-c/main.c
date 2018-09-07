#include <stdio.h>

// copied this little average program off the web. 
// have to figure out how to read a file into these things
/*
int main()
{
    int marks[10], i, n, sum = 0, avg;
    printf("Enter n: ");
    scanf("%d", &n);
    for (i=0; i < n; ++i) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &marks[i]);
        sum += marks[i];
    }
    avg = sum/n;

    printf("Average = %d", avg);
    return 0;
}
*/

// another program from the internet
float average(float age[]);

int main()
{
    float avg, age[] = {23.4, 55, 22.6, 3, 40.5, 18};
    avg = average(age); // only name of array is passed as argument
    printf("%.2f", avg);
    return 0;
}

float average(float age[])
{
    int i;
    float avg, sum = 0.0;
    for (i = 0; i < 6; i++) { // is this supposed to be ++i or i++?
        sum += age[i];
    }
    avg = (sum / 6);
    return avg;
}