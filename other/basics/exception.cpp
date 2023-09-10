#include <iostream>

class ZeroDivisionError : public std::runtime_error {
    public:
        ZeroDivisionError() : std::runtime_error("Division by zero is not allowed") {}
};

template <typename T, typename U>

auto divide(T n1, U n2) {
    if (n2 == 0) {
        throw ZeroDivisionError();
    }
    return n1/n2;
}

int main()
{
    using namespace std;
    
    try 
    {
        int r1 = divide(4, 1);
        double r2 = divide(7.3, 0);
        cout << "Result1: " << r1 << endl << "Result2: " << r2 << endl;
    }
    
    catch (ZeroDivisionError& e) 
    {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}