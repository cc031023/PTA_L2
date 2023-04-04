#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, k;
    stack<int> s;
    cin >> n >> m >> k;
    while (k--)
    {
        while (!s.empty())
        {
            s.pop();
        }
        int now = 1, pd = 1;
        for (int i = 1; i <= n; ++i)
        {
            int x;
            cin >> x;
            if (x == now)
            {
                ++now;
                while (!s.empty() && s.top() == now)
                {
                    s.pop();
                    ++now;
                }
            }
            else
            {
                s.push(x);
                if (s.size() > m)
                {
                    pd = 0;
                }
            }
        }
        if (s.empty() && pd)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
