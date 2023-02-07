#include<iostream>
using namespace std;

class BASE {
    public:
        virtual void vir_func(void){
            cout << __func__ << ", class BASE" << endl;
        }
        virtual void func(void){
            cout << __func__ << ", class BASE" << endl;
        }
};

class C: public BASE {
    public:
        void vir_func(void){
            cout << __func__ << ", class C" << endl;
        }
        void func(void){
            cout << __func__ << ", class C" << endl;
        }
};

class D: public BASE {
    public:
        void vir_func(void){
            cout << __func__ << ", class D" << endl;
        }
        void func(void){
            cout << __func__ << ", class D" << endl;
        }
};

typedef void (*fp)();
fp get_address(void *obj, unsigned int addr){
    cout << "---------------------------" << endl;
    void *vptr_addr = (void *)*(unsigned int*)obj;
    cout << "vptr_addr = " << hex << vptr_addr << endl;

    cout << "vTable_base = " << hex << (void *)*(unsigned int*)vptr_addr << endl;

    void *func_addr = (void *)*((unsigned int*)vptr_addr + addr);
    cout << "func_addr = " << hex << func_addr << endl;
    return (fp)func_addr;
}

int main(){
    BASE *baseOne = new BASE();
    BASE *c = new C();
    BASE *d = new D();

    baseOne->vir_func();
    baseOne->func();
    c->vir_func();
    c->func();
    d->vir_func();
    d->func();

    fp fp_1;
   
    fp_1 = get_address(baseOne, 0);
    fp_1();
    fp_1 = get_address(baseOne, 1);
    fp_1();
   
    fp_1 = get_address(c, 0);
    fp_1();
    fp_1 = get_address(c, 1);
    fp_1();

    fp_1 = get_address(d, 0);
    fp_1();
    fp_1 = get_address(d, 1);
    fp_1();


    system("pause");
    return 0;
}