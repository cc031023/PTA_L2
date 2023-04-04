#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
struct cc
{
    string name, id, time;
    int val;
};
struct ans
{
    string name, id;
};
vector<ans> v;
vector<cc> now;
map<string, int> pd, mp;
bool check(string s)
{
    if (s.size() != 18)
    {
        return false;
    }
    for (int i = 0; i < s.size(); ++i)
    {
        if (!isdigit(s[i])) // 判断是否是数字
        {
            return false;
        }
    }
    return true;
}
bool cmp(const cc &a, const cc &b)
{
    return a.time == b.time ? a.val < b.val : a.time < b.time;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int d, p;
    cin >> d >> p;
    for (int i = 1; i <= d; ++i)
    {
        int t, s;
        now.clear();
        cin >> t >> s; // t个人,s个名额
        for (int j = 1; j <= t; ++j)
        {
            string name, id, body, time;
            cin >> name >> id >> body >> time;
            if (check(id))
            {
                if (body == "1" && !pd[id])
                {
                    v.push_back(ans{name, id});
                    pd[id] = 1;
                }
                now.push_back(cc{name, id, time, j});
            }
        }
        sort(now.begin(), now.end(), cmp);
        for (int j = 0; j < now.size(); ++j)
        {
            if (s <= 0)
            {
                break;
            }
            if (mp[now[j].id] <= i)
            {
                --s;
                mp[now[j].id] = i + p + 1;
                cout << now[j].name << " " << now[j].id << '\n';
            }
        }
    }
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i].name << " " << v[i].id << '\n';
    }
    return 0;
}