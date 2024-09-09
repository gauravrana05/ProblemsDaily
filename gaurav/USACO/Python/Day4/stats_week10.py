# Given data: Durations of last ten meetings
durations = [29, 33, 23, 24, 21, 17, 18, 35, 30, 26]
# durations = [20, 30, 35, 30, 25, 25, 20, 28, 34, 30]

# Sum of the durations
sum_durations = sum(durations)
print(sum_durations)
# Number of observations
n = len(durations)

# Prior information (Exp(1/15))
prior_rate = 1 / 15

# Posterior parameters
a = n + 1  # shape parameter
print(a)
b = prior_rate + sum_durations  # rate parameter

# Posterior mean for λ (Gamma(a, b) distribution)
posterior_mean_lambda = a / b
print(posterior_mean_lambda)
# Round to two decimal places
print(round(posterior_mean_lambda, 2))
