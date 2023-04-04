#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    stack<int> s1;
    stack<char> s2;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        s1.push(x);
    }
    for (int i = 1; i < n; ++i)
    {
        char x;
        cin >> x;
        s2.push(x);
    }
    while (s1.size() > 1)
    {
        int a = s1.top();
        s1.pop();
        int b = s1.top();
        s1.pop();
        char t = s2.top();
        s2.pop();
        int sum;
        if (t == '/')
        {
            if (!a)
            {
                cout << "ERROR: " << b << '/' << a << endl;
                return 0;
            }
            sum = b / a;
        }
        else if (t == '*')
        {
            sum = b * a;
        }
        else if (t == '+')
        {
            sum = b + a;
        }
        else
        {
            sum = b - a;
        }
        s1.push(sum);
    }
    cout << s1.top() << endl;
    return 0;
}