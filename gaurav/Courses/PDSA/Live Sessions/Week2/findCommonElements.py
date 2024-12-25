def findCommonElements(L1, L2):
    L1.sort()
    L2.sort()
    i,j = 0, 0
    ans = []
    while(i < len(L1) and j < len(L2)):
        if L1[i] == L2[j]:
            ans.append(L1[i])
            i+=1 
            j+=1 
        elif L1[i] > L2[j]:
            j += 1 
        else:
            i += 1 
    return ans
