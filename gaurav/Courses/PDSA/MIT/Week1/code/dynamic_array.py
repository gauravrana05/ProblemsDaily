from array_seq import Array_Seq

class Dynamic_Array_Seq(Array_Seq):
  def __init__(self, r = 2):
    super().__init__()
    self.size = 0
    self.r = r 
    self._compute_bounds()
    self._resize(0)
    
  def __len__(self):
    return self.size
  
  def __iter__(self):
    for i in range(len(self)):
      yield self.A[i]
      
  def build(self, X):
    for a in X: self.insert_last(a)

  def _compute_bounds(self):
    self.upper = len(self.A)
    self.lower = len(self.A) // (self.r * self.r)
    
  def _resize(self, n):
    if(self.lower < n < self.upper): return 
    m = max(n, 1) * self.r 
    A = [None] * m
    self._copy_forward(0, self.size, A, 0)
    self.A = A
    self._compute_bounds()
    
  def insert_last(self, x):
    self._resize(self.size + 1)
    self.A[self.size] = x
    self.size+=1
    
  def delete_last(self):
    self.A[self.size - 1] = None 
    self.size-=1
    self._resize(self.size)
    
  def insert_at(self, i, x):
    n = self.size 
    self.insert_last(None)
    self._copy_backwards(i, n - i, self.A, i + 1)
    self.A[i] = x
    
  def delete_at(self, i):
    x = self.A[i]
    self._copy_forward(i+1, self.size - (i+1), self.A, i)
    self.delete_last()
    return x
  
  def insert_first(self, x):
    self.insert_at(0,x)
    
  def delete_first(self):
    self.delete_at(0)
    

if __name__ == "__main__":
  def main():
    a = Dynamic_Array_Seq()
    a.build([0,1,2,3,4,5,6,7,8,9])
    print(a)
    a.insert_at(4,-905)
    print(a)
    a.delete_at(4)
    print(a)
    a.delete_first()
    print(a)
    a.delete_last()
    print(a)
    a.delete_last()
    print(a)
    a.delete_last()
    print(a)
    a.delete_last()
    print(a)
    a.delete_last()
    print(a)
    a.delete_last()
    print(a)
    a.delete_last()
    print(a)
    a.delete_last()
    print(a)
    a.delete_last()
    print(a)
  main()  
    
    
  