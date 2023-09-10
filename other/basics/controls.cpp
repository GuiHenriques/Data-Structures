#include <iostream>

int main()
{
    using namespace std;

    int age;
    string name;

    do {
        // cout << age << endl;
        cout << "Age: ";
        cin >> age;
    } while (age < 0);

    cout << "Name: ";
    getline(cin >> ws, name);

    cout << "Hello " << name << endl;
    
    if (age < 18)
        cout << "You are a minor." << endl;
    else if (age < 65)
        cout << "You are an adult." << endl;
    else
        cout << "You are a senior citizen." << endl;
}