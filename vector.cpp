#include <iostream>
#include <stdexcept>

// Define a templated Vector class
template <typename T>
class Vector {
private:
    T* data;         // Pointer to the dynamic array
    size_t size;     // Current number of elements in the vector
    size_t capacity; // Current capacity of the vector

public:
    // Constructor
    Vector() : data(nullptr), size(0), capacity(0) {}

    // Destructor
    ~Vector() {
        delete[] data;
    }

    // Copy constructor
    Vector(const Vector& other) : size(other.size), capacity(other.capacity) {
        // Allocate memory for the new dynamic array
        data = new T[capacity];

        // Copy elements from the other vector to this vector
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Assignment operator
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            
            // Allocate memory for the new dynamic array
            data = new T[capacity];

            // Copy elements from the other vector to this vector
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Add an element to the end of the vector
    void push_back(const T& value) {
        if (size >= capacity) {
            if (capacity == 0) {
                capacity = 1;
            } else {
                capacity *= 2; // Double the capacity
            }

            // Create a new dynamic array with increased capacity
            T* new_data = new T[capacity];

            // Copy elements from the old array to the new array
            for (size_t i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }

            // Delete the old array and update the pointer
            delete[] data;
            data = new_data;
        }
        // Add the new element and increment the size
        data[size++] = value;
    }

    // Access an element at a specific index
    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Get the current size of the vector
    size_t getSize() const {
        return size;
    }
};

int main() {
    // Create a Vector of integers
    Vector<int> myVector;

    // Add elements to the vector
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);

    // Access elements using the subscript operator
    std::cout << "Vector elements: ";
    for (size_t i = 0; i < myVector.getSize(); ++i) {
        std::cout << myVector[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}