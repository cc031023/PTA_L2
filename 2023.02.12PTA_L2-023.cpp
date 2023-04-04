#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 1;
struct node
{
    vector<int> v;
    int val;
} p[N];
bool pd[N];
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int V, E, K; // 顶点,边数,颜色数.
    cin >> V >> E >> K;
    for (int i = 1; i <= E; ++i)
    {
        int x, y;
        cin >> x >> y;
        p[x].v.push_back(y);
        p[y].v.push_back(x);
    }
    int N;
    cin >> N;
    while (N--)
    {
        int sum = 0;
        for (int i = 1; i <= V; ++i)
        {
            cin >> p[i].val;
            if (!pd[p[i].val])
            {
                ++sum;
                pd[p[i].val] = true;
            }
        }
        bool flag = false;
        for (int i = 1; i <= V; ++i)
        {
            for (int j = 0; j < p[i].v.size(); ++j)
            {
                int next = p[i].v[j];
                if (p[i].val == p[next].val)
                {
                    flag = true;
                }
            }
        }
        if (flag || sum > K)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }
        memset(pd, 0, sizeof(pd));
    }
    return 0;
}