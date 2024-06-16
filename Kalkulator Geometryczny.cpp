#include <iostream>
#include <locale>
#include <cmath>
#include <string>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


class Circle {
public:
   
    Circle(double r) : radius(r) {}

    // obliczanie obwodu koła
    double getPerimeter() const {
        return 2 * M_PI * radius;
    }

    // obliczanie pola koła
    double getArea() const {
        return M_PI * radius * radius;
    }

private:
    double radius;
};

class Rectangle {
public:
   
    Rectangle(double l, double w) : length(l), width(w) {}

    // obliczanie obwodu prostokąta
    double getPerimeter() const {
        return 2 * (length + width);
    }

    // obliczanie pola prostokąta
    double getArea() const {
        return length * width;
    }

    // obliczanie przekątnej prostokąta
    double getDiagonal() const {
        return std::sqrt(length * length + width * width);
    }

private:
    double length;
    double width;
};

class Square {
public:
   
    Square(double s) : side(s) {}

    // obliczanie obwodu kwadratu
    double getPerimeter() const {
        return 4 * side;
    }

    // obliczanie pola kwadratu
    double getArea() const {
        return side * side;
    }

private:
    double side;
};


class IView {
public:
    // wyświetlanie komunikatów
    virtual void display(const std::string& message) = 0;

    // pobieranie danych od użytkownika
    virtual std::string getInput(const std::string& prompt) = 0;

   
    virtual ~IView() {}
};

class ConsoleView : public IView {
public:
    // Implementacja wyświetlania komunikatów
    void display(const std::string& message) override {
        std::cout << message << std::endl;
    }

    // Implementacja pobierania danych od użytkownika
    std::string getInput(const std::string& prompt) override {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        return input;
    }
};

class GeometryController {
public:
    
    GeometryController(IView* v) : view(v) {}

    // Główna metoda uruchamiająca pętlę programu
    void run() {
        while (true) {
            view->display("Wybierz figurę geometryczną:");
            view->display("1. Kwadrat");
            view->display("2. Prostokąt");
            view->display("3. Koło");
            view->display("4. Wyjście");

            std::string choice = view->getInput("Twój wybór: ");
            if (choice == "4") break;

            // Wywołanie odpowiednich metod w zależności od wyboru użytkownika
            if (choice == "1") {
                handleSquare();
            }
            else if (choice == "2") {
                handleRectangle();
            }
            else if (choice == "3") {
                handleCircle();
            }
            else {
                view->display("Nieprawidłowy wybór, spróbuj ponownie.");
            }
        }
    }

private:
    // obliczenia kwadratu
    void handleSquare() {
        double side = std::stod(view->getInput("Podaj długość boku: "));
        Square square(side);
        view->display("Obwód: " + std::to_string(square.getPerimeter()));
        view->display("Pole: " + std::to_string(square.getArea()));
    }

    // obliczenia prostokąta
    void handleRectangle() {
        double length = std::stod(view->getInput("Podaj długość: "));
        double width = std::stod(view->getInput("Podaj szerokość: "));
        Rectangle rectangle(length, width);
        view->display("Obwód: " + std::to_string(rectangle.getPerimeter()));
        view->display("Pole: " + std::to_string(rectangle.getArea()));
        view->display("Przekątna: " + std::to_string(rectangle.getDiagonal()));
    }

    // obliczemia koła
    void handleCircle() {
        double radius = std::stod(view->getInput("Podaj promień: "));
        Circle circle(radius);
        view->display("Obwód: " + std::to_string(circle.getPerimeter()));
        view->display("Pole: " + std::to_string(circle.getArea()));
    }

    IView* view;
};

// Funkcja główna
int main() {
   
    std::locale::global(std::locale("pl_PL.UTF-8"));
   
    ConsoleView view;
    GeometryController controller(&view);
    controller.run();
    return 0;
}