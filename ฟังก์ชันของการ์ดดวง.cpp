#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

string drawFortuneCard() {
    vector<string> cards = {"Suan Krua","Moisgure","Aoa Mue","Hom Bun","Regular Customer","Moldy Cutting Board","Hom poy","Ngan Katin","The Kitchen","Rainy Season","Broken Mortar","Fliped"};
    
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