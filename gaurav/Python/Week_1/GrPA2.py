
a = 5

price1, discount1 = 50, 
price2, discount2 = 60, 


output1 = a >= 5  # bool: True if a is greater than or equal to 5

output2 = a % 5 == 0  # bool: True if a is divisible by 5

output3 = (a % 2 != 0) and (a < 10) and isinstance(a, int)  # bool: True if a is odd number less than 10



output4 = (-10 < a < 10) and (a % 2 != 0) and isinstance(a, int)  # bool: True if a is an odd number within the range -10 and 10

output5 = (1 <= len(str(a)) <= 10) and (len(str(a)) % 2 == 0)   # bool: True if a has even number of digits but not more than 10 digits

# Calculate the discounted prices for each offer and compare them
discounted_price1 = price1 - (discount1 * price1 / 100)
discounted_price2 = price2 - (discount2 * price2 / 100)
is_offer1_cheaper = discounted_price1 < discounted_price2  # bool: True if offer1 is strictly cheaper
