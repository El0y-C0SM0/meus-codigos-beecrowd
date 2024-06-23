import heapq

INF = float('inf')

def dijkstra(i, g):
    vis = [False] * len(g)
    path = INF
    q = []
    heapq.heappush(q, (0, i))
    
    while len(q) > 0:
        a, b = heapq.heappop(q)
        vis[b] = True

        for d, v in g[b]:
            if v == i:
                path = min(path, a + d)

            if not vis[v]:
                heapq.heappush(q, (a + d, v))

    return path

def main():
    s, c = map(int, input().split())
    tempos = list(map(int, input().split()))
    salas = [[] for _ in range(s)]

    for i in range(c):
        x, y, z = map(int, input().split())
        salas[x-1].append((z + tempos[x-1], y-1))

    r = INF
    for i in range(s):
        r = min(r, dijkstra(i, salas))

    print(r)    

if __name__ == '__main__':
    main()