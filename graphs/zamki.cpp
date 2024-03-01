#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Castle{
    int castleID;
    int distance = 0;
    bool visited = false;

    vector<int> connections;

    Castle(int numberInit){
        castleID = numberInit;
    }
};

void searchCastles(vector<Castle *>& castles, Castle *startCastle ,int& days){

    int counterCastle = 0, distance = 0;

    queue<Castle*> castleQueue;
    castleQueue.push(startCastle);
    castles[startCastle->castleID]->visited = true;

    while(!castleQueue.empty()){

        int childrenSize = castleQueue.front()->connections.size();
        int parentID = castleQueue.front()->castleID;
        int parentDistance = castleQueue.front()->distance;

        for(int i = 0; i < childrenSize; i ++){

            int nextCastle = castles[parentID]->connections[i];
            int incDistance = parentDistance + 1;

            if (!castles[nextCastle]->visited) {

                castleQueue.push(castles[nextCastle]);
                castles[nextCastle]->distance = incDistance;
                castles[nextCastle]->visited = true;
            }
        }

        if(parentDistance != 0 && parentDistance <= floor(days/2)){
            counterCastle += 1;
        }

        distance = parentDistance;
        castleQueue.pop();
    }

    cout << distance << ' ' << counterCastle << '\n';
}

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, s, d;
    int firstCastle, secondCastle;

    cin >> n >> m >> s >> d;

    vector<Castle *> castles;
    for(int i = 0; i < n; i++){
        castles.push_back(new Castle(i));
    }

    for(int j = 0; j < m; j++){
        cin >> firstCastle >> secondCastle;
        castles[firstCastle]->connections.push_back(secondCastle);
        castles[secondCastle]->connections.push_back(firstCastle);
    }

    searchCastles(castles, castles[s],d);

    return 0;
}