from functools import cmp_to_key

def comp(a, b):
    if a['score'] > b['score']:
        return -1
    elif a['score'] < b['score']:
        return 1
    else:
        if a['name'] > b['name']:
            return 1
        elif a['name'] < b['name']:
            return -1
        else:
            return 0

target = input()
n = int(input())

cntL = cntO = cntV = cntE = 0
for i in target:
    if i == 'L':
        cntL += 1
    elif i == 'O':
        cntO += 1
    elif i == 'V':
        cntV += 1
    elif i == 'E':
        cntE += 1

max = 0
list = []
for i in range(n):
    name = input()
    l = name.count('L') + cntL
    o = name.count('O') + cntO
    v = name.count('V') + cntV
    e = name.count('E') + cntE
    score = ((l + o) * (l + v) * (l + e) * (o + v) * (o + e) * (v + e)) % 100
    list.append({'name': name, 'score': score})


print(sorted(list, key=cmp_to_key(comp))[0]['name'])
