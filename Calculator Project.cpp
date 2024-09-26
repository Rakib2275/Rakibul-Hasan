#include <iostream>
#include <cmath> //what is cmath
                //In C++, the <cmath> header provides a set of mathematical functions that you can use to perform various mathematical operations.
                // It includes functions for basic arithmetic, trigonometric functions, logarithms, and more. Here's a basic overview of how you can use <cmath> in C++:

using namespace std;
//In C++, the using namespace std; directive allows you to avoid prefixing standard library names with std::. While it can simplify your code,
//it can also lead to potential issues, especially in larger programs or when working with multiple namespaces. Here’s a deeper look at when and
//why you might use or avoid using namespace std;:

class Calculator {
public:
    virtual double add(double a, double b) {
        return a + b;
    }

    virtual double subtract(double a, double b) {
        return a - b;
    }

    virtual double multiply(double a, double b) {
        return a * b;
    }

    virtual double divide(double a, double b) {
        if (b != 0) {
            return a / b;
        } else {
            cout << "Error: Division by zero!" << endl;
            return NAN;
        }
    }

    virtual ~Calculator() {}
};

class ScientificCalculator : public Calculator {
public:
    double squareRoot(double a) {
        if (a >= 0) {
            return sqrt(a);
        } else {
            cout << "Error: Cannot compute the square root of a negative number!" << endl;
            return NAN;
        }
    }

    double power(double base, double exponent) {
        return pow(base, exponent);
    }
};

class PythagoreanCalculator : public Calculator {
private:
    double a, b;

public:
    PythagoreanCalculator(double a, double b) : a(a), b(b) {}

    double calculateHypotenuse() const {
        return sqrt(a * a + b * b);
    }

    void calculateNextIncrement() const {
        double hypotenuse = calculateHypotenuse();
        cout << "Hypotenuse of the right triangle with sides " << a << " and " << b << " is: " << hypotenuse << endl;

        int nextIncrement = static_cast<int>(ceil(hypotenuse));
        cout << "Next integer increment of the hypotenuse is: " << nextIncrement << endl;
    }
};

int main() {
    Calculator basicCalc;
    ScientificCalculator sciCalc;
    PythagoreanCalculator pytha(3.0, 4.0); // Initialize with sides 3.0 and 4.0

    double a = 10.0, b = 5.0;

    cout << "Basic Calculator:" << endl;
    cout << "Addition: " << basicCalc.add(a, b) << endl;
    cout << "Subtraction: " << basicCalc.subtract(a, b) << endl;
    cout << "Multiplication: " << basicCalc.multiply(a, b) << endl;
    cout << "Division: " << basicCalc.divide(a, b) << endl;

    cout << "\nScientific Calculator:" << endl;
    cout << "Square Root of 16: " << sciCalc.squareRoot(16) << endl;
    cout << "2 to the power of 3: " << sciCalc.power(2, 3) << endl;

    cout << "\nPythagorean Calculator:" << endl;
    pytha.calculateNextIncrement(); // Use the PythagoreanCalculator

    return 0;
}
