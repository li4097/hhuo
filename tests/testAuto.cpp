#include <vector>
#include <typeinfo>
#include <iostream>
#include <algorithm>
using namespace std;

template <class T, class U>
auto Multiply(T t, U u) -> decltype(t * u)
{
    return t * u;
}

int main(int argc, char *argv[])
{
    auto a = 10;
    typeof(a) x = static_cast<float >(a);
    std::cout << x << " typeis: " << typeid(x).name() << std::endl;

    vector<int > vector1;
    vector1.push_back(1);
    for (auto &it: vector1)
    {
        cout << it << endl;
    }
    cout << "for (auto &it: vector1) end" << endl;

    for_each(vector1.begin(), vector1.end(), [](int v){
        cout << v << endl;
    });
    for_each(vector1.begin(), vector1.end(), [=](int v){
        cout << v << endl;
    });
    for_each(vector1.begin(), vector1.end(), [&](int v) mutable{
        cout << v << endl; a++;
    });
    cout << a << endl;
    for_each(vector1.begin(), vector1.end(), [a](int v) mutable{
        cout << v << endl; a++;
    });
    cout << a << endl;
    for_each(vector1.begin(), vector1.end(), [&a](int v) mutable{
        cout << v << endl; a++;
    });
    cout << a << endl;
    for_each(vector1.begin(), vector1.end(), [=, &x](int v) mutable{
        cout << v << endl; x++;a++;
    });
    cout << x << " " << a << endl;

    auto ptr = []()
    {
        std::cout << "hello world" << std::endl;
    };

    ptr();

    std::cout << Multiply(0.2, 100) << std::endl;
    return 0;
}