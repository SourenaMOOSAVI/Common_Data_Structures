#include <iostream>
#include <initializer_list>

template <typename T, size_t Size>
class MyArray {
private:
    T data[Size];

public:
    // Default Constructor
    MyArray() {
        for (size_t i = 0; i < Size; ++i) {
            data[i] = T(); // Initialize elements to default value
        }
    }

    // Constructor with initializer list
    MyArray(std::initializer_list<T> initList) {
        size_t i = 0;
        for (const T& value : initList) {
            if (i >= Size) break;
            data[i++] = value;
        }
    }

    // Accessor
    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }

    // Size accessor
    size_t size() const {
        return Size;
    }
};

int main() {
    MyArray<int, 5> intArray;

    // Fill the array with values
    for (size_t i = 0; i < intArray.size(); ++i) {
        intArray[i] = i * 10;
    }

    // Display the array elements
    std::cout << "Array elements: ";
    for (size_t i = 0; i < intArray.size(); ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    // Access a specific element
    std::cout << "Element at index 2: " << intArray[2] << std::endl;

    // Try modifying an element
    intArray[3] = 42;
    std::cout << "Modified element at index 3: " << intArray[3] << std::endl;

    // Test const accessor (reading)
    const MyArray<int, 3> constIntArray = {1, 2, 3};
    
    std::cout << "Const array elements: ";
    for (size_t i = 0; i < constIntArray.size(); ++i) {
        std::cout << constIntArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}