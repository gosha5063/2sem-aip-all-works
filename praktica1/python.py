#1
# a = int(input())
# arr = [int(i) for i in input().split()]

# podhod = 0
# ans = []
# k = 0
# for i in range(a-1,-1,-1):
#     k+=1
#     if arr[i] == 1:
#         podhod +=1
#         ans.append(k)
#         k = 0

# print(podhod)
# print(*ans[::-1])

# import collections
# def bfs(graph, root): 
#     visited, queue = [], collections.deque([root])
#     visited.append(root)
#     dlina = 0
#     star = []
#     while len(visited)!=n:
#         while queue and len(visited)!=n:
#             vertex = queue.popleft()
#             for neighbour in graph[vertex]: 
#                 if neighbour not in visited: 
#                     visited.append(neighbour) 
#                     queue.append(neighbour)
#         mn = 10000
#         for i in visited:
#             if i not in star:
#                 mn = min(mn,energy[i])
#         if  len(graph[root])!=0:
#             dlina += mn
#         star = []
#         for i in visited:
#             star.append(i)
#         if visited[-1] + 1 < n:
#             root = visited[-1] + 1
#             queue.append(root)
#             visited.append(root)
#     return dlina

# n = int(input())
# energy =[int(i) for i in input().split()]
# num = int(input())
# arr = [[] for i in range(n)]
# for i in range(num):
#     out,inp = map(int,input().split())
#     arr[out-1].append(inp-1)
# print(bfs(arr,0))

