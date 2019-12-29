#include <boost/timer.hpp>
#include <iostream>

using namespace boost;
using namespace std;

int main(int argc, char* argv[]) {
    timer t;

    cout << "max timespan: " << t.elapsed_max() / 3600 << "h" << endl;
    cout << "min timespan: " << t.elapsed_min() << "s" << endl;
    cout << "t elapsed: " << t.elapsed() / 3600 << "s" << endl;

    return 1;
}
