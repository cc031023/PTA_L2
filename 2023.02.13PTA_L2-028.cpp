#include <bits/stdc++.h> //嫌麻烦自己的代码懒得考虑-0分没拿满这是别人的代码.
using namespace std;
int sexx[1005]; // 桶装性别
double qx[1005][1005];
double qy[1005][1005];
int sss[1005][505]; // 存放输入的照片和照片上的人
int b[1005];        // 存放每张照片人数
int n, m, x;
char xx[11], yy[11], c[11];
int dg(char xx[])
{
    int cx = 0;
    if (xx[0] == '-')
    {
        for (int k = 1; k < strlen(xx); k++)
            cx = cx * 10 + xx[k] - '0';
    }
    else
    {
        for (int k = 0; k < strlen(xx); k++)
            cx = cx * 10 + xx[k] - '0';
    }
    return cx;
}
int main()
{
    scanf("%d%d", &n, &m);
    memset(sss, 0, sizeof(sss));
    memset(b, 0, sizeof(b));
    for (int i = 0; i <= 1000; i++)
        sexx[i] = 2;
    for (int t = 0; t < m; t++)
    {
        scanf("%d", &x);
        b[t] = x;
        for (int i = 0; i < x; i++)
        {
            // 考虑-0的情况，所以要用字符串输入
            scanf("%s", c);
            sss[t][i] = dg(c);
            if (c[0] == '-')
                sexx[sss[t][i]] = 1; // 存放性别，女1男0
            else
                sexx[sss[t][i]] = 0;
        }
    }
    scanf("%s%s", xx, yy);
    int cx = 0, cy = 0;
    cx = dg(xx);
    cy = dg(yy);
    double sx = 0, sy = 0;
    for (int i = 0; i < m; i++)
    {
        int flag = 0;
        int flbg = 0;
        for (int j = 0; j < b[i]; j++)
        {
            // if()break;
            if (sss[i][j] == cx)
                flag = 1;
            if (sss[i][j] == cy)
                flbg = 1;
        }
        if (flag)
        {
            // cout<<i<<endl;
            for (int j = 0; j < b[i]; j++)
            {
                if ((sexx[sss[i][j]] != sexx[cx]))
                {
                    qx[sss[i][j]][cx] += 1.0 / b[i] * 1.0;
                    qx[cx][sss[i][j]] = qx[sss[i][j]][cx];
                    if (qx[sss[i][j]][cx] > sx)
                    {
                        sx = qx[sss[i][j]][cx];
                    }
                }
            }
        }
        if (flbg)
        {
            for (int j = 0; j < b[i]; j++)
            {
                if ((sexx[sss[i][j]] != sexx[cy]))
                {
                    qy[sss[i][j]][cy] += 1.0 / b[i] * 1.0;
                    qy[cy][sss[i][j]] = qy[sss[i][j]][cy];
                    if (qy[sss[i][j]][cy] > sy)
                    {
                        sy = qy[sss[i][j]][cy];
                    }
                }
            }
        }
    }
    if (sy == qx[cx][cy] && sx == qy[cx][cy])
        cout << xx << " " << yy << endl;
    else
    {
        for (int i = 0; i <= 1000; i++)
            if (sx == qx[cx][i])
            {
                cout << xx << " ";
                if (sexx[i] == 1)
                    cout << "-";
                cout << i << endl;
            }
        for (int i = 0; i <= 1000; i++)
            if (sy == qy[cy][i])
            {
                cout << yy << " ";
                if (sexx[i] == 1)
                    cout << "-";
                cout << i << endl;
            }
    }
    return 0;
}