#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
vector<int> v[N];
int dis[101];
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    int now = 1;
    while (m--)
    {
        int t, j;
        cin >> t >> j;
        switch (t)
        {
        case 0:
            now = v[now][j - 1];
            break;
        case 1:
            dis[j] = now;
            cout << now << '\n';
            break;
        default:
            now = dis[j];
        }
    }
    cout << now << '\n';
    return 0;
}