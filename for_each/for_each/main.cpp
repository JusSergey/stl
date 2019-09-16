#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
using std::vector;
using std::list;
using std::string;
using std::for_each;
using std::cout;
using std::endl;

void func(int num)
{
    cout << "func num: " << num << endl;
}

auto lambda = [](int &num)
{
    cout << "lambda num: " << num << endl;
    num = 0;
};

class Callback
{
public:
    void operator() (int num)
    {
        cout << "callback num: " << num << endl;
    }
};

void example_vector()
{
    vector<int> numbers {5, 2, 7, 9};
    for_each(numbers.begin(), numbers.end(), func);
    cout << " * * * " << endl;
    for_each(numbers.begin(), numbers.end(), lambda);
    cout << " * * * " << endl;
    Callback c;
    for_each(numbers.begin(), numbers.end(), c);
}

void example_list()
{
    list<string> names {"Jack", "Mike", "Bob"};
    for_each(names.begin(), names.end(), [] (string name) { cout << "name is " << name << endl; });
}

int main()
{
    example_vector();
    example_list();
    return 0;
}
