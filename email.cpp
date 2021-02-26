#include <iostream>

/*
 *
Напишите программу, которая проверяет корректность email-адреса, введенного пользователем.
Согласно международным требованиям, корректный email-адрес должен состоять из двух частей, разделенных знаком @.
Первая часть должна иметь длину не менее 1 и не более 64 символов, вторая часть - не менее 1 и не более 63 символов.
Из символов допускаются только английские буквы, цифры и знак - (дефис), а также точка. Точка не может быть первым или
последним символом, а кроме того, две точки не могут идти подряд. В первой части (которая предшествует символу @),
кроме вышеперечисленных, разрешены еще следующие символы:
!#$%&'*+-/=?^_`{|}~
Пользователь вводит строку, задающую email-адрес. Программа должна вывести слово Yes, если адрес корректен,
а в противном случае - слово No.
Примеры корректных email-адресов (примеры взяты из Википедии):
simple@example.com
very.common@example.com
disposable.style.email.with+symbol@example.com
other.email-with-hyphen@example.com
fully-qualified-domain@example.com
user.name+tag+sorting@example.com (may go to user.name@example.com inbox depending on mail server)
x@example.com (one-letter local-part)
example-indeed@strange-example.com
admin@mailserver1
example@s.example
mailhost!username@example.org
user%example.com@example.org

Примеры некорректных email-адресов (примеры взяты из Википедии):
John..Doe@example.com (две точки не могут идти подряд)
Abc.example.com (нет символа @)
A@b@c@example.com (символ @ должен быть только один)
a"b(c)d,e:f;g<h>i[j\k]l@example.com (присутствуют недопустимые символы)
1234567890123456789012345678901234567890123456789012345678901234+x@example.com (первая часть длиннее 64 символов)
i_like_underscore@but_its_not_allow_in _this_part.example.com (во второй части присутствует недопустимый символ _)
 * */

bool allowed(char c, bool isSecondPart){
    std::string allowedSymbols = isSecondPart ? "abcdefghigklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVYXYZ0123456789.!#$%&'*+-/=?^`{|}~" :
                                                "abcdefghigklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVYXYZ0123456789.!#$%&'*+-/=?^`{|}~_";

    return allowedSymbols.find(c) <= allowedSymbols.length();
}

bool checkSymbols(std::string & address, bool isSecondPart){
    char prevSymbol = '.';
    if (address[0] == '.') return false;
    for (char c : address){
            if (!allowed(c, isSecondPart)) return false;
            if (c == '.' && prevSymbol == '.') return false;
            prevSymbol = c;
        }
    return true;
}

std::string checkEmail(std::string & address){
    // check for @
    if (address.find('@') != address.rfind('@') || address.find('@') > address.length()) return "No. @";
    // check length
    int at_pos = address.find('@');
    int firstPartLength = address.substr(0, at_pos).length();
    int secondPartLength = address.substr(at_pos, address.length()).length();
    std::string firstPart, secondPart;
    if (firstPartLength < 1 || firstPartLength > 64 || secondPartLength < 1 || secondPartLength > 63) return "No. length";
    // check first part symbols
    firstPart = address.substr(0, firstPartLength);
    secondPart = address.substr(at_pos + 1, secondPartLength);
    if (!checkSymbols(firstPart, false)) return "No. first part";
    // check second part symbols
    if (!checkSymbols(secondPart, true)) return "No. second part";
    return "Yes";
}