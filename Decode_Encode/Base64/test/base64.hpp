//
// Created by yjs on 2022/7/14.
//

#ifndef YJSTOOLS_BASE64_H
#define YJSTOOLS_BASE64_H
#include <iostream>
#include <string>


using namespace std;


static const std::string base64_chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";


static inline bool is_base64(const char c){
    return (isalnum(c) || (c == '+') || (c == '/'));
}


std::string base64_encode(const std::string & inputs){

    const char * bytes_to_encode=inputs.c_str();
    unsigned int in_len=inputs.size();

    size_t len_encoded = (in_len +2) / 3 * 4;

    char trailing_char = '=';
    std::string ret;
    ret.reserve(len_encoded);

    unsigned int pos = 0;

    while (pos < in_len) {
        // 0xfc "11111100" >> 2 取开头第1B的6个比特
        // encode 1
        ret.push_back(base64_chars[(bytes_to_encode[pos + 0] & 0xfc) >> 2]);

        if (pos+1 < in_len) {
            // 0x03 "00000011" << 4 "110000"  取开头第1B的后2个比特当作 char_array_4 [1] 的高2位
            // 0xf0 "11110000" >> 4 取开头第2B的前4个比特
            // encode 2
            ret.push_back(base64_chars[((bytes_to_encode[pos + 0] & 0x03) << 4) + ((bytes_to_encode[pos + 1] & 0xf0) >> 4)]);

            if (pos+2 < in_len) {
                // encode 3
                // 0x0f "00001111" << 2  取开头第2B的后4个比特 当作高4位
                // 0xc0 "11000000" >> 6  取开头第3B的后2个比特 当作低2位
                ret.push_back(base64_chars[((bytes_to_encode[pos + 1] & 0x0f) << 2) + ((bytes_to_encode[pos + 2] & 0xc0) >> 6)]);

                // encode 4
                // 0x3f "00111111" 取开头第3B的后6个比特
                ret.push_back(base64_chars[  bytes_to_encode[pos + 2] & 0x3f]);
            }
            else {
                // pos+2 >= in_len
                // 如果最后剩下 2 个字节未编码，那么将补 2 个 0 位，编码成 3 个 Base64 字符，然后补一个 =
                // pos pos+1 pos+2
                // encode 3
                ret.push_back(base64_chars[(bytes_to_encode[pos + 1] & 0x0f) << 2]);
                ret.push_back(trailing_char);
            }
        }
        else {
            // pos+1 >= in_len
            // 如果最后剩下 1 个字节未编码 ，那么将补 4 个 0 位，编码成 2 个 Base64 字符，然后补两个 =
            // 0x03 "00000011" 取开头第1B的后2个比特 作高2位
            ret.push_back(base64_chars[(bytes_to_encode[pos + 0] & 0x03) << 4]);
            ret.push_back(trailing_char);
            ret.push_back(trailing_char);
        }

        pos += 3;
    }


    return ret;






}

std::string base64_decode(std::string const & encoded_string){

    size_t length_of_string = encoded_string.length();
    size_t pos = 0;

    //
    // The approximate length (bytes) of the decoded string might be one or
    // two bytes smaller, depending on the amount of trailing equal signs
    // in the encoded string. This approximation is needed to reserve
    // enough space in the string to be returned.
    //
    size_t approx_length_of_decoded_string = length_of_string / 4 * 3;
    std::string ret;
    ret.reserve(approx_length_of_decoded_string);
    unsigned char char_array_4[4];

    while (pos < length_of_string) {

        int tmpPos=pos;
        for (int i = 0; i <4; i++)
            char_array_4[i] = base64_chars.find(encoded_string[tmpPos++]);
        // 0x30 "110000"
        ret.push_back(static_cast<std::string::value_type>( (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4)));

        if ( ( pos + 2 < length_of_string  ) &&  encoded_string[pos+2] != '=')
        {
            //
            // Emit a chunk's second byte (which might not be produced in the last chunk).
            //

            ret.push_back(static_cast<std::string::value_type>( ((char_array_4[1] & 0xf) << 4)+((char_array_4[2] & 0x3c) >> 2)));

            if ( ( pos + 3 < length_of_string ) && encoded_string[pos+3] != '=')
            {
                //
                // Emit a chunk's third byte (which might not be produced in the last chunk).
                //
                ret.push_back(static_cast<std::string::value_type>( ((char_array_4[2] & 0x3) << 6) + char_array_4[3]));
            }
        }

        pos += 4;

    }
    return ret;
}

#endif //YJSTOOLS_BASE64_H
