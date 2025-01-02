for _ in range(int(input())):
  n = int(input())
  elsie_log = [int(i) for i in input().split()]
  
  log_sum = sum(elsie_log)
  
  for num_hours in range(log_sum+1):
    if num_hours != 0 and log_sum % num_hours != 0:
      continue
    
    curr_sum = 0
    for h in elsie_log:
      curr_sum += h 
      if curr_sum > num_hours:
        break
      elif curr_sum == num_hours:
        curr_sum = 0
    else:
      if num_hours == 0:
        print(0) 
      else:
        print(n - log_sum // num_hours)
        break
  