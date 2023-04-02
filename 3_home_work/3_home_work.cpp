#include <iostream>
#include <vector>

template<class T>
class unique {
private:
    T* t;

public:
    unique& operator= (const unique&) = delete;
    unique(const unique&) = delete;
    unique(const T& t_) : t{ new T{t_} } {};
    ~unique() {
            delete t;     
    }

    T& operator*() const {
        return *t;
    }
    T* release() {
        T* r = t;
        t = nullptr;
        return r;
    }


};



int main()
{
    std::vector<int> arr;
    std::vector<int> arr_2;

    unique<std::vector<int>> U(arr);
    unique<std::vector<int>> U_2(arr_2);

    

    std::cout << "adress arr =" << &(*U);
    std::cout << std::endl;
    std::cout << "adress arr_2 =" << &(*U_2);
    std::cout << std::endl;
    
     auto qq = U.release();
     auto qq_2 = U_2.release();

     std::cout << std::endl;
     std::cout << "adress arr =" << &(*U);
     std::cout << std::endl;
     std::cout << "adress arr_2 =" << &(*U_2);
     std::cout << std::endl;
     std::cout << "adress qq =" << qq;
     std::cout << std::endl;
     std::cout << "adress qq_2 =" << qq_2;

}

