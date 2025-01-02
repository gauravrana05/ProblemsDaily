def generate_permutations(arr, perm, current = []):
  if not arr:
    perm.append(current)
    return 
  for i in range(len(arr)):
    generate_permutations(arr[:i] + arr[i+1:], perm, current + [arr[i]])
    

def main():
  arr = [int(i) for i in input().split()]
  
  perm = []
  generate_permutations(arr, perm)
  print(perm)
  
if __name__ == "__main__":
  main()
  
    
    