def expanding(L):
    """
    Determines if the absolute differences between consecutive elements in the list
    are strictly increasing.
    """
    # Start with the difference between the first two elements
    previous_difference = abs(L[1] - L[0])
    
    # Iterate over pairs of consecutive elements
    for i in range(1, len(L) - 1):
        current_difference = abs(L[i + 1] - L[i])
        
        # Check if the current difference is not greater than the previous
        if current_difference <= previous_difference:
            return False
        
        # Update the previous difference
        previous_difference = current_difference
    
    return True

# Input and Output
L = eval(input("Enter a list of numbers: "))
print(expanding(L))
  