
class TTest
    def initialize(arr1 : Array(Float32), arr2 : Array(Float32)) : Array(Float32)
        @arr1 = arr1
        @arr2 = arr2
    end

    def add(x : Int, y : Int) : Int
        x + y
    end

    def mean(arr : Array(Float32)) : Float32
        arr.reduce{|m, e| m + e} / arr.size
    end
end

Array1 = [1,2,3,4,5] of Float32
Array2 = [3,4,5,6,7] of Float32

ttest = TTest.new(Array1, Array2)

#p ttest.add(1,2)
p ttest.mean(Array1)