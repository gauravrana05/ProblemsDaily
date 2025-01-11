def generate_permutations(arr, perm, current = []):
  if not arr:
    perm.append(current)
    return 
  for i in range(len(arr)):
    generate_permutations(arr[:i] + arr[i+1:], perm, current + [arr[i]])
    
def generate_perm(arr, perm, chosen, current = []):
  if len(current) == len(arr):
    print(current)
    return 
  for i in range(len(arr)):
    if chosen[i] ==  True: 
      continue 
    chosen[i] = True 
    generate_perm(arr, perm, chosen, current+ [arr[i]])
    chosen[i] = False

def generate_permutation(arr, perm, current = []):
  if not arr:
    return 
  for i in range(len(arr)):
    generate_permutation(arr[])

def main():
  arr = [int(i) for i in input().split()]
  
  perm = []
  generate_permutations(arr, perm)
  print(perm)
  
if __name__ == "__main__":
  main()
  
    
    