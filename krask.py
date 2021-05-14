n, m = map(int, input().split())
edges = []
for i in range(m):
    start, end, weight = map(int, input().split())
    edges.append([weight, start, end])
edges.sort()

print(edges)

Comp = [i for i in range(n)]

print(Comp)

Ans = 0
for weight, start, end in edges:
    if Comp[start] != Comp[end]:
        Ans += weight
        a = Comp[start]
        b = Comp[end]
        for i in range(n):
            if Comp[i] == b:
                Comp[i] = a


"""
7 12
0 1 20
0 5 23
0 6 1
1 6 4
1 2 15
5 6 36
6 2 9
5 4 28
6 4 25
6 3 16
3 2 3
4 3 17
"""
