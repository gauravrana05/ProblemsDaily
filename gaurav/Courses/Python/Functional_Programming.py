import collections
from pprint import pprint 

Scientist = collections.namedtuple("Scientist", ['name', 'field','born','nobel'])

scientists = (
              Scientist("Raghav", "Chemistry",1997,"no"),
              Scientist("Swapnil", "Maths",1999,"yes"),
              Scientist("Nishant", "Biology",2000,"no"),
              Scientist("Ajay", "Statistics",1995,"yes"),
              Scientist("Ram", "Yoga",2000,"no"),
              Scientist("Sham", "Religion", 1998, "yes"))

fs = filter(lambda x: x.nobel == "yes", scientists)
names_ages = tuple(map(lambda x: {'name': x.name , 'age': 2024 - x.born} , scientists))
pprint(names_ages)
