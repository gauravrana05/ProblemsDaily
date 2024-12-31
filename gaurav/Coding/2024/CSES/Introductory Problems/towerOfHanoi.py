n = int(input())

print(2**n -1)

def toh(i, src, dest, aux):
    if(i == 1):
        print(src, dest);
        return;
   
    toh(i-1, src, aux, dest);
    print(src, dest);
    toh(i-1, aux, dest, src);

toh(n, 1, 3 ,2);
