#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

namespace my {
    enum eNums{ZERO, ONE};

    const int GLOBAL = 5;

    int func();

    void funcPrint();

    class Fruit {
    public:
        Fruit() = default;

        virtual int justVirtual()noexcept {
            return 5;
        }

        virtual void getInfo() = 0;
    };

    class Apple : protected Fruit {
        float appleValue;
    public:
        Apple()
                : Fruit() {
            appleValue = 3.5f;
        }
    protected:
        int getAppleValue()const{
            return (int)appleValue;
        }
    public:
        virtual void getInfo() override {
            cout << "Apple";
        }
    };

    class Orange : public Fruit {
        int orangeField;

    protected:
        Orange()
                : Fruit() {
            orangeField = 6;
        }

    public:
        virtual void getInfo() override {
            cout << "Orange";
        }

    protected:
        int OrangeFunc(int num) const{
            return num * orangeField;
        }
    };

    class Mutant : virtual Apple, Orange {
        int var;
        explicit Mutant(const int &var)
                : Apple(), Orange() {
            this->var = var;
        }

        virtual void getInfo() override {
            cout << "Mutant";
        }

        template<class T>
        T* getSmth(T &obj){
            return obj;
        }

        inline int getBoth() const{
            int a = OrangeFunc(3);
            int b = getAppleValue();
            return a+b;
        }

    };
    template<class T>
    class myStatic{
    public:
        class myException : public std::exception{};
        static int getVar(T obj, int num)noexcept(false){
            int var = num;
            for(int i = 0; i < 10; ++i){
                var++;
                if(var < 10){
                    var--;
                }else if(var == 10){
                    throw myException();
                }else{
                    var++;
                }
            }
                return var;
        }
    };
};

const int& func1(const int& num){return num;}
const int* func2(const int* num){return num;}
int& func3(int& num){return num;}
const int func4(const int num){return num;}
int func5(int&& num){return num;}
const int func6(const int&& num){return num;}


int main() {
    int var;
    var = 3;
    int &ref = var;
    int *pointer;
    pointer = &var;
    var = *pointer;

    auto *apple = new my::Apple;
    apple->getInfo();
    delete apple;
    try {
        var = my::myStatic<int>::getVar(2, 2);
    }catch (my::myStatic<int>::myException()){
        cout << "exc";
    }catch(exception){

    }
    vector<int> vector{1,4,6,3,6};
    for(auto i : vector)cout << i;
    for_each(vector.begin(), vector.end(), [](const int &val)mutable {
        cout << val;
    });
    func1(var);
    func2(&var);
    func3(var);
    func4(var);
    func5(3);
    func6(4);

    do{
        break;
    }while(true);

    switch (my::eNums::ONE) {
        case 1:
            break;
        default:
            break;
    }
    ll lon = 4;
    while(lon > 0){
        lon--;
    }
    return 0;
}

int my::func() {
    return my::GLOBAL;
}

void my::funcPrint() {
    cout << my::func();
}