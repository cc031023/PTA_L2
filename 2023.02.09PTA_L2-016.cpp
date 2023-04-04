#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
struct cc
{
    char sex;
    int fa;
    int ma;
} p[N];
bool flag, pd[N];
void dfs(int x, int count)
{
    if (x == -1 || !count || flag)
    {
        return;
    }
    pd[x] = true;
    int ans1 = p[x].fa, ans2 = p[x].ma;
    if (ans1 != -1 && pd[ans1])
    {
        flag = true;
        return;
    }
    else
    {
        dfs(ans1, count - 1);
    }
    if (ans2 != -1 && pd[ans2])
    {
        flag = true;
        return;
    }
    else
    {
        dfs(ans2, count - 1);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    memset(p, -1, sizeof(p));
    while (n--)
    {
        int id;
        cin >> id >> p[id].sex >> p[id].fa >> p[id].ma;
        p[p[id].fa].sex = 'M', p[p[id].ma].sex = 'F';
    }
    int k;
    cin >> k;
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        if (p[a].sex == p[b].sex)
        {
            cout << "Never Mind\n";
            continue;
        }
        flag = false;
        dfs(a, 5);
        dfs(b, 5);
        if (flag)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }
        memset(pd, false, sizeof(pd));
    }
    return 0;
}