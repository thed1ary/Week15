#include <iostream>
#include <vector>
#include <string>
#include <memory>


class Shape {
protected:
    std::string color;
    
public:
    // TASK 1: Implement the constructor to initialize the 'color' attribute.
    Shape(const std::string& color) : color(color) {}
    
    // TASK 2: Define the pure virtual function for drawing, named 'draw'.
    virtual void draw() const = 0;
    
    // TASK 3. Define a virtual destructor.
    // Inside, print: "Base (Shape) destructor for 'color'.
    virtual ~Shape() {
        std::cout << "Base (Shape) destructor for " << color << std::endl;
    }

};


class Circle : public Shape {
private:
    double radius;
    
public:
    // TASK 4: Implement the Circle constructor. It must call the Base (Shape) constructor.
    Circle(const std::string& color, double r)
    : Shape(color), radius(r) {}
    
    // TASK 5: Implement the 'draw' function, using the 'override' keyword.
    // Inside, print: "'color' circle with radius 'radius'."
    void draw() const override {
        std::cout << color << " circle with radius " << radius << "." << std::endl;
    }
    
    // TASK 6: Include a derived destructor.
    // Inside, print: "Circle destructor."
    ~Circle() {
        std::cout << "Circle destructor." << std::endl;
    }

};


class Rectangle : public Shape {
private:
    double width, height;
    
public:
    // TASK 7: Implement the Rectangle constructor, calling the Base (Shape) constructor.
    Rectangle(const std::string& color, double width, double height)
    : Shape(color), width(width), height(height) {}
    
    // TASK 8: Implement the 'draw' function, using the 'override' keyword.
    // Inside, print: "'color' rectangle ('width' x 'height')."
    void draw() const override {
        std::cout << color << " rectangle (" << width << " x " << height << ")." << std::endl;
    }
    
    // TASK 9: Include a derived destructor.
    // Inside, print: "Rectangle destructor."
    ~Rectangle() {
        std::cout << "Rectangle destructor." << std::endl;
    }

};


int main() {
    std::vector<Shape*> canvas;

    // TASK 10: Create a "Red" Circle (with radius 5.0) and add its pointer to the canvas.
    // Use std::make_unique and push_back functions.
    Circle Red = Circle("Red", 5.0);
    canvas.push_back(&Red);
    
    // TASK 11: Create a "Blue" Rectangle (10.0 x 8.0) and add its pointer to the canvas.
    Rectangle Blue = Rectangle("Blue", 10.0, 8.0);
    canvas.push_back(&Blue);

    for (const auto& s : canvas) {
        // TASK 12: Call the draw method polymorphically.
        s->draw();
    }

    canvas.clear();

    // TASK 13: Delete Memories
    Red.~Circle();
    Blue.~Rectangle();

    return 0;
}
