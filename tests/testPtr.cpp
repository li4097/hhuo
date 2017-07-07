#include <iostream>

using namespace std;

#include <memory>

class A;
class B;

typedef std::shared_ptr<A> APtr;
typedef std::shared_ptr<B> BPtr;
typedef std::weak_ptr<A> AWeakPtr;
typedef std::weak_ptr<B> BWeakPtr;

class A
{
public:
    BWeakPtr b;

    ~A()
    {
        cout << "A released" << endl;
    }
};

class B
{
public:
    AWeakPtr a;

    ~B()
    {
        cout << "B released" << endl;
    }
};

class Widget
{
public:
    Widget()
    {
        cout << "construct Widget!!!" << endl;
    }

    ~Widget()
    {
        cout << "destruct Widget!!!" << endl;
    }
};

void foo(int* p)
{
    std::cout << *p << std::endl;
}

void fo(std::shared_ptr<int> p, int init)
{
    *p = init;
}

int main()
{
    cout << "//////////shared_ptr////////////////" << endl;
    {
        auto it = std::shared_ptr<Widget>(new Widget);
    }
    cout << "//////////shared_ptr////////////////" << endl;

    cout << "//////////weak_ptr////////////////" << endl;
    {
        APtr a(new A());
        BPtr b(new B());
        a->b = b;
        b->a = a;
    }
    cout << "//////////weak_ptr////////////////" << endl;

    cout << "//////////unique_ptr////////////////" << endl;
    {
        std::unique_ptr<int> p1(new int(42));
        std::unique_ptr<int> p2 = std::move(p1); // transfer ownership

        if (p1)
            foo(p1.get());

        (*p2)++;

        if (p2)
            foo(p2.get());
    }
    {
        fo(std::shared_ptr<int>(new int(42)), 1);

        auto p = std::make_shared<int>(42);
        auto y = p;
        if (y == p)
            std::cout << "ok" << std::endl;
        std::weak_ptr<int> wp = p;
        {
            auto sp = wp.lock();
            std::cout << *sp << std::endl;
        }
        p.reset();
        if(wp.expired())
            std::cout << "expired" << std::endl;
        cout << *y << endl;
    }
    cout << "//////////unique_ptr////////////////" << endl;
    return 0;
}