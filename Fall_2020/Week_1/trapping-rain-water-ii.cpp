/*
Problem: https://leetcode.com/problems/trapping-rain-water-ii/

Approach: Use a priority queue to push all reactangle border cells, then run a BFS from highest to
lowest cell using the waterflow logic, we will stop a single BFS when reaching a cell that has more
water than BFS start.

Time complexity: O(n)

Space complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Cell {
    int height, x, y;
    Cell(int _height, int _x, int _y){
        height = _height;
        x = _x;
        y = _y;
    }
    bool operator >(const Cell& pt) const {
        return height > pt.height;
    }
};

int trapRainWater(vector<vector<int> >& heightMap) {
    int n = heightMap.size(), m = heightMap[0].size(), ans = 0;
    // This arrays are used to run bfs in four directions for each cell.
    int bfsX[] = { 0, 0, 1, -1 }, bfsY[] = { 1, -1, 0, 0 };
    // Priority queue structure is Cell(height, x, y)
    priority_queue<Cell, vector<Cell>, greater<Cell> > pq;
    // Matrix of visited cells.
    vector<vector<bool> > vis(n, vector<bool>(m, false));
    // Push a cell if its on the border of our map of cells.
    for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if (!i || !j || i == n-1 || j == m-1) 
                    pq.push(Cell(heightMap[i][j], i, j));
    while(!pq.empty()){
        // Get the highest height Cell.
        Cell start = pq.top();
        // Run a BFS from this cell looking for lower or same height cells.
        while(!pq.empty()){
            Cell curr = pq.top();
            // We will get out of this BFS in case that we reach a cell that is highest than our current, 
            // as Waterflow logic (from up to down).
            if(curr.height > start.height) break;
            // Pop the current cell to find others. 
            pq.pop();
            // If we already visited this cell we will skip the Breadth First Search for this cell.
            if(vis[curr.x][curr.y]) continue;
            // Marked as visited the current cell.
            vis[curr.x][curr.y] = true;
            // If height is less than start there will be some water in this cell.
            ans+= start.height - curr.height;
            // Breadth Search (Checking bound limits).
            for(int i=0; i<4; i++)
                if(~(curr.x+bfsX[i]) && curr.x+bfsX[i] < n && ~(curr.y+bfsY[i]) && curr.y+bfsY[i] < m) 
                    pq.push(Cell(heightMap[curr.x+bfsX[i]][curr.y+bfsY[i]], curr.x+bfsX[i], curr.y+bfsY[i]));
        }
    }
    return ans;
}

int main(){
    vector<vector<int> > heightMap = {
        {1,4,3,1,3,2},
        {3,2,1,3,2,4},
        {2,3,3,2,3,1}
    };
    cout << trapRainWater(heightMap) << endl;
    return 0;
}