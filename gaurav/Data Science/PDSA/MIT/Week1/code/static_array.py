class StaticArray:
  def __init__(self, size):
    self.data = [None] * size
  
  def get_at(self, k):
    if not (0 <= k < len(self.data)): raise IndexError
    return self.data[k]
  
  def set_at(self, k, value):
    if not (0 <= k < len(self.data)): raise IndexError
    self.data[k] = value
  
  