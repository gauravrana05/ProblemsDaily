from pprint import pprint

f = open("students.csv", 'r')
f.readline()

D = dict()

for line in f:
  name, gender, age = line.strip().split(",")
  D[name] = {'Age': age, "Gender": gender}
pprint(D)