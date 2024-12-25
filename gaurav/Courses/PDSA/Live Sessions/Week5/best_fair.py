def addallpath(WList,u, d, visited, path,allpath):
  	visited[u]= True
  	path.append(u)
  	if u == d:
         L = path.copy()
         allpath.append(L)
  	else:
         for i in WList[u]:
             if visited[i[0]]== False:
                 addallpath(WList, i[0], d, visited, path, allpath)      	
  	path.pop()
  	visited[u]= False
# Following function returns a list of all paths from s to d
# Format of returned list:- [[s,...,d],[s,...,d],...]
def findallpath(WList,s,d):
    visited = {}
    allpath = []
    for v in WList.keys():
        visited[v] = False
    path = []
    addallpath(WList,s, d, visited, path,allpath)
    return(allpath)

import math 

def best_fare(WL, s, d, k):
    paths = findallpath(WL, s, d)
    if paths != []:
        cost = float('inf')
        route = []
        for ret in paths:
            if len(ret) < k + 3:
                s = 0
                for i in range(0, len(ret) - 1):
                    for j in WL[ret[i]]:
                        if ret[i+1] == j[0]:
                            s+= j[1]
                if s < cost:
                    cost = s 
                    route = ret 
        if route != []:
            return (cost, route)
        return "Not found"
    else:
        return "Not found"
        
    



size = int(input())
edges = eval(input())
s = int(input()) 
d = int(input())
k = int(input())
WL = {}
for i in range(size):
    WL[i] = []
for ed in edges:
    WL[ed[0]].append((ed[1],ed[2]))
print(best_fare(WL,s,d,k))