"""
given list gen and int n returns all comibations
input: gen = [1, 2, 3] n = 2
output: [1, 2], [1, 3], [2, 3]
"""
a = []
temp = []
def comb(gen, n):
    if len(temp) == n:
        a.append(temp.copy())
        return
    else:
        for y, x in enumerate(gen):
            temp.append(x)
            comb(gen[y+1:], n)
            temp.pop()
