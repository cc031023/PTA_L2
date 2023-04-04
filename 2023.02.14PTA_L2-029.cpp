#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;
bool isyifu[N];
bool isunhappy[N];
bool ishappy[N];
int tran(int x)
{
    int res = 0;
    while (x)
    {
        res = res + (x % 10) * (x % 10);
        x /= 10;
    }
    return res;
}
void check(int x, int l, int r)
{
    set<int> S;
    S.insert(x);
    int m = tran(x);
    if (m == 1)
    {
        ishappy[x] = true;
        return;
    }
    isyifu[m] = true;
    bool ok = false;
    while (true)
    {
        m = tran(m);
        if (m == 1)
        { // 变成1那么就是幸福的
            ishappy[x] = true;
            return;
        }
        if (m >= l && m <= r)
            isyifu[m] = true;
        if (S.count(m))
        {
            ok = true;
            break;
        }
        S.insert(m);
    }
    if (ok)
    {
        isunhappy[x] = true; // 如果
    }
    return;
}

bool isprime(int x)
{
    if (x == 0 || x == 1)
        return false;
    for (int i = 2; i <= x / i; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
// 1是一个幸福数字

int work(int x, int l, int r)
{
    int res = 0, temp = x;
    while (x != 1)
    {
        res += 1;
        x = tran(x);
    }
    return res * (isprime(temp) ? 2 : 1);
}

int main()
{
    int l, r;
    cin >> l >> r;
    for (int x = l; x <= r; x++)
    {
        check(x, l, r);
    }
    bool isSad = true;
    for (int x = l; x <= r; x++)
    {
        if (ishappy[x] && !isyifu[x])
        {
            isSad = false;
            cout << x << ' ' << work(x, l, r) << '\n';
        }
    }
    if (isSad)
    {
        cout << "SAD\n";
    }
    return 0;
}
