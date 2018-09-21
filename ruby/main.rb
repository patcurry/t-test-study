require 'csv'


class TTest
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

# create two empty arrays for males and females
males = Array.new
females = Array.new

# read the csv data into the arrays
CSV.foreach('./height-data.csv', :headers => true, converters: :numeric) do |row|
    males << row[0]
    females << row[1]
end

# instantiate / initialize the ttest with the data from the csv file
ttest = TTest.new(males, females)

# print the result
p ttest.tTestResult 


# test the t-test
# the answer should be {:"T Score"=>2.514866859365871, :dof=>8}
#
#array1 = [1,2,3,4,5]
#array2 = [3,4,5,6,7]
#
#yeah = TTest.new(array1, array2)
#p yeah.tTestResult