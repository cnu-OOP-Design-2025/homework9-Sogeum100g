#include <iostream>
#include <string>
#include <list>
using namespace std;

// MyIntVector를 템플릿으로 일반화하여 MyVector 클래스 구현
// void resize(), void push_back(const int& value), int pop_back()
// int& operator[](const int index), size_t size()
template<typename T>
class MyVector {
/* TODO */
private:
    T* data;
    size_t capacity;
    size_t length;

    




    
    void resize() {
        cout << "Resize: " << capacity << " -> " << capacity * 2 << endl;

        /* TODO */
        // capacity의 크기를 2배로 늘리고, 새로운 배열을 생성하세요.
        // 기존 데이터를 새로운 배열로 복사한 뒤, 기존 배열을 해제하세요.

        capacity *= 2;
        T* newData = new T[capacity];
        
        for (int i = 0; i < length; ++i) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
    }    

public: 

    // 초기 capacity를 2로 설정하고, length는 0으로 초기화하세요.
    MyVector() : capacity(2), length(0) {
        /* TODO */
        // data는 capacity 크기의 배열을 동적 할당하세요.
        data = new T[capacity];
    }
    
    ~MyVector() {
        delete[] data;
    }
    
    void push_back(T value) {
        if (length == capacity) {
            resize();
        }
        data[length] = value;
        length++;        
    }
    
    T pop_back() {
        if (length == 0)
            throw out_of_range("Vector is empty");
        return data[--length]; // 마지막 요소 제거
    }

    T& operator[](const int index){
        return data[index];
    }
    
    // 현재 저장된 요소 개수를 반환하세요.
    size_t size() const {
        return length;
    }    
};




template<typename T>
void testVector(const string& name, std::list<T> values) {

    cout << "------------------" << endl;
    MyVector<T> vec;
    for (auto& v : values)
        vec.push_back(v);

    cout << name << ": ";
    for (size_t i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";

    cout << endl;
    while(vec.size())
        cout << "Pop: " << vec.pop_back() << "\n";
}

int main() {
    testVector<int>("IntVec", {1, 2, 3, 4, 5, 6});
    testVector<double>("DoubleVec", {1.1, 2.2, 3.3, 4.4, 5.5});
    testVector<char>("CharVec", {'A', 'B', 'C', 'D', 'E', 'F'});
    testVector<string>("StringVec", {"Hello", "World", "C++", "Template", "Vector"});
    return 0;
}
