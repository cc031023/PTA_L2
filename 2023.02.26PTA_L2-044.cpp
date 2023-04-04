#include <bits/stdc++.h>
std::vector<int> m, f;
const int N = 5e2 + 3;
char ch[10];
int dis[N][N];
void floyed(int n)
{
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dis[i][j] = std::min(dis[i][k] + dis[k][j], dis[i][j]);
            }
        }
    }
    return;
}
void pre(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        dis[i][i] = 0;
    }
    return;
}
int main()
{
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    int n;
    scanf("%d", &n);
    pre(n);
    for (int i = 1; i <= n; ++i)
    {
        int t;
        scanf("%s%d", ch, &t);
        if (ch[0] == 'M')
        {
            m.push_back(i);
        }
        else
        {
            f.push_back(i);
        }
        for (int j = 1; j <= t; ++j)
        {
            int x, y;
            scanf("%d:%d", &x, &y);
            dis[i][x] = std::min(dis[i][x], y);
        }
    }
    floyed(n);
    std::vector<int> ans;
    std::vector<std::pair<double, int>> v1, v2;
    for (int i = 0; i < f.size(); ++i)
    {
        int d = 0;
        for (int j = 0; j < m.size(); ++j)
        {
            d = std::max(d, dis[m[j]][f[i]]);
        }
        v1.push_back(std::make_pair(1.0 / d, f[i]));
    }
    std::sort(v1.begin(), v1.end(), std::greater<std::pair<double, int>>());
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i].first != v1[0].first)
        {
            break;
        }
        ans.push_back(v1[i].second);
    }
    std::sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i)
    {
        printf("%d", ans[i]);
        if (i != ans.size() - 1)
        {
            putchar(' ');
        }
        else
        {
            putchar('\n');
        }
    }
    ans.clear();
    for (int i = 0; i < m.size(); ++i)
    {
        int d = 0;
        for (int j = 0; j < f.size(); ++j)
        {
            d = std::max(d, dis[f[j]][m[i]]);
        }
        v2.push_back(std::make_pair(1.0 / d, m[i]));
    }
    std::sort(v2.begin(), v2.end(), std::greater<std::pair<double, int>>());
    for (int i = 0; i < v2.size(); i++)
    {
        if (v2[i].first != v2[0].first)
        {
            break;
        }
        ans.push_back(v2[i].second);
    }
    std::sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i)
    {
        printf("%d", ans[i]);
        if (i != ans.size() - 1)
        {
            putchar(' ');
        }
        else
        {
            putchar('\n');
        }
    }
    return 0;
}