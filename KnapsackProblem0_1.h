//
// Created by Yican Zhang on 2022/11/9.
//

#ifndef LAB1_KNAPSACKPROBLEM0_1_H
#define LAB1_KNAPSACKPROBLEM0_1_H
using namespace std;
#include "vector"

class KnapsackProblem0_1 {
public:
    // dynamic programming
    int Solution_with_dp(int bag_weight, int goods_nums ,vector<int> goods_weight, vector<int> goods_value);
    // back tracking
    int Solution_with_BT();
};


#endif //LAB1_KNAPSACKPROBLEM0_1_H
