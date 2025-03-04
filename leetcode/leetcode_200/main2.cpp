#include <bits/stdc++.h>

using namespace std;

class Makemap {
   public:
    Makemap(vector<vector<char>>& grid) {
        count = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    parent.push_back(i * m + j);
                } else
                    parent.push_back(-1);
            }
        }
    }
    int get(int i) {
        // cout << parent[i] << " " << i << endl;
        if (parent[i] != i) return parent[i] = get(parent[i]);
        return parent[i];
    }
    void merge(int x, int y) {
        int fx = get(x), fy = get(y);
        if (fx != fy) {
            parent[fy] = fx;
            count--;
        }
    }
    int getcount() { return count; }

   private:
    vector<int> parent;
    int count;
};

class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int n = grid.size(), m = grid[0].size();
        Makemap uf(grid);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    if (i - 1 >= 0 && grid[i - 1][j] == '1')
                        uf.merge(i * m + j, (i - 1) * m + j);
                    if (i + 1 < n && grid[i + 1][j] == '1')
                        uf.merge(i * m + j, (i + 1) * m + j);
                    if (j - 1 >= 0 && grid[i][j - 1] == '1')
                        uf.merge(i * m + j, i * m + j - 1);
                    if (j + 1 < m && grid[i][j + 1] == '1')
                        uf.merge(i * m + j, i * m + j + 1);
                }
            }
        }
        return uf.getcount();
    }
};

int main() {
    Solution e;
    vector<vector<char>> v;
    for(int i = 0; i < 4; i++) {
        vector<char> t;
        for(int j = 0; j < 5; j++) {
            char ch;
            cin >> ch;
            t.push_back(ch);
        }
        v.push_back(t);
    }
    cout << e.numIslands(v) << endl;
    return 0;
}