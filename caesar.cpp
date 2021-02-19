#include <iostream>

/*
 *Шифр Цезаря

В древности для зашифрования сообщений использовался такой способ. Все буквы в сообщении сдвигались на одно и то же
 число позиций в алфавите. Число позиций могло быть как положительным, так и отрицательным, и являлось параметром шифра.
 Если для сдвига на данное число позиций алфавита не хватает, то он зацикливается
 (то есть буква с номером 27 - это снова a, буква с номером 28 - это b, и так далее).
 Например, слово abracadabra при сдвиге на 10 позиций превратится в klbkmknklbk.
 Этот простейший шифр называется шифром Цезаря. Регистр букв (заглавные и строчные) менять не нужно.
 Напишите функцию encryptCaesar от строки и числа, которая возвращает исходную строку,
 зашифрованную шифром Цезаря с параметром, равным данному числу. Также напишите функцию decryptCaesar,
 выполняющую обратное преобразование. Считаем, что входные строки состоят лишь из английских букв;
 если там содержатся и другие символы, то их надо игнорировать.

Подсказка: имея функцию encryptCaesar, функцию decryptCaesar можно реализовать в одну строчку.
 */

char convertCharFn(char c, int n, char startChar, char finishChar){
    if (c + n > finishChar){
        return startChar + (c + n) - finishChar;
    } else if (c + n < startChar){
        return finishChar - (startChar - (c + n));
    }
    return c + n;
}

char convertChar(char c, int n){
    if (c >='a' && c <= 'z'){
        return convertCharFn(c, n, 'a', 'z');
    }else if (c >= 'A' && c <= 'Z') {
        return convertCharFn(c, n, 'A', 'Z');
    }else{
        return c;
    }
}

std::string encryptCaesar(std::string s, int n){
    std::string res;
    for (char c : s){
        res += convertChar(c, n);
    }
    return res;
}

std::string decryptCaesar(std::string s, int n){
    return encryptCaesar(s, -n);
}