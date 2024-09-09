def check_palindrome(str):
  if len(str) <= 1: return True
  elif str[0] != str[-1]: return False
  else: return check_palindrome(str[1:-1])


def main():
  s = str(12343)
  print(check_palindrome(s))

if __name__ == "__main__":
  main()