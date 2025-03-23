

def sort_Ascending_Order(num_array):
    for i in range(len(num_array)):
        for j in range(len(num_array) - 1):
            if num_array[j] > num_array[j + 1]:
                temp = num_array[j] 
                num_array[j] = num_array[j+1]
                num_array[j+1] = temp
    return num_array


def sort_Descending_Order(num_array):
    for i in range(len(num_array)):
        for j in range(len(num_array) - 1):
            if num_array[j] < num_array[j + 1]:
                temp = num_array[j] 
                num_array[j] = num_array[j+1]
                num_array[j+1] = temp
    return num_array



a = [2,2,6,8,3,1,3,9]
b = [2,1,4,2,4,5,6,3]

print(sort_Ascending_Order(a))
print(sort_Descending_Order(a))