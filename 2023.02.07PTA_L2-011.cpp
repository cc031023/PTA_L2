#include <iostream>
int in[53], pre[53];
int ans[9997];
void build(int root, int l, int r, int dep)
{
    if (l > r)
    {
        return;
    }
    ans[dep] = pre[root];
    int i = l;
    while (i <= r && in[i] != pre[root])
    {
        ++i;
    }
    build(root + 1, l, i - 1, dep * 2 + 1);
    build(root + (i - l) + 1, i + 1, r, dep * 2);
    return;
}
int main()
{
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> in[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> pre[i];
    }
    build(1, 1, n, 1);
    int x = 1, i = 1;
    while (x <= n)
    {
        if (ans[i])
        {
            std::cout << ans[i] << " \n"[x == n];
            ++x;
        }
        ++i;
    }
    return 0;
}
