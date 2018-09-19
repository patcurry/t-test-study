array1 = [1,2,3,4,5]
array2 = [3,4,5,6,7]

# m is the average of of array1
# it looks like a reduce function
"""
m = array1.inject{ |sum, el| sum + el }.to_f / array1.size
n = array2.inject{ |sum, el| sum + el }.to_f / array2.size
"""

class Calculator
    def initialize(arr1, arr2)
        @arr1 = arr1
        @arr2 = arr2
    end

    def mean(arr)
        arr.reduce(0.0) { |sum, num| sum + num } / arr.length
    end

    def sampleStdDevDenom(arr)
        arr.reduce(0.0) { |sum, num| sum + num } / (arr.length - 1)
    end

    def squareDiffs(arr)
        arr.map { |a| (a - mean(arr)) ** 2 }
    end

    def stdDev(arr)
        Math.sqrt( sampleStdDevDenom( squareDiffs(arr) ) )
    end

    def twoSampleTTest(arr1, arr2)
        numerator = (mean(arr1) - mean(arr2)).abs
        arr1_denom = stdDev(arr1) / arr1.length
        arr2_denom = stdDev(arr2) / arr2.length
        denominator = Math.sqrt(arr1_denom + arr2_denom)
        dof = arr1.length + arr2.length - 2
        t_score = numerator / denominator
        {'T Score': t_score, 'dof': dof}
    end

    def tTestResult
        twoSampleTTest(@arr1, @arr2)
    end
end

calculator = Calculator.new(array1, array2)
#p calculator.sum(array1)
p calculator.tTestResult 