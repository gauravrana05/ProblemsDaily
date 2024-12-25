from math import sqrt

size = 1001
prime = [True] * (size + 1)

def soe():
    """Implements the Sieve of Eratosthenes to find all primes up to `size`."""
    prime[0] = prime[1] = False  # 0 and 1 are not primes
    for i in range(2, int(sqrt(size)) + 1):
        if prime[i]:  # If `i` is prime
            for j in range(i * i, size + 1, i):
                prime[j] = False

def prime_till(m):
    """Returns a list of all primes up to `m`."""
    ret = []
    for i in range(2, m + 1):
        if prime[i]:
            ret.append(i)
    return ret

def prime_product(n):
    """
    Checks if the number `n` can be expressed as the product of two primes.
    """
    if n < 4:  # No prime product is less than 4
        return False
    
    primes = prime_till(n)
    
    for i in primes:
        if n % i == 0 and (n // i) in primes:
            return True
    return False

# Precompute the sieve
soe()

# Input and Output
n = int(input("Enter a number: "))
print(prime_product(n))
