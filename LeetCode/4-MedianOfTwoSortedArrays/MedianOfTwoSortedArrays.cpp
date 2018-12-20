//
//  MedianOfTwoSortedArrays.cpp
//  LeetCode
//
//  Created by zhoutao on 2018/12/20.
//  Copyright © 2018 zhoutao. All rights reserved.
//

#include "MedianOfTwoSortedArrays.hpp"
#include "../CommonUtil.hpp"

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    const int m = nums1.size();
    const int n = nums2.size();
//    //开辟新空间做法
    int i = 0, j = 0;
    vector<int> newNum;
    while (i < m || j < n) {
        if (i == m) {
            newNum.push_back(nums2[j]);
            j++;
        } else if (j == n) {
            newNum.push_back(nums1[i]);
            i++;
        } else if (nums1[i] < nums2[j]) {
            newNum.push_back(nums1[i]);
            i++;
        } else {
            newNum.push_back(nums2[j]);
            j++;

        }
    }
    if ((m + n)%2 == 0) {
        return (newNum[(m+n-1)/2] + newNum[(m+n+1)/2])/2.0;
    }
    return newNum[(m+n)/2.0];
}

int findMedianSortedArraysText() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);
        
        double ret = findMedianSortedArrays(nums1, nums2);
        
        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
