/*
 * @Author: zengzh
 * @Date: 2023-04-29 09:15:41
 * @Last Modified by:   zengzh
 * @Last Modified time: 2023-04-29 09:15:41
 */

// 1 有序 bool check(int x) {}
// int bsearch_1(int l, int r)
// {
//     while (l < r)
//     {
//         int mid = l + r >> 1;
//         if check (mid)
//             r = mid;
//         l = mid + 1;
//     }
//     return l;
// }
// int bsearch_2(int l, int r)
// {
//     while (l < r)
//     {
//         int mid = l + r + 1 >> 1;
//         if check (mid)
//             l = mid;
//         r = mid - 1;
//     }
//     return l;
// }

#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 100010;

int n = 12, m = 1;
int q[] = {1, 2, 3, 3, 3, 4, 4, 4, 4, 5, 6, 7, 8, 9, 10};

int main()
{
    // scanf("%d%d", &n, &m);
    // for (int i = 0; i < n; i++)
    //     scanf("%d", &q[i]);
    int x = 3;
    while (m--)
    {
        // int x;
        // scanf("%d", &x);
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (q[mid] >= x)
                r = mid;
            else
                l = mid + 1;
        }
        if (q[l] != x)
            printf("%d%d", -1, -1);
        else
        {
            printf("%d ", l);
            int l = 0, r = n - 1;
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (q[mid] <= x)
                    l = mid;
                else
                    r = mid - 1;
            }
            printf("%d", l);
        }
    }
    return 0;
}
