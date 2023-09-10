#include <iostream>

struct Student {
private:   
    std::string name;
    int age;
    char grade;

public:
    Student(std::string name, int age, char grade) : name(name), age(age), grade(grade) {}

    void display() {
        std::cout << "Name: " << name << ", Age: " << age << ", Grade: " << grade << std::endl;
    }
};


int main()
{
    Student p1("Gui", 18, 'A');

    p1.display();

    return 0;
}
