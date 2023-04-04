#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 7;
vector<int> v[N];
int a[N];
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, k; // 总的数量,小盒子能放的数量,一个松枝最多能放多少个.
    cin >> n >> m >> k;
    stack<int> s; // 模拟小盒子.
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    int head = 1, p = 0;
    while (head <= n)
    {
        if (v[p].size() == k || (v[p].size() && s.size() == m && s.top() > v[p].back() && a[head] > v[p].back()))
        {
            ++p;
        }
        if (!s.empty()) // 当小盒子有东西优先.
        {
            if (!v[p].size())
            {
                v[p].push_back(s.top());
                s.pop();
            }
            else
            {
                if (v[p].back() >= s.top())
                {
                    v[p].push_back(s.top());
                    s.pop();
                }
                else
                {
                    if (v[p].back() >= a[head])
                    {
                        v[p].push_back(a[head++]);
                    }
                    else
                    {
                        s.push(a[head++]);
                    }
                }
            }
        }
        else // 拿推送器的.
        {
            if (!v[p].size())
            {
                v[p].push_back(a[head++]);
            }
            else
            {
                if (v[p].back() >= a[head])
                {
                    v[p].push_back(a[head++]);
                }
                else
                {
                    if (s.size() + 1 <= m)
                    {
                        s.push(a[head++]);
                    }
                    else
                    {
                        ++p;
                    }
                }
            }
        }
    }
    // 拿完推送器之后.
    while (!s.empty())
    {
        if (v[p].size() == k)
        {
            ++p;
        }
        else
        {
            if (!v[p].size())
            {
                v[p].push_back(s.top());
                s.pop();
            }
            else
            {
                if (v[p].back() >= s.top())
                {
                    v[p].push_back(s.top());
                    s.pop();
                }
                else
                {
                    ++p;
                }
            }
        }
    }
    for (int i = 0; i <= p; ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            cout << v[i][j] << " \n"[j == v[i].size() - 1];
        }
    }
    return 0;
}