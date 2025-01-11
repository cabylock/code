class BIT:
    def __init__(self, n):
        self.n = n
        self.tree = [0] * (n + 1)

    def update(self, i, x):
        while i <= self.n:
            self.tree[i] += x
            i += i & -i

    def query(self, i):
        res = 0
        while i > 0:
            res += self.tree[i]
            i -= i & -i
        return res

n, q = map(int, input().split())
v = [int(x) for x in input().split()]

bit = BIT(n + q)
for x in v:
    bit.update(x, 1)

for _ in range(q):
    x = int(input())
    index = bit.query(x)
    bit.update(x, 1)
    print(index + 1)