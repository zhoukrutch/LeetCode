//
//  TwoSum.cpp
//  LeetCode
//
//  Created by zhoutao on 2018/12/17.
//  Copyright © 2018 zhoutao. All rights reserved.
//

#include "TwoSum.hpp"
#include "../CommonUtil.hpp"

vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> mapping;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        mapping[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); i++) {
        int gap = target - nums[i];
        if (mapping.find(gap) != mapping.end() && mapping[gap] > i) {
            result.push_back(i);
            result.push_back(mapping[gap]);
            break;
        }
    }
    return result;
}


void twoSumTest(void) {
    
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        vector<int> ret = twoSum(nums, target);
        
        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return;
//    cout << "Input nums:\n";
//    string line;
//    getline(cin, line);
//    std::stringstream ss(line);
//    vector<int> nums;
//    int x;
//    while (ss >> x)
//        nums.push_back(x);
//    int target;
//    cout << "Input target:\n";
//    cin>>target;
//    vector<int> result;
//    result = twoSum(nums, target);
//    cout <<"two Sum result is [" <<result[0]<<" , "<<result[1] << "]\n";
//    return;
}




