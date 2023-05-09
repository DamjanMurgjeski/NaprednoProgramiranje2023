#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Креирање на структура tempMK со Grad, denska temperatura, temperatura navecer
struct tempMK {
    string Grad;
    int denska_temperatura;
    int temperatura_navecer;

    // Сортирање на структурата по опаѓачки редослед
    bool operator<(const tempMK& other) const {
        return denska_temperatura > other.denska_temperatura;
    }
};

int main() {
    // Внесување на 10 градови во структурата tempMK
    tempMK data[] = {
        {"Skopje", 16, 10},
        {"Bitola", 13, 7},
        {"Prilep", 15, 8},
        {"Tetovo", 15, 9},
        {"Veles", 15, 9},
        {"Ohrid", 13, 8},
        {"Stip", 16, 10},
        {"Delcevo", 11, 6},
        {"Kavadarci", 16, 10},
        {"Kocani", 15, 9}
    };

    // Печатење на комбинации на градови според денска температура и температура навечер
    cout << "Temperatura na vneseni gradovi na 10/05/2023" << endl;
    for (int i = 0; i < 10; i++) {
        cout << data[i].Grad << ": " << data[i].denska_temperatura << "C / " << data[i].temperatura_navecer << "C" << endl;
    }
    // Додавање на tempMK во vector
    vector<tempMK> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(data[i]);
    }

    // Сортирање на содржината на векторот прво по denska temperatura па по  vecerna temperatura одделно  по опаѓачки редослед
    sort(v.begin(), v.end(), [](const tempMK& a, const tempMK& b) {
        if (a.denska_temperatura != b.denska_temperatura) {
            return a.denska_temperatura > b.denska_temperatura;
        } else {
            return a.temperatura_navecer > b.temperatura_navecer;
        }
    });

    cout << "\n""Sortirana sodrzina:" << endl;
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << it->Grad << ": " << it->denska_temperatura << "C / " << it->temperatura_navecer << "C" << endl;
    }

    return 0;
}
