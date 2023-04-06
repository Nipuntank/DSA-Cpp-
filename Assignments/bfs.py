graph={
    '5':['3','7'],
    '3':['2','4'],
    '7':['8'],
    '2':[],
    '4':['8'],
    '8':[]
}
visited=[]
queue=[]
def dfs(graph,visited,node):
    visited.append(node)
    print(node)
    for i in graph(node):
        if i not in visited:
            dfs(graph,visited,i)

def bfs(graph,visited,node):
    visited.append(node)
    queue.append(node)
    while queue:
        m = queue[0]
        del queue[0]
        print(m,end=" ")
        for i in graph[m]:
            if i not in visited:
                visited.append(i)
                queue.append(i)

print("DFS:")
bfs(graph,visited,'5')
dfs(graph,visited,'5')