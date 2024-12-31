mat = [list(input()) for y in range(8)]

count = [0];

def isSafe(mat, row, col):
    if(mat[row][col] == '*'):
        return False;

    for i in range(col):
        if(mat[row][i] == 'q'):
            return False;
    i = row;
    j = col;
    while( i>=0 and j>= 0):
        if(mat[i][j] == 'q'):
            return False;
        i-=1;
        j-=1;
    i = row;
    j = col;
    while( i < 8 and j >= 0):
        if(mat[i][j] == 'q'):
            return False;
        i+=1;
        j-=1;
    return True;

def solve(col, mat, count):
    if(col >= 8):
        count[0]+=1;
        return;
    for i in range(8):
        if(isSafe(mat, i, col)):
            mat[i][col] = 'q';
            solve(col + 1, mat, count);
            mat[i][col] = '.';

solve(0, mat, count)
print(count[0])