def coolWorkers(AList, preference):
    indegree = {}
    visited = {}
    lst = []
    
    for i in AList.keys():
        indegree[i] = 0
        visited[i] = False

    for u in AList.keys():
        for k in AList[u]:
            indegree[k] += 1

    for  q in AList.keys():
        nextlistv = [ u for u in AList.keys() if indegree[u] == 0 and not visited[u]]
        
        nextlistv.sort(key=lambda x: preference.index(x))
        nextv = nextlistv[0]
        visited[nextv] = True
        
        lst.append(nextv)
        
        for k in AList[nextv]:
            if not visited[k]:
                indegree[k] -= 1
    return lst

AList = eval(input())
preference = eval(input())
print(coolWorkers(AList, preference))