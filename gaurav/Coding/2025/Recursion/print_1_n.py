def print_1_n(n):
  if n <= 1:
    print(1)
    return 
  print(n, end=', ')
  print_1_n(n-1)

def print_n_1(n):
  if n== 0:
    return 

  print_n_1(n-1)
  print(n, end=', ')