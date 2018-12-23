//
//  zigZagConversion.cpp
//  LeetCode
//
//  Created by zhoutao on 2018/12/23.
//  Copyright © 2018 zhoutao. All rights reserved.
//

#include "zigZagConversion.hpp"
#include "../CommonUtil.hpp"

string zigZagConvertSpace(string s, int numRows) {
    if (numRows == 1) {
        return s;
    }
    string result;
    //开辟空间方法
    vector<string> rowString(min(numRows, int(s.size())));
    bool growUp = false;
    int rowIndex = 0;
    for (int i = 0; i < s.length(); i++) {
        rowString[rowIndex] += s[i];
        if (rowIndex == 0 || rowIndex == numRows -1) {
            growUp = !growUp;
        }
        growUp ? rowIndex++ : rowIndex--;
    }
    for (string s : rowString) {
        result += s;
    }
    return result;
}

string zigZagConvert(string s, int numRows) {
    if (numRows == 1) {
        return s;
    }
    string result;
    int runloop = numRows * 2 - 2;
    for (int numIndex = 0; numIndex < numRows; numIndex++) {
        for (int stringIndex = numIndex; stringIndex < s.length(); stringIndex += runloop ) {
            result += s[stringIndex];
            if (numIndex != 0 && numIndex != numRows -1 && stringIndex + (runloop - numIndex * 2) < s.length()) {
                result +=s[stringIndex + (runloop - numIndex * 2)];
            }
        }
    }
    
    return result;
}

int zigZagConversionTest(void) {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int numRows = stringToInteger(line);
        
        string ret = zigZagConvert(s, numRows);
        
        string out = (ret);
        cout << out << endl;
        ret = zigZagConvertSpace(s, numRows);
        
        out = (ret);
        cout << out << endl;
    }
    return 0;
}
