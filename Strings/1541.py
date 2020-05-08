str_in = input().split('-')

num = []
for i in str_in:
    cnt = 0
    for j in i.split('+'):
        cnt += int(j)
    num.append(cnt)

ans = num[0]
for i in range(1, len(num)):
    ans -= num[i]

print(ans)