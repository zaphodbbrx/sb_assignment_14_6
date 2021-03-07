#include "iostream"
#include "cmath"

bool checkChars(std::string line){
    int nZeros=0, nCrosses=0;
    if (line.length() != 3) return false;
    return true;
}

bool checkNumbers(std::string line){
    int nCrosses=0, nZeros=0;
    for (int i = 0; i < line.length(); i++){
        if (line[i] != 'O' && line[i] != 'X' && line[i] != '.') return false;
        if (line[i] == 'X') nCrosses++;
        if (line[i] == 'O') nZeros++;
    }
    return std::abs(nCrosses - nZeros) == 1;
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
    bool petyaWon, vanyaWon = false;
//    check if correct of not
    if (!checkChars(line1) || !checkChars(line2) || !checkChars(line3)) return "incorrect";
    if (!checkNumbers(line1 + line2 + line2)) return "incorrect";
//    check result
// check horizontals
    if(checkLine(line1) == 'X' || checkLine(line2) == 'X' || checkLine(line3) == 'X') petyaWon = true;
    if(checkLine(line1) == 'O' || checkLine(line2) == 'O' || checkLine(line3) == 'O') vanyaWon = true;
// check verticals
    if(checkLine(concatChars(line1[0], line1[1], line1[2])) == 'X'
    || checkLine(concatChars(line2[0], line2[1], line2[2])) == 'X'
    || checkLine(concatChars(line3[0], line3[1], line3[2])) == 'X') petyaWon = true;
    if(checkLine(concatChars(line1[0], line1[1], line1[2])) == 'O'
       || checkLine(concatChars(line2[0], line2[1], line2[2])) == 'O'
       || checkLine(concatChars(line3[0], line3[1], line3[2])) == 'O') vanyaWon = true;
// check diagonals
    if(checkLine(concatChars(line1[0], line2[1], line3[2])) == 'X'
       || checkLine(concatChars(line3[0], line2[1], line1[2])) == 'X') petyaWon = true;
    if(checkLine(concatChars(line1[0], line2[1], line3[2])) == 'O'
       || checkLine(concatChars(line3[0], line2[1], line1[2])) == 'O') vanyaWon = true;
    if (petyaWon && !vanyaWon){
        return "Petya won";
    }else if (vanyaWon && !petyaWon){
        return "Vanya won";
    }else if(petyaWon && vanyaWon){
        return "incorrect";
    }
    else{
        return "Nobody";
    }
}