def generate_subsets(arr, index = 0, subset = None):
  if subset is None:
    subset = []
  if index == len(arr):
    print(subset)
    return
  generate_subsets(arr, index + 1, subset)
  
  generate_subsets(arr, index + 1, subset + [arr[index]])
  
def get_difference(arr, index = 0, sum1 = 0, sum2 = 0):
  if index == len(arr):
    return abs(sum1-sum2)
  return min(
    get_difference(arr, index + 1, sum1 + arr[index], sum2), 
  get_difference(arr, index + 1, sum1, sum2 + arr[index]))

def main():
  n = int(input())
  arr = [int(i) for i in input().split()]
  
  generate_subsets(arr)
  
if __name__ == "__main__":
  main()
