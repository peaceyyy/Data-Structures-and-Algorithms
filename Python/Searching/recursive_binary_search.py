def binarySearch(target, list, left, right):
    
    if left > right:
        return -1
    

    mid = left + (right - 1) // 2

    if list[mid] == target:
        return mid
    
    elif list[mid] < target:
        return binarySearch(target, list, mid + 1, right)
    
    return binarySearch(target, list, left, mid - 1)



sortedList = [0, 1, 2, 4, 6, 8, 9, 12, 15]

left = 0
right = len(sortedList) - 1
target = 4

print(binarySearch(target, sortedList, left, right))

