def findPair(L, sum):
    
    L.sort()
    
    st = 0
    end = len(L) - 1
    while(st< end):
        if L[st] + L[end] == sum:
            return True
        elif L[st] + L[end] < sum:
            st+=1 
        else:
            end -= 1 
            
    return False


L = [int(item) for item in input().split()]
pairsum = int(input())
print(findPair(L, pairsum))