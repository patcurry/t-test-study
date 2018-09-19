from functools import reduce
from math import sqrt
import pandas as pd

# get data with one column for male heights and one column for female heights
# each with ten values
df = pd.read_csv('./height-data.csv', skipinitialspace=True)

# get a t score by subtracting the mean of the males and the mean of the females from each other
# then divide by the pooled standard deviation times the square root of 1 over n of males plus 1 over
# the n of females, being the number of points in each sample (in this case 10 for each)
# where the pooled standard deviation is
# t = absolute_value(male_mean - female_mean) / sqrt(std_dev_m/nm + std_dev_f/nf)

class TTest:

    def __init__(self, arr1, arr2):
        self.arr1 = arr1
        self.arr2 = arr2 

    def sum(self, a, b): 
        return a + b

    def mean(self, arr):
        array_sum = reduce(self.sum, arr)
        result = array_sum/len(arr)
        return result


    def sampleStdDevDenom(self, arr):
        """
        basically the function above (mean) but instead
        of dividing by the length, we divide by the length
        minus 1
        """
        array_sum = reduce(self.sum, arr)
        result = array_sum / (len(arr) - 1)
        return result

    def squareDiffs(self, arr):
        """
        map the function a - b over the array d
        where a is the value in the array and b is
        the average of d, then return the square
        of the difference between the value and
        the average
        """
        return list(map(lambda a: (a - self.mean(arr))**2, arr))


    def std_dev(self, arr):
        """
        subtract each value in the sample from the sample mean
        then square the result
        take the sum of the results and divide it by the
        one less than the sample count 
        """
        sd = self.squareDiffs(arr)
        MSD = self.sampleStdDevDenom(sd)
        return sqrt(MSD)


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


class_answer = TTest(df['male'], df['female'])
print(class_answer.ttest_result())

# test the t-test
# the answer should be {'T Score': 2.514866859365871, 'dof': 8}
#
#array1 = [1, 2, 3, 4, 5]
#array2 = [3, 4, 5, 6, 7]

#yeah = TTest(array1, array2)
#print(yeah.ttest_result())