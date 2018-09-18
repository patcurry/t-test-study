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

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def sum(self, a, b): 
        return a + b

    def mean(self, a):
        array_sum = reduce(self.sum, a)
        result = array_sum/len(a)
        return result


    def sampleStdDevDenom(self, a):
        """
        basically the function above (mean) but instead
        of dividing by the length, we divide by the length
        minus 1
        """
        array_sum = reduce(self.sum, a)
        result = array_sum / (len(a) - 1)
        return result

    def squareDiffs(self, d):
        """
        map the function a - b over the array d
        where a is the value in the array and b is
        the average of d, then return the square
        of the difference between the value and
        the average
        """
        return list(map(lambda a: (a - self.mean(d))**2, d))


    def std_dev(self, d):
        """
        subtract each value in the sample from the sample mean
        then square the result
        take the sum of the results and divide it by the
        one less than the sample count 
        """
        sd = self.squareDiffs(d)
        MSD = self.sampleStdDevDenom(sd)
        return sqrt(MSD)


    def two_sample_t_test(self, a, b):
        numerator = abs(self.mean(a) - self.mean(b))
        a_denom = self.std_dev(a) / len(a)
        b_denom = self.std_dev(b) / len(b)
        denominator = sqrt(a_denom + b_denom)
        dof = len(a) + len(b) - 2
        t_score = numerator / denominator
        return {'T Score': t_score, 'dof': dof}

    def ttest_result(self):
        return self.two_sample_t_test(self.x, self.y)


class_answer = TTest(df['male'], df['female'])
print(class_answer.ttest_result())

# test the t-test
# the answer should be {'T Score': 2.514866859365871, 'dof': 8}
#
#array1 = [1, 2, 3, 4, 5]
#array2 = [3, 4, 5, 6, 7]

#yeah = TTest(array1, array2)
#print(yeah.ttest_result())