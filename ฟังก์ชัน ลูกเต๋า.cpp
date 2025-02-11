#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void rollFourSideDice() {
    srand(time(0));
    string Colors[] = {"Red","Brown","Orange","Green"};

    cout << "The results of the dice roll:  ";
    for (int i = 0; i < 4; i++){
        int roll = (rand() % 4);
        cout << Colors[roll] << " "; 
    }
    cout << endl;
}

int main(){
    rollFourSideDice();
    return 0;
}