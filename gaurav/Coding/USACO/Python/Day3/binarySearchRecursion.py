def binary_search_recursion(s, e, lst, k):
  if( s > e):
    return -1
  
  mid = s + (e - s) // 2

  if lst[mid] == k:
    return mid
  elif lst[mid] > k:
    return binary_search_recursion(s, mid - 1, lst, k)
  else:
    return binary_search_recursion(mid + 1, e ,  lst, k)
  
def main():
  L = range(1000 * 1000 * 1000)
  print(binary_search_recursion(0, len(L) - 1, L, 1001383324324323413))
  print(False == (1 in L))
  

if __name__  == "__main__":
  main()