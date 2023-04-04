#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3;
struct cc
{
    set<int> s;
} p[53];
inline int read()
{
    char ch = getchar();
    int x = 0, f = 1;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            f = -1;
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
int main()
{
    int n;
    n = read();
    for (int i = 1; i <= n; ++i)
    {
        int x;
        x = read();
        for (int j = 1; j <= x; ++j)
        {
            int y;
            y = read();
            p[i].s.insert(y);
        }
    }
    int t;
    t = read();
    while (t--)
    {
        int same = 0, s1, s2;
        s1 = read();
        s2 = read();
        set<int>::iterator it = p[s1].s.begin();
        for (it; it != p[s1].s.end(); it++)
        {
            if (p[s2].s.find(*it) != p[s2].s.end())
            {
                ++same;
            }
        }
        int dif = p[s1].s.size() + p[s2].s.size();
        double ans = (double)same / (dif - same) * 100;
        printf("%.2lf%\n", ans);
    }
    return 0;
}