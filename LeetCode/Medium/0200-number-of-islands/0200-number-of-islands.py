def graph_bfs(grid, visited_queue, i, j):
    visited_queue.append([i, j])
    grid[i][j] = "0"   

    while visited_queue:
        i, j = visited_queue.pop()
        #print(i,j)
        # Down
        if i + 1 < len(grid) and grid[i+1][j] == "1":
            visited_queue.append([i+1, j])
            grid[i+1][j] = "0"   

        # Up
        if i - 1 >= 0 and grid[i-1][j] == "1":
            visited_queue.append([i-1, j])
            grid[i-1][j] = "0"

        # Right
        if j + 1 < len(grid[0]) and grid[i][j+1] == "1":
            visited_queue.append([i, j+1])
            grid[i][j+1] = "0"

        # Left
        if j - 1 >= 0 and grid[i][j-1] == "1":
            visited_queue.append([i, j-1])
            grid[i][j-1] = "0"
            
    


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        #print(len(grid))
        islands = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                #print(i,j, "   ", grid[i][j])
                if(grid[i][j] == "1"):
                    graph_bfs(grid, [], i, j)
                    islands+=1

        return islands

        