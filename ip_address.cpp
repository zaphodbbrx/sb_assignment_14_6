#include <iostream>

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
            currentNum = std::stoi(currentStr);
            if (currentNum < 0 || currentNum > 255) return "No";
            if (std::to_string(currentNum).length() != currentStr.length()) return "No";
            if (numDots > 3) return "No";
            currentStr = "";
        }else{
            return "No";
        }
        prevSymbol = c;
    }
    if (numDots != 3) return "No";
    return "Yes";
}
