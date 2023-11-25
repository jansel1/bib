#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>
#include <vector>

using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

#define PI = 3.141592653589793238462643383279

// Default Printing //

void Print(string text="Empty", bool newline=true) 
{
    cout << text;

    if (newline) {
        cout << endl;
    }
};

void print(string text="Empty") {Print(text, false);} // Same as "Print" but does not leave a \n / newline at the end.

// Printing With Color / Console Color Customization //
void ColorReset() {cout << RESET;}

void CPrint(string text="Empty", const char color[100]=RED, bool newline=true) 
{
    cout << color << text << RESET;

    if (newline) {
        cout << endl;
    }
}

void cprint(string text="Empty", const char color[100]=RED) {CPrint(text, color, false);} // This one is the same as CPrint but does not leave a \n / newline at the end.

void CustomPrint(string text="Empty", int fg=0, int bg=0, bool newline=true) 
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(console, (fg, bg) * 16);

    if (newline) {
        Print(text);
    } else {
        print(text);
    }

    ColorReset();
};

void customprint(string text="Empty", int fg=0, int bg=0) {CustomPrint(text, fg, bg, false);}
void error(string text="Empty") {CPrint(text, RED);}

// Useful Functions //
void cls() {system("cls");}

string input(string text, bool newline = false) 
{
    cout << text;

    if (newline) {
        cout << endl;
    }

    getline(cin, text);

    return text;
};

// Random Functions //
void Seed() {srand(static_cast<unsigned int>(time(nullptr)));}

int Random(int min, int max) 
{
    Seed();
    return rand() % (max - min + 1) + min;
};

template <typename any_list>
any_list RandomPick(const vector<any_list>& list) // The list must be a 'vector<...>'
{
    Seed();
    return (list[Random(0, list.size()-1)]);
};

int main()
{  

    return (0);
};