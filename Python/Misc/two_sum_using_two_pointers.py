def two_sum(list, target):

        left = 0
        right = len(list) - 1

        while left < right:

            current_sum = list[left] + list[right]

            if current_sum == target:
                return left, right  
            elif current_sum < target:
                left += 1
            else:
                right -= 1
        
        return -1


numbers = [1, 2, 3, 4, 5]  
target = 6  
result = two_sum(numbers, target)  

if result:  
    print(f"Indices found: {result}")  
else:  
    print("No such indices found.")  