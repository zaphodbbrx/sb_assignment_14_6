#include <iostream>
/*
На этот раз вам нужно проверить, задает ли введенная пользователем строка корректный IP-адрес. IP-адрес должен представлять из себя 4 числа, разделенных точками без пробелов, причем каждое число должно быть в диапазоне от 0 до 255 включительно. Числа не должны содержать ведущих нулей. Других символов в строке, кроме вышеописанных, присутствовать не должно.
Пользователь вводит строку, задающую email-адрес. Программа должна вывести слово Yes, если адрес корректен, а в противном случае - слово No.

 Примеры корректных IP-адресов:
127.0.0.1
255.255.255.255
1.2.3.4
55.77.213.101

 Примеры строк, не являющихся корректными IP-адресами:
255.256.257.258 (числа больше 255)
0.55.33.22. (лишняя точка в конце)
10.00.000.0 (лишние нули)
23.055.255.033 (опять лишние нули)
65.123..9 (две точки подряд)
a.b.c.d (посторонние символы, помимо цифр и точек)
*/
bool checkNum(std::string str){
    if (str.length() == 0) return false;
    int currentNum = std::stoi(str);
    return (currentNum >= 0 && currentNum <= 255) && (std::to_string(currentNum).length() == str.length());
}
std::string checkIP(std::string & ipAddress){
    char prevSymbol = '.';
    int numDots = 0;
    int currentNum = 0;
    std::string currentStr;
    for (char c : ipAddress){
        if (c == '.' && prevSymbol == '.') return "No";
        if (c >= '0' && c <= '9'){
            currentStr += c;
        } else if (c == '.') {
            numDots++;
            if (!checkNum(currentStr)) return "No";
            if (numDots > 3) return "No";
            currentStr = "";
        }else{
            return "No";
        }
        prevSymbol = c;
    }
    if (numDots != 3) return "No";
    if (!checkNum(currentStr)) return "No";
    return "Yes";
}
