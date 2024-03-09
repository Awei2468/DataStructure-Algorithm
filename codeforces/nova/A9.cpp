#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class A{
public:
    int *resA;
    A() {resA = new int[100]; g();}
    ~A() {delete resA; cout << "~A::A()" << endl;}
    void f() {cout << "A::f()" << endl;}
    virtual void g() {cout << "A::g()" << endl;}
};

class B : public A{
public:
    int *resB;
    B() {resB = new int[100]; g();}
    ~B() {delete resB; cout << "~B::B()" << endl;}
    void f() {cout << "B::f()" << endl;}
    void g() {cout << "B::g()" << endl;}
};

void run_and_release(A *pa) {
    pa->g();
    delete pa;
}

int main(){
    A *p = new B; //因為是new class B, 所以會先建parent constructor  //印出A::g() B::g() 
    p->f(); //印出A::f() 
    p->g(); //雖然p是指到A class, 但virtual function會吃class B  //印出B::g() 
    delete p; //印出~A::A()
    cout << "****" << endl; 

    B *p1 = new B; //印出A::g() B::g()
    run_and_release(p1); //因delete p1是指到class A, 所以解構時是看destructor A, 而virtual function會吃class B  //印出B::g() ~A::A()
    A *p2 = new A; //印出A::g()
    run_and_release(p2); //印出A::g() ~A::A()
    cout << "****" << endl;

    B q; //ok, parent class will contructor before child class, and child class will destructor before parent class 
    //印出A::g() B::g() ~B::B() ~A::A()
    
    return 0;
}