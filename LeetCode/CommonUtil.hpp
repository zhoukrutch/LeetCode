//
//  CommonUtil.hpp
//  LeetCode
//
//  Created by zhoutao on 2018/12/17.
//  Copyright © 2018 zhoutao. All rights reserved.
//

#ifndef CommonUtil_hpp
#define CommonUtil_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "string"
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x=0) : val(x), left(NULL), right(NULL) {}
};

int stringToInteger(string input);
vector<int> stringToIntegerVector(string input);
string integerVectorToString(vector<int> list);
ListNode* stringToListNode(string input);
string listNodeToString(ListNode* node);
string stringToString(string input);

#endif /* CommonUtil_hpp */
