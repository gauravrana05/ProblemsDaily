//Bellman Form Algo

def min_transmission_time(n, edges, s):
    distance = [float('inf')] * n 
    distance[s] = 0
    for _ in range(n - 1):
        for u,v,w in edges:
            if distance[u] != float('inf'):
                distance[v] = min(distance[v], w + distance[u])
    if max(distance) == float('inf'):
        return -1
    return max(distance)
    

//Floyd Warshall Algo
def min_transmission_time(n, edges, s):
    
    distance = [[float('inf')] * n for _ in range(n)]
    
    for u in range(n):
        distance[u][u] = 0
    
    for u,v,w in edges:
        distance[u][v] = w 
    
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if distance[i][k]  < float('inf') and distance[k][j] < float('inf'):
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j])
                    
    if max(distance[s]) == float('inf'):
        return -1
    return max(distance[s])
    

//Dikstra Algo  
def min_transmission_time(n, edges, s):
  
    adj_list = {}
    for i in range(n):
        adj_list[i] = []
        
    for u,v,d in edges:
        adj_list[u].append([v,d])
    
    distance = [float('inf')] * n 
    visited = [False] * n 
    distance[s] = 0
    
    for _ in range(n):
        min_dist = float('inf')
        nextv = None 
        for i in range(n):
            if not visited[i] and distance[i] < min_dist:
                min_dist = distance[i]
                nextv = i 
                
        if nextv is None:
            break
        
        visited[nextv] = True 
        for v, w in adj_list[nextv]:
            if not visited[v]:
                distance[v] = min(distance[v], distance[nextv] + w)
    if max(distance) == float('inf'):
        return -1
    return max(distance)
        
        
n = int(input())
edges = eval(input())
s = int(input())
print(min_transmission_time(n, edges, s))