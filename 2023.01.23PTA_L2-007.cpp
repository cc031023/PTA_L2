#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 3;
int n;
int p[N];           // 父节点
bool st[N], st2[N]; // st记录每个成员是否存在, st2在最后记录人数时记录家庭编号
struct Note
{
    int id, num;      // id为编号, num为成员数量
    double sum, area; // sun为房产套数, area为房产面积
} a[N];

bool cmp(Note a, Note b)
{
    // 按题目要求排序
    if (a.area != b.area)
        return a.area > b.area;
    return a.id < b.id;
}
int find(int x) // 并查集模板1, 寻找父节点
{
    if (x != p[x])
    {
        p[x] = find(p[x]);
    }
    return p[x];
}

void make(int a, int b) // 并查集模板2, 合并集合
{
    int x = find(a);
    int y = find(b);
    if (x != y)
    {
        // 以最小编号为家庭编号
        if (x > y)
        {
            p[x] = y;
        }
        else
            p[y] = x;
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < N; i++)
    {
        p[i] = i;
    }                          // 并查集初始化
    memset(st, 0, sizeof(st)); // 状态初始化
    memset(st2, 0, sizeof(st2));
    for (int i = 0; i < n; i++)
    {
        int p1, p2; // 父母
        cin >> a[i].id >> p1 >> p2;
        st[a[i].id] = 1;
        if (p1 != -1) // 若父母存在则存入家庭集合
        {
            make(a[i].id, p1);
            st[p1] = 1; // 更新状态
        }
        if (p2 != -1)
        {
            make(a[i].id, p2);
            st[p2] = 1;
        }
        int k;
        cin >> k;
        while (k--)
        {
            int son;
            cin >> son;
            if (son != -1)
            {
                // 若孩子存在则存入家庭集合
                make(son, a[i].id);
                st[son] = 1;
            }
        }
        cin >> a[i].sum >> a[i].area;
    }
    Note r[N]; // 统计合并家庭信息
    for (int i = 0; i < n; i++)
    {
        int id = find(a[i].id);
        r[id].id = id;
        r[id].sum += a[i].sum;
        r[id].area += a[i].area;
    }

    for (int i = 0; i < N; i++) // 计算家庭成员数
    {
        if (st[i])
        {
            r[find(i)].num++;
        }
    }

    Note ans[N];
    int cnt = 0; // 家庭数量

    // 更新答案
    for (int i = 0; i < N; i++)
    {
        if (st[i])
        {
            int id = find(i);
            if (!st2[id])
            {

                st2[id] = 1;
                int x = r[id].num;
                ans[cnt].id = id;
                ans[cnt].num = x;
                ans[cnt].sum = r[id].sum * 1.0 / (1.0 * x);
                ans[cnt++].area = r[id].area * 1.0 / (1.0 * x);
            }
        }
    }

    cout << cnt << endl;
    // 按题目要求排序
    sort(ans, ans + cnt, cmp);

    for (int i = 0; i < cnt; i++)
    {
        printf("%04d %d %.3lf %.3lf\n", ans[i].id, ans[i].num, ans[i].sum, ans[i].area);
    }
    return 0;
}