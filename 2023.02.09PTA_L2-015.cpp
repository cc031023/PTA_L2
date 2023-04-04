#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;
vector<double> ans;
double a[13];
bool cmp(const double &a, const double &b)
{
    return a > b;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            cin >> a[j];
        }
        sort(a + 1, a + k + 1);
        double cc = 0;
        for (int j = 2; j <= k - 1; ++j)
        {
            cc += a[j];
        }
        cc /= k - 2;
        ans.push_back(cc);
    }
    sort(ans.begin(), ans.end(), cmp);
    for (int i = m - 1; i >= 0; --i)
    {
        cout << fixed << setprecision(3) << ans[i] << " \n"[!i];
    }
    return 0;
}