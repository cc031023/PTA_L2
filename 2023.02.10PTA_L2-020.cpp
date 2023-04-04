#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
double ans, z, r;
int n;
vector<int> v[N];
bool pd[N];
void solve(int dep, double val)
{
    if (pd[dep] == true)
    {
        ans += val * v[dep][0];
        return;
    }
    for (int i = 0; i < v[dep].size(); ++i)
    {
        solve(v[dep][i], val * r);
    }
    return;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> z >> r;
    r = (100 - r) / 100;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (!x) // 得道者
        {
            int y;
            cin >> y;
            v[i].push_back(y); // 得道者就存放大倍数
            pd[i] = true;      // 标记得道者
        }
        else
        {
            for (int j = 0; j < x; ++j)
            {
                int y;
                cin >> y;
                v[i].push_back(y); // 普通人就存徒弟
            }
        }
    }
    solve(0, z);
    cout << (int)ans << '\n';
    return 0;
}
