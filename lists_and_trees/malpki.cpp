#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Monkey{
    char letter;
    int number;
    vector<Monkey *> children;

    Monkey(char letterInit, int numberInit){
        letter = letterInit;
        number = numberInit;
    }
};

void addMonkeys(Monkey * monkey, queue<Monkey *> &nodeQueue){
    if(nodeQueue.empty()){
        nodeQueue.push(monkey);
    }else{
        nodeQueue.push(monkey);
        nodeQueue.front()->children.push_back(monkey);
        nodeQueue.front()->number = nodeQueue.front()->number - 1;

        if(nodeQueue.front()->number == 0){
            nodeQueue.pop();
        }
    }
}

void display(Monkey * monkey){
    if(monkey != nullptr){
        cout << monkey->letter;
        for(Monkey * child: monkey->children){
            display(child);
        }
    }
}


int main(){

    int K;
    cin >> K;

    for(int i = 0; i < K; i++){

        int N;
        cin >> N;

        queue<Monkey * > nodeQueue;
        Monkey * header = nullptr;

        for(int j = 0; j < N; j++){
            char letter;
            int number;

            cin >> letter >> number;
            Monkey * monkey = new Monkey(letter, number);

            if(header == nullptr){
                header = monkey;
            }
            addMonkeys(monkey, nodeQueue);
        }
        display(header);
        cout << '\n';
    }

    return 0;
}