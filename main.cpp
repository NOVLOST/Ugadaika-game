#include <iostream>
#include <unordered_map>
#include <cstring>


int main()
{
    char in_char;
    char remind_word[256];
    std::unordered_map<char, bool> checker_dict;
    bool all_pos;

    std::cout << "Введите слово: ";
    std::cin >> remind_word;

    size_t len = strlen(remind_word);
    for (size_t i = 0; i < len; i++) {
        checker_dict[remind_word[i]] = false;
    }

    while (true) {
        std::cout << "Введите букву на угад: ";
        std::cin >> in_char;

        // Используем count() вместо contains()
        if (checker_dict.count(in_char)) {
            bool val = checker_dict.at(in_char);
            if (val == false) {
                checker_dict[in_char] = true;
                std::cout << "Буква угадана!\n";
            } else {
                std::cout << "Буква уже была угадана.\n";
            }
        } else {
            std::cout << "Вы ввели букву, которой нет в слове.\n";
        }

        // Используем std::all_of с итераторами вместо std::ranges::all_of
       for (const auto& pair : checker_dict)
            {
                all_pos = true;
                if (pair.second == false)
                {
                    all_pos = false;
                    break;
                }


            }

        if (all_pos) {
            std::cout << "Поздравляем! Все буквы угаданы!\n";
            break;
        }
    }

    return 0;
}
