#include <boost/assign.hpp>
#include <cstdlib>
#include <iostream>

using namespace boost::assign;
using namespace std;

int main(int argc, char* argv[]) {
    vector<int> v = list_of(1).repeat(3, 2)(3)(4)(5);
    // v=1,2,2,2,3,4,5
    for (auto& val : v) {
        cout << "v val = " << val << endl;
    }

    multiset<int> ms;
    insert(ms).repeat_fun(5, &rand).repeat(2, 1), 10;

    for (multiset<int>::iterator iter = ms.begin(); iter != ms.end(); ++iter) {
        cout << "ms val = " << *iter << endl;
    }

    deque<int> d;
    push_front(d).range(v.begin(), v.begin() + 5);
    for (deque<int>::iterator iter = d.begin(); iter != d.end(); ++iter) {
        cout << "d val = " << *iter << endl;
    }

    cout << "over" << endl;
    return 1;
}
