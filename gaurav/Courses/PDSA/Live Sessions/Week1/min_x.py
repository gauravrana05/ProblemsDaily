def Min_X(n, m):
    # print(n, m)
    
    if n < m:
        return Min_X(m, n)
        
    if n == 1 and m == 1:
        return 1
    if n == 2 and m == 1:
        return 1
    if n == 2 and m == 2:
        return 2
    
    q_n = n // 3
    q_m = m // 3
    r_n = n % 3
    r_m = m % 3
    
    if r_n == 0 and r_m == 0:
        return 3 * q_n * q_m
    elif r_n == 0:
        return 3 * q_n * q_m + r_m * q_n
    elif r_m == 0:
        return 3 * q_n * q_m + r_n * q_m
    else: 
        if q_n > 0:
                return q_n * m + Min_X(r_n, m)

        elif q_m > 0:
            return q_m * n + Min_X(n, r_m)
        
            
            
n = int(input())
for i in range(n):
  u,v = map(int,(input().split()))
  print(Min_X(u, v))
  