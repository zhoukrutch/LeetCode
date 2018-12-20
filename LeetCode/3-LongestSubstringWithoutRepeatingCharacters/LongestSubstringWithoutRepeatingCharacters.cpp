//
//  LongestSubstringWithoutRepeatingCharacters.cpp
//  LeetCode
//
//  Created by zhoutao on 2018/12/19.
//  Copyright © 2018 zhoutao. All rights reserved.
//

#include "LongestSubstringWithoutRepeatingCharacters.hpp"
#include "../CommonUtil.hpp"

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 0; i < input.length() ; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

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
