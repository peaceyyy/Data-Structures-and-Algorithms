

def bottomUpFib(n):

    if n == 0:
        return 0
    if n == 1:
        return 1

    prev = 0
    curr = 1

    for i in range(2, n + 1):
        prev, curr = curr, curr + prev

    return curr
def topDownFib(n):
    memo = {0: 0, 1: 1}

    def findInDict(x):
        if x in memo:
            return memo[x]
        else:
            memo[x] = findInDict(x - 1) + findInDict(x - 2)
            return memo[x]

    return findInDict(n)


print(bottomUpFib(8))
print(topDownFib(6))

