#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;
vector<int> v[N];
bool pd[N];
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        for (int i = 1; i <= k; ++i)
        {
            int x;
            cin >> x;
            pd[x] = true;
        }
        int flag = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (pd[i])
            {
                continue;
            }
            for (int j = 0; j < v[i].size(); ++j)
            {
                if (!pd[v[i][j]])
                {
                    flag = 1;
                }
            }
        }
        if (flag)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
        memset(pd, 0, sizeof(pd));
    }
    return 0;
}