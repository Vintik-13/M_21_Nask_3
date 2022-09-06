/*Задание 3. Реализация математического вектора
Что нужно сделать
Реализуйте структуру двумерного математического вектора и основные
операции над ним. Обе координаты вектора (x и y) должны быть
вещественными числами.
В начале программы пользователь вводит команду, которая соответствует
требуемой операции. Далее, в зависимости от операции, пользователь
вводит её аргументы. Это могут быть как векторы, так и обычные,
скалярные значения. В результате в стандартный вывод помещается результат.
Это тоже может быть или вектор, или скаляр.
Реализуйте следующие операции в виде отдельных функций:
сложение двух векторов — команда add;
вычитание двух векторов — команда subtract;
умножение вектора на скаляр — команда scale;
нахождение длины вектора — команда length;
нормализация вектора — команда normalize.*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

struct myVector {
    float x{ 0 };
    float y{ 0 };
};

myVector inputV() {
    float x{ 0 };
    float y{ 0 };
    std::cout << "Enter the X coordinate: ";    
    std::cin >> x;
    std::cout << "Enter the Y coordinate: ";
    std::cin >> y;
    myVector tmp; tmp.x = x; tmp.y = y;
    return tmp;
}

void showVector(const myVector& a) {
    std::cout << "{" << a.x << ", " << a.y << "}";
}

myVector addVectors(const myVector& a, const myVector& b) {
    myVector tmp; 
    tmp.x = a.x + b.x;
    tmp.y = a.y + b.y;
    return tmp;
}

myVector subtractVectors(const myVector& a, const myVector& b) {
    myVector tmp;
    tmp.x = a.x - b.x;
    tmp.y = a.y - b.y;
    return tmp;
}

myVector scaleVector(const myVector& a, int b) {
    myVector tmp;
    tmp.x = a.x * b;
    tmp.y = a.y * b;
    return tmp;
}

int lengthVector(const myVector& a) {
    int tmp = std::sqrt(std::pow(a.x, 2) + std::pow(a.y, 2));
    return tmp;
}

myVector normalize(const myVector& a) {
    myVector tmp;
    tmp.x = a.x / lengthVector(a);
    tmp.y = a.y / lengthVector(a);
    return tmp;
}

void addCommand() {
    std::cout << "Enter the coordinates of vector a:\n";
    myVector a = inputV();
    std::cout << "Enter the coordinates of vector b:\n";
    myVector b = inputV();
    myVector c = addVectors(a, b);
    std::cout << "The sum of vectors a and b is equal "; showVector(c);
}

void subtractCommand() {
    std::cout << "Enter the coordinates of vector a:\n";
    myVector a = inputV();
    std::cout << "Enter the coordinates of vector b:\n";
    myVector b = inputV();
    myVector c = subtractVectors(a, b);
    std::cout << "The difference between vectors a and b is even "; showVector(c);
}

void scaleCommand() {
    std::cout << "Enter the coordinates of vector a:\n";
    myVector a = inputV();
    std::cout << "Enter a scalar number b:\n";
    int b;
    std::cin >> b;
    a = scaleVector(a, b);
    std::cout << "Multiplying the vector a by the number b is equal to "; showVector(a);
}

void lengthVectorComand() {
    std::cout << "Enter the coordinates of vector a:\n";
    myVector a = inputV();    
    std::cout << "The length of the vector a is even " << lengthVector(a);
}

void normalizeComand() {
    std::cout << "Enter the coordinates of vector a:\n";
    myVector a = inputV();
    myVector tmp = normalize(a);
    std::cout << "The normalized vector a is equal to "; showVector(tmp);
}

int position(const std::vector <std::string>& pattern, std::string comand) {
    std::transform(comand.begin(), comand.end(), comand.begin(), ::tolower);
    int pos{ -1 };
    for (int i = 0; i < pattern.size(); i++) {
        if (pattern[i] == comand) 
            pos = i;        
    }
    return pos < 0 ? -1 : pos;        
}

int main()
{
    std::vector <std::string> pattern{ "add", "subtract", "scale", "length", "normalize" };

    std::cout << R"(add
subtract
scale
length
normalize
Enter the command: )";
    std::string comand;
    std::getline(std::cin, comand);
    int int_com = position(pattern, comand);
    switch (int_com)
    {
    case 0:
        addCommand();
        break;
    case 1:
        subtractCommand();
        break;
    case 2:
        scaleCommand();
        break;
    case 3:
        lengthVectorComand();
        break;
    case 4:
        normalizeComand();
        break;
    default:
        std::cout << "Incorrect comand!";
        break;
    }
        
}
