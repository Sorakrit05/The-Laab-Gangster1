bool isNameUnique(const vector<Player>& players, const string& name) {
    for (const auto& player : players) {
        if (player.name == name) {
            return false; // ถ้าชื่อซ้ำจะส่งค่าผลลัพธ์เป็น false
        }
    }
    return true; // ถ้าชื่อไม่ซ้ำ
}


int main() {
    srand(time(0));
    int numPlayers;
    
    // รับจำนวนผู้เล่น
    do {
        cout << "Enter number of players (max 4): ";
        cin >> numPlayers;
        if (numPlayers > 4) {
            cout << "Too many players! Please enter again.\n";
        }
        if (numPlayers < 2) {
            cout << "Not enough players! Please enter again.\n";
        }
    } while (numPlayers > 4 || numPlayers < 2);
    
    vector<Player> players(numPlayers);
    
   // ตั้งค่าผู้เล่น
    cin.ignore(); // กำจัดบรรทัดที่ค้างจากการรับค่า numPlayers
    for (int i = 0; i < numPlayers; i++) {
        string playerName;
        bool uniqueName = false;
        
        // ตรวจสอบชื่อผู้เล่น
        while (!uniqueName) {
            cout << "Enter player " << i + 1 << " name: ";
            getline(cin, playerName); // ใช้ getline เพื่อรับชื่อที่มีช่องว่าง
            
            if (isNameUnique(players, playerName)) {
                players[i].name = playerName; // ถ้าชื่อไม่ซ้ำก็เก็บ
                uniqueName = true;
            } else {
                cout << "Name already taken. Please choose a different name.\n";
            }
        }
    }
    cout << endl;