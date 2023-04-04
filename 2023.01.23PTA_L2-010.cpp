#include <bits/stdc++.h>
const int N = 1e2 + 3;
int fa[N], v[N][N];
int find(int x)
{
    if (x != fa[x])
    {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
void pre(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
    }
    return;
}
void unionn(int x, int y)
{
    int a = find(x);
    int b = find(y);
    if (a != b)
    {
        fa[find(a)] = find(b);
    }
    return;
}
int main()
{
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int n, m, k;
    std::cin >> n >> m >> k;
    pre(n);
    for (int i = 1; i <= m; ++i)
    {
        int x, y, z;
        std::cin >> x >> y >> z;
        if (z == 1)
        {
            unionn(x, y);
        }
        else
        {
            v[x][y] = 1;
            v[y][x] = 1;
        }
    }
    for (int i = 1; i <= k; ++i)
    {
        int x, y;
        std::cin >> x >> y;
        if (find(x) == find(y))
        {
            if (v[x][y] != 1)
            {
                std::cout << "No problem" << '\n';
            }
            else
            {
                std::cout << "OK but..." << '\n';
            }
        }
        else
        {
            if (v[x][y] != 1)
            {
                std::cout << "OK" << '\n';
            }
            else
            {
                std::cout << "No way" << '\n';
            }
        }
    }
    return 0;
}