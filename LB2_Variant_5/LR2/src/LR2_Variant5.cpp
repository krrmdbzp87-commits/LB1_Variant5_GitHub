#include <cassert>
#include <iostream>

constexpr int BASE_MIN = 0;
constexpr int BASE_MAX = 100;
constexpr int ABSENCES_MIN = 0;
constexpr int ABSENCES_MAX = 10;
constexpr int STUDY_DAY_LIMIT = 30;
constexpr int THRESHOLD = 50;

int calculateM(int base, int absences) {
    int raw = base - 3 * absences;
    if (raw < 0) {
        return 0;
    }
    return raw;
}

const char* categoryFor(int m) {
    if (m >= THRESHOLD) {
        return "поріг досягнуто";
    }
    return "нижче порогу";
}

bool isSearchMatch(int m) {
    return m >= THRESHOLD;
}

bool readValidRecord(int recordNumber, int& base, int& absences) {
    while (true) {
        std::cout << "Запис " << recordNumber
                  << " (база, пропуски; база 0..100, пропуски 0..10): ";

        if (!(std::cin >> base >> absences)) {
            return false;
        }

        if (base < BASE_MIN || base > BASE_MAX ||
            absences < ABSENCES_MIN || absences > ABSENCES_MAX) {
            std::cerr << "Помилка діапазону. Повторіть увесь запис.\n";
            continue;
        }
        return true;
    }
}

int main() {
    // Unit checks for pure functions. These do not replace input validation.
    assert(calculateM(74, 4) == 62);
    assert(calculateM(40, 2) == 34);
    assert(calculateM(50, 0) == 50);
    assert(calculateM(10, 10) == 0);
    assert(isSearchMatch(50));
    assert(!isSearchMatch(49));

    int recordCount = 0;
    while (true) {
        std::cout << "Кількість записів N (1..30): ";
        if (!(std::cin >> recordCount)) {
            std::cerr << "Помилка формату або кінець вводу для N. "
                         "Підсумок не сформовано.\n";
            return 1;
        }
        if (recordCount >= 1 && recordCount <= STUDY_DAY_LIMIT) {
            break;
        }
        std::cerr << "N має бути в межах 1..30. Введіть N ще раз.\n";
    }

    long long sum = 0;
    int minimum = 0, maximum = 0;
    int minimumRecord = 0, maximumRecord = 0;
    int matchCount = 0, firstMatch = 0;

    for (int i = 1; i <= recordCount; ++i) {
        int base = 0, absences = 0;
        if (!readValidRecord(i, base, absences)) {
            std::cerr << "Помилка формату або кінець вводу під час читання запису. "
                         "Підсумок не сформовано.\n";
            return 1;
        }

        int m = calculateM(base, absences);
        bool match = isSearchMatch(m);

        if (i == 1) {
            sum = m;
            minimum = m;
            maximum = m;
            minimumRecord = i;
            maximumRecord = i;
        } else {
            sum += m;
            if (m < minimum) {
                minimum = m;
                minimumRecord = i;
            }
            if (m > maximum) {
                maximum = m;
                maximumRecord = i;
            }
        }

        if (match) {
            ++matchCount;
            if (firstMatch == 0) {
                firstMatch = i;
            }
        }

        std::cout << "  m=" << m << "; категорія: " << categoryFor(m)
                  << "; пошук: " << (match ? "так" : "ні") << "\n";
    }

    double average = static_cast<double>(sum) / recordCount;

    std::cout << "\nПІДСУМОК:\n"
              << "Сума: " << sum << "\n"
              << "Середнє: " << average << "\n"
              << "Мінімум: " << minimum << " (запис " << minimumRecord << ")\n"
              << "Максимум: " << maximum << " (запис " << maximumRecord << ")\n"
              << "Кількість збігів: " << matchCount << "\n"
              << "Перший збіг: ";

    if (firstMatch == 0) {
        std::cout << "немає\n";
    } else {
        std::cout << firstMatch << "\n";
    }

    return 0;
}