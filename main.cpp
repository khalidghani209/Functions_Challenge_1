#include <iostream>
#include <limits>

using namespace std;

const double PI = 3.14159;

// Function Prototypes
double calculateArea(const double radius);
double calculateArea(const double length, const double width);
double calculatePerimeter(const double radius);
double calculatePerimeter(const double length, const double width);
void clearInputError();

int main() {
    int choice;
    double radius, length, width;

    do {
        cout << "\n--- Geometric Calculations Menu ---\n";
        cout << "1. Area of a Circle\n";
        cout << "2. Perimeter of a Circle\n";
        cout << "3. Area of a Rectangle\n";
        cout << "4. Perimeter of a Rectangle\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Input validation for menu
        if (cin.fail() || choice < 1 || choice > 5) {
            clearInputError();
            cout << "Invalid choice. Please enter a number between 1 and 5.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter radius: ";
                cin >> radius;
                if (cin.fail() || radius <= 0) { clearInputError(); cout << "Invalid radius.\n"; break; }
                cout << "Area of Circle: " << calculateArea(radius) << "\n";
                break;
            case 2:
                cout << "Enter radius: ";
                cin >> radius;
                if (cin.fail() || radius <= 0) { clearInputError(); cout << "Invalid radius.\n"; break; }
                cout << "Perimeter of Circle: " << calculatePerimeter(radius) << "\n";
                break;
            case 3:
                cout << "Enter length and width (separated by space): ";
                cin >> length >> width;
                if (cin.fail() || length <= 0 || width <= 0) { clearInputError(); cout << "Invalid dimensions.\n"; break; }
                cout << "Area of Rectangle: " << calculateArea(length, width) << "\n";
                break;
            case 4:
                cout << "Enter length and width (separated by space): ";
                cin >> length >> width;
                if (cin.fail() || length <= 0 || width <= 0) { clearInputError(); cout << "Invalid dimensions.\n"; break; }
                cout << "Perimeter of Rectangle: " << calculatePerimeter(length, width) << "\n";
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}

// Clears the input buffer to prevent infinite loops on bad input
void clearInputError() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Overloaded Functions
double calculateArea(const double radius) {
    return PI * radius * radius;
}

double calculateArea(const double length, const double width) {
    return length * width;
}

double calculatePerimeter(const double radius) {
    return 2 * PI * radius;
}

double calculatePerimeter(const double length, const double width) {
    return 2 * (length + width);
}
