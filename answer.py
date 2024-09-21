import random

n, k = 10, 5
a = [random.randint(0, 1) for i in range(n)]

print(n, k)
while True:
    line = input()
    c, x = line[0], line[2:]
    x = list(map(int, x.split()))
    if c == '?':
        res = 0
        for i in x:
            res ^= a[i - 1]
        print(res)
    else:
        assert a == x
        break

# インタラクティブ問題：テストの実行方法
# $ mkfifo tmp
# $ ./a.out < tmp | python3 answer.py > tmp