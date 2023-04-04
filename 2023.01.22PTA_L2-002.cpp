#include <iostream>
#include <cmath>
using namespace std;
int Key[100005], Next[100005], list1[100005], list2[100005];
// key存数值，next存下一个地址，list1为输出以去重的链表地址，list2为去重的地址
bool Judge[100005]; // 是否为重复数值
int main()
{
    int begin, n;
    cin >> begin >> n;
    int a, b, c;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        Key[a] = b;
        Next[a] = c;
    }
    // 判断
    int k1 = 0, k2 = 0;
    for (int i = begin; i != -1; i = Next[i])
    {
        if (!Judge[abs(Key[i])])
        {
            Judge[abs(Key[i])] = true;
            list1[k1++] = i;
        }
        else
        {
            list2[k2++] = i;
        }
    }
    // 输出
    for (int i = 0; i < k1; i++)
    {
        if (i < k1 - 1)
            printf("%05d %d %05d\n", list1[i], Key[list1[i]], list1[i + 1]);
        else
            printf("%05d %d -1\n", list1[i], Key[list1[i]]);
    }
    for (int i = 0; i < k2; i++)
    {
        if (i < k2 - 1)
            printf("%05d %d %05d\n", list2[i], Key[list2[i]], list2[i + 1]);
        else
            printf("%05d %d -1\n", list2[i], Key[list2[i]]);
    }

    return 0;
}
