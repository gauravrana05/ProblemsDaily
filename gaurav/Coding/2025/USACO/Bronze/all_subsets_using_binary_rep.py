def generate_subsets(arr):
  subsets = []
  for i in range(1<<len(arr)):
    subset = []
    for j in range(len(arr)):
      if (i & 1 << j):
        subset.append(arr[j])
    subsets.append(subset)
  return subsets
    

def main():
  arr = [int(i) for i in input().split()]
  subsets = generate_subsets(arr)
  print(subsets)
  

if __name__ == "__main__":
  main()