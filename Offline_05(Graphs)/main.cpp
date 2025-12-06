#include <iostream>
#include <vector>
#include "bfs.h"
// #include "dfs.h"
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    // DFS dfs;
    BFS bfs;
    int dfs_count, bfs_count;
    vector<int> dfs_edge;
    vector<int> bfs_edge;

    dfs_count = bfs_count = 0;

    cin >> n >> m;

    // dfs.init(n);
    bfs.init(n);

    // for (int i = 0; i < m; i++)
    // {
    //     int a, b;
    //     cin >> a >> b;
    //     if(a > 0 && a <= n && b > 0 && b <= n && a != b){
    //          dfs.make_edge(a, b);
    //          bfs.make_edge(a, b);
    //      }
    // }

    // for (int i = 0; i < m; i++)
    // {
    //     int a, b;
    //     cin >> a >> b;
    //     if (a > 0 && a <= n && b > 0 && b <= n && a != b)
    //     {
    //         dfs.make_edge(a, b);
    //     }
    // }
    // for (int i = 1; i <= n; i++)
    // {
    //     if (dfs.isVisited(i))
    //     {
    //         continue;
    //     }
    //     dfs_count++;
    //     dfs_edge.push_back(i);
    //     dfs.traverse(i);
    // }
    // if (dfs_edge.size() > 1)
    // {
    //     cout << dfs_edge.size() - 1 << endl;
    //     for (int i = 0; i < dfs_edge.size() - 1; i++)
    //     {
    //         cout << dfs_edge[i] << " " << dfs_edge[i + 1] << endl;
    //     }
    // }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > 0 && a <= n && b > 0 && b <= n && a != b)
        {
            bfs.make_edge(a, b);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (bfs.isVisited(i))
        {
            continue;
        }
        bfs_count++;
        bfs_edge.push_back(i);
        bfs.traverse(i);
    }

    if (bfs_edge.size() > 1)
    {
        cout << bfs_edge.size() - 1 << endl;
        for (int i = 0; i < bfs_edge.size() - 1; i++)
        {
            cout << bfs_edge[i] << " " << bfs_edge[i + 1] << endl;
        }
    }

    return 0;
}