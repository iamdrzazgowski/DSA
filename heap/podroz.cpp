#include <iostream>

using namespace std;

struct City{
    string name;
    int activity;
    int index;
};

class Heap{
private:
    City *cities;
    int citiesSize;

public:

    Heap(int capacity){
        this->citiesSize = 0;
        this->cities = new City[capacity];
    }

    void insertCity(City city){
        cities[citiesSize] = city;
        int currentIndex = citiesSize;

        // Przesiewanie w górę
        while (currentIndex > 0 && ((cities[currentIndex].activity > cities[(currentIndex - 1) / 2].activity) || (cities[currentIndex].activity == cities[(currentIndex - 1) / 2].activity && cities[currentIndex].index < cities[(currentIndex - 1) / 2].index))) {
            City temp = cities[currentIndex];
            cities[currentIndex] = cities[(currentIndex - 1) / 2];
            cities[(currentIndex - 1) / 2] = temp;

            currentIndex = (currentIndex - 1) / 2;
        }

        citiesSize++;
    }

    // Przesiewanie w dół
    void sortDown(){

        int currentIndex = 0;
        int leftSide = currentIndex * 2 + 1;
        int rightSide = currentIndex * 2 + 2;
        int largestChild = currentIndex;

        while(currentIndex < citiesSize){
            if(leftSide < citiesSize && (cities[leftSide].activity > cities[largestChild].activity || (cities[leftSide].activity == cities[largestChild].activity && cities[leftSide].index < cities[largestChild].index))){
                largestChild = leftSide;
            }

            if(rightSide < citiesSize && (cities[rightSide].activity > cities[largestChild].activity || (cities[rightSide].activity == cities[largestChild].activity && cities[rightSide].index < cities[largestChild].index))){
                largestChild = rightSide;
            }

            if(largestChild == currentIndex){
                break;

            }else{
                City temp = cities[currentIndex];
                cities[currentIndex] = cities[largestChild];
                cities[largestChild] = temp;

                currentIndex = largestChild;
                leftSide = currentIndex * 2 + 1;
                rightSide = currentIndex * 2 + 2;
            }

        }
    }

    void findLocations(int maxActivity){

        City root;

        while (citiesSize != 0 && maxActivity > 0) {

            root = cities[0];

            if(root.activity <= maxActivity){
                cout << root.name << " ";
                maxActivity -= root.activity;
            }

            citiesSize--;
            cities[0] = cities[citiesSize];
            sortDown();
        }
    }
};


int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int size, maxActivity;
    cin >> size;

    Heap heap(size);

    for(int i = 0; i < size; i++){
        City city;
        cin >> city.name >> city.activity;
        city.index = i;
        heap.insertCity(city);
    }

    cin >> maxActivity;
    heap.findLocations(maxActivity);

    return 0;
}