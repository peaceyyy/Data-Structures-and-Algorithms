


def mergeSort(arr): 
    if len(arr) > 1:
        leftSubArr = arr[:len(arr)//2]
        rightSubArr = arr[len(arr)//2:]
        leftSubArrLen = len(leftSubArr)
        rightSubArrLen = len(rightSubArr)

        mergeSort(leftSubArr)
        mergeSort(rightSubArr)

        i = j = k = 0

        for _ in range(leftSubArrLen + rightSubArrLen):
            if i < leftSubArrLen and (j >= rightSubArrLen or leftSubArr[i] <= rightSubArr[j]):
                arr[k] = leftSubArr[i]
                i += 1
            else:
                arr[k] = rightSubArr[j]
                j += 1
            k += 1     

def main():
        arr = [12, 11, 13, 5, 6, 7]
        print("Given array is", arr)
        mergeSort(arr)
        print("Sorted array is", arr)

if __name__ == "__main__":
        main()