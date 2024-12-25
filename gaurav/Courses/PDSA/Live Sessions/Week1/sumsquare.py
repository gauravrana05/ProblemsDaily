def sumsquare(L):
    """
    Returns the sum of squares of odd and even numbers in the list.
    """
    odd_sum = 0
    even_sum = 0
    
    for num in L:
        if num % 2 == 0:
            even_sum += num**2
        else:
            odd_sum += num**2
    
    return [odd_sum, even_sum]

# Input and Output
L = eval(input("Enter a list of integers: "))
print(sumsquare(L))
