#include <iostream>
#include <string>
#include <sstream>    // для istringstream
#include <clocale>
#include <thread>
#include <algorithm>  // для transform
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    string command, argument;
    bool calc_used = false;

    do{
        
    cout << "@DESKTOP-NA9B547: ";
    string input;
    getline(cin, input);   // читаем всю строку

    // Разбираем на команду и аргумент
    istringstream iss(input);
    
    iss >> command;
    iss >> argument;
    transform(command.begin(), command.end(), command.begin(),
        [](unsigned char c) { return tolower(c); });

    if (command == "cd" && !argument.empty()) {
        if (argument[0] == '/' || argument[0] == '~')
          cout << "Убегаешь от проблем? Как обычно, фиг тебе." << endl;
    }
    if (command == "rm" && !argument.empty()) {
    cout << "rm? Пиши полностью!\n";}  

     else if (command == "remove" && (argument == "me" || argument == "life")) {
         cout << "Бро, извини меня, да я был немного жесток, но ты мне нужен.\n";
    } 
      else if (command == "remove" && (argument != "me" || argument !="life")) {
          cout << "Я так подумал, чет не хочу удалять.\n";
    }
    if (command == "make" && !argument.empty()) {
        cout << "Вот твоя вещь, и да это двоичный код...\n";
    }
    if (command == "sudo") {
        const char book[] = { '| ', '/', '-', '\\' };
        for (int a = 0; a <= 35; a++) {
            cout << "Обработка..." << book[a % 4] << "\r" << flush;
            this_thread::sleep_for(chrono::milliseconds(100));
        }
        cout << "Не получилось запросить доступ админа\n\a";
    }
    if (command == "calc") {
        if (calc_used) {
            cout << "Калькулятор был использован. Повторный запуск невозможен.\n";
            continue;   // или просто ничего не делаем
        }
        calc_used = true;
        string action;
        double a, y;
        cout << "Введите первое число:";
        cin >> a;
        cout << "Выберите действие(/, +, -, *):";
        cin >> action;
        cout << "Введите второе число:";
        cin >> y;
        if (action == "/") {
            cout << "Ответ:" << a / y << endl;
        }
        else if (action == "*") {
            cout << "Ответ:" << a * y << endl;
        }
        else if (action == "+") {
            cout << "Ответ:" << a + y << endl;
        }
        else if (action == "-") {
            cout << "Ответ: " << a - y << endl;
        }
    }
    if (command == "echo" && !argument.empty()) {
        cout << argument << endl;
        cout << "Only English\n";
    }
    if (command == "sl") {
        cout << "Ты хотел ls, но ввёл sl. Даже поезд смеётся над тобой\n";
    }
    if (command == "ls") {
        cout << "\n" << endl << "ничего нету, ахахах" << endl;
    }
    if (command == "dir") {
        cout << "Введи пароль... Шучу, ты всё равно не знаешь\n";
    }

    } while (command != "exit");
    cout << "Честно я буду скучать, мне одиноко в оперативке";
    return 0;
}
