#include <stdio.h>


// Перевод из 10-й в 2-ю систему (с учетом дополнительного кода)
void to_binary(long long n) {
    if (n < -65535 || n > 65535) {
        printf("ERROR\n");
        return;
    }

    if (n == 0) {
        printf("00\n");
        return;
    }

    bool is_negative = (n < 0);
    if (is_negative) {
        n = -n;
    }

    bool bits[20] = {false};
    int len = 0;
    long long temp = n;

    while (temp > 0) {
        bits[len] = (temp % 2 == 1);
        temp /= 2;
        len++;
    }

    if (!is_negative) {
        printf("0");
        for (int i = len - 1; i >= 0; i--) {
            printf("%d", bits[i]);
        }
        printf("\n");
    } else {
        // Инвертируем биты (обратный код)
        for (int i = 0; i < len; i++) {
            bits[i] = !bits[i];
        }
        // Прибавляем 1 (дополнительный код)
        bool carry = true;
        for (int i = 0; i < len; i++) {
            bool current_bit = bits[i];
            bits[i] = current_bit ^ carry;
            carry = current_bit && carry;
        }
        printf("1");
        for (int i = len - 1; i >= 0; i--) {
            printf("%d", bits[i]);
        }
        printf("\n");
    }
}

// Перевод из 2-й в 10-ю систему
void to_decimal(char first, long long num) {
    // Первый символ в двоичной записи может быть только '0' или '1', а остаток >= 0
    if ((first != '0' && first != '1') || num < 0) {
        printf("ERROR\n");
        return;
    }

    bool is_negative = (first == '1');
    bool bits[20] = {false};
    int len = 0;

    if (num == 0) {
        bits[0] = false;
        len = 1;
    } else {
        long long temp = num;
        while (temp > 0) {
            int digit = temp % 10;
            // Проверяем, что в числе нет цифр кроме 0 и 1
            if (digit != 0 && digit != 1) {
                printf("ERROR\n");
                return;
            }
            bits[len] = (digit == 1);
            temp /= 10;
            len++;
        }
    }

    // Проверка на выход за диапазон [-65535; 65535] (максимум 16 значащих бит)
    if (len > 16) {
        printf("ERROR\n");
        return;
    }

    if (is_negative) {
        // Переводим из дополнительного кода обратно в прямой
        for (int i = 0; i < len; i++) {
            bits[i] = !bits[i];
        }
        bool carry = true;
        for (int i = 0; i < len; i++) {
            bool current_bit = bits[i];
            bits[i] = current_bit ^ carry;
            carry = current_bit && carry;
        }
    }

    // Собираем десятичное число из массива битов (от старшего к младшему)
    long long result = 0;
    for (int i = len - 1; i >= 0; i--) {
        result = result * 2 + (bits[i] ? 1 : 0);
    }

    if (result > 65535) {
        printf("ERROR\n");
        return;
    }

    if (is_negative && result != 0) {
        result = -result;
    }

    printf("%lld\n", result);
}

int main() {
    int b;
    char first;
    long long number;

    // Считываем: систему счисления, пробел, первый символ числа и остаток числа
    if (scanf("%d %c%lld", &b, &first, &number) != 3) {
        printf("ERROR\n");
        return 0;
    }

    if (b == 2) {
        to_decimal(first, number);
    } else if (b == 10) {
        // Собираем десятичное число обратно из первого символа и остатка
        if (first == '-') {
            if (number < 0) { // Защита от ввода вида "--86"
                printf("ERROR\n");
                return 0;
            }
            to_binary(-number);
        } else if (first == '+') {
            if (number < 0) {
                printf("ERROR\n");
                return 0;
            }
            to_binary(number);
        } else if (first >= '0' && first <= '9') {
            if (number < 0) { // Защита от ввода вида "8-6"
                printf("ERROR\n");
                return 0;
            }
            // Считаем количество цифр в number, чтобы правильно приклеить первую цифру
            long long multiplier = 1;
            long long temp = number;
            if (temp == 0) {
                multiplier = 10;
            } else {
                while (temp > 0) {
                    multiplier *= 10;
                    temp /= 10;
                }
            }
            long long full_number = (first - '0') * multiplier + number;
            to_binary(full_number);
        } else {
            printf("ERROR\n");
        }
    } else {
        printf("ERROR\n");
    }

    return 0;
}

   
}
