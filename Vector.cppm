// /workspace/Vector.cppm

module;
#include <iostream>
export module Vector;



export class Vector {
public:
    Vector(double x, double y) : x_(x), y_(y) {}
    void print() const {
        std::cout << "Vector(" << x_ << ", " << y_ << ")" << std::endl;
    }
private:
    double x_, y_;
};

export void hello_vector() {
    std::cout << "Hello from Vector module!" << std::endl;
}

