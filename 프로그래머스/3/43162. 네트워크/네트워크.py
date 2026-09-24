def solution(n, computers):
    visited = [False] * n
    
    def dfs(cur):
        visited[cur] = True
        for nxt in range(n):
            if computers[cur][nxt] == 1 and not visited[nxt]:
                dfs(nxt)
    answer = 0
    for i in range(n):
        if not visited[i]:
            dfs(i)
            answer+=1
    return answer