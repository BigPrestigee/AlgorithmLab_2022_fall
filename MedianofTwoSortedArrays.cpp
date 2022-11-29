//
// Created by Yican Zhang on 2022/11/7.
//

#include "MedianofTwoSortedArrays.h"

double MedianofTwoSortedArrays::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    // 计算长度总和，从而获得中位数的位置
    int total = nums1.size() + nums2.size();
    if (total % 2 == 0)
    {
        // 如果total为偶数，则中位数是中间两个数的均值，位置分别在total/2和total/2+1
        // 注意：这里的位置均是从1开始的，比如说6个数，下标从1-6，中位数位置为第3和4个数的均值
        // 0 表示从数组的哪个下标开始搜索
        int left = findKthNumber(nums1, 0, nums2, 0, total / 2);
        int right = findKthNumber(nums1, 0, nums2, 0, total / 2 + 1);
        return (left + right) / 2.0;
    }
    else
    {
        // 如果total为奇数，则中位数是位置为第total/2+1的数（这里是整数向下除法）
        return findKthNumber(nums1, 0, nums2, 0, total / 2 + 1);
    }

}

int MedianofTwoSortedArrays::findKthNumber(vector<int> &nums1, int i, vector<int> &nums2,int j, int k) {
    // 1 3 4
    // 2 3 4 5 6
    // 寻找第k小的元素，每次循环排除k/2个数
    // 这里默认nums1的长度比nums2的长度短，否则就调换一下
    if (nums1.size() - i > nums2.size() - j) return findKthNumber(nums2, j, nums1, i, k);

    // 边界情况：nums1为空，则直接返回nums2的第j+k-1位置上的数
    if (nums1.size() == i) return nums2[j + k - 1];
    // 边界情况：k==1，即找最小值即可。注意：此时nums1和nums2一定都不为空
    if (k == 1) return min(nums1[i], nums2[j]);

    // 一般情况：先确定两个数组第k/2位置在数组中的下标是多少（si和sj）
    // 注意：由于nums1比较短，因此i+k/2可能会越界，需要和nums1.size()取个最小值
    int si = min(i + k / 2, int(nums1.size())), sj = j + k / 2;
    if (nums1[si - 1] > nums2[sj - 1])
    {
        // 如果nums1第si位置上的数大于nums2第sj位置上的数，则可以删除nums2前sj个数
        // 因此，下一次迭代nums2从sj开始，且搜寻第k-k/2小的数
        return findKthNumber(nums1, i, nums2, sj, k - k / 2);
    } else {
        // 如果nums1第si位置上的数小于nums2第sj位置上的数，则可以删除nums1前si个数
        // 因此，下一次迭代nums1从si开始，且搜寻第k-(si-i)小的数
        return findKthNumber(nums1, si, nums2, j, k - (si - i));
    }

}