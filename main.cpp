#include <iostream>
#include "MedianofTwoSortedArrays.h"
#include "CountingSort.h"
#include "KnapsackProblem0_1.h"
using namespace std;
#include "unordered_set"
#include "string"


int main() {

    // 背包问题
    /*KnapsackProblem0_1 k;
    int Bag_W = 10;
    int Goods_N = 5;
    vector<int> goods_w{2,2,6,5,4};
    vector<int> goods_v{6,3,5,4,6};
    int res = k.Solution_with_dp(Bag_W,Goods_N,goods_w,goods_v);
    cout<<res;*/

    // 计数排序
    /*vector<int> nums{95,94,91,98,99,90,99,93,91,92};
    CountingSort s;
    vector<int> res = s.sortArray(nums);
    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<" ";
    }*/

    // 寻找两个有序数组的中位数
    /*vector<int> list1{1,2,3,5,7};
    vector<int> list2{1,3,6,7,9,10};
    MedianofTwoSortedArrays a;
    double res = a.findMedianSortedArrays(list1,list2);
    cout << res << endl;*/

    return 0;
}
