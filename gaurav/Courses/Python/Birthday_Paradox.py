import random 
l = []
count = 0;
sum = 0;
for i in range(1000):
  for i in range(1000):
    for i in range(23):
      l.append(random.randint(1,365))
    l.sort()
    flag = False
    for ind1, i in enumerate(l):
      if ind1 < len(l)-1 and l[ind1] == l[ind1+1]:
          flag = True
          break;
      if flag:
        break;
    if flag:
      count+=1;
    flag = False
    l = []
  # print(count)
  sum+=count
  count = 0
print(f"Probability is {sum/1000000:0.9f}")