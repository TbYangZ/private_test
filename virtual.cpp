#include <iostream>
#include <cstring>
using namespace std;
struct A {
    void f() {
        cout << "A" << endl;
    }
};

struct B : A {
    void f() {
        cout << "B" << endl;
    }
    void g() {
        f();
    }
};
void f(A& a) { a.f(); }

struct C {
    virtual void f() { cout << "C" << endl; }
};

struct Creature {
    virtual void walk() = 0;
};

struct Human : Creature {
    void walk() { cout << "Human Walk" << endl; }
};
struct Monkey : Creature {
    void walk() { cout << "Monkey Walk" << endl; }
};
struct Dog : Creature {
    void walk() { cout << "Dog Walk" << endl; }
};

int main() {
    Human human;
    Monkey monkey;
    Dog dog;
    human.walk();
    monkey.walk();
    dog.walk();
    return 0;
}