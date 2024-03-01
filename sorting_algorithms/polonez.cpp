#include <iostream>
#include <string>

using namespace std;

struct Uczen{
    string code;
    float average;
    int meters;
    int month;
};

void sort(Uczen uczen[], int size, string option){
    Uczen temp;
    int index;

    if(option == "s d m"){ //OK
        for(int i = 1; i < size; i++){
            temp = uczen[i];
            index = i - 1;
            while(index >= 0 && (temp.average > uczen[index].average) || (temp.average == uczen[index].average && temp.meters > uczen[index].meters) || (temp.average == uczen[index].average && temp.meters == uczen[index].meters && temp.month > uczen[index].month)){
                uczen[index + 1] = uczen[index];
                index--;
            }
            uczen[index + 1] = temp;
        }
    }else if(option == "s m d"){ //OK
        for(int i = 1; i < size; i++){
            temp = uczen[i];
            index = i - 1;
            while(index >= 0 && (temp.average > uczen[index].average) || (temp.average == uczen[index].average && temp.month > uczen[index].month) || (temp.average == uczen[index].average && temp.month == uczen[index].month && temp.meters > uczen[index].meters)){
                uczen[index + 1] = uczen[index];
                index--;
            }
            uczen[index + 1] = temp;
        }
    }else if(option == "d m s"){ //OK
        for(int i = 1; i < size; i++){
            temp = uczen[i];
            index = i - 1;
            while(index >= 0 &&(temp.meters > uczen[index].meters) || (temp.meters == uczen[index].meters && temp.month > uczen[index].month) || (temp.meters == uczen[index].meters && temp.month == uczen[index].month && temp.average > uczen[index].average)){
                uczen[index + 1] = uczen[index];
                index--;
            }
            uczen[index + 1] = temp;
        }
    }else if(option == "d s m"){ //OK
        for(int i = 1; i < size; i++){
            temp = uczen[i];
            index = i - 1;
            while(index >= 0 && (temp.meters > uczen[index].meters) || (temp.meters == uczen[index].meters && temp.average > uczen[index].average) || (temp.meters == uczen[index].meters && temp.average == uczen[index].average && temp.month > uczen[index].month)){
                uczen[index + 1] = uczen[index];
                index--;
            }
            uczen[index + 1] = temp;
        }
    }else if(option == "m d s"){
        for(int i = 1; i < size; i++){
            temp = uczen[i];
            index = i - 1;
            while(index >= 0 && (temp.month > uczen[index].month) || (temp.month == uczen[index].month && temp.meters > uczen[index].meters) || (temp.month == uczen[index].month && temp.meters == uczen[index].meters && temp.average > uczen[index].average)){
                uczen[index + 1] = uczen[index];
                index--;
            }
            uczen[index + 1] = temp;
        }
    }else if(option == "m s d"){
        for(int i = 1; i < size; i++){
            temp = uczen[i];
            index = i - 1;
            while(index >= 0 && (temp.month > uczen[index].month) || (temp.month == uczen[index].month && temp.average > uczen[index].average) || (temp.month == uczen[index].month && temp.average == uczen[index].average && temp.meters > uczen[index].meters)){
                uczen[index + 1] = uczen[index];
                index--;
            }
            uczen[index + 1] = temp;
        }
    }

}

void displayStudents(Uczen boys[], Uczen girls[], int size){
    for(int i = 0; i < size; i++){
        cout << boys[i].code << ' ' << girls[i].code << ' ';
    }
}

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n = 0;
    cin >> n;
    cin.ignore();
    string option;

    Uczen * boys = new Uczen[n];
    Uczen * girls = new Uczen[n];

    getline(cin, option, '\n');

    for(int i = 0; i < n; i++){
        getline(cin, boys[i].code, ' ');
        cin >> boys[i].average;
        cin >> boys[i].meters;
        cin >> boys[i].month;
        cin.ignore();

        getline(cin, girls[i].code, ' ');
        cin >> girls[i].average;
        cin >> girls[i].meters;
        cin >> girls[i].month;
        cin.ignore();
    }

    sort(boys, n , option);
    sort(girls, n , option);
    displayStudents(boys, girls, n);

    delete[] boys;
    delete[] girls;

    return 0;
}