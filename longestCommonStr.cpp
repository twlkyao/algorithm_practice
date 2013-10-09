/*
Description: 求一个字符串最长重复子串

链接：程序员面试宝典14.5.2

基本算法描述:
从大到小取子串，分别从前查找子串和从后查找子串，如果位置不一样，则表示为重复子串
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, tep;
    cin >> str;

    for (int i = str.length() - 1; i > 1; --i) {
        for (int j = 0; j < str.length(); ++j) {

            if (j + i <= str.length()) {
                size_t t = 0;
                size_t num = 0;
                tep = str.substr(j, i); // 从大到小取子串
                t = str.find(tep);      // 正序查找
                num = str.rfind(tep);   // 逆序查找
                // cout << "t:" << t << " num:" << num << endl;
                if (t != num) {             // 如果两次查找位置不一致说明存在重复子串
                    // cout << "t:" << t << " num:" << num << endl;
                    cout << tep << " " << t + 1 << endl; // 输出子串及为位置
                    return 0;
                }
            }

        }
    }

    return 0;
}