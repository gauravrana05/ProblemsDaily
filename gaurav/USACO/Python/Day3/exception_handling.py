
try:
  a = int(input())
  b = int(input())
except ValueError:
  print("Invalid Input")

try:
  c  = a / b 
  print(c)
except ZeroDivisionError:
  print("Invalid Input, divisor cannot be zero")
except NameError:
  print("Please retry with proper inputs")
except FileNotFoundError:
  print("File does not exist")
except: 
  print("Something went wrong")
finally: 
  print('I am here in finally')
  