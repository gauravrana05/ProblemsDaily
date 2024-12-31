[n, w] = list(map(int, input().split()))

weights = list(map(int, input().split()))

weights.sort()

ans = 0;
i = 0;
st = 0;
end = n - 1;
while(st < end):
    if(weights[st] + weights[end] <= w):
        st+=1;
        end-=1;
    else:
        end-=1;

    ans+=1;

if(st == end):
    ans+=1;
print(ans)