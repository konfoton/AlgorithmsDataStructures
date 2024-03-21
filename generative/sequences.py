"""
given list generates all posiible sequences
input:  [1, 2]
output: [1, 1], [1, 2], [2, 2], [1, 1]
"""
a = []
temp = []
def all(gen):
    if len(temp) == len(gen):
        a.append(temp.copy())
        return
    else:
        for x in gen:
            temp.append(x)
            all(gen)
            temp.pop()

