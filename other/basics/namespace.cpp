#include <iostream>

namespace first {
    int x = 1;
}

namespace second {
    int x = 2;
}

int main()
{
    using namespace std;
    using namespace first;
    // int x = 0;
    
    cout << x << endl; // 0
    cout << second::x << endl; // 2
}