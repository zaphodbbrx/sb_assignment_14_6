#include <iostream>

/*
 Сравнение длинных вещественных чисел

Вы продолжаете писать калькулятор, работающий с вещественными числами с очень высокой точностью. Вы уже научились
 проверять корректность записи вещественных чисел в виде строк, и теперь перед вами новая цель - научиться сравнивать
 такие вещественные числа.

Пользователь вводит две строки, задающие вещественные числа, в том же формате, как было описано в задаче
 “Длинное вещественное число”. Программа должна проверить корректность ввода (для этого можно переиспользовать код,
 написанный в задаче “Длинное вещественное число”), после чего вывести слово Less, если первое число строго меньше
 второго; слово More, если первое число строго больше второго; и слово Equal, если введенные числа равны.
*/

bool checkFloat(std::string & input){
    bool correct;
    int numDots = 0;
    correct = (input[0] == '-'
               || input[0] == '.'
               || (input[0] >= '0' && input[0] <= '9'));

    for(int i=0; i < input.length(); i++){
        if (input[i] == '.') numDots++;
        if (numDots > 1){
            correct = false;
            break;
        }

        if (input[i] == '-' && i > 0){
            correct = false;
            break;
        }
    }

    for (char i : input){
        if ((i != '.' && i != '-')
            && (i < '0' || i > '9')){
            correct = false;
            break;
        }
    }
    return correct;
}

void compareFloat(std::string s1, std::string s2){
    if (!(checkFloat(s1) && checkFloat(s2))){
        std::cout << "incorrect\n";
        return;
    }
    float f1, f2;

    f1 = std::stof(s1);
    f2 = std::stof(s2);

    if (f1 > f2){
        std::cout << "More\n";
    }else if (f1 < f2){
        std::cout << "Less\n";
    }else{
        std::cout << "Equal\n";
    }
}