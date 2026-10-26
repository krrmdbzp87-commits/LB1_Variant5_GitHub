#include <algorithm>
#include <iostream>

int main() {
    int base = 0;
    int absences = 0;

    if (!(std::cin >> base >> absences)) {
        std::cerr << "Помилка введення: введіть два цілі числа (base absences).\n";
        return 1;
    }

    if (base < 0 || base > 100) {
        std::cerr << "Помилка: base має бути в межах від 0 до 100.\n";
        return 1;
    }

    if (absences < 0 || absences > 10) {
        std::cerr << "Помилка: absences має бути в межах від 0 до 10.\n";
        return 1;
    }

    const int penalty = 3 * absences;
    const int adjusted = std::max(0, base - penalty);

    std::cout << "Штраф: " << penalty << '\n';
    std::cout << "Скоригований результат: " << adjusted << '\n';

    if (adjusted < 50) {
        std::cout << "Нижче порога\n";
    } else {
        std::cout << "Поріг досягнуто\n";
    }

    return 0;
}