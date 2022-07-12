//
// Created by yjs on 2022/7/12.
//

#include <bits/stdc++.h>

using namespace std;



unsigned char ToHex(unsigned char x) {
    return x > 9 ? x + 55 : x + 48;
    // x + 55  10 进制到大写 HEX 字母 A B C D E F
    // x + 48  10 进制到数字 0 1 2 3 4 5 6 7 8 9
}




int main() {
//   auto res=ascii2value('c');
//   auto res2= ToHex('c');
//
//    printf("%02x\n",res);
//    printf("%02x\n",res2);
//
//    unsigned char ch = 'c';
//    std::stringstream ss;
//    cout<<std::hex<<std::setw(2)<< ch;
//  unsigned char c='c';
//  cout << int(c)<<endl;
//
//
//    string out;
//    stringstream ss;
//    ss << std::hex <<c;
//    ss >> out ;
//    transform(out.begin(), out.end(), out.begin(), ::toupper);
//    cout << out <<endl;
    string c{"你好"};
    cout << c.size() << endl;
    const char *res = c.c_str();
    for (int i = 0; i < c.size(); ++i) {
        cout << ((unsigned char) res[i] >> 4) << "      "<<((unsigned char) res[i] % 16) << endl;

        cout << ToHex((unsigned char) res[i] >> 4) << ToHex((unsigned char) res[i] % 16) << endl;

    }
//    cout << sizeof((unsigned char) 'c')<<endl;


    return 0;
}
