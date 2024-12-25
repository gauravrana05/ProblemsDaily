t = int(input())

while(t):
    [x,y] = map(int,input().split());

    if(x > y):
        if(x % 2 == 0):
            ans = x * x - y + 1;
        else:
            ans = (x - 1) * (x - 1) + y  ;
    else:
        if(y % 2 == 0):
            ans = (y - 1) * (y - 1) + x ;
        else:
            ans = y * y - x + 1;
    print(ans)
    t = t - 1;

