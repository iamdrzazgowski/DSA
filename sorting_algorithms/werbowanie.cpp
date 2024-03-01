#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct Person{
    string name;
    int minutes;
};

// Sortowanie
void sort(Person person[], int size){

    Person temp;
    int index;

    for(int i = 1; i < size; i++){
        temp = person[i];
        index = i - 1;
        while(index >= 0 && (person[index].minutes < temp.minutes || (person[index].minutes == temp.minutes && person[index].name > temp.name))){
            person[index + 1] = person[index];
            index--;
        }
        person[index + 1] = temp;
    }
}

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t, n, p;
    cin >> t;
    int constValue = pow(10,6) + 3;

    for(int i = 0; i < t; i++){
        cin >> n >> p;

        Person *persons = new Person[n];
        long long sum = 0;

        for(int j = 0; j < n; j++){
            cin >> persons[j].name >> persons[j].minutes;
        }

        sort(persons, n);

        for(int z = 0; z < n; z++){
            sum += 1 + z * persons[z].minutes;
            sum = sum % constValue;
            if(z < p){
                cout << persons[z].name << ' ';
            }
        }
        cout << '\n' << sum << '\n';

        delete[] persons;
    }
    return 0;
}