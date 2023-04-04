#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 7;
struct node
{
    string id;
    int sum;
    int dif;
    bool operator<(const node &b) const
    {
        if (this->dif == b.dif)
        {
            return this->sum < b.sum;
        }
        return this->dif > b.dif;
    }
} p[N];
bool pd[10000099];
bool cmp(node a, node b)
{

    if (a.dif == b.dif)
    {
        return a.sum < b.sum;
    }
    return a.dif > b.dif;
};
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i].id >> p[i].sum;
        for (int j = 0; j < p[i].sum; ++j)
        {
            int x;
            cin >> x;
            if (!pd[x])
            {
                ++p[i].dif;
            }
            pd[x] = true;
        }
        memset(pd, 0, sizeof(pd));
    }
    sort(p + 1, p + n + 1);
    if (n < 3)
    {
        for (int i = 1; i <= n; ++i)
        {
            cout << p[i].id << " ";
        }
        for (int i = 1; i <= 3 - n; ++i)
        {
            cout << '-';
            if (i != 3 - n)
            {
                cout << " ";
            }
        }
    }
    else
    {
        for (int i = 1; i <= 3; ++i)
        {
            cout << p[i].id << " \n"[i == 3];
        }
    }
    return 0;
}