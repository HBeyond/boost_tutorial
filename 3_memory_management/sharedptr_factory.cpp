#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class abstract {
   public:
    virtual void f() = 0;
    virtual void g() = 0;

   protected:
    virtual ~abstract() = default;
};

class impl : public abstract {
   public:
    impl() = default;
    ~impl() override = default;

   public:
    void f() override { cout << "class impl f" << endl; }
    void g() override { cout << "class impl g" << endl; }
};

shared_ptr<abstract> create() { return make_shared<impl>(); }  // factory function, return the implement class pointer

int main(int argc, char* argv[]) {
    auto p = create();
    p->f();
    p->g();

    //    abstract* q = p.get();
    //    delete q;    // wrong, cannot all the ~abstract() under protected

    return 1;
}
