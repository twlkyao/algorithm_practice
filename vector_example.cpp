#include <string>
#include <vector>
#include <iostream>

using namespace std;

class v_out {
public:
    int vOutAll(vector <int> v_exa, string s)
    {
        cout << s;
        for (std::vector<int>::iterator it = v_exa.begin(); it != v_exa.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }
};

int main ()
{
    unsigned int i;
    v_out out_ins;
    v_out *out_ins_p = &out_ins;

    // constructors used in the same order as described above:
    std::vector<int> first;                                // empty vector of ints
    std::vector<int> second (4,100);                       // four ints with value 100
    std::vector<int> third (second.begin(),second.end());  // iterating through second
    std::vector<int> fourth (third);                       // a copy of third
    std::vector<int> sixth;

    // second output
    out_ins_p->vOutAll(second, "The contents of second are:");

    // fourth output
    out_ins_p->vOutAll(fourth, "The contents of fourth are: ");

    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16,2,77,29};
    int *lenth = myints + sizeof(myints) / sizeof(int);
    std::vector<int> fifth (myints, lenth );

    fifth.push_back(38);
    out_ins_p->vOutAll(fifth, "The contents of fifth are: ");

    // sixth output
    sixth.push_back(102);
    sixth.push_back(103);
    sixth.push_back(104);

    out_ins_p->vOutAll(sixth, "The contents of sixth are: ");

    return 0;
}