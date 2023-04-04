#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
int counts, fa[N], dis[N], pd[N];
int dfs(int x)
{
    if (fa[x] == -1 || pd[x]) // 到头或者曾经访问过此时dis数组有到根节点的值.
    {
        return dis[x];
    }
    ++counts;
    pd[x] = 1;
    return dis[x] = dfs(fa[x]) + 1;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> fa[i];
    }
    int maxx = -1;
    while (m--)
    {
        int x;
        cin >> x;
        maxx = max(maxx, dfs(x));
        cout << counts * 2 - maxx << '\n';
    }
    return 0;
}