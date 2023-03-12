/*
 * @Author: zengzh
 * @Date: 2023-03-12 15:58:38
 * @Last Modified by: zengzh
 * @Last Modified time: 2023-03-12 16:29:00
 */

// 1 确定mid
// 2 递归排序left right
// 3 归并 left right

#include <stdio.h>
#include <algorithm>
using namespace std;

int tmp[9];

void merge_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        else
            tmp[k++] = q[j++];
    }
    while (i <= mid)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];
    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
}

int main()
{
    int q[] = {1, 3, 2, 4, 5, 6, 7, 8, 9, 10};
    int n = 9;
    merge_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
    return 0;
}