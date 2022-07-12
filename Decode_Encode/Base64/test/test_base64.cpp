//
// Created by yjs on 2022/7/12.
//

#include "../base64.h"

#include <iostream>


using namespace std;


int main(){
    string inputs{"你好"};
    string res=base64_encode(inputs.c_str(),inputs.size());
    cout << res<<endl;
    return 0;
}