#include <bits/stdc++.h>
std::vector<int> v;
int main()
{
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    int ans = 0;
    int x;
    std::cin >> x;
    v.push_back(x);
    for (int i = 1; i < n; ++i)
    {
        int x;
        std::cin >> x;
        if (x > v[ans])
        {
            v.push_back(x);
            ++ans;
        }
        else
        {
            *upper_bound(v.begin(), v.begin() + ans, x) = x;
        }
    }
    std::cout << ans + 1 << '\n';
    return 0;
}