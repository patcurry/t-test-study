# Crystal's syntax is remarkably similar to Ruby's
require "csv"

class TTest
    def initialize(arr1 : Array(Float32), arr2 : Array(Float32)) : Array(Float32)
        @arr1 = arr1
        @arr2 = arr2
    end

    def add(x : Int, y : Int) : Int
        x + y
    end

    def mean(arr : Array(Float32)) : Float32
        # a = accumulator, c = current
        arr.reduce{ |a, c| a + c } / arr.size
    end

    def sampleStdDevDenom(arr : Array(Float32)) : Float32
        # this is a mean divided by the array size - 1, it should have a better name
        arr.reduce{ |a, c| a + c } / (arr.size - 1)
    end

    def squareDifferences(arr : Array(Float32)) : Array(Float32)
        arr.map{ |a| (a - mean(arr))**2 }
    end

    def standardDeviation(arr : Array(Float32)) : Float32
        Math.sqrt(sampleStdDevDenom(squareDifferences(arr)))
    end

    def twoSampleTTest(arr1 : Array(Float32), arr2 : Array(Float32)) : Hash(String, Float32) 
        # this should return a hash with T Score and dof
        numerator = (mean(arr1) - mean(arr2)).abs
        denominator = Math.sqrt((standardDeviation(arr1) / arr1.size) + (standardDeviation(arr2) / arr2.size))
        dof = arr1.size + arr2.size - 2
        tScore = numerator / denominator
        #{"T Score" => 1.5_f32, "dof" => 1.0_f32}
        {"T Score" => tScore, "dof" => dof.to_f32}
    end

    def ttest_result
        twoSampleTTest(@arr1, @arr2)
    end
end

#Array1 = [1,2,3,4,5] of Float32
#Array2 = [3,4,5,6,7] of Float32
#
#ttest = TTest.new(Array1, Array2)

#p ttest.add(1,2)
#p ttest.standardDeviation(Array1)
#p ttest.twoSampleTTest(Array1, Array2)
#p ttest.ttest_result

# I am out of my depth here.
# I shoudl probably turn to ruby docs to figure this out hahaha

df = File.open("./height-data.csv", mode="r")
#csv = CSV.new(df, headers: true)
#csv = CSV.parse(a)
#csv.map{ |r| p r[1] }
csv = CSV.parse(df)
csv.map{
    p csv[2][0]
}