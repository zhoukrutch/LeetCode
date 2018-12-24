//
//  StringToInteger.cpp
//  LeetCode
//
//  Created by zhoutao on 2018/12/24.
//  Copyright © 2018 zhoutao. All rights reserved.
//

#include "StringToInteger.hpp"
#include "../CommonUtil.hpp"

int myAtoi(string str) {
    if (str.length() == 0) {
        return 0;
    }
    int result = 0;
    bool isPositive = true;
    int len=str.length();
    int sign_count = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == '-' || str[i] == '+') {
            sign_count++;
        }
        if (sign_count <= 1) {
            if (str[i] == '-' || str[i] == '+') {
                if (str[i] == '-') {
                    isPositive = false;
                }
                if (i + 1 > len || str[i+1] == ' ') {
                    break;
                }
            } else if (str[i] >= '0' && str[i] <= '9') {
                int x =  str[i] - '0';
                if (isPositive && (result > INT_MAX/10 || (result == INT_MAX / 10 && x > 7))) {
                    return INT_MAX;
                } else if (!isPositive && (result < INT_MIN/10 || (result == INT_MIN / 10 && x < -8))) {
                    return INT_MIN;
                }
                result = result * 10 + x;
                if (i + 1 > len || str[i+1] == ' ') {
                    break;
                }
            } else if (str[i] == ' ') {
                
            } else {
                break;
            }
        } else {
            return 0;
        }
    }
    if (!isPositive) {
        result = -result;
    }
    return result;
}

int stringToIntegerTest() {
    
    string str0;
    string str1="1ab3";  // 应返回1
    string str2="18446744073709551617";
    string str3="- +899999 ";
    string str4="    010"; // 应返回10
    string str5="   +0 123";
    string str6="13  456"; // 123
    string str7="   - 321";
    
    cout<<myAtoi(str0)<<endl;
    cout<<myAtoi(str1)<<endl;
    cout<<myAtoi(str2)<<endl;
    cout<<myAtoi(str3)<<endl;
    cout<<myAtoi(str4)<<endl;
    cout<<myAtoi(str5)<<endl;
    cout<<myAtoi(str6)<<endl;
    cout<<myAtoi(str7)<<endl;
    string line;
    while (getline(cin, line)) {
        int x = myAtoi(line);
        
        string out = to_string(x);
        cout << out << endl;
    }
    return 0;
}
