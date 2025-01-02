def generate_subsets(arr, index = 0, subset = None):
  if subset is None:
    subset = []
  if index == len(arr):
    print(subset)
    return
  generate_subsets(arr, index + 1, subset)
  
  generate_subsets(arr, index + 1, subset + [arr[index]])

def main():
  n = int(input())
  arr = [int(i) for i in input().split()]
  
  generate_subsets(arr)
  
if __name__ == "__main__":
  main()