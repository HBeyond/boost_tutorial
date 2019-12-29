#include <boost/progress.hpp>
#include <iostream>

using namespace boost;
using namespace std;

int main(int argc, char* argv[]) {
    // time will be output automatically when ihe instance is destructed
    {
        progress_timer t1;
        for (size_t i = 0; i < 10000; ++i) {
        }
        cout << "part 1" << endl;
    }

    {
        progress_timer t2;
        for (size_t i = 0; i < 10000; ++i) {
        }
        cout << "part 2" << endl;
    }

    return 1;
}
