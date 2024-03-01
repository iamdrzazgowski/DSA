#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sort_cameras(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

void check_cameras(pair<int,int> * cameras, bool *set_cameras, int size){

    for(int i = 0; i < size; i++){
        for(int j = cameras[i].first; j <= cameras[i].second; j++){
            if(!set_cameras[j]){
                set_cameras[j] = true;
                break;
            }
        }
    }
}

string get_result(bool * set_cameras, int size){
    for(int i = 0; i < size; i++){
        if(!set_cameras[i]){
            return "NIE";
        }
    }

    return "TAK";
}


int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;

    for(int j = 0; j < t; j++){

        int n;
        cin >> n;

        pair<int,int> * cameras = new pair<int,int>[n];
        bool * set_cameras = new bool[n];

        for(int i = 0; i < n; i++){
            cin >> cameras[i].first >> cameras[i].second;
            set_cameras[i] = false;
        }

        sort(cameras, cameras + n, sort_cameras);
        check_cameras(cameras, set_cameras, n);
        cout << get_result(set_cameras, n) << '\n';
    }

    return 0;
}