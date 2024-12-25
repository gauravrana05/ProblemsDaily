def subordinates(L):        
    if len(L) == 1:
        return (L, 1)
    if len(L) == 2:
        return (sorted(L), 1)
       
    mid = len(L) // 2
    
    left, lcount = subordinates(L[:mid])
    right, rcount = subordinates(L[mid:])
    
    ret = []
    
    i, j = 0, 0
    
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            ret.append(left[i])
            i+= 1
        else:
            ret.append(right[j])
            j+=1 
    while(i < len(left)):
        ret.append(left[i])
        i+=1 
    
    while(j < len(right)):
        ret.append(right[j])
        j+=1
    
    return (ret, 1 + rcount+lcount)
    
    


print(subordinates(eval(input())))