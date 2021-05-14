INF = 10 ** 9
N = 7
M = 12
dist = [INF] * N
dist[0] = 0
used = [False] * N
ans = 0

W = []

for i in range(N):
    W.append([])
    for j in range(N):
        W[i].append(INF)

for i in range(M):
    start, end, weight = map(int, input().split())
    W[start][end] = weight
    W[end][start] = weight


for i in range(N):
    min_dist = INF
    for j in range(N):
        if not used[j] and dist[j] < min_dist:
            min_dist = dist[j]
            u = j
    ans += min_dist
    used[u] = True
    print(u, end=' ')
    for v in range(N):
        dist[v] = min(dist[v], W[u][v])
