matrix1 = [[1,2,3],[4,5,6],[6,7,8]]
matrix2 = [[1,3,2],[2,3,4],[5,6,7]]

sum = [[0,0,0],[0,0,0],[0,0,0]]

for i in range(len(sum)):
  for j in range(len(sum[0])):
    prod = 0
    for k in range(len(matrix1[0])):
        prod += matrix1[i][k] * matrix2[k][j]
    sum[i][j] = prod

for row in matrix1:
  print(' '.join(f'{value:3d}' for value in row))

print('-'*20)

for row in matrix2:
   print(' '.join(f'{value:3d}' for value in row))

print('-'*20)

for row in sum:
   print(' '.join(f'{value:3d}' for value in row))


