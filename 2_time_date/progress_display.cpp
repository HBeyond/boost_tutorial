#include <boost/progress.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace boost;
using namespace std;

int main(int argc, char* argv[]) {
    vector<string> v(100);
    ofstream fs("./progress_display test.txt");

    progress_display pd(v.size());

    // 1. normal display method
    for (auto& val : v) {
        fs << val << endl;
        ++pd;
    }

    // 2. but there may be some chaos
    v[23] = "";
    v[88] = "";
    // chaos situation
    //    for (auto pos = v.begin(); pos != v.end(); ++pos) {
    //        fs << *pos << endl;
    //        ++pd;
    //        if (pos->empty()) {
    //            cout << "null string # " << (pos - v.begin()) << endl;
    //        }
    //    }

    // 3. solution
    for (auto pos = v.begin(); pos != v.end(); ++pos) {
        fs << *pos << endl;

        pd.restart(v.size());         // !
        pd += (pos - v.begin() + 1);  // !
        cout << endl;                 // !

        if (pos->empty()) {
            cout << "null string # " << (pos - v.begin()) << endl;
        }
    }

    return 1;
}
