//
// Created by yjs on 2022/7/8.
//

#ifndef YJSTOOLS_URLENCODE_URLDECODE_H
#define YJSTOOLS_URLENCODE_URLDECODE_H


#include <iostream>
#include <assert.h>

using namespace std;



unsigned char ToHex(unsigned char x);
unsigned char FromHex(unsigned char x);

std::string UrlEncode(const std::string& str);
std::string UrlDecode(const std::string& str);


#endif //YJSTOOLS_URLENCODE_URLDECODE_H
