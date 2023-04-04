#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 3;
vector<int> v[N], ans, now;
bool pd[N];
void solve(int x)
{
    if (!v[x].size())
    {
        if (ans.size() < now.size())
        {
            ans = now;
        }
        else if (ans.size() == now.size() && ans > now)
        {
            ans = now;
        }
        return;
    }
    for (int i = 0; i < v[x].size(); ++i)
    {
        now.push_back(v[x][i]);
        solve(v[x][i]);
        now.pop_back();
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
            pd[x] = true;
        }
    }
    int head;
    for (int i = 0; i < n; ++i)
    {
        if (!pd[i])
        {
            head = i;
            now.push_back(head);
            break;
        }
    }
    solve(head);
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
    return 0;
}