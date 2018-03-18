
with open('/home/martin/X-Brain/Bachelar/Atom/algorithm/oj/poj-pre/lan/a.txt') as f:
    with open('/home/martin/X-Brain/Bachelar/Atom/algorithm/oj/poj-pre/lan/b.txt') as g:
        lineA = f.readlines()
        lineB = g.readlines()
        sorted(lineB)
        sorted(lineA)
        for i in range(len(lineA)):
            print(lineA[i], lineB[i])
    



