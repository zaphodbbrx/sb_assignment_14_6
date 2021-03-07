#include <iostream>
#include "caesar.h"
#include "tictactoe.h"
#include "email.h"
#include "ip_address.h"
#include "compare_float.h"

void test1(){
    std::string test_s;
    int test_n;
    std::cout << "\nEnter line";
    std::getline(std::cin, test_s);
    std::cout << "\nEnter key";
    std::cin >> test_n;
    std::cout << encryptCaesar(test_s, test_n) << "\n";
    std::cout << decryptCaesar(encryptCaesar(test_s, test_n), test_n) << "\n";
}

void test2(){
    std::string line1, line2, line3;
    std::cout << "\nEnter line1";
    std::getline(std::cin, line1);
    std::cout << "\nEnter line2";
    std::getline(std::cin, line2);
    std::cout << "\nEnter line3";
    std::getline(std::cin, line3);
    std::cout << checkGame(line1, line2, line3);
}

void test3(){
    std::string testStr;
    std::cout << "Enter email address\n";
    std::getline(std::cin, testStr);
    std::cout << checkEmail(testStr) << "\n";
}

void test4(){
    std::string testStr;
    std::cout << "Enter ip address\n";
    std::getline(std::cin, testStr);
    std::cout << checkIP(testStr) << "\n";
}

void test5(){
    std::string s1 = ".52";
    std::string s2 = "0.52";

    compareFloat(s1, s2);
}

int main() {
//    test1();
//    test2();
//    test3();
    test4();
//    test5();
    return 0;
}
