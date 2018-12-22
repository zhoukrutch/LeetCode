//
//  LongestPalindromicSubstring.cpp
//  LeetCode
//
//  Created by zhoutao on 2018/12/22.
//  Copyright © 2018 zhoutao. All rights reserved.
//

#include "LongestPalindromicSubstring.hpp"
#include "../CommonUtil.hpp"

string longestPalindrome(string s) {
    long n = s.length();
    bool f[n][n];
    fill_n(&f[0][0], n * n, false);
    int maxLength = 0;
    int start = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j) {
                f[j][i] = true;
            } else if (i == j + 1 && s[i] == s[j]) {
                f[j][i] = true;
            } else if (s[i] == s[j] && f[j+1][i-1]) {
                f[j][i] = true;
            }
            if (f[j][i] && maxLength < i - j +1) {
                maxLength = i - j +1;
                start = j;
            }
        }
    }
    return s.substr(start,maxLength);
}

int longestPalindromeTest() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        string ret = longestPalindrome(s);
        
        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
