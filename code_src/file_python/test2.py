def twoStacks(maxSum, a, b):
    Totalsum = 0
    countS1 = 0 
    countS2 = 0
    result = 0
    for ele in a:
        if Totalsum + ele > maxSum:
            break
        Totalsum = Totalsum + ele
        countS1 = countS1 + 1
    for ele in b:
        Totalsum = Totalsum + ele
        countS2 = countS2 + 1
        while Totalsum > maxSum and countS1 > 0:
            Totalsum = Totalsum - a[countS1-1]
            countS1 = countS1 -1
        if Totalsum <= maxSum:
            result = max((countS1 + countS2), result)
    return result


print(twoStacks(62, [7 ,15, 12, 0, 5, 18, 17, 2, 10 ,15 ,4 ,2, 9, 15, 13, 12, 16], [12 ,16, 6 ,8 ,16, 15, 18, 3 ,11 ,0 ,17, 7 ,6 ,11, 14, 13, 15, 6 ,18, 6, 16, 12, 16 ,11 ,16 ,11])) # 5