#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Car{
    string name;
    long long rotation;
};

void sort(Car cars[], int size ){
    for( int i = 0; i < size; i++ ){
        for( int j = 0; j < size - 1; j++ ){
            if( cars[j].rotation > cars[j + 1].rotation){
                swap(cars[j], cars[j + 1]);
            }else if((cars[j].rotation == cars[j + 1].rotation) && (cars[j].name > cars[j + 1].name)){
                swap(cars[j], cars[j + 1]);
            }
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long int n;
    cin >> n;
    cin.ignore();
    Car cars[3];

    long double p;
    long int d;

    string name;
    long long rotation;

    for(int i = 0; i < n; i++){

        getline(cin, name, '\n');
        cin >> p >> d;
        cin.ignore();
        rotation = floor((p * 1000) / ((d * 0.0254)  * 3.141593));

        if(i < 3){
            cars[i].name = name;
            cars[i].rotation = rotation;
        }else{
            long long maxi = cars[0].rotation;
            int index = 0;

            for(int j = 0; j < 3; j++){
                if(cars[j].rotation > maxi ){
                    maxi = cars[j].rotation;
                    index = j;
                }
            }

            if(rotation < cars[index].rotation){
                cars[index].name = name;
                cars[index].rotation = rotation;
            }else if(rotation == cars[index].rotation){
                for(int x = 0; x < 3; x++){
                    if(cars[x].name > cars[index].name){
                        index = x;
                    }
                }
                if(rotation == cars[index].rotation && name < cars[index].name){
                    cars[index].name = name;
                }
            }
        }
    }
    
    sort(cars, 3);

    for(int j = 0; j < 3; j++){
        cout << cars[j].name << '\n' << cars[j].rotation << '\n';
    }

    return 0;
}