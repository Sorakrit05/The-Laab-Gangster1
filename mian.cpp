#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main(){
    cout << "1. When starting the game, the person who ate the last Laab in the group will start first.\n\n";

    cout << "2. When it's their turn, the players roll all 4 dice to choose and pick the ingredients according to the color they rolled.\n\n";

    cout << "3. Dice roll results\n\n";

    cout << "-If the result shows 2 or more of the same color, the player must pick 1 event card. Near the picking of the ingredient coin, the event card will show the result immediately after picking.\n\n";

    cout << "4. If the player has received all the ingredients of that color as desired, the player can choose to pick ingredients from other colors instead.\n\n";

    cout << "5. End of the game The player who receives all the ingredients according to the Laab recipe first will be the winner. And you are the\n\n";

    cout << "REAL_Laab_gangster\n\n";

    int numPlayers;
    cout << "Enter your number of player(not more than 4) : ";
    cout << endl;
    cin >> numPlayers;
    while(numPlayers>4 || numPlayers<2){
        cout << "Sorry. the number of player exceeded the limit.\n";
        cout << "Enter your number agian : ";
        cin >> numPlayers;
        cout << endl;
    }

    string colors[] = {
        "\033[31m", // สีแดง
        "\033[32m", // สีเขียว
        "\033[33m", // สีเหลือง
        "\033[34m", // สีน้ำเงิน
        "\033[35m", // สีม่วง
        "\033[36m", // สีฟ้า
        "\033[37m", // สีขาว
    };

    for (int i = 0; i < 15; i++) {
        cout << colors[i % 7] << "||" << flush;
        this_thread::sleep_for(std::chrono::seconds(1));
    }
    cout << "\033[0m" << endl;

    return 0;
}
