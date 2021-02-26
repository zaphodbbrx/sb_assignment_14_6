#include "iostream"
#include "cmath"

bool isCorrect(std::string line){
    int nZeros=0, nCrosses=0;
    if (line.length() != 3) return false;
    for (int i = 0; i < line.length(); i++){
        if (line[i] != 'O' && line[i] != 'X' && line[i] != '.') return false;
        if (line[i] == 'X') nCrosses++;
        if (line[i] == 'O') nZeros++;
    }
//    if (std::abs(nCrosses - nZeros) > 1) return false;
    return true;
}

char checkLine(std::string line){
    if (line.length() == 3 && line[0] == line[1] && line[1] == line[2] && line[0] != '.') return line[0];
    return 0;
}

std::string concatChars(char c1, char c2, char c3){
    std::string res = "   ";
    res[0] = c1;
    res[1] = c2;
    res[2] = c3;
    return res;
}

std::string checkGame(std::string line1, std::string line2, std::string line3){
//    check if correct of not
    if (!isCorrect(line1) || !isCorrect(line2) || !isCorrect(line3)) return "incorrect";
//    check result
// check horizontals
    if(checkLine(line1) == 'X' || checkLine(line2) == 'X' || checkLine(line3) == 'X') return "Petya won";
    if(checkLine(line1) == 'O' || checkLine(line2) == 'O' || checkLine(line3) == 'O') return "Vanya won";
// check verticals
    if(checkLine(concatChars(line1[0], line1[1], line1[2])) == 'X'
    || checkLine(concatChars(line2[0], line2[1], line2[2])) == 'X'
    || checkLine(concatChars(line3[0], line3[1], line3[2])) == 'X') return "Petya won";
    if(checkLine(concatChars(line1[0], line1[1], line1[2])) == 'O'
       || checkLine(concatChars(line2[0], line2[1], line2[2])) == 'O'
       || checkLine(concatChars(line3[0], line3[1], line3[2])) == 'O') return "Vanya won";
// check diagonals
    if(checkLine(concatChars(line1[0], line2[1], line3[2])) == 'X'
       || checkLine(concatChars(line3[0], line2[1], line1[2])) == 'X') return "Petya won";
    if(checkLine(concatChars(line1[0], line2[1], line3[2])) == 'O'
       || checkLine(concatChars(line3[0], line2[1], line1[2])) == 'O') return "Vanya won";
    return "Nobody";
}