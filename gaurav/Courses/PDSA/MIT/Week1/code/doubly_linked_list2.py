class Node:
  def __init__(self, data, prev = None, next = None):
    self.data = data
    self.next = next
    self.prev = prev 
  
  def next_node(self, i):
    if i:
      assert self.next 
      return self.next.next_node(i-1)
    return self

  def prev_node(self, i):
    if i:
      assert(self.prev)
      return self.prev.prev_node(i-1)
    return self
    
class LinkedList:
  def __init__(self):
    self.head = None 
    self.tail = None 
    self.size = 0
    
  def __len__(self):
    return self.size

  def __iter__(self):
    node = self.head
    while node: 
      yield node.data
      node = node.next
      
  def build(self, X):
    for a in reversed(X):
      self.insert_first(a)
      
  def get_at(self, i):
    node = self.head.next_node(i)
    return node

  def set_at(self,i, value):
    node = self.head.next_node(i)
    node.data = value 
  
  def insert_first(self, x):
    node = LinkedList(x)
    self.head.prev = node 
    node.next = self.head
    node.prev = None 
    self.head = node 
    self.size += 1
    
  def delete_first(self):
    x = self.head.data
    self.head = self.head.next 
    self.head.prev = None
    self.size -= 1
    return x 

  def insert_at(self, i, value):
    if i == 0:
      self.insert_first(value)
      
    node = self.head.next_node(i - 1)
    new_node = LinkedList(value)
    new_node.next = node.next
    node.next = new_node
    self.size += 1
  
  def delete_at(self, i):
    if i == 0:
      self.delete_first()
    
    node = self.head.next_node(i-1)
    x = node.next.data
    node.next = node.next.next
    self.size -= 1
    return x
  
  def insert_last(self, x):
    node = LinkedList(x)
    
    node.prev = self.tail 
    self.tail.next = node
    node.next = None 
    self.tail = node
    self.size += 1
    
    
  
  def delete_last(self):
    x = self.tail.data
    self.tail = self.tail.prev
    self.tail.next = None 
    self.size -= 1 
    return x 
  
  def swap_ends(self):
    self.head.data, self.tail.data = self.tail.data, self.head.data
  
  def shift_left(self, k):
    if k:
      node1 = self.head
      self.head = self.head.next 
      self.head.prev = None 
       
      self.tail.next = node1 
      node1.prev = self.tail
      self.tail = node1 
      self.tail.next = None
      return self.shift_left(k-1)

    return self.head
    
      
    
  
    
    
    
    
    