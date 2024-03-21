"""
given list generates all possible permutations
input: [1, 2, 3]
otput: [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]
"""
a = []
temp = []
def perm(gen):
    if len(gen) == 0:
        a.append(temp.copy())
        return
    else:
        for x in gen:
            temp.append(x)
            temp1 = gen.copy()
            temp1.remove(x)
            perm(temp1)
            temp.pop()
