//
//  CommonUtil.cpp
//  LeetCode
//
//  Created by zhoutao on 2018/12/17.
//  Copyright © 2018 zhoutao. All rights reserved.
//

#include "CommonUtil.hpp"

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    input = input.substr(0, input.length());
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list) {
    long length = list.size();
    
    if (length == 0) {
        return "[]";
    }
    
    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += std::to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);
    
    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }
    
    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}
