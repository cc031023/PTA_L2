#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 3;
int fa[N], pd[N];
void pre(int x)
{
    for (int i = 1; i <= x; ++i)
    {
        fa[i] = i;
    }
    return;
}
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void add(int x, int y)
{
    int a = find(x), b = find(y);
    if (a != b)
    {
        fa[a] = b;
    }
    return;
}
int all(int x)
{
    int ans = 0;
    for (int i = 1; i <= x; ++i)
    {
        if (fa[i] == i)
        {
            ++ans;
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    pre(N);
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        int k;
        cin >> k;
        int first;
        cin >> first;
        if (!pd[first])
        {
            ++sum;
            pd[first] = true;
        }
        for (int j = 2; j <= k; ++j)
        {
            int x;
            cin >> x;
            if (!pd[x])
            {
                ++sum;
                pd[x] = true;
            }
            add(first, x);
        }
    }
    cout << sum << " " << all(sum) << endl;
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b))
        {
            cout << "Y" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
    }
    return 0;
}