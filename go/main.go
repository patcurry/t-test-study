package main

import "fmt"
import "math"


func main() {
   // an int array with 5 elements
   var  balance = []float64 {10.1, 20, 30, 17, 50}
   var avg float64


   var  one = []float64 {10, 11, 12, 13, 14}
   var  two = []float64 {5, 10, 12, 18, 20}

   // pass array as an argument
   avg = mean(balance)
   squareDiffs(balance)

   // output the returned value
   fmt.Printf( "Average value is: %f\n", avg )
   fmt.Printf( "Standard Deviation is: %f\n", stdDev(balance))
   //for i=0; i < len(balance); i++; { fmt.Println(balance[i]) }
   fmt.Println(twoSampleTTest(one, two))
}

func sum(x float64, y float64) float64 {
    return x + y
}

func mean(arr []float64) float64 {
   var sum float64  

   for i:=0; i < len(arr); i++ {
      sum += arr[i]
   }

   return float64(sum / float64(len(arr)))
}

func squareDiffs(arr []float64) []float64 {
    var result = make([]float64, len(arr))

    for i:=0; i < len(arr); i++ {
        result[i] = math.Pow((arr[i] - mean(arr)), 2)
    }

    return result
}

func sampleStdDevDenom(arr []float64) float64 {
    var sum float64

    // get sum of array
    for i:=0; i < len(arr); i++ {
        sum += arr[i]
    }

    return sum / float64(len(arr) - 1)
}

func stdDev(arr []float64) float64 {
    return math.Sqrt(sampleStdDevDenom(squareDiffs(arr)))
}

/*
    def two_sample_t_test(self, arr1, arr2):
        numerator = abs(self.mean(arr1) - self.mean(arr2))
        arr1_denom = self.std_dev(arr1) / len(arr1)
        arr2_denom = self.std_dev(arr2) / len(arr2)
        denominator = sqrt(arr1_denom + arr2_denom)
        dof = len(arr1) + len(arr2) - 2
        t_score = numerator / denominator
        return {'T Score': t_score, 'dof': dof}

    def ttest_result(self):
        return self.two_sample_t_test(self.arr1, self.arr2)
*/

func twoSampleTTest(arr1 []float64, arr2 []float64) map[string]float64 {
    // make the map
    res := make(map[string]float64)

    numerator := math.Abs(mean(arr1) - mean(arr2))
    arr1Denom := stdDev(arr1) / float64(len(arr1))
    arr2Denom := stdDev(arr2) / float64(len(arr2))
    denominator := math.Sqrt(arr1Denom + arr2Denom)
    dof := float64(len(arr1) + len(arr2) - 2)
    tScore := numerator / denominator
    res["dof"] = dof
    res["T Score"] = tScore
    return res
}




