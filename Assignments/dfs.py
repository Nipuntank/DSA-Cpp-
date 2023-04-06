graph={
    '5':['3','7'],
    '3':['2','4'],
    '7':['8'],
    '2':[],
    '4':['8'],
    '8':[]
}
visited=[]
def dfs(graph,visited,node):
    visited.append(node)
    print(node,end=" ")
    for i in graph[node]:
        if i not in visited:
            dfs(graph,visited,i)

print("DFS:")
dfs(graph,visited,'5')