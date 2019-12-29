#include <boost/pool/object_pool.hpp>
#include <iostream>

using namespace std;
using namespace boost;

class demo_class {
   public:
    int a, b, c;
    demo_class(int x = 1, int y = 2, int z = 3) : a(x), b(y), c(z) {}
};

int main(int argc, char* argv[]) {
    // the class will not be initialized until the construct function is called of the object pool
    object_pool<demo_class> pl;

    auto p = pl.malloc();
    assert(pl.is_from(p));

    assert(p->a != 1 || p->b != 2 || p->c != 3);

    p = pl.construct();

    // continuely malloc
    object_pool<string> pls;
    for (size_t i = 0; i < 10; ++i) {
        string* ps = pls.construct("hello object_pool");
        cout << *ps << endl;
    }

    return 1;
}
