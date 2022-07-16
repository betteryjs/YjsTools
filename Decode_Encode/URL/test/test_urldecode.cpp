//
// Created by yjs on 2022/7/8.
//

#include "../urlEncodeDecode.hpp"
#include <iostream>
#include <string>


using namespace std;


int main(int argc,char *argv[])
{
    //U+82E6 CJK UNIFIED IDEOGRAPH-82E6
    //UTF-8: e8 8b a6 UTF-16BE: 82e6 Decimal: &#33510; Octal: \0101346
    //苦
    //Category: Lo (Letter, Other); East Asian width: W (wide)
    //Unicode block: 4E00..9FFF; CJK Unified Ideographs
    //Bidi: L (Left-to-Right)
    string unencode_url("苦");
    cout << "unencode_url: " << unencode_url << endl;
    string   encode_url = UrlEncode(unencode_url);
    cout << "encode_url: " << encode_url << endl;
    string   decode_url = UrlDecode(encode_url);
    cout << "decode_url: " << decode_url << endl;
}