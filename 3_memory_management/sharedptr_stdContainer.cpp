#include <iostream>
#include <memory>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    auto v = make_shared<vector<shared_ptr<int>>>(10);
    typedef vector<shared_ptr<int>> vs;
    vs k(10);

    int i = 0;
    for (auto pos = v->begin(); pos != v->end(); ++pos) {
        (*pos) = make_shared<int>(++i);
        cout << *(*pos) << ", ";
    }
    cout << endl;

    auto p = make_shared<int>(*((*v)[9]));
    // shared_ptr<int> p = (*v)[9];
    cout << *p << endl;

    return 1;
}
