#include <bits/stdc++.h>
const int N = 503;
#define PII pair<int, int>
struct cc
{
    int id, val;
};
std::vector<cc> v[N];
int a[N], pre[N], sum[N], cnt[N], dis[N];
bool pd[N];
int main()
{
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int n, m, s, d;
    std::cin >> n >> m >> s >> d;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }
    std::priority_queue<std::PII, std::vector<std::PII>, std::greater<std::PII>> q; // 待选顶点
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        std::cin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    memset(pre, -1, sizeof(pre));
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    dis[s] = 0, sum[s] = a[s], cnt[s] = 1;
    q.push(std::make_pair(0, s)); // 放入距离起点
    while (!q.empty())
    {
        int x = q.top().second; // 点
        q.pop();
        if (pd[x])
        {
            continue;
        }
        pd[x] = true;
        for (int i = 0, l = v[x].size(); i < l; ++i)
        {
            int next = v[x][i].id, nextdis = v[x][i].val;
            if (dis[next] > dis[x] + nextdis)
            {
                dis[next] = dis[x] + nextdis;
                pre[next] = x;
                cnt[next] = cnt[x];
                sum[next] = sum[x] + a[next];
                q.push(std::make_pair(dis[next], next));
            }
            else if (dis[next] == dis[x] + nextdis)
            {
                cnt[next] += cnt[x];
                if (sum[next] < sum[x] + a[next])
                {
                    sum[next] = sum[x] + a[next];
                    pre[next] = x;
                }
            }
        }
    }
    std::cout << cnt[d] << " " << sum[d] << '\n';
    std::stack<int> S;
    while (d != -1)
    {
        S.push(d);
        d = pre[d];
    }
    while (!S.empty())
    {
        std::cout << S.top();
        if (S.size() != 1)
        {
            std::cout << " ";
        }
        S.pop();
    }
    return 0;
}