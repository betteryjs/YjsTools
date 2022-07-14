//
// Created by yjs on 2022/7/12.
//

#ifndef YJSTOOLS_BASE64_H
#define YJSTOOLS_BASE64_H
#include <iostream>


static const std::string base64_chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

static inline bool is_base64(const char c);
std::string base64_encode(const std::string & decoded_string);
std::string base64_decode(std::string const & encoded_string);

#endif //YJSTOOLS_BASE64_H
