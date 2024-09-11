def find_number_appearing_twice(arr):
    result = 0
    for i in range(32):  # Giả sử số nguyên 32 bit
        sum = 0
        for num in arr:
            if num & (1 << i):
                sum += 1
        if sum % 3 != 0:
            result |= (1 << i)
    return result

# Ví dụ sử dụng
arr = [1,1,1, 4 ,4,5,4,5]
print(find_number_appearing_twice(arr))  # Kết quả: 2