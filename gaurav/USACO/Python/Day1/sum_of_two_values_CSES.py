import sys
n, target = map(int, input().split())
values = [int(x) for x in input().split()]

val_to_ind = {}
for i, val in enumerate(values):
    if target - val in val_to_ind:
        print(i+1, val_to_ind[target - val])
        sys.exit()
    val_to_ind[val] = i + 1
print("IMPOSSIBLE")

