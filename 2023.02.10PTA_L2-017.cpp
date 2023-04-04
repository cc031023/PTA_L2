#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
int a[N];
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if (n & 1)
    {
        int x = 0, y = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (i <= n / 2)
            {
                x += a[i];
            }
            else if (i != n / 2 + 1)
            {
                y += a[i];
            }
        }
        cout << "Outgoing #: " << n / 2 + 1 << endl;
        cout << "Introverted #: " << n / 2 << endl;
        cout << "Diff = " << abs(y + a[n / 2 + 1] - x) << endl;
    }
    else
    {
        int x = 0, y = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (i <= n / 2)
            {
                x += a[i];
            }
            else
            {
                y += a[i];
            }
        }
        cout << "Outgoing #: " << n / 2 << endl;
        cout << "Introverted #: " << n / 2 << endl;
        cout << "Diff = " << abs(x - y) << endl;
    }
    return 0;
}