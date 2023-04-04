#include <bits/stdc++.h>
using namespace std;
const int N = 3e2 + 1;
struct node
{
    int next, dis;
};
vector<node> v[N], ans;
int pd[N], a[N];
bool check(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        if (pd[i] == -1)
        {
            return false;
        }
    }
    return true;
}
int find(int a, int b)
{
    for (int i = 0; i < v[a].size(); ++i)
    {
        if (v[a][i].next == b)
        {
            pd[b] = -pd[b];
            return v[a][i].dis;
        }
    }
    return -1;
}
bool cmp(const node &a, const node &b)
{
    return a.dis == b.dis ? a.next < b.next : a.dis < b.dis;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m; // n个网红点,m条路.
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x, y, dis;
        cin >> x >> y >> dis;
        v[x].push_back(node{y, dis});
        v[y].push_back(node{x, dis});
    }
    int k, sum = 0;
    cin >> k;
    for (int i = 1; i <= k; ++i)
    {
        memset(pd, -1, sizeof(pd));
        memset(a, 0, sizeof(a));
        int num, val = 0;
        cin >> num;
        for (int j = 1; j <= num; ++j)
        {
            cin >> a[j];
        }
        for (int j = 0; j <= num; ++j) // 家是0,太妙了.
        {
            int now = find(a[j], a[j + 1]);
            if (now == -1)
            {
                val = 0;
                break;
            }
            val += now;
        }
        if (check(n) && val)
        {
            ans.push_back(node{i, val});
            // cout << i << '\n';
            ++sum;
        }
    }
    cout << sum << '\n';
    sort(ans.begin(), ans.end(), cmp);
    cout << ans[0].next << " " << ans[0].dis << '\n';
    return 0;
}