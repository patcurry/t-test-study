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

def mean(d):
    """
    A bit more functional style programming.
    """
    sum = lambda a, b: a + b
    array_sum = reduce(sum, d)
    result = array_sum/len(d)
    return result

def sampleStdDevDenom(d):
    """
    basically the function above (mean) but instead
    of dividing by the length, we divide by the length
    minus 1
    """
    f = lambda a, b: a + b
    array_sum = reduce(f, d)
    return array_sum / len(d) - 1

def squareDiffs(d):
    """
    map the function a - b over the array d
    where a is the value in the array and b is
    the average of d, then return the square
    of the difference between the value and
    the average
    """
    avg = mean(d)
    f = lambda a: (a - avg) ** 2
    res = list(map(f, d))
    return res
    #return list(map(lambda a, b: (a - b)**2, d, avg))

def std_dev(d):
    """
    subtract each value in the sample from the sample mean
    then square the result
    take the sum of the results and divide it by the
    one less than the sample count 
    """
    sd = squareDiffs(d)
    MSD = sampleStdDevDenom(sd)
    res = sqrt(MSD)
    print(res)
    return res

def two_sample_t_test(a, b):
    count_a = len(a) 
    count_b = len(b)
    numerator = abs(mean(a) - mean(b))
    a_denom = std_dev(a) / count_a
    b_denom = std_dev(b) / count_b
    denominator = sqrt(a_denom + b_denom)
    dof = count_a + count_b - 2
    t_score = numerator / denominator

    res = {'T Score': t_score, 'dof': dof}

    # getting a different answer than one written in python
    # why?
    return res

answer = two_sample_t_test(df['male'], df['female'])

array1 = [1, 2, 3, 4, 5]
array2 = [3, 4, 5, 6, 7]

#print(std_dev(array1))