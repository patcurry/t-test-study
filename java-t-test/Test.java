/* start with program to get sum of elements in given array */
/* How about we get the average of elements in given array */
/*
class Test {
    // is there an init method?
    static double arr[] = {1, 2, 3.1, 4, 5};

    // method
    static double sum() {
        double sum = 0;
        int i;

        for (i = 0; i < arr.length; i++)
          sum += arr[i];

        return sum;
    }

    // method
    static double mean() {
        return sum() / arr.length;
    } 

    // Driver method
    public static void main(String[] args) {
        System.out.println("Sum of given array is " + sum());
        System.out.println("Average of given array is " + mean());
    }
}
*/

public class Test {
    // actually it's a point
    public int x = 0;
    public int y = 0;
    // constructor
    public Test(int a, int b) {
        x = a;
        y = b;
    }
}