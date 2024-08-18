from pprint import pprint 

L = [('Arjun', 75), ('Anita', 85), ('Atul', 80), ('Anwer', 75), ('Andrew', 80)]

def main():
    f = open('scores.csv', 'w')
    f.write('Name,Python\n')
    for i in range(len(L)):
        name, marks = L[i]
        line = f'{name},{marks}'
        if i != len(L) - 1:
            line = line + '\n'
        f.write(line)
    f.close()
if __name__ == "__main__":
    main()