
#include <bits/stdc++.h> //狗屎多项式看不懂抄的不想写
using namespace std;
int main()
{
    const int maxn = 10000;
    float e1[maxn], e2[maxn], e3[maxn];
    int N;
    int ep1 = 0, ep2 = 0;
    int a;
    float b;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        e1[a] = b;
        if (ep1 < a)
        {
            ep1 = a;
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        e2[a] = b;
        if (ep2 < a)
        {
            ep2 = a;
        }
    }
    if (ep1 < ep2)
    {
        cout << "0 0 0.0" << endl;
        cout << N;
        for (int i = ep1; i >= 0; i--)
        {
            if (fabs(e1[i]) >= 0.05)
            {
                cout << ' ' << i;
                printf(" %.1f", e1[i]);
            }
        }
    }
    else
    {
        int tp = ep1;
        while (ep1 >= ep2)
        {
            int i;
            float y = e1[ep1] / e2[ep2];
            e3[ep1 - ep2] += y;
            for (i = ep2; i >= 0; i--)
            {
                if (fabs(e2[i]) > 0)
                {
                    e1[ep1 + i - ep2] -= y * e2[i];
                }
            }
            int ep = 0;
            for (i = tp; i >= 0; i--)
            {
                if (fabs(e1[i]) >= 0.05)
                {
                    if (i > ep)
                    {
                        ep = i;
                    }
                    break;
                }
            }
            if (i < 0)
            {
                break;
            }
            ep1 = ep;
        }
        int f1 = 0, f2 = 0;
        for (int i = tp; i >= 0; i--)
        {
            if (fabs(e3[i]) >= 0.05)
            {
                f1++;
            }
            if (fabs(e1[i]) >= 0.05)
            {
                f2++;
            }
        }
        if (f1 == 0)
        {
            cout << "0 0 0.0" << endl;
        }
        else
        {
            cout << f1;
            for (int i = tp; i >= 0; i--)
            {
                if (fabs(e3[i]) >= 0.05)
                {
                    cout << ' ' << i;
                    printf(" %.1f", e3[i]);
                }
            }
            cout << endl;
        }
        if (f2 == 0)
        {
            cout << "0 0 0.0" << endl;
        }
        else
        {
            cout << f2;
            for (int i = tp; i >= 0; i--)
            {
                if (fabs(e1[i]) >= 0.05)
                {
                    cout << ' ' << i;
                    printf(" %.1f", e1[i]);
                }
            }
        }
    }

    return 0;
}
