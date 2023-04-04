#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
struct node
{
    int next;
    int data;
    int self;
} p[N];
vector<node> ans;
void pre()
{
    for (int i = 0; i < N; ++i)
    {
        p[i].self = i;
    }
    return;
}
int main()
{
    int head, n;
    pre();
    scanf("%d%d", &head, &n);
    int copy = head;
    for (int i = 1; i <= n; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (z == -1)
        {
            z = 100000;
        }
        p[x].data = y;
        p[x].next = z;
    }
    int count = 0;
    for (int i = 1; i <= n; ++i)
    {
        int nowd = p[head].data;
        int nown = p[head].next;
        if (nown == 100000)
        {
            nown = -1;
        }
        ans.push_back(node{nown, nowd, head});
        ++count;
        if (nown == -1)
        {
            break;
        }
        head = p[head].next;
    }

    int l = 0, r = count - 1;
    int pd = 0;
    while (l <= r)
    {
        if (pd + 1 == ans.size())
        {
            printf("%05d %d %d\n", ans[r].self, ans[r].data, -1);
            break;
        }
        printf("%05d %d %05d\n", ans[r].self, ans[r].data, ans[l].self);
        ++pd;
        if (pd == ans.size())
        {
            break;
        }
        if (r - 1 >= l + 1)
        {
            printf("%05d %d %05d\n", ans[l].self, ans[l].data, ans[r - 1].self);
        }
        else
        {
            printf("%05d %d %d\n", ans[l].self, ans[l].data, -1);
        }
        --r, ++l, ++pd;
    }

    return 0;
}