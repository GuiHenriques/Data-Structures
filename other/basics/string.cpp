#include <iostream>

int main()
{
    using namespace std;

    string name;

    cout << "Name: ";
    getline(cin, name);

    /* cout << name << " has " << name.length() << " characters" << '\n';
     name.append("eee");
    if (name.empty())
        cout << "Empty name";
    else
        cout << "Hi " << name;
    name.insert(3, "mary");
    name.clear()*/
    cout << name;
}