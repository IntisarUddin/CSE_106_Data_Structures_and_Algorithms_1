#include <vector>
using namespace std;

class DFS
{
    int n;
    vector<vector<int>> vec;
    vector<bool> isVis;

public:
    void init(int n)
    {
        this->n = n;
        vector<int> temp;
        vec.clear();
        isVis.clear();
        for (int i = 0; i <= n; i++)
        {
            isVis.push_back(false);
            vec.push_back(temp);
        }
    }
    void make_edge(int a, int b)
    {
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    void traverse(int i)
    {
        isVis[i] = true;
        for (int nb : vec[i])
        {
            if (isVis[nb])
            {
                continue;
            }

            traverse(nb);
        }
        return;
    }
    bool isVisited(int i)
    {
        return isVis[i];
    }
};