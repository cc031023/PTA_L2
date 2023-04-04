#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
struct cc
{
    string id;
    int val;
} p[N];
bool cmp(const cc &a, const cc &b)
{
    if (a.val != b.val)
    {
        return a.val > b.val;
    }
    return a.id < b.id;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, g, k;
    cin >> n >> g >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i].id >> p[i].val;
    }
    sort(p + 1, p + n + 1, cmp);
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (p[i].val >= g)
        {
            sum += 50;
        }
        else if (p[i].val >= 60)
        {
            sum += 20;
        }
        else
        {
            break;
        }
    }
    cout << sum << endl;
    int x = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (p[i].val != p[i - 1].val)
        {
            if (i > k)
            {
                return 0;
            }
            cout << i << " " << p[i].id << " " << p[i].val << endl;
            x = 1;
        }
        else
        {
            cout << i - x << " " << p[i].id << " " << p[i].val << endl;
            ++x;
        }
    }
    return 0;
}