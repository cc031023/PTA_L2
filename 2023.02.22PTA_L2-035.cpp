#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3;
int post[N], ans[N];
int n, temp, x;
void build(int dex)
{
    if (dex > n)
    {
        return;
    }
    build(2 * dex);
    build(2 * dex + 1);
    ans[dex] = post[++x];
    return;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> post[i];
    }
    build(1);
    for (int i = 1; i <= n; ++i)
    {
        cout << ans[i] << " \n"[i == n];
    }
    return 0;
}