//
// Created by Yican Zhang on 2022/11/8.
//

#include "CountingSort.h"

vector<int> CountingSort::sortArray(vector<int> &nums) {
    int max = INT_MIN,min = INT_MAX;
    for(int i = 0; i < nums.size(); i++){
        //get min
        if(nums[i] <= min) min = nums[i];
        //get max
        if(nums[i] >= max) max = nums[i];
    }
    vector<int> res(nums.size(),0);
    //vector<int> container(max-min+1,0);
    //cout << container.size();
    return COUNITING_SORT(nums, res, max+1);
}

vector<int> CountingSort::COUNITING_SORT(vector<int> &nums, vector<int> &res, int size) {
    //初始化container
    vector<int> container(size,0);
    for(int i = 0; i < nums.size(); i++){
        //记录出现次数 num[i] -> i
        container[nums[i]]++;
    }
    for(int i = 1; i < size; i++){
        //container[num[i]] 表示<=num[i] 的元素个数
        container[i] = container[i] + container[i-1];
    }
    for(int i = nums.size()-1; i >= 0; i--){
        // con
        res[container[nums[i]]-1] = nums[i];
        container[nums[i]]--;
    }
    return res;
}
