is_prime = [True] * (n + 1)  

majority_type = max(set(types), key=types.count)

types = [get_type(i) for i in L]