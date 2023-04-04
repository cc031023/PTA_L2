#include <iostream>
const int N = 5e3 + 3;
int fa[N];
bool pd[N];
struct node
{
    int a, b;
} p[N];
void pre(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
    }
    return;
}
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void unnion(int x, int y)
{
    if (find(x) != find(y))
    {
        fa[find(x)] = find(y);
    }
    return;
}
int main()
{
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    int num = 0;
    pre(n);
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        std::cin >> x >> y;
        ++x, ++y;
        p[i].a = x;
        p[i].b = y;
        unnion(x, y);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (fa[i] == i)
        {
            ++num;
        }
    }
    int t;
    std::cin >> t;
    for (int k = 0; k < t; ++k)
    {
        pre(n);
        int x;
        std::cin >> x;
        ++x;
        pd[x] = true;
        for (int i = 1; i <= m; ++i)
        {
            if (pd[p[i].a] || pd[p[i].b])
            {
                continue;
            }
            unnion(p[i].a, p[i].b);
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (fa[i] == i)
            {
                ++ans;
            }
        }
        if (ans == num + 1 || ans == num)
        {
            std::cout << "City " << x - 1 << " is lost.\n";
        }
        else
        {
            std::cout << "Red Alert: City " << x - 1 << " is lost!\n";
        }
        num = ans;
    }
    if (t >= n)
    {
        std::cout << "Game Over.\n";
    }
    return 0;
}