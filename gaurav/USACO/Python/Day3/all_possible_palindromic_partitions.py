#author dqgr
class All_Plaindromic_Partitions:
  
  def check_palindrome(self, s):
    if len(s) <= 1:     return True
    elif s[0] != s[-1]: return False
    else:               return self.check_palindrome(s[1:-1])
  
  def partitions(self, result, str, ind, curr):
    if ind == len(str):
      result.append(list(curr))
      return
    temp = ""
    for i in range(ind, len(str)):
      temp += str[i]
      if self.check_palindrome(temp):
        curr.append(temp)
        self.partitions(result, str, i + 1, curr)
        curr.pop()
        
  def main(self):
    res = []
    s = "gauravaruag"
    ind = 0
    curr = []
    self.partitions(res, s, ind, curr)

    for iter in res:
      print(iter)

gfg_obg = All_Plaindromic_Partitions()
gfg_obg.main()

