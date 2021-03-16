/*
 Тотальный разбор: напишите ряд функций для работы с целыми числами:
 1) функция, которая вычисляют длину(количество цифр) числа
 2) функция, которая получает последнюю цифру числа
 3) функция, которая получает первую цифру числа
 4) функция, которая получает цифру, которую запросил пользователь (подумать, как быть, если запросили некорректную цифру, или под таким номером нет цифры)
 5) функция, которая переводит число из 10-ой системы счисления в двоичную
 6) функция, которая переводит число из двоичной системы счисления в десятичную
 */
#include <iostream>
using namespace std;
#include <cmath>

int toDefineLanghtNumber (int a);
int getLastNumber (int a);
int getFirstNumber (int a);
int enterUserNumber(int a, int step);
int doBinaryConversion(int a);
int conversFromBinToDec (int a);
void printOnConsole (string massage);
void printOnConsole (string massege, int parametr);

int main()
{
    int number = 0, step = 0;
    int decNum = 0, binNum = 0;
    
    printOnConsole("Enter any number: ");
    cin >> number;
    printOnConsole("Langht number is: ", toDefineLanghtNumber(number));
    printOnConsole("Last number is: ", getLastNumber(number));
    printOnConsole("First number is: ", getFirstNumber(number));
    printOnConsole("Enter the sequence number of the digit you want to get from the number?: ");
    cin >> step;
    printOnConsole("User number is: ", enterUserNumber(number, step));
    printOnConsole("Enter any decimal number (from 1 to 1000): ");
    cin >> decNum;
    printOnConsole("Decimal to binary conversion: ", doBinaryConversion(decNum));
    printOnConsole("Enter any binary number (up to 10 elements): ");
    cin >> binNum;
    printOnConsole("Binary to decimal conversion: ", conversFromBinToDec (binNum));
    
    return 0;
}

int toDefineLanghtNumber(int a) {
    int i = 0;
    
    while (a > 0) {
        a /= 10;
        i++;
    }
    
    return i;
}

int getLastNumber(int a) {
    a %= 10;
    
    return a;
}

int getFirstNumber(int a) {
    int lenght = toDefineLanghtNumber(a);
    int digit = 0;
    
    while (lenght > 0) {
        lenght--;
        digit = a % 10;
        a /= 10;
    }
    
    return digit;
}

int enterUserNumber(int a, int step) {
    int lenght = toDefineLanghtNumber(a);
    int digit = 0;
    
    while (lenght - step >= 0) {
        lenght--;
        digit = a % 10;
        a /= 10;
    }
    
    return digit;
}

int doBinaryConversion(int a) {
    int i = 0, result = 0;
    
    while (a > 0) {
        result += (a % 2) * pow(10, i);
        a /= 2;
        i++;
    }
    
    return result;
}

int conversFromBinToDec (int a) {
    int result = 0, i = 0;
    
    while(a > 0){
        result += (a % 10) * pow(2, i);
        a /= 10;
        i++;
    }
    
    return result;
}

void printOnConsole(string massege, int parametr) {
    cout << massege << parametr << endl;
}

void printOnConsole(string massage) {
    cout << massage;
}


