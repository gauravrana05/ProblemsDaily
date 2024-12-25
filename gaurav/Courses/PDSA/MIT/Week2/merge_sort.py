def merge(A, L, R, i, j, a, b):
  if b > a:
    if j <=0 or (i > 0 and L[i-1] > R[j-1]):
      A[b-1] = L[i-1]
      i -= 1
    else:
      A[b-1] = R[j-1]
      j -= 1
    merge(A, L, R, i, j, a, b-1)
    
    

def merge_sort(A, a = 0, b = None):
  if b is None: b = len(A)
  if b - a > 1:
    c = (a + b) // 2
    merge_sort(A, a, c)
    merge_sort(A, c, b)
    
    L = A[a: c]
    R = A[c: b]
    merge(A, L, R, len(L), len(R), a, b)
  
if __name__ == "__main__":
  A = [3,4,5,2,6,4,5,3]
  merge_sort(A)
  print(A)