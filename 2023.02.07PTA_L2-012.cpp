#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 10005;
int a[N];
int n, m;
void build(int u) // 实现小顶堆操作
{
    while (u / 2 > 0 && a[u / 2] > a[u])

    {
        swap(a[u / 2], a[u]);
        u /= 2;
    }
}
map<int, int> ma; // 点权对应编号
signed main()
{

    cin >> n >> m; // n个点，m个询问
    for (int i = 1; i <= n; i++)

    {
        cin >> a[i];
        build(i); // 对每个点进行操作
    }
    for (int i = 1; i <= n; i++)
    {
        ma[a[i]] = i; // 点权对应编号
    }
    int x, y;
    string s;
    while (m--)
    {
        cin >> x >> s;
        if (s[0] == 'a') // 问两个点是否是兄弟节点

        {
            cin >> y >> s >> s;
            x = ma[x];
            y = ma[y];
            if (x / 2 == y / 2)
                cout << "T" << endl;
            else
                cout << "F" << endl;
        }
        else
        {
            cin >> s >> s;
            if (s[0] == 'r') // 问该点是否是根节点

            {
                if (x == a[1])
                    cout << "T" << endl;
                else
                    cout << "F" << endl;
            }
            else if (s[0] == 'p') // 问x是不是y的父节点

            {
                cin >> s >> y;
                x = ma[x];
                y = ma[y];
                if (y / 2 == x)
                    cout << "T" << endl;
                else
                    cout << "F" << endl;
            }
            else if (s[0] == 'c') // 问y是不是x的父节点

            {
                cin >> s >> y;
                x = ma[x];
                y = ma[y];
                if (x / 2 == y)
                    cout << "T" << endl;
                else
                    cout << "F" << endl;
            }
        }
    }
    return 0;
}