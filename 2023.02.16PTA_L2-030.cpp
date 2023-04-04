#include <bits/stdc++.h>
using namespace std;
map<string, pair<int, string>> cc;
string solve(string a, string b)
{
    int sum1 = 0, sum2 = 0;
    while (a != "")
    {
        sum2 = 0;
        string next = b;
        while (next != "")
        {
            if (next == a && (sum1 < 4 || sum2 < 4))
            {
                return "No\n";
            }
            if (sum1 >= 4 && sum2 >= 4)
            {
                return "Yes\n";
            }
            ++sum2;
            next = cc[next].second;
        }
        a = cc[a].second;
        ++sum1;
    }
    return "Yes\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    string f, c;
    while (n--)
    {
        cin >> f >> c;
        if (c.back() == 'n')
        {
            cc[f] = make_pair(1, c.substr(0, c.length() - 4));
        }
        else if (c.back() == 'r')
        {
            cc[f] = make_pair(0, c.substr(0, c.length() - 7));
        }
        else if (c.back() == 'm')
        {
            cc[f].first = 1;
        }
        else
        {
            cc[f].first = 0;
        }
    }
    cin >> n;
    string trash;
    while (n--)
    {
        cin >> f >> trash >> c >> trash;
        if (!cc.count(f) || !cc.count(c))
        {
            cout << "NA\n";
        }
        else if (cc[f].first == cc[c].first)
        {
            cout << "Whatever\n";
        }
        else
        {
            cout << solve(f, c);
        }
    }
    return 0;
}
