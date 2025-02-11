#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

string drawFortuneCard() {
    vector<string> cards = {"1","2","3","4","5","6","7","8","9"};
    srand(time(0));
    

    cout << "Gangster's Fortune Card:  ";
    for (int i = 0; i < 1; i++){
        int randomCards = rand() % cards.size();
        cout << cards[randomCards] << " "; 
    }
    cout << endl;
}

int main(){
    drawFortuneCard();
    return 0;
}