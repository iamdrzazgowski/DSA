#include <iostream>
#include <cmath>

using namespace std;

double P(int i, int j){
    return 30 - sqrt((i - 5) * (i - 5) + (j - 5) * (j - 5));
}

double findMax(int y, int x, int& index_y){
    double maxi;

    for(int i = 0; i < y; i++){
        if(i == 0){
            maxi = P(i,x);
        }

        if(P(i,x) > maxi){
            maxi = P(i,x);
            index_y = i;
        }
    }
    return maxi;
}

double findHill(int y, int start_x, int end_x){

    int index_y = 0;
    int mid_x = start_x + ((end_x - start_x)/2);
    double maxi = findMax(y, mid_x, index_y);

    if(mid_x == start_x || mid_x == end_x){
        return P(index_y, mid_x);
    }

    if (P(index_y, mid_x - 1) > maxi) { 
        return findHill(y, start_x, mid_x);
    }else if (P(index_y, mid_x + 1) > maxi) {
        return findHill(y, mid_x, end_x);
    }

    return P(index_y, mid_x);
}
int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int y, x;
    cin >> y >> x;

    int start_x = 0, end_x = x;

    for(int i = 0; i < y; i++){
        for(int j = 0 ; j < end_x; j++){
            cout << P(i,j) << ' ';
        }
        cout << '\n';
    }

    cout << (int)floor(findHill(y, start_x, end_x));
    return 0;
}
