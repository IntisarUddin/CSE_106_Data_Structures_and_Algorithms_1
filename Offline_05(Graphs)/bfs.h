#include <vector>
#include <queue>
using namespace std;

class BFS
{
    int n;
    vector<vector<bool>> vec;
    vector<bool> isVis;

public:
    void init(int n)
    {
        this->n = n;
        vec.clear();
        isVis.clear();
        for (int i = 0; i <= n; i++)
        {
            isVis.push_back(false);
            vector<bool> temp;
            for (int j = 0; j <= n; j++)
            {
                temp.push_back(false);
            }
            vec.push_back(temp);
        }
    }
    void make_edge(int a, int b)
    {
        vec[a][b] = true;
        vec[b][a] = true;
    }
    bool isVisited(int i)
    {
        return isVis[i];
    }
    void traverse(int i)
    {

        queue<int> Queue;
        Queue.push(i);
        isVis[i] = true;
        while (!Queue.empty())
        {
            int node = Queue.front();
            Queue.pop();
            for (int j = 1; j <= n; j++)
            {
                if (vec[node][j])
                {
                    if (isVis[j])
                    {
                        continue;
                    }
                    isVis[j] = true;
                    Queue.push(j);
                }
            }
        }
        return;
    }
};