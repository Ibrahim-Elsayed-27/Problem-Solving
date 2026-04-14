def dfs_graph(grid, visited, start_node):
    rows = len(grid)
    cols = len(grid[0])

    r, c = start_node

    # mark current node as visited
    visited[r][c] = 1

    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

    for dr, dc in directions:
        nr, nc = r + dr, c + dc

        if (
            0 <= nr < rows and
            0 <= nc < cols and
            visited[nr][nc] == 0 and
            grid[nr][nc] == '1'   # or 1 depending on input
        ):
            dfs_graph(grid, visited, (nr, nc))
    

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        visited_list = [[0 for _ in range(len(grid[0]))] for _ in range(len(grid))]
        islands = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                print(grid[i][j], "   ", visited_list[i][j])
                if ( grid[i][j] == '1'):
                    if(not visited_list[i][j]):
                        print("hima")
                        dfs_graph(grid, visited_list, (i, j))
                        islands += 1

        return islands



