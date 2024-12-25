from collections import defaultdict
from queue import Queue
from stack import Cstack as Stack


class Graph:
  def __init__(self, vertices = None, edges = None):
    self.vertices = vertices
    self.edges = edges
    self.adjacency_matrix = [[0 for _ in range(len(vertices))] for _ in range(len(vertices))]
    self.adjacency_list = defaultdict(list)
    
    for edge in edges:
      v1, v2 = edge
      i, j = vertices.index(v1), vertices.index(v2)
      self.adjacency_matrix[i][j] = 1
      self.adjacency_matrix[j][i] = 1

      self.adjacency_list[v1].append(v2)
      self.adjacency_list[v2].append(v1)
  
  def print_matrix(self):
    if not self.adjacency_matrix or not self.vertices:
        print("Adjacency matrix is empty or not initialized.")
        return

    # Print column headers
    print("    " + " ".join(f"{v:>3}" for v in self.vertices))
    print("    " + "----" * len(self.vertices))

    # Print each row with row header
    for i, row in enumerate(self.adjacency_matrix):
        print(f"{self.vertices[i]:<3} " + " ".join(f"{value:>3}" for value in row))
  
  def print_list(self):
    if not self.adjacency_list or not self.vertices:
      print("adjacency List is empty or not initialized.")
      return 
    
    # Print list 
    for v in self.vertices:
      print(f"{v}:{",".join(map(str, self.adjacency_list[v]))}")
 
  def add_edge(self, edge):
    v1, v2 = edge
    if v1 not in self.vertices or v2 not in self.vertices:
            print(f"Error: One or both vertices {v1}, {v2} not found in the graph.")
            return
    
    i, j = self.vertices.index(v1), self.vertices.index(v2)
    
    self.adjacency_matrix[i][j] = 1
    self.adjacency_matrix[j][i] = 1
    
    self.adjacency_list[v1].append(v2)
    self.adjacency_list[v2].append(v1)
    
  def add_vertex(self, vertex, edges=[]):
    if vertex in self.vertices:
      print(f"Vertex {vertex} already exists.")
      return
    self.vertices.append(vertex)
    
    new_size = len(self.vertices)
    for row in self.adjacency_matrix:
      row.append(0)
    self.adjacency_matrix.append([0] * new_size)
    self.adjacency_list[vertex] = []
    for v in edges:
      if v not in self.vertices:
        print(f"Error: Vertex {v} is not in the graph.")
        continue 
      
      i, j = self.vertices.index(vertex), self.vertices.index(v)
      self.adjacency_matrix[i][j] = 1
      self.adjacency_matrix[j][i] = 1

      self.adjacency_list[vertex].append(v)
      self.adjacency_list[v].append(vertex)
      
  def bfs_list(self, start):
    visited = {vertex:False for vertex in self.vertices}
    queue = Queue()
    queue.enqueue(start)
    visited[start] = True
    
    bfs_result = []
    
    while not queue.is_empty():
      vertex = queue.dequeue()
      bfs_result.append(vertex)
      
      for neighbour in self.adjacency_list[vertex]:
        if not visited[neighbour]:
          visited[neighbour]= True 
          queue.enqueue(neighbour)
          
    return bfs_result
  
  def bfs_matrix(self, start):
    visited = {vertex: False for vertex in self.vertices}
    queue = Queue()
    queue.enqueue(start)
    
    visited[start] = True
    bfs_result = []
    
    while not queue.is_empty():
      vertex = queue.dequeue()
      bfs_result.append(vertex)
      
      current_index = self.vertices.index(vertex)
      
      for i in range(len(self.vertices)):
        if self.adjacency_matrix[current_index][i] == 1 and not visited[self.vertices[i]]:
          visited[self.vertices[i]] = True
          queue.enqueue(self.vertices[i])
          
    return bfs_result
    
  def dfs_list(self, start, visited = None, dfs_result = None):
    if visited is None:
      visited = {vertex: False for vertex in self.vertices}
    if dfs_result is None:
      dfs_result = []
      
    visited[start] = True
    dfs_result.append(start)
    
    for neighbor in self.adjacency_list[start]:
      if not visited[neighbor]:
        self.dfs_list(neighbor, visited, dfs_result)
    
    return dfs_result 
  
  def dfs_matrix(self, start, visited = None, dfs_result = None):
    if visited is None:
      visited = {vertex: False for vertex in self.vertices}
      
    if dfs_result is None:
      dfs_result = []
      
    visited[start] = True 
    dfs_result.append(start)
    
    current_index = self.vertices.index(start)
    
    for i in range(len(self.vertices)):
      if self.adjacency_matrix[current_index][i] == 1 and not visited[self.vertices[i]]:
        self.dfs_matrix(self.vertices[i], visited, dfs_result)

    return dfs_result
    
  def dfs_list_stack(self, start):
    visited = {vertex: False for vertex in self.vertices}
    stack = Stack()
    dfs_result = []

    stack.push(start)
    while not stack.is_empty():
      vertex = stack.pop()

      if not visited[vertex]:
        visited[vertex] = True
        dfs_result.append(vertex)

        for neighbor in reversed(self.adjacency_list[vertex]):  # Reverse for correct visiting order
          if not visited[neighbor]:
            stack.push(neighbor)

    return dfs_result
  
  def dfs_matrix_stack(self, start):
    visited = {vertex: False for vertex in self.vertices}
    stack = Stack()
    dfs_result = []

    stack.push(start)
    while not stack.is_empty():
      vertex = stack.pop()

      if not visited[vertex]:
          visited[vertex] = True
          dfs_result.append(vertex)

          # Add neighbors to the stack using the adjacency matrix
          current_index = self.vertices.index(vertex)
          for i in reversed(range(len(self.vertices))):  # Reverse for correct visiting order
              if self.adjacency_mtrix[current_index][i] == 1 and not visited[self.vertices[i]]:
                  stack.push(self.vertices[i])

    return dfs_result
  
  def bfs_shortest_path(self, start, end):
    distances = {vertex : float('inf') for vertex in self.vertices}
    previous_nodes = {vertex: None for vertex in self.vertices}
    
    
    queue = Queue()
    queue.enqueue(start)
    distances[start] = 0
    
    while not queue.is_empty():
      current_node = queue.dequeue()
      
      if current_node == end:
        break 
      
      for neighbor in self.adjacency_list[current_node]:
        if distances[neighbor] == float('inf'):
          queue.enqueue(neighbor)
          distances[neighbor] = distances[current_node] + 1
          previous_nodes[neighbor] = current_node
    
    path = []
    current_node = end 
    while current_node is not None:
      path.append(current_node)
      current_node = previous_nodes[current_node]
    
    if distances[end] == float('inf'):
      return []
    
    return path[::-1]
  
    
    
  
    
    
    