#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
map<string, bool> m;
vector<string> ans;
struct cc
{
    string id;
    int val;
} p[N];
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        m[s] = true;
    }
    cin >> n;
    double sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i].id >> p[i].val;
        sum += p[i].val;
    }
    sum /= n;
    for (int i = 1; i <= n; ++i)
    {
        if (p[i].val > sum && !m[p[i].id])
        {
            ans.push_back(p[i].id);
        }
    }
    sort(ans.begin(), ans.end());
    if (ans.empty())
    {
        cout << "Bing Mei You\n";
    }
    else
    {
        for (int i = 0; i < ans.size(); ++i)
        {
            cout << ans[i] << '\n';
        }
    }
    return 0;
}