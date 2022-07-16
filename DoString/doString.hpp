//
// Created by yjs on 2022/7/17.
//

#ifndef YJSTOOLS_DOSTRING_HPP
#define YJSTOOLS_DOSTRING_HPP

#include <iostream>
#include <string>
#include <vector>


using namespace std;


///////////////////////////////////////////////////////////////////////////////////
static const std::string WHITE_SPACE = " \n\r\t\f\v";

std::string ltrim(const std::string &);

std::string rtrim(const std::string &);

std::string trim(const std::string &);

std::vector<std::string> split(const std::string &, const std::string &);

std::vector<std::string> split(const std::string &, const std::string &, bool);

/////////////////////////////////////////////////////////////////////////////////////
std::string ltrim(const std::string &s) {
    size_t start = s.find_first_not_of(WHITE_SPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string &s) {
    size_t end = s.find_last_not_of(WHITE_SPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string &s) {
    return rtrim(ltrim(s));
}

std::vector<std::string> split(const std::string &str, const std::string &delim) {
    return split(str, delim, false);
}

std::vector<std::string> split(const std::string &str, const std::string &delim, bool is_trim) {
    std::vector<string> res;
    if (str.empty()) {
        return res;
    }
    std::string string1 = str + delim; //*****扩展字符串以方便检索最后一个分隔出的字符串
    std::string::size_type pos;
    std::size_t size = string1.size();
    for (int i = 0; i < (int) size; ++i) {
        pos = string1.find(delim, i); //pos为分隔符第一次出现的位置，从i到pos之前的字符串是分隔出来的字符串
        if (pos != string::npos) { //如果查找到，如果没有查找到分隔符，pos为string::npos
            string s = string1.substr(i, pos - i);//*****从i开始长度为pos-i的子字符串
            if (is_trim) {
                res.push_back(trim(s));//两个连续空格之间切割出的字符串为空字符串，这里没有判断s是否为空，所以最后的结果中有空字符的输出，
            } else {
                res.push_back(s);//两个连续空格之间切割出的字符串为空字符串，这里没有判断s是否为空，所以最后的结果中有空字符的输出，
            }
            i = pos + delim.size() - 1;
        }
    }
    return res;
}

#endif //YJSTOOLS_DOSTRING_HPP
