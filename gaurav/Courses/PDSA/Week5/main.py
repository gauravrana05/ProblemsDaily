from graph import Graph

if __name__ == '__main__':
  def main():
    g = Graph([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], [(1, 2), (1, 3), (2, 4), (2, 5), (3, 6), (3, 7), 
    (4, 8), (5, 9), (6, 10), (7, 10)])
    
    # g.print_list()
    g.add_edge((4,5))
    print(g.dfs_list(1))
    print(g.bfs_list(1))
    print(g.bfs_shortest_path(10,1))
    
  main()
  
  
  
  