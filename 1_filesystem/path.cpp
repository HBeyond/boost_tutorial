#include <string.h>
#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;
using namespace std;

int main(int argc, char* argv[]) {
    string tmp = "/tmp";
    path parent;
    path path(tmp);
    // find the parent path
    if (path.has_parent_path()) {
        cout << "path has parent path" << endl;
        parent = path.parent_path();
        cout << "parent = " << parent << endl;
    }
    // find the name of last file or folder without extension name in the path
    if (path.has_stem()) {
        cout << "path has stem: " << path.stem().string() << endl;
    }
    // find the filename of last file or folder with extension name in the path
    if (!path.empty()) {
        cout << "path filepath: " << path.filename().string() << endl;
    }
    // iterator in this path
    directory_iterator end_iter;
    for (directory_iterator iter(path); iter != end_iter; ++iter) {
        // check with extension so filename is used
        string name = iter->path().filename().string();
        // get the extension of this file
        string extension_name = iter->path().extension().string();
        // cout << "name = " << name << endl;
        int ret = strcmp(name.c_str(), "SA-Result.tar.gz");
        if (ret == 0) {
            cout << iter->path().filename().string() << endl;
            cout << "the extension name is: " << extension_name << endl;

        } /*else {
            cout << "no SA-SA-Result.tar.gz is found" << endl;
        }*/
    }
    return 1;
}
