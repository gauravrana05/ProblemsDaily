from collections import defaultdict

def histogram(l):
    store = defaultdict(int)
    
    for i in l:
        store[i] += 1
    ret = sorted( [(u,v) for u,v in store.items()],key = lambda x: (x[1], x[0]))
    return ret
    

L=eval(input())
print(histogram(L))