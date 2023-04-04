#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
struct node
{
    vector<int> son;
    int val;
    int id;
} p[N];
void pre(int x)
{
    for (int i = 1; i <= x; ++i)
    {
        p[i].id = i;
    }
    return;
}
void dfs(int x)
{
    for (int i = 0; i < p[x].son.size(); ++i)
    {
        int next = p[x].son[i];
        p[next].val = p[x].val + 1;
        dfs(next);
    }
    return;
}
bool cmp(node a, node b)
{
    if (a.val == b.val)
    {
        return a.id < b.id;
    }
    return a.val > b.val;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    pre(n);
    int boss;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        if (x == -1)
        {
            p[i].val = 1;
            boss = i;
            continue;
        }
        p[x].son.push_back(i);
    }
    dfs(boss);
    sort(p + 1, p + n + 1, cmp);
    int maxx = p[1].val;
    cout << maxx << endl;
    int i = 1, j = 0;
    while (p[i].val == maxx)
    {
        ++j, ++i;
    }
    for (int a = 1; a <= j; ++a)
    {
        cout << p[a].id << " \n"[a == j];
    }
    return 0;
}