#include <bits/stdc++.h>
const int N = 1e5 + 3;
int n, post[N], in[N];
std::vector<int> tree(N, -1);
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            f = -f;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
void build(int root, int st, int ed, int dep)
{
    if (st > ed)
    {
        return;
    }
    int i = st;
    while (i < ed && in[i] != post[root])
    {
        ++i;
    }
    tree[dep] = post[root];
    build(root - ed + i - 1, st, i - 1, dep * 2); // 左
    build(root - 1, i + 1, ed, dep * 2 + 1);      // 右
}
int main()
{
    n = read();
    for (int i = 1; i <= n; ++i)
    {
        post[i] = read();
    }
    for (int i = 1; i <= n; ++i)
    {
        in[i] = read();
    }
    build(n, 1, n, 1);
    std::vector<int> ans;
    for (int i = 1, l = tree.size(); i < l; ++i)
        if (tree[i] != -1)
        {
            ans.push_back(tree[i]);
        }

    for (int i = 0, l = ans.size(); i < l; ++i)
    {
        std::cout << ans[i] << " \n"[i == l - 1];
    }
    return 0;
}