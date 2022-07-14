//
// Created by yjs on 2022/7/12.
//

#include "base64.hpp"

#include <iostream>


using namespace std;


int main(){
    string inputs{"你好阿公司的公司的告别赛公司的公司的个"};
    string res=base64_encode(inputs);
    cout << res<<endl;
    string  res2= base64_decode(res);
    cout << res2<<endl;

    return 0;
}