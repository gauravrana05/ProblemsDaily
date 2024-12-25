def shuffle(a, b):
    """
    Interleaves two lists a and b into a single list, alternating elements.
    If one list is longer, the remaining elements are appended at the end.
    """
    ret = []
    min_len = min(len(a), len(b))  # Determine the shorter length

    # Interleave elements from both lists
    for i in range(min_len):
        ret.append(a[i])
        ret.append(b[i])
    
    # Append the remaining elements from the longer list
    ret.extend(a[min_len:])
    ret.extend(b[min_len:])
    
    return ret

# Input and Output
L1 = eval(input("Enter the first list: "))
L2 = eval(input("Enter the second list: "))
print(shuffle(L1, L2))
