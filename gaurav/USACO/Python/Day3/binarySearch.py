import time

def search(L, k):
    for i in L:
        if i == k:
            return 1
    return -1
    
def binary_search(l, k):
    s = 0
    e = len(l) - 1
    while s <= e:
        mid = (s + e) // 2
        
        if l[mid] == k:
            return mid
        elif l[mid] < k:
            s = mid + 1
        else:
            e = mid + 1
    return -1

L = range(1000000)

a = time.time()
print(binary_search(L, 29000000))
b = time.time()
print(search(L, 2900099))
c = time.time()

print(a, " ", b)
print(f"Binary Search {b - a}")
print(f"Search {c - a:>26}")