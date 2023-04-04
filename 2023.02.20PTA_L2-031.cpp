#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
int pd = -1, anss;
int f[N];
struct node
{
    int id;
    int dep;
    // bool operator<(const node &b) const
    // {
    //     return this->dep > b.dep;
    // }
};
// vector<node> ans;
vector<int> v[N];
void dfs(int idd, int depp)
{
    if (pd < depp)
    {
        pd = depp;
        anss = idd;
    }
    // ans.push_back(node{idd, depp});
    for (int i = 0; i < v[idd].size(); ++i)
    {
        dfs(v[idd][i], depp + 1);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int x;
            cin >> x;
            f[x] = 1;
            v[i].push_back(x);
        }
    }
    int h;
    for (int i = 1; i <= n; ++i)
    {
        if (!f[i])
        {
            h = i;
            dfs(h, 0);
            cout << anss << '\n';
            return 0;
        }
    }
    // << anss << '\n';
    // sort(ans.begin(), ans.end());
    // cout << ans[0].id << endl;
    // return 0;
}