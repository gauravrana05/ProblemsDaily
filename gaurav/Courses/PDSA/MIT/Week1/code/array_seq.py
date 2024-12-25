class Array_Seq:
  def __init__(self):
    self.A = []
    self.size = 0
  
  def __len__(self):
    return self.size 
  
  def __iter__(self):
    return iter(self.A)
  
  def __str__(self):
    return f'Array_seq({self.A})'
  
  def build(self, X):
    self.A = [a for a in X]
    self.size = len(self.A)
  
  def get_at(self, i):
    return self.A[i]

  def set_at(self,i, x):
    self.A[i] = x
  
  def _copy_forward(self, start, count, target, dest):
    for k in range(count):
      target[dest+k] = self.A[start+k]
  
  def _copy_backwards(self, start, count, target, dest):
    for k in range(count, -1, -1):
      target[dest+k] = self.A[start+k]
      
  def insert_at(self, i, x):
    n = len(self.A)
    A = [None] * (n + 1)
    self._copy_forward(0,i, A, 0)
    A[i] = x
    self._copy_forward(i, n-i, A, i+1)
    self.build(A)
  
  def delete_at(self, i):
    n = len(self.A)
    A = [None] * (n-1)
    self._copy_forward(0, i, A, 0)
    x = self.A[i]
    self._copy_forward(i+1, n - i - 1, A, i)
    self.build(A)
    return x

  def insert_first(self, x):
    self.insert_at(0, x)
  
  def delete_first(self):
    return self.delete_at(0)

  def delete_last(self):
    return self.delete_at(len(self.A) - 1)
  
  def insert_last(self, x):
    return self.insert_at(len(self.A), x)

if __name__ == "__main__":
  def main():
    a = Array_Seq()
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
    a.insert_first(34)
    print(a)
    a.insert_last(45)
    print(a)
  main()


  
    
  
    
    
    
    
    
    
    