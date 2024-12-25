import csv
import random
import names

def generate_marks():
  return random.randint(0, 100)

with open('scores.csv', 'w' , newline = '') as file:
  writer = csv.writer(file)
  writer.writerow(['ID', 'Name', 'Maths', 'Science', 'English', 'Total'])
  for i in range(1, 10001):
    student_id = f'S{i:03}'
    name = f"{names.get_first_name()} {names.get_last_name()}"
    math_marks = generate_marks()
    science_marks = generate_marks()
    english_marks = generate_marks()

    total_marks = math_marks + science_marks + english_marks

    writer.writerow([student_id, name, math_marks, science_marks, english_marks, total_marks])


print("scores.csv has been created with 10000 records.")



