#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
struct node
{
    string s1, s2;
} p[N];
bool cmp(const node &a, const node &b)
{
    return a.s1 < b.s1;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string x;
        cin >> p[i].s1 >> x >> p[i].s2;
    }
    sort(p, p + n, cmp);
    if (p[0].s1 != "00:00:00")
    {
        cout << "00:00:00 - " << p[0].s1 << '\n';
    }
    for (int i = 0; i < n - 1; ++i)
    {
        if (p[i].s2 != p[i + 1].s1)
        {
            cout << p[i].s2 << " - " << p[i + 1].s1 << '\n';
        }
    }
    if (p[n - 1].s2 != "23:59:59")
    {
        cout << p[n - 1].s2 << " - "
             << "23:59:59\n";
    }
    return 0;
}