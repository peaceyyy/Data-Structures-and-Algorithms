
def binarySearch(list: list, target: int) -> int:
    l = 0 
    r = len(list) - 1

    while (l <= r):

        middle = l + (r - l)// 2

        if(list[middle] == target):
            return middle
        elif(list[middle] < target):
            l = middle + 1  
        else:
            r = middle - 1
    

        
list = [0, 1, 2, 4, 5, 6, 7, 8, 9, 12]

print(binarySearch(list, 12)) 