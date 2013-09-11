// https://community.topcoder.com/stat?c=problem_statement&pm=1259&rd=4493

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

class ZigZag {
public:
    int longestZigZag(vector <int> sequence) 
    {
        if(sequence.size() == 1) return 1;
        vector<int> v(sequence.size()-1);
        for(int i=1;i<sequence.size();i++)
        {
            v[i-1] = sequence[i] - sequence[i-1];
        }
        //    dir is first nonzero
        int ii=0;
        while( ii < v.size() && v[ii] == 0)
            ii++;
        if(ii == v.size()) return 1;
        int dir = v[ii];
        int len = 2;
        for(int i=ii+1;i<v.size();i++)
        {
            if(v[i] * dir < 0)
            {
                dir *= -1;  
                len++;
            }
        }
        return len;
    }
};

class v_out {
public:
    int static vOutAll(vector <int> v_exa, string s)
    {
        cout << s;
        for (std::vector<int>::iterator it = v_exa.begin(); it != v_exa.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }
};

int main ()
{
    int zz[] = {4, 6, 4, 4, 1, 2, 6, 7, 1, 3};
    std::vector<int> zigzag_in (zz, zz + sizeof(zz) / sizeof(int));
    v_out::vOutAll(zigzag_in, "The contents of zigzag_in are:");

    ZigZag zz_example;
    ZigZag *zz_example_p = &zz_example;
    int output = zz_example_p->longestZigZag(zigzag_in);
    cout << "The length of the longest subsequence of sequence: ";
    cout << output << "\n";

    return 0;
}