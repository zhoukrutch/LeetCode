//
//  LongestSubstringWithoutRepeatingCharacters.cpp
//  LeetCode
//
//  Created by zhoutao on 2018/12/19.
//  Copyright © 2018 zhoutao. All rights reserved.
//

#include "LongestSubstringWithoutRepeatingCharacters.hpp"
#include "../CommonUtil.hpp"

int lengthOfLongestSubstring(string s) {
    int maxLength = 0;
    set<char> cache;
    int i = 0, j= 0;
    int start = 0;
    long n = s.length();
    while (i<n && j< n) {
        if (cache.find(s[j]) == cache.end()) {
            int length = j-i+1;
            cache.insert(s[j]);
            if (length > maxLength) {
                start = i;
                maxLength = length;
            }
            j++;
        } else {
            cache.clear();
            i++;
            j = i;
        }
    }
    cout<<s.substr(start,maxLength)<<endl;
//    for (int i = 0; i < s.length(); i++) {
//        cache.clear();
//        for (int j = i; j< s.length(); j++) {
//            if (cache.find(s[j]) == cache.end()) {
//                int length = j-i+1;
//                cache.insert(s[j]);
//                if (length > maxLength) {
//                    maxLength = length;
//                    cout<<s.substr(i,maxLength)<<endl;
//                }
//                continue;
//            }
//            break;
//        }
//    }
    return maxLength;
}

int LongestSubstringWithoutRepeatingCharactersTest(void) {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = lengthOfLongestSubstring(s);
        
        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
