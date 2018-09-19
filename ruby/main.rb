array1 = [1.23,2.45,3.67,4.89,5.0]
array2 = [3,4,5,6,7]

# m is the average of of array1
# it looks like a reduce function
"""
m = array1.inject{ |sum, el| sum + el }.to_f / array1.size
n = array2.inject{ |sum, el| sum + el }.to_f / array2.size
"""

# another implementation
# reduce and inject are aliases
# apparently size and length are also aliases
def sum(arr)
    arr.reduce(0.0) { |sum, num| sum + num}
end

def mean(arr)
    arr.reduce(0.0) { |sum, num| sum + num } / arr.length
end

# looks like 'p' is shorthand for 'puts'

class Calculator
    def initialize(x, y)
        @x = x
        @y = y
    end

    def mean(arr)
        arr.reduce(0.0) { |sum, num| sum + num } / arr.length
    end

    def sampleStdDevDenom(arr)
        arr.reduce(0.0) { |sum, num| sum + num } / (arr.length - 1)
    end

    def squareDiffs(arr)

end

calculator = Calculator.new(1, 2)
p calculator.sum(array1)