/*
 * @Author: zengzh
 * @Date: 2023-03-12 15:22:53
 * @Last Modified by: zengzh
 * @Last Modified time: 2023-03-12 16:30:00
 */

// 1 确定 mid
// 2 确定在 mid 左右的数
// 3 递归2步骤

#include <stdio.h>
#include <algorithm>
using namespace std;

void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    int i = l - 1, j = r + 1, x = q[(l + r) >> 1];
    while (i < j)
    {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
        quick_sort(q, l, j), quick_sort(q, j + 1, r);
    }
}

int main()
{
    int q[] = {1, 3, 2, 4, 5, 6, 7, 8, 9, 10};
    int n = 9;
    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
    return 0;
}