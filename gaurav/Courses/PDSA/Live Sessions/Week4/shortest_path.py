# Prefix code
def BFSListPathLevel(AList, v):
    level, parent = {}, {}
    for i in AList.keys():
        level[i] = -1
        parent[i] = -1
    q = []

    level[v] = 0
    q.append(v)

    while len(q) > 0:
        j = q.pop(0)
        for k in AList[j]:
            if level[k] == -1:
                level[k] = level[j]+1
                parent[k] = j
                q.append(k)
    return level, parent
# Write Solution code below



def minimumhops(AList, start, end):
    level, parent = BFSListPathLevel(AList, start)
    ret = []
    while parent[end] != -1 :
        ret.append(end)
        end = parent[end]
    ret.append(start)
    return ret[::-1]
    


# Suffix code
start = int(input())
end = int(input())
AList = eval(input())
shortestpath = minimumhops(AList, start, end)
print(len(shortestpath))