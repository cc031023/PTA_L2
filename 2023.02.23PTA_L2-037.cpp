#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3;
struct node
{
    queue<char> v;
} p[N];
vector<char> ans;
stack<char> ss;
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j)
        {
            p[i].v.push(s[j]);
        }
    }
    int x;
    while (cin >> x && x != -1)
    {
        if (!x) // 从ss拿出来
        {
            if (!ss.empty())
            {
                ans.push_back(ss.top());
                ss.pop();
            }
        }
        else
        {
            if (p[x].v.size())
            {
                if (ss.size() >= s)
                {
                    ans.push_back(ss.top());
                    ss.pop();
                    ss.push(p[x].v.front());
                    p[x].v.pop();
                }
                else
                {
                    ss.push(p[x].v.front());
                    p[x].v.pop();
                }
            }
        }
    }
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}