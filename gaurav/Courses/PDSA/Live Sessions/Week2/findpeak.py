def Findpeak(L, st=0, end=None):
    """
    Function to find a peak element in the list.
    A peak element is defined as an element that is greater than its neighbors.
    
    Parameters:
        L (list): List of integers
        st (int): Starting index for the search
        end (int): Ending index for the search
    
    Returns:
        int: Value of a peak element if found, otherwise -1
    """
    # Handle the initial setup for the end index
    if end is None:
        end = len(L)
    
    # Handle edge cases for lists with fewer than 3 elements
    if len(L) == 1:
        return L[0]
    if len(L) == 2:
        return max(L)

    # Check if the first or last elements are peak elements
    if L[0] > L[1]:
        return L[0]
    if L[-1] > L[-2]:
        return L[-1]

    # Recursive binary search
    if st < end:
        mid = (st + end) // 2

        # Check if the middle element is a peak
        if L[mid - 1] < L[mid] > L[mid + 1]:
            return L[mid]
        
        # If left neighbor is greater, search the left half
        if L[mid - 1] > L[mid]:
            return Findpeak(L, st, mid)
        
        # Otherwise, search the right half
        return Findpeak(L, mid + 1, end)
    
    return -1
