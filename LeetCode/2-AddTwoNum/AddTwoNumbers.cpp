//
//  AddTwoNumbers.cpp
//  LeetCode
//
//  Created by zhoutao on 2018/12/18.
//  Copyright © 2018 zhoutao. All rights reserved.
//

#include "AddTwoNumbers.hpp"
#include "../CommonUtil.hpp"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(-1);
    int carry = 0;
    ListNode *pre = &dummy;
    for (ListNode *nodeA = l1, *nodeB = l2; nodeA != nullptr || nodeB != nullptr; nodeA = nodeA != nullptr ? nodeA = nodeA->next : nullptr, nodeB = nodeB != nullptr ? nodeB = nodeB->next : nullptr, pre = pre->next) {
        int valuA = nodeA == nullptr ? 0 : nodeA->val;
        int valuB = nodeB == nullptr ? 0 : nodeB->val;
        int value = (valuA + valuB + carry)%10;
        carry = (valuA + valuB + carry) / 10;
        pre->next = new ListNode(value);
    }
    
    if (carry > 0) {
        pre->next = new ListNode(carry);
    }
    
    
    return dummy.next;
}

int addTwoNumbersTest(void) {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = addTwoNumbers(l1, l2);
        
        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
