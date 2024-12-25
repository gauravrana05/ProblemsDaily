def primes(m):
    is_prime = [True] * (m + 1)
    is_prime[0] = is_prime[1] = False
    
    for i in range(2, int(m ** 0.5) + 1):
        if is_prime[i]:
            for j in range( i * i, m + 1,i):
                is_prime[j] = False
    
    return [i for i in range(2, m + 1) if is_prime[i]]
        

def Twin_Primes(n, m):
    prime_list = primes(m)
    ret = []
    for i in range(n, m-1):
        if i in prime_list and i + 2 in prime_list :
            ret.append((i, i + 2))
    return ret

n=int(input())
m=int(input())
print(sorted(Twin_Primes(n, m)))