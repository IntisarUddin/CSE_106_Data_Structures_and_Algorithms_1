#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int N = 1e7 + 10;
int parent[N];
int Count[N];
void initialize(int v)
{
    parent[v] = v;
    Count[v] = 1;
}
int find_parent(int v)
{
    if (parent[v] == v)
    {
        return v;
    }

    return (parent[v] = find_parent(parent[v]));
}

void make_union(int u, int v)
{
    int v_parent = find_parent(v);
    int u_parent = find_parent(u);
    if (v_parent != u_parent)
    {
        if (Count[v_parent] < Count[u_parent])
        {
            swap(v_parent, u_parent);
        }
        parent[u_parent] = v_parent;
        Count[v_parent] += Count[u_parent];
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> vec(m);
    for (int i = 0; i < m; i++)
    {
        int wt, u, v;
        cin >> wt >> u >> v;
        vec[i] = {wt, {u, v}};
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < n; i++)
    {
        initialize(i);
    }

    int cost = 0;

    for (int i = 0; i < m; i++)
    {
        int wt = vec[i].first;
        int u = vec[i].second.first;
        int v = vec[i].second.second;

        if (find_parent(u) == find_parent(v))
        {
            continue;
        }
        make_union(u, v);
        cost += wt;
    }
    cout << cost << endl;
    return 0;
}