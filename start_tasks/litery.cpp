#include <iostream>
#include <cstring>

using namespace std;

int findMinIndex(const int arr[], int size){
    int mini = 2000000;
    int minIndex = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] < mini && arr[i] > 0){
            mini = arr[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int findMaxIndex(const int arr[], int size) {
    int maxi = 0;
    int maxIndex = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] > maxi){
            maxi = arr[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int size = 26;
    int * array = new int[size];

    for(int z = 0; z < size; z++){
        array[z] = 0;
    }

    string text;

    getline(cin, text, '^');

    for(int i = 0; i < text.length(); i++){
        int temp;
        if(text[i] >= 'A' && text[i] <= 'Z'){
            temp = int(tolower(text[i])) - 97;
            array[temp]++;
        }if(text[i] >= 'a' && text[i] <= 'z'){
            temp = int(tolower(text[i])) - 97;
            array[temp]++;
        }
    }

    int minIndex = findMinIndex(array, size);
    int maxIndex = findMaxIndex(array, size);

    char mostCommon = char(maxIndex + 97);
    char lessCommon = char(minIndex + 97);
    cout << mostCommon << ' ' << lessCommon;

    delete[] array;
    return 0;
}
