#include <iostream>
#include <string>

using namespace std;

struct Person{
    string name;
    int fans;
    Person  * nextPerson;
};

class List{
private:
    Person* head;

public:
    List() {
        head = nullptr;
    }

    ~List(){
        while(head != nullptr){
            Person * temp = head;
            head = head->nextPerson;
            delete temp;
        }
    }

    void addPerson(string &name, int fans){
        if(personExist(name, fans)){
            cout << "NIE" << '\n';
        }else{
            addElement(name, fans);
            cout << "TAK" << '\n';
        }
    }

    void addElement(string &name, int fans){
        Person * person = new Person;
        person->name =  name;
        person->fans = fans;
        person->nextPerson = nullptr;

        if(head == nullptr){
            head = person;
        }else{
            Person * temp = head;
            while(temp->nextPerson != nullptr){
                temp = temp->nextPerson;
            }
            temp->nextPerson = person;
        }
    }


    bool personExist(string &name, int fans){
        Person * current= head;
        while( current != nullptr){
            if(current->name == name && current->fans == fans){
                return true;
            }
            current = current->nextPerson;
        }
        return false;
    }

    void removePerson(int maxFans){
        if(head != nullptr) {

            Person * current = head;
            Person * previous = nullptr;
            Person * previousSelected = nullptr;
            Person * selectedPerson = nullptr;

            int minFans = 2000000;

            while (current != nullptr) {
                int difference = maxFans - current->fans;

                if (difference >= 0 && (difference < minFans || (difference == minFans && (selectedPerson == nullptr || selectedPerson->name > current->name)))) {
                    selectedPerson = current;
                    minFans = difference;
                    previousSelected = previous;
                }
                previous = current;
                current = current->nextPerson;
            }

            if (selectedPerson) {
                (previousSelected ? previousSelected->nextPerson : head) = selectedPerson->nextPerson;
                cout << selectedPerson->name << '\n';
            } else {
                cout << "NIE" << '\n';
            }

        }else{
            cout << "NIE" << '\n';
        }
    }
};

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    List list;

    int option, n;
    cin >> n;
    cin.ignore();

    for(int i = 0; i < n; i++){
        cin >> option;
        cin.ignore();
        if(option == 1) {
            string name;
            int fans;
            getline(cin >> ws, name, '\n');
            cin >> fans;
            cin.ignore();
            list.addPerson(name, fans);
        }else if(option == 2){
            int maxFans;
            cin >> maxFans;
            cin.ignore();
            list.removePerson(maxFans);
        }
    }
    return 0;
}