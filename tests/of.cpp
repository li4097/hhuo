#include <iostream>
#include <memory>

using namespace std;

class B
{
public:
    virtual void f(int) /*final*/
    { std::cout << "B::f" << std::endl; }
};

class D : public B
{
public:
    virtual void f(int) override final
    { std::cout << "D::f" << std::endl; }
};

int fib(int n)
{
    return n <= 2 ? 1 : fib(n-1) + fib(n-2);
}
std::function<int(int)> lfib = fib;

enum class Options {None, One, All};

int main(int argc, char *argv[])
{
    {
        std::shared_ptr<B> b = std::shared_ptr<D>(new D);
        b->f(1);
    }
    Options o = Options::All;

    cout << lfib(5) << endl;
    return 0;
}