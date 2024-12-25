t = int(input())

while(t):
    [a, b] = map(int, input().split())    
    if( a == 0 and b == 0):
        print("YES")
    elif(a == 0 or b == 0):
        print("NO")
    else:        
        if( (a + b) % 3 != 0):
            print("NO")
        else:
            if(a > (2 * b) or b > (2 * a) ):
                print("NO")
            else:
                print("YES")
    t = t - 1;