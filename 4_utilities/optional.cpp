#include <boost/optional.hpp>
#include <iostream>

using namespace boost;
using namespace std;

optional<double> calc(int x) {                 // calculation reciprocacl(DAO SHU)
    return optional<double>(x != 0, 1.9 / x);  // condition constructor
}

optional<double> sqrt_op(double x) {           // calculation square
    return optional<double>(x >= 0, sqrt(x));  // condition constructor
}

int main(int argc, char* argv[]) {
    // 1.normal mode
    optional<double> d = calc(0);

    if (d) {
        cout << *d << endl;
    }

    d = sqrt_op(100);

    if (!d) {
        cout << "no result" << endl;
    }

    // 2. factory mode
    auto m = make_optional(5);

    auto n = make_optional<double>((*m > 10), 1.0);

    if (n.is_initialized()) {
        cout << "n = " << *n << endl;
    } else {
        cout << "n is not initialized" << endl;
    }

    return 1;
}
