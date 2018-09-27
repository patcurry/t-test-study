// Math lifted from geeks for geeks how to implement ttest with java
import java.util.*;
import java.io.*;

class Main {
    // function to find mean
    // I would rather use something like a reduce statement, but everyone
    // loves for loops. Except me.
    static double Mean(double arr[], int n) {
        double sum = 0;
        for (int i = 0; i < n; i++) 
            sum = sum + arr[i];
        return sum / n;
    }

    // function to find standard deviation of given array
    static double standardDeviation(double arr[], int n) {
        double sum = 0;
        for (int i = 0; i < n; i ++)
            sum = sum + Math.pow(arr[i] - Mean(arr, n), 2);
        return (double)Math.sqrt(sum / (n - 1));
    }

    // Function to find t-test of two sets of statistical data (arrays?)
    static double tTest(double arr1[], int n, double arr2[], int m) {
        double mean1 = Mean(arr1, n);
        double mean2 = Mean(arr2, n);
        double denom1 = standardDeviation(arr1, n) / n;
        double denom2 = standardDeviation(arr2, m) / m;

        double numerator = mean1 - mean2;
        double denominator = Math.sqrt(denom1 + denom2);

        double result = numerator / denominator;
        return result;
    }

    static int dof(int n, int m) {
        return n + m - 2;
    }

    // Driver code
    public static void main(String args[]) {
        double arr1[] = { 1, 2, 3, 4, 5 };
        double arr2[] = { 3, 4, 5, 6, 7 };
        int n = arr1.length;
        int m = arr2.length;

        System.out.println("T-Score: " + tTest(arr1, n, arr2, m));
        System.out.println("dof: " + dof(n, m));
    }
}