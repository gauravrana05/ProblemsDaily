  
'''
The two arguments for this function are the files:
    - currentMem: File containing list of current members
    - exMem: File containing list of old members
    
    This function should remove all rows from currentMem containing 'no' 
    in the 'Active' column and appends them to exMem.
    '''
def cleanFiles(currentMem, exMem):
    headers = "Membership No  Date Joined  Active  \n"
    with open(currentMem, 'r+') as file:
        file.readline()
        active_lines = []
        with open(exMem, 'a+') as file2:
            for current in file.readlines():
                active = current.strip().split()[2]
                if active == 'no':
                    file2.write(current)
                else:
                    active_lines.append(current)
        file.seek(0)
        file.truncate(0)
        file.write(headers)
        for line in active_lines:
            file.write(line)
