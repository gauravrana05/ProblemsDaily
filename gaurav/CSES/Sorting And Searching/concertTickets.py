from bisect import bisect
[n, m] = list(map(int, input().split()))

h = list(map(int, input().split()))
t = list(map(int, input().split()))

h.sort()

for j in t:
    itr = bisect(h, j)
    # print("I am itr for", j, itr)
    if(itr == 0):
        print('-1')
    else:
        print(h[itr - 1]);
        h.remove(h[itr - 1]);



'''
Binary search


def search(key, h, st, end):
    while(st <= end):
        mid = (end + st) //2;
        if(key == h[mid]):
            return h[mid];
    
        if(len(h) == 0 or key < h[mid]):
            end = mid - 1;
        else:
            st = mid + 1;
    return h[st - 1];




sold = [0] * (n + 1)

h.sort();

price = -1;


for key in t:

    if(len(h) == 0 or key < h[0]):
        print(-1)
        continue;
    
    val = search(key, h, 0, len(h) - 1);
    h.remove(val);
    print(val)
'''