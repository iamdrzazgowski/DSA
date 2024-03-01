#include <iostream>
#include <vector>
#include <string>

using namespace std;

int MAX_NAMES = 1500;

string getLetters(string father, int start){
    string letters;
    for(int i = start; i < start + 3; i++){
        letters += father[i];
    }
    return letters;
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> names(MAX_NAMES);

    for(int i = 0; i < m; i++){
        cin >> names[i];
    }

    for(int j = m; j < n; j++){

        int father1, father2, father3, father4;
        cin >> father1 >> father2 >> father3 >> father4;

        string name;

        name += getLetters(names[father1 % MAX_NAMES], 0);
        name += getLetters(names[father2 % MAX_NAMES], 3);
        name += getLetters(names[father3 % MAX_NAMES], 6);
        name += getLetters(names[father4 % MAX_NAMES], 9);

        names[j % MAX_NAMES] = name;
    }

    cout << names[(n-1) % MAX_NAMES] << '\n';

    return 0;
}