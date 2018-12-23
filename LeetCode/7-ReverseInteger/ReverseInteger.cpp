//
//  ReverseInteger.cpp
//  LeetCode
//
//  Created by zhoutao on 2018/12/23.
//  Copyright © 2018 zhoutao. All rights reserved.
//

#include "ReverseInteger.hpp"
#include "../CommonUtil.hpp"

int reverseInteger(int x) {
    int rev = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
        if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
        rev = rev * 10 + pop;
    }
    return rev;
}

int reverseIntegerTest() {
    string line;
    while (getline(cin, line)) {
        int x = stoi(line);
        
        int ret = reverseInteger(x);
        
        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
