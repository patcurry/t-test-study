package main

import "fmt"
import "math"


func main() {
   // an int array with 5 elements
   var  balance = []float64 {1000.1, 2, 3, 17, 50}
   var avg float64

   // pass array as an argument
   avg = mean(balance)
   squareDiffs(balance)

   // output the returned value
   fmt.Printf( "Average value is: %f\n", avg )
   //for i=0; i < len(balance); i++; { fmt.Println(balance[i]) }
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

    for i:=0; i < len(arr); i ++ {
        result[i] = math.Pow((arr[i] - mean(arr)), 2)
    }

    return result
}

