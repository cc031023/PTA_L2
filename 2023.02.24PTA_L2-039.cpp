#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3;
struct node
{
    int val;
    vector<int> v;
};
struct cc
{
    int num;
    vector<int> v;
};
map<string, node> mp;
set<string> st;
int a[N];
vector<cc> ans;
string change(int x)
{
    string s = "";
    string f = "";
    if (x < 0)
    {
        f = "-";
        x = -x;
    }
    if (x > 99) // 为了防止数字并在一起的神奇特判法,如1 22和12 2的string是一样的
    {
        f += "tt";
    }
    else if (x > 9)
    {
        f += "t";
    }
    while (x > 9)
    {
        int last = x % 10;
        s += char(last + '0');
        x /= 10;
    }
    s += char(x + '0');
    s += f;
    reverse(s.begin(), s.end());
    return s;
}
bool cmp(const cc &a, const cc &b)
{
    return a.num == b.num ? a.v < b.v : a.num > b.num;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        string s = "";
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[j];
            string mid = change(a[j]);
            s += mid;
        }
        st.insert(s);
        ++mp[s].val;
        for (int j = 1; j <= m; ++j)
        {
            mp[s].v.push_back(a[j]);
        }
    }
    cout << st.size() << '\n';
    map<string, node>::iterator it;
    // int p = 0;
    for (it = mp.begin(); it != mp.end(); it++)
    {
        ans.push_back({it->second.val, it->second.v});
        // for (int j = 0; j < m; ++j)
        // {
        //     ans[p].v.push_back(it->second.v[j]);
        // }
        // ++p;
        //  ans[p++].v.assign(it->second.v.begin(), it->second.v.end());
    }
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i].num << " ";
        for (int j = 0; j < m; ++j)
        {
            cout << ans[i].v[j] << " \n"[j == m - 1];
        }
    }
    return 0;
}