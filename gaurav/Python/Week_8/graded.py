from debugger import debug

def subject_average(filename, subject):
  f = open(filename, 'r')
  f.readline()
  val, count = 0,0
  for line in f:
    sno, name, gender, ct, python, pdsa = line.strip().split(',')
    sno, ct, python, pdsa = int(sno), int(ct), int(python), int(pdsa)
    if subject.upper() == "CT":
      val  = val + ct
    elif subject.lower() == "python":
      val = val + python
    else:
      val = val + pdsa
    count += 1
    return val / count
  f.close()

def get_scores(filename, index):
    f = open(filename, 'r')
    # Ignore the header
    f.readline()	
    # we are now at the beginning of the second line of the file
    
    scores = [ ]
    line = f.readline()
    while line != '':
        marks_list = line.strip().split(',')
        scores.append(int(marks_list[index]))
        line = f.readline()
    
    f.close()
    return scores

def median(marks_list):
    marks_list.sort()
    mid = len(marks_list) // 2
    if len(marks_list) % 2 == 0:
        return (marks_list[mid] + marks_list[mid - 1]) // 2
    else:
        return marks_list[mid]
    
def marks_by_gender(infile, gender, outfile):
   f = open(infile, 'r')
   g = open(outfile, 'w')
   header = f.readline()
   header = header.replace(',Gender,', ',')
   g.write(header)
   for line in f.readlines():
      fields = line.strip().split(',')
      gender_in_file = fields[2]
      if gender_in_file == gender:
         out_line = line.replace(f',{gender},', ',')
         g.write(out_line)
   f.close()
   g.close()

def max_len_word_count(filename):
    f = open(filename, 'r')
    maxword = f.readline().strip()
    count = 1
    # we are now at the beginning of the second line
    for line in f:
        word = line.strip()
        if len(word) > len(maxword):
            maxword = word
            count = 1
        elif len(word) == len(maxword):
            count += 1
    
    f.close()
    return count

def main():
  file = "scores.csv"
  file2 = "words.txt"
  ct_average = subject_average(file, "ct")
  python_average = subject_average(file, 'python')
  pdsa_average = subject_average(file, 'pdsa')

  print("The average ct marks are     : ", ct_average)
  print("The average python marks are : ", python_average)
  print("The average pdsa marks are   : ", pdsa_average)
  debug("median",median(get_scores(file, 4)))
  marks_by_gender(file,"M", "male_marks.csv")
  marks_by_gender(file,"F", "female_marks.csv")
  print(max_len_word_count(file2))

if __name__ == "__main__":
  main()