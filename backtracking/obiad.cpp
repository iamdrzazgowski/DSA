#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a > b;
}
//TODO: Dwie mozliwości 1 bierzemy pod uwage aktualny element, 2 nie bierzemy pod uwage aktualnego elementu

int countWays(vector<int>& calories, int maxCalories, int currentIndex, int currentSum) {

    if(currentSum > maxCalories){
        return 0;

    }else if(currentSum == maxCalories){
        return 1;

    }else if(currentIndex == calories.size()){

        if(currentSum == maxCalories){
            return 1;
        }else{
            return 0;
        }
    }

    int withCurrentPoint = countWays(calories, maxCalories, currentIndex + 1, currentSum + calories[currentIndex]);
    int withoutCurrentPoint = countWays(calories, maxCalories, currentIndex + 1, currentSum);

    return withCurrentPoint + withoutCurrentPoint;
}

void display(vector<int>& calories){
    for(int i = 0; i < calories.size(); i++){
        cout << calories[i] << ' ';
    }
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int n, maxCalories;
        cin >> n;

        vector<int> calories(n);

        for(int j = 0; j < n; j++){
            cin >> calories[j];
        }

        cin >> maxCalories;
//        sort(calories.begin(), calories.end(), compare);
//        display(calories);
        cout << countWays(calories, maxCalories, 0, 0) << '\n';
    }

    return 0;
}