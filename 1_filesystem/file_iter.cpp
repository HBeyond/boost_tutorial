#include <string.h>
#include <boost/filesystem.hpp>
#include <iostream>
#include <vector>

using namespace boost::filesystem;
using namespace std;

int main(int argc, char* argv[]) {
    //    string image_path =
    //        "/home/beyoung/Desktop/mac-ubuntu-share/work/0_Mine/14_boost/boost_tutorial/1_filesystem/NormalImages";
    //    path file_path(image_path);

    //    if (!exists(file_path)) {
    //        cout << "file path not exists" << endl;
    //    }

    //    directory_iterator end;

    //    for (directory_iterator pos(file_path); pos != end; ++pos) {
    //        remove(*pos);
    //    }

    vector<int> a(10);
    //    a.emplace_back(0);
    //    a.emplace_back(1);

    a[-1] = 0;

    return 1;
}
