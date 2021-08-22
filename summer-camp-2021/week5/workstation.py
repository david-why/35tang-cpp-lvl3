move = []
left = {}
right = {}

with open('workstation.in') as fin:
    n, m, k = map(int, fin.readline().split())
    for i in range(1, n + 1):
        gl, gr = fin.readline().split()
        left[str(i)] = gl
        right[str(i)] = gr
    move = fin.readline().split()

now = '1'
for i in range(k):
    for m in move:
        if m == 'L':
            now = left[now]
        else:
            now = right[now]

with open('workstation.out', 'w') as fout:
    print(now, file=fout)
