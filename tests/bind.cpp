#include <iostream>
#include <memory>
#include <functional>
#include <string.h>

using namespace std;

int add1(int i, int j, int k)
{
    return i + j + k;
}

class Utils
{
public:
    Utils(const char *name)
    {
        strcpy(_name, name);
    }

    void sayHello(const char *name, int i) const
    {
        std::cout << _name << " say: hello " << name << std::endl;
    }

    static int getId()
    {
        return 10001;
    }

    int operator()(int i, int j, int k) const
    {
        return i + j + k;
    }

private:
    char _name[32];
};

int main(int argc, char *argv[])
{
    auto fun = std::bind(add1, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    cout << fun(1, 2, 3) << endl;

    Utils utils("Vicky");
    std::function<void(const char *name, int)> sayHello = std::bind(&Utils::sayHello, utils, std::placeholders::_1, std::placeholders::_2);
    sayHello("Jack", 10);
    return 0;
}