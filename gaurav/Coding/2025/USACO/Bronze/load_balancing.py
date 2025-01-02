with open("balancing.in") as read:
  cow_num, max_pos = map(int, input().split())
  x_vals = []
  y_vals = []
  
  v_fence = set()
  h_fence = set()
  
  for _ in range(cow_num):
    x, y = map(int, input().split())
    x_vals.append(x)
    y_vals.append(y)
    
    v_fence.add(x_vals[-1] + 1)
    h_fence.add(y_vals[-1] + 1)
    
min_balance = cow_num 
for v in v_fence:
  for h in h_fence:
    top_left = 0
    top_right = 0
    bottom_left = 0
    bottom_right = 0
    
    for c in range(cow_num):
      if x_vals[c] < v and y_vals[c] > h:
        top_left += 1
      elif x_vals[c] > v and y_vals[c] > h:
        top_right += 1
      elif x_vals[c] > v and y_vals[c] < h:
        bottom_rimht += 1
      else:
        bottom_left += 1
      min_balance = min(min_balance, max(top_left, top_right, bottom_left, bottom_right))

print(min_balance, file=open('balacing.out', 'w'))
      
        