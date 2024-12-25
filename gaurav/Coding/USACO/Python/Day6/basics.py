i = 23;
print(i)

i = 34;
print(i)

x = 0.1 + 0.2
print(x)
squares = [x**2 for x in range(23) if x % 2 == 0]
print(squares)
dict = {x: x**2 for x in range(10)}
print(dict)
with open('data.txt' , 'w') as file:
  file.write("This is a new file")

print("Hello, {} ".format("Gaurav"))
print("{:>10}".format("Test"))
print("{:<10}".format("Test"))
print("{:^10}".format("Test"))
pi = 3.124243232323
print("{:10.2f}".format(pi))  # Output: 3.14
print(f"{23423432432:,}")  # Output: 1,234,567,890
