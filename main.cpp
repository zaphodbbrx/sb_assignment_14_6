#include <iostream>
#include "caesar.h"
#include "tictactoe.h"
#include "email.h"
#include "ip_address.h"
#include "compare_float.h"

void test1(){
    std::string test_s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    int test_n = 25;
    std::cout << encryptCaesar(test_s, test_n) << "\n";
    std::cout << decryptCaesar(encryptCaesar(test_s, test_n), test_n) << "\n";
}

void test2(){
    std::string line1, line2, line3;
    line1 = "O..";
    line2 = "...";
    line3 = "..a";

    std::cout << checkGame(line1, line2, line3);
}

void test3(){
    std::string testStr = "i_like_underscore@but_its_not_allow_in _this_part.example.com";
    std::cout << checkEmail(testStr) << "\n";
}

void test4(){
    std::string testStr = "192.168.O10.1";
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
//    test4();
    test5();
    return 0;
}
