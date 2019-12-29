#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

bool explicit_cast(shared_ptr<int>& p) {
    return static_cast<bool>(p);  // return must use explicit cast(XIAN SHI ZHUAN HUAN)
}

int main(int argc, char* argv[]) {
    auto p = make_shared<int>(134);
    assert(p);  // assert:implicit cast(YIN SHI ZHUAN HUAN)

    if (p) {
        cout << "p is not nul, implicit cast" << endl;  // if:implicit cast(YIN SHI ZHUAN HUAN)
    }

    bool kk = explicit_cast(p);
    cout << kk << endl;

    return 1;
}
