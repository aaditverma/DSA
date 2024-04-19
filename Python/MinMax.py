def findMaxMin(arr, low, high):
    # Base cases
    if low == high:  # If there's only one element
        return arr[low], arr[low]
    elif high - low == 1:  # If there are two elements
        return max(arr[low], arr[high]), min(arr[low], arr[high])

    # Divide the array into two halves
    mid = (low + high) // 2

    # Recursively find the maximum and minimum in the left and right halves
    leftMax, leftMin = findMaxMin(arr, low, mid)
    rightMax, rightMin = findMaxMin(arr, mid + 1, high)

    # Compare and return the overall maximum and minimum
    return max(leftMax, rightMax), min(leftMin, rightMin)

# Read the number of elements
n = int(input("Enter the number of elements: "))

# Read the elements of the array
arr = []
print("Enter the elements:")
for _ in range(n):
    arr.append(int(input()))

# Call the findMaxMin function and print the result
maximum, minimum = findMaxMin(arr, 0, n - 1)
print("Maximum element:", maximum)
print("Minimum element:", minimum)