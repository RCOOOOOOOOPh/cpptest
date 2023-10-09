#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(vector<vector<int>>& mountain, vector<vector<int>>& num, int i, int j)
{
    if (num[i][j] != 0) return num[i][j];
    int ans = 1;
    if (i > 0 && mountain[i-1][j] < mountain[i][j])
    {
        ans = max(ans, dfs(mountain, num, i-1, j)+1);
    }
    if (i < mountain.size()-1 && mountain[i+1][j] < mountain[i][j])
    {
        ans = max(ans, dfs(mountain, num, i+1, j)+1);
    }
    if (j > 0 && mountain[i][j-1] < mountain[i][j])
    {
        ans = max(ans, dfs(mountain, num, i, j-1)+1);
    }
    if (j < mountain[0].size()-1 && mountain[i][j+1] < mountain[i][j])
    {
        ans = max(ans, dfs(mountain, num, i, j+1)+1);
    }
    num[i][j] = ans;
    return ans;
}

int max_mountain(vector<vector<int>> mountain) {
    int m = mountain.size();
    int n = mountain[0].size();
    vector<vector<int>> num(m, vector<int>(n, 0));
    int ans = 0;
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            ans = max(ans, dfs(mountain, num, i, j));
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> mountains {{9, 8, 7}, {4, 5, 6}, {3, 2, 1}};
    
    int res = max_mountain(mountains);
    
    cout << res << endl;

    return 0;
}
