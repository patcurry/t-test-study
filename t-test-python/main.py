import pandas as pd
from math import sqrt
from math import sqrt

# get data with one column for male heights and one column for female heights
# each with ten values
df = pd.read_csv('../height-data.csv', skipinitialspace=True)

print(type(df))
#
# get a t score by subtracting the mean of the males and the mean of the females from each other
# then divide by the pooled standard deviation times the square root of 1 over n of males plus 1 over
# the n of females, being the number of points in each sample (in this case 10 for each)
# where the pooled standard deviation is 
# t = absolute_value(male_mean - female_mean) / sqrt(std_dev_m/nm + std_dev_f/nf)

def mean(d):
    """
    Not good functional programming... I'll deal with that in lisp and javascript
    """
    sum = 0
    count = 0
    for n in d:
        sum = sum + n
        count = count + 1
    result = sum/count

    return result

def std_dev(d):
    """
    Pretty ugly, but it'll do

    subtract each value in the sample from the sample mean
    then square the result
    take the sum of the results and divide it by the
    one less than the sample count 
    """
    mean_d = mean(d)
    count = 0
    numerator = 0
    for n in d:
        numerator = numerator + ((n - mean_d) ** 2)
        count = count + 1

    res = sqrt(numerator/count - 1)
    
    return res

def two_sample_t_test(a, b):
    count_a = len(a) 
    count_b = len(b)
    numerator = abs(mean(a) - mean(b))
    a_denom = std_dev(a)/count_a
    b_denom = std_dev(b)/count_b
    denominator = sqrt(a_denom/b_denom)
    dof = count_a + count_b - 2
    t_score = numerator/denominator

    res = {'t_score': t_score, 'dof': dof}

    return res

answer = two_sample_t_test(df['male'], df['female'])
print(answer)