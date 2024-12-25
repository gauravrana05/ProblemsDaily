f = open('numbers.txt', 'a')
n = int(input())

for i in range(1, n+1):
  f.write(str(i))
  if i != n:
    f.write('\n')

f.close()

r = open('numbers.txt', 'r')
print(r.read())