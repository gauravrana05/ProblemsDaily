for _ in range(int(input())):
    k = int(input())

    length = first = 1
    while( k > 9* first * length ):
        k -= 9*first * length
        length +=1
        first *= 10
    q, r = divmod(k, length)
    print(str(first + q)[r])