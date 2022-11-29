//
// Created by Yican Zhang on 2022/11/9.
//

#include "KnapsackProblem0_1.h"
#include "algorithm"

int KnapsackProblem0_1::Solution_with_dp(int bag_weight, int goods_nums, vector<int> goods_weight,vector<int> goods_value) {

    // dp[i][j] 物品编号为 0 - i-1 以及 背包容量为 j 时的最大价值量
    // if goods_weight > j -> dp[i][j] = dp[i-1][j];
    // 在于第 i 件商品选择不选择 不选 or 选
    // else dp[i][j] = max(dp[i-1][j], dp[i-1][j-goods_weight[i]] + goods_value[i])
    // 假设 5个商品 编号0-4 背包重量为 10 -> dp[5][11]
    vector<vector<int>> dp(goods_nums, vector<int>(bag_weight+1));
    // Init
    for(int i = 0; i < goods_nums; i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i < bag_weight + 1; i++){
        if(i >= goods_weight[0]) dp[0][i] = goods_value[0];
        else dp[0][i] = 0;
    }
    // dp
    for(int i = 1 ; i < goods_nums; i++){
        // 商品不动 bag_weight++
        for(int j = 1; j < bag_weight + 1; j++){
            //装不下
            if(goods_weight[i] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j],dp[i-1][j-goods_weight[i]]+goods_value[i]);
        }
    }
    
    /*for(int i = 1; i < bag_weight + 1; i++){
        //先遍历商品
        for(int j = 1; j < goods_nums; j++){
            //装不下
            if(goods_weight[j] > i) dp[j][i] = dp[j-1][i];
            else dp[j][i] = max(dp[j-1][i],dp[j-1][i-goods_weight[j]]+goods_value[j]);
        }
    }*/


    return dp[goods_nums-1][bag_weight];
}
