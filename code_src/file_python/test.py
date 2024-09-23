def arithmeticExpressions(arr):
    this = [None] * 101
    this[arr[0]] = [arr[0]]
    for a in arr[1:]:
        if this[0]:
            this[0] += ['*', a]
        else:
            that = [None] * 101
            for i, v in enumerate(this):
                if v is not None:
                    that[(i+a)%101] = this[i] + ['+', a]
                    that[(i-a)%101] = this[i] + ['-', a]
                    that[(i*a)%101] = this[i] + ['*', a]
                    print((i+a)%101, (i-a)%101, (i*a)%101)
            this = that
    
    return ''.join(map(str, this[0]))


print( -5 % 101)
# print(arithmeticExpressions([59, 34 ,36, 63, 79, 82, 20 ,4 ,81, 16 ,30, 93 ,50 ,38 ,78, 10 ,22 ,61 ,91 ,27, 18, 78, 96, 19 ,38, 10 ,3 ,17 ,42, 90, 98 ,60 ,1 ,63, 16, 28 ,97, 45, 19, 35, 44, 56, 77, 43, 24, 42, 28, 35, 95 ,44 ,61 ,55 ,32 ,84]))