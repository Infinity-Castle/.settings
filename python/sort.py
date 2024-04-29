def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

# Prompt the user to enter the array elements
user_input = input("Enter the array elements separated by spaces: ")

# Convert the user input into a list of integers
arr = [int(x) for x in user_input.split()]

print("Original array:", arr)
print("Quick sorted array:", quick_sort(arr))