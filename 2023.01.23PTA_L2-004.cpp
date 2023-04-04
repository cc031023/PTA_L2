#include <bits/stdc++.h>
const int N = 1e5 + 3;
int a[N], n;
std::vector<int> v;
void dfs1(int root, int tail)
{
    if (root > tail)
    {
        return;
    }
    int l = root + 1, r = tail;
    while (a[l] < a[root] && l <= tail)
    {
        ++l;
    }
    while (a[r] >= a[root] && r > root)
    {
        --r;
    }
    if (l - r != 1)
    {
        return;
    }
    dfs1(root + 1, r);
    dfs1(l, tail);
    v.push_back(a[root]);
    return;
}
void dfs2(int root, int tail)
{
    if (root > tail)
    {
        return;
    }
    int l = root + 1, r = tail;
    while (a[l] >= a[root] && l <= tail)
    {
        ++l;
    }
    while (a[r] < a[root] && r > root)
    {
        --r;
    }
    if (l - r != 1)
    {
        return;
    }
    dfs2(root + 1, r);
    dfs2(l, tail);
    v.push_back(a[root]);
    return;
}
int main()
{
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }
    dfs1(0, n - 1);
    if (v.size() != n)
    {
        v.clear();
        dfs2(0, n - 1);
    }
    if (v.size() == n)
    {
        std::cout << "YES" << '\n';
        for (int i = 0; i < n; ++i)
        {
            std::cout << v[i] << " \n"[i == n - 1];
        }
    }
    else
    {
        std::cout << "NO" << '\n';
    }
    return 0;
}
