#include <bits/stdc++.h>
const int N = 1e4 + 3;
struct node
{
    double val;
    int num;
    int id;
    bool operator<(const node &b) const
    {
        if (this->val != b.val)
        {
            return this->val > b.val;
        }
        if (this->num != b.num)
        {
            return this->num > b.num;
        }
        return this->id < b.id;
    }
} p[N];
inline int read()
{
    int x = 0, f = 1;
    char a = getchar();
    while (a < '0' || a > '9')
    {
        if (a == '-')
        {
            f = -f;
        }
        a = getchar();
    }
    while (a >= '0' && a <= '9')
    {
        x = (x << 3) + (x << 1) + (a ^ 48);
        a = getchar();
    }
    return x * f;
}

int main()
{
    int n;
    n = read();
    for (int i = 1; i <= n; ++i)
    {
        int k;
        k = read();
        for (int i = 1; i <= n; ++i)
        {
            p[i].id = i;
        }
        for (int j = 1; j <= k; ++j)
        {
            int x, y;
            x = read(), y = read();
            ++p[x].num, p[x].val += y;
            p[i].val -= y;
        }
    }
    std::sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; ++i)
    {

        printf("%d %.2lf\n", p[i].id, p[i].val / 100);
    }
    return 0;
}