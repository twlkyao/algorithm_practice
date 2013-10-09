/*
Description: 求一个字符串中连续出现次数最多的子串.

链接：http://blog.csdn.net/imcdragon/article/details/6838565

基本算法描述:
    给出一个字符串abababa
    1.穷举出所有的后缀子串
        substrs[0] = abababa;
        substrs[1] = bababa;
        substrs[2] = ababa;
        substrs[3] = baba;
        substrs[4] = aba;
        substrs[5] = ba;
        substrs[6] = a;
    2.然后进行比较
        substrs[0]比substrs[1]多了一个字母,如果说存在连续匹配的字符,那么
        substrs[0]的第1个字母要跟substrs[1]首字母匹配,同理
        substrs[0]的前2个字母要跟substrs[2]的前2个字母匹配(否则不能叫连续匹配)
        substrs[0]的前n个字母要跟substrs[n]的前n个字母匹配.
        如果匹配的并记下匹配次数.如此可以求得最长连续匹配子串.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

pair<int, string> fun (const string &str) {
    vector<string> substrs;
    int maxcount = 1, count = 1;
    string substr;
    int i, len = str.length();

    for (i = 0; i < len; ++i)
        substrs.push_back(str.substr(i, len - i));
    // for (vector<string>::iterator it = substrs.begin(); it != substrs.end(); ++it)
    //     cout << ' ' << *it << endl;

    for (i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {

            count = 1;
            if (substrs[i].substr(0, j - i) == substrs[j].substr(0, j - i)) {
                ++count;
                for (int k = j + (j - i); k < len; k += j - i) {
                    if (substrs[i].substr(0, j - i) == substrs[k].substr(0, j - i))
                        ++count;
                    else
                        break;
                }
                if (count > maxcount) {
                    maxcount = count;
                    substr = substrs[i].substr(0, j - i);
                }
            }

        }
    }

    return make_pair(maxcount, substr);
}

int main() {
    string str;
    pair<int, string> rs;

    while (cin >> str) {
        rs = fun(str);
        cout << rs.second << ':' << rs.first << '\n';
    }

    return 0;
}

/*
abcccabc
c:3

abcabcbcbcbcabc
bc:4
 */