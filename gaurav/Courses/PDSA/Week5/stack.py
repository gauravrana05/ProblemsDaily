class Cstack:
  def __init__(self):
    self.stack = []
    
  def push(self, item):
    self.stack.append(item)
  
  def pop(self):
    if self.is_empty():
      print("Stack is empty")
      return None 
    return self.stack.pop()
  
  def peek(self):
    if self.is_empty():
      print("Stack is empty")
      return None
    return self.stack[-1]
  
  def is_empty(self):
    return len(self.stack) == 0

    # Get the size of the stack
  def size(self):
      return len(self.stack)

  # Print the stack for visualization
  def print_stack(self):
      print("Stack:", self.stack)

    