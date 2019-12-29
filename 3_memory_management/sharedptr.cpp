#include <iostream>
#include <memory>

using namespace std;

class shared {
   private:
    shared_ptr<int> p_;

   public:
    shared(shared_ptr<int> p) : p_(p) {}
    void print() { cout << "count: " << p_.use_count() << ", v = " << *p_ << endl; }
};

void print_func(shared_ptr<int> p) { cout << "count: " << p.use_count() << ", v = " << *p << endl; }

int main(int argc, char* argv[]) {
    // definition, count + 1 = 1
    // shared_ptr<int> p(new int(100));  // original mode
    auto p = make_shared<int>(100);  // factory mode, avoid using new, and faster
    // create 2 instances, count + 2 = 3
    shared s1(p), s2(p);

    cout << "when *p = 100:" << endl;
    s1.print();
    s2.print();

    *p = 20;
    cout << "when *p = 20:" << endl;
    // copy in function print_func(), count + 1 = 4
    print_func(p);
    // function ends, auto erase the copy one, count - 1 = 3
    s1.print();
    s2.print();

    return 1;
}
