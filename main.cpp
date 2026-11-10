#include <iostream>
#include <string>
#include <sstream>
#include <clocale>

using namespace std;

// Перечисление для доступных операций
enum class Operation {
    ADD,
    SUBTRACT,
    MULTIPLY,
    UNKNOWN
};

// Структура для хранения вектора (x, y)
struct Vector2D {
    double x;
    double y;
};

// Docstring: Преобразует введенный пользователем символ операции в enum.
Operation parseOperation(const string& opStr) {
    if (opStr == "+") return Operation::ADD;
    if (opStr == "-") return Operation::SUBTRACT;
    if (opStr == "*") return Operation::MULTIPLY;
    return Operation::UNKNOWN;
}

// Docstring: Извлекает числа из строки формата "(x;y)" и сохраняет их в вектор.
Vector2D parseVector(const string& input) {
    Vector2D v = {0, 0};
    string cleanStr = input;

    for (char& c : cleanStr) {
        if (c == '(' || c == ')' || c == ';') {
            c = ' ';
        }
    }

    stringstream ss(cleanStr);
    ss >> v.x >> v.y;
    return v;
}

// Docstring: Функция сложения двух векторов.
Vector2D addVectors(Vector2D a, Vector2D b) {
    return {a.x + b.x, a.y + b.y};
}

// Docstring: Функция вычитания двух векторов.
Vector2D subtractVectors(Vector2D a, Vector2D b) {
    return {a.x - b.x, a.y - b.y};
}

// Docstring: Функция умножения вектора на скаляр.
Vector2D multiplyVectors(Vector2D a, Vector2D b) {
    return {a.x * b.x, a.y * b.x};
}

// Docstring: Выводит вектор в красивом формате (x;y).
void printVector(Vector2D v) {
    cout << "(" << v.x << ";" << v.y << ")" << endl;
}

int main() {
    // Жесткая установка русской кодировки, которая работает на твоем ПК
    setlocale(LC_ALL, "Russian");

    string vecAStr, vecBStr, opStr;
    Vector2D a, b, result;
    Operation op;

    cout << "=== КАЛЬКУЛЯТОР ВЕКТОРОВ ===" << endl;

    cout << "Введите вектор a (например, (1;2)): ";
    cin >> vecAStr;

    cout << "Введите вектор b (например, (3;4)): ";
    cin >> vecBStr;

    cout << "Введите операцию (+, -, *): ";
    cin >> opStr;

    a = parseVector(vecAStr);
    b = parseVector(vecBStr);
    op = parseOperation(opStr);

    switch (op) {
        case Operation::ADD:
            result = addVectors(a, b);
            break;
        case Operation::SUBTRACT:
            result = subtractVectors(a, b);
            break;
        case Operation::MULTIPLY:
            result = multiplyVectors(a, b);
            break;
        case Operation::UNKNOWN:
        default:
            cout << "Ошибка: неизвестная операция!" << endl;
            return 1;
    }

    cout << "\nc=";
    printVector(result);

    return 0;
}
