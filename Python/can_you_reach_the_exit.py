def dfs(graph, source):
    if source is None or source not in graph:
        return "Invalid input"
    
    visited = {}
    for key in graph.keys():
        visited[key] = False

    path = []
    stack = [source]
    
    while(len(stack) != 0):
        s = stack.pop()        
        if (not visited[s]):
            visited[s] = True
            path.append(s)
        for neighbor in graph[s]:
            if (not visited[neighbor]):
                stack.append(neighbor)
    return path

def available_moves(idx_to_check, maze):
    row_idx, el_idx = idx_to_check
    directions_available = []
    
    if row_idx - 1 >= 0 and maze[row_idx - 1][el_idx] != 'W': # check north
        directions_available.append("N")
    if row_idx + 1 < len(maze) and maze[row_idx + 1][el_idx] != 'W': # check south
        directions_available.append("S")
    if el_idx - 1 >= 0 and maze[row_idx][el_idx - 1] != 'W': # check west
        directions_available.append("W")
    if el_idx + 1 < len(maze[row_idx]) and maze[row_idx][el_idx + 1] != 'W': # check east
        directions_available.append("E")
    return directions_available

def build_graph(maze):
    nodes = []
    graph = {}
    
    for row in range(len(maze)):
        for col in range(len(maze)):
            nodes.append((row,col))

    for node in nodes:
        connecting_nodes = []
        for dir in available_moves(node, maze):
            if dir == 'N':
                r,c = node
                r -= 1
                connecting_nodes.append((r,c))
            if dir == 'S':
                r,c = node
                r += 1
                connecting_nodes.append((r,c))
            if dir == 'W':
                r,c = node
                c -= 1
                connecting_nodes.append((r,c))
            if dir == 'E':
                r,c = node
                c += 1
                connecting_nodes.append((r,c))
        graph[node] = connecting_nodes
    return graph
            

def path_finder(maze):
    maze_split = maze.split("\n")
    maze_traveled = [[] for el in range(len(maze_split))]
    N = len(maze_split)

    N = len(maze_split) 
    last_node = (N - 1, N - 1)
    first_node = (0,0)
    visited = set()

    reachable = dfs(build_graph(maze_split), first_node)
    return last_node in reachable