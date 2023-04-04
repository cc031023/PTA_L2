#include <bits/stdc++.h>
using namespace std;
struct cc
{
    int x, y;
    double maxx;
    bool operator<(const cc &b) const
    {
        return this->maxx > b.maxx;
    }
} a[1003];
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].x;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].y;
    }
    for (int i = 0; i < n; ++i)
    {
        a[i].maxx = (double)a[i].y / a[i].x;
    }
    sort(a, a + n);
    int p = 0;
    double ans = 0;
    while (p < n && d > 0)
    {
        if (d - a[p].x < 0) // x多少个
        {
            ans += a[p].maxx * d;
            break;
        }
        else
        {
            d -= a[p].x;
            ans += a[p].y;
        }
        ++p;
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}