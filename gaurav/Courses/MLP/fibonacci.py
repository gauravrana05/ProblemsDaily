import math

def fibonacci_diagonalization(n):
    """
    Calculate the n-th Fibonacci number using diagonalization.
    """
    # Define the golden ratio and its conjugate
    phi = (1 + math.sqrt(5)) / 2  # Golden ratio
    psi = (1 - math.sqrt(5)) / 2  # Conjugate of the golden ratio

    # Formula for the n-th Fibonacci number
    fib_n = (phi**n - psi**n) / math.sqrt(5)
    fib_n_approx = phi**n / math.sqrt(5)
    
    # Return the nearest integer since Fibonacci numbers are integers
    return  fib_n, fib_n_approx

# Test the function
n = 12
print(f"F_{n} = {fibonacci_diagonalization(n)}")
