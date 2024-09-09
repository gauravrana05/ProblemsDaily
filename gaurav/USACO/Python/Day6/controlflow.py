from pprint import pprint 

# pprint({x:x**2 for x in range(41)})

squares = list(map(lambda x: x**2, range(12)))
evens = list(filter(lambda x: x % 2 == 0, range(100)))
pprint(evens)