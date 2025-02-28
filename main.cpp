#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>
#include <algorithm>
#include <iomanip>
#include <chrono>
#include <thread>
#include <set>
#include <limits>
using namespace std;



// โครงสร้างส่วนผสม
struct Ingredient {
    string name;
    string type;
};

// โครงสร้างสูตรลาบ
struct LarbRecipe {
    string name;
    vector<string> mainIngredients;
    vector<string> spices;
    vector<string> herbs;
    vector<string> specialIngredients;
};

// โครงสร้างสำหรับผู้เล่น
struct Player {
    string name;
    vector<string> ingredients;
    LarbRecipe recipe;
    int mainIngredients;
    int spices;
    int herbs;
    int specialIngredients;

};

// สูตรลาบพร้อมส่วนผสมที่ต้องใช้
vector<LarbRecipe> recipes = {
        {"Laab Wua Khom", {"Beef", "Fried garlic", "Bile", "Blood"}, {"Makwaen", "Coriander", "Nutmeg", "Star Anise", "Black Pepper", "Long Pepper", "Cinnamon", "Clove"}, {"Makwaen", "Fragrant", "Fennel Seed", "Dried Galangal", "Cardamom", "Chili Spur Pepper", "Caraway"}, {"KaowTong","Parsley", "Vietnamese Coriander"}},
        {"Laab Lor", {"Beef", "Buffalo", "Fried Garlic", "Blood", "Offal"}, {"Makwaen", "Coriander", "Nutmeg", "Star Anise", "Black Pepper", "Long Pepper", "Cinnamon", "Clove"}, {"Makwaen", "Fragrant", "Fennel Seed", "Dried Galangal", "Cardamom", "Chili Spur Pepper", "Caraway"}, {"Matoom","Phak Paem","Dried Fennel Seed" }},
        {"Laab Mi", {"Fried Garlic", "Blood", "Offal"}, {"Makwaen", "Coriander", "Nutmeg", "Star Anise", "Black Pepper", "Long Pepper", "Cinnamon", "Clove"}, {"Makwaen", "Fragrant", "Fennel Seed", "Dried Galangal", "Cardamom", "Chili Spur Pepper", "Caraway"}, {"Deeplygung", "Makwen-infused Fish Sauce", "Para Cress", "Olive"}},
        {"Laab Wua Niao", {"Beef", "Fried Garlic", "Blood", "Offal"}, {"Makwaen", "Coriander", "Nutmeg", "Star Anise", "Black Pepper", "Long Pepper", "Cinnamon", "Clove"}, {"Makwaen", "Fragrant", "Fennel Seed", "Dried Galangal", "Cardamom", "Chili Spur Pepper", "Caraway"}, {"Makwen-infused Fish Sauce", "Damocles Tree", "Para Cress"}},
        {"Laab Khwai Khom", {"Buffalo", "Fried Garlic", "Bile", "Blood"}, {"Makwaen", "Coriander", "Nutmeg", "Star Anise", "Black Pepper", "Long Pepper", "Cinnamon", "Clove"}, {"Makwaen", "Fragrant", "Fennel Seed", "Dried Galangal", "Cardamom", "Chili Spur Pepper", "Caraway"}, {"Oreille", "Para Cress", "Olive"}},
        {"Laab Khwai Niao", {"Buffalo", "Fried Garlic", "Blood", "Offal"}, {"Makwaen", "Coriander", "Nutmeg", "Star Anise", "Black Pepper", "Long Pepper", "Cinnamon", "Clove"}, {"Makwaen", "Fragrant", "Fennel Seed", "Dried Galangal", "Cardamom", "Chili Spur Pepper", "Caraway"}, {"KaowTong", "Vietnamese Coriander", "Parsley"}},
        {"Laab Khwai Khua Nam", {"Buffalo", "Fried Garlic", "Beef Broth", "Blood"}, {"Makwaen", "Coriander", "Nutmeg", "Star Anise", "Black Pepper", "Long Pepper", "Cinnamon", "Clove"}, {"Makwaen", "Fragrant", "Fennel Seed", "Dried Galangal", "Cardamom", "Chili Spur Pepper", "Caraway"}, {"Matoom","Damocles Tree", "Parsley"}},
        {"Laab Mu Khua Haeng", {"Beef", "Offal", "Fried Garlic"}, {"Makwaen", "Coriander", "Nutmeg", "Star Anise", "Black Pepper", "Long Pepper", "Cinnamon", "Clove"}, {"Makwaen", "Fragrant", "Fennel Seed", "Dried Galangal", "Cardamom", "Chili Spur Pepper", "Caraway"}, {"Oreille", "Deeplygung", "Dried Fennel Seed", "Damocles Tree", "Para Cress"}},
        {"Laab Wua Khua Nam", {"Beef", "Fried Garlic", "Beef Broth", "Blood"}, {"Makwaen", "Coriander", "Nutmeg", "Star Anise", "Black Pepper", "Long Pepper", "Cinnamon", "Clove"}, {"Makwaen", "Fragrant", "Fennel Seed", "Dried Galangal", "Cardamom", "Chili Spur Pepper", "Caraway"}, {"Matoom", "Damocles Tree","Olive"}},
};

// รายการส่วนผสมแบ่งตามประเภท
vector<Ingredient> meats = {
    {"Beef", "meat"}, {"Pork", "meat"}, {"Beef broth", "meat"}, {"Fried garlic", "meat"},
    {"Buffalo", "meat"}, {"Bile", "meat"}, {"Blood", "meat"}, {"Offal", "meat"}
};

vector<Ingredient> herbs = {
    {"Makwaen", "herb"}, {"Coriander", "herb"}, {"Nutmeg", "herb"}, {"Star Anise", "herb"},
    {"Black Pepper", "herb"}, {"Long Pepper", "herb"}, {"Cinnamon", "herb"}, {"Clove", "herb"}
};

vector<Ingredient> vegetables = {
    {"Matoom", "vegetable"}, {"KaowTong", "vegetable"}, {"Oreille", "vegetable"}, {"Deeplygung", "vegetable"},
    {"Makwen-infused fish sauce", "vegetable"}, {"Dried Fennel Seed", "vegetable"}, {"Phak paem", "vegetable"},
    {"Vietnamese Coriander", "vegetable"}, {"Damocles tree", "vegetable"}, {"Parsley", "vegetable"},
    {"Para cress", "vegetable"}, {"Olive", "vegetable"}
};

vector<Ingredient> spices = {
    {"Makwaen", "spice"}, {"Fragrant", "spice"}, {"Fennel Seed", "spice"}, {"Dried Galangal", "spice"},
    {"Cardamom", "spice"}, {"Chili Spur Pepper", "spice"}, {"Caraway", "spice"}
};

// ฟังก์ชันสุ่มสูตรลาบ
LarbRecipe drawLarbRecipe() {
    return recipes[rand() % recipes.size()];
}

void printIngredient(vector<string> Ingredient){
    for (int i = 0; i < Ingredient.size(); i++){
        if (i != 0){
            cout << ", ";
        }
        cout << Ingredient[i];
    }

}
//แสดงสูตรลาบ และส่วนผสม
void printRecipe(const LarbRecipe& recipe) {
    cout << endl;
    cout << left << setw(20) << "Category" << setw(60) << "Ingredients" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(20) << "Meats: ";
    printIngredient(recipe.mainIngredients);
    cout << endl;
    cout << setw(20) << "Spices: " ;
    printIngredient(recipe.spices);
    cout << endl;
    cout << setw(20) << "Herbs: " ;
    printIngredient(recipe.herbs);
    cout << endl;
    cout << setw(20) << "Vegetables: " ;
    printIngredient(recipe.specialIngredients);
    cout << "\n------------------------------------------------------------------------------------------------------\n" << "\n";
}
//ฟังก์ชันทอยลูกเต๋า
vector<string> rollFourSideDice() {
    vector<string> resultsColour;
    string Colors[] = {"Red", "Brown", "Orange", "Green"};

    cout << "The dice are rolling... ";
    cout.flush();

    // Simulate dice rolling animation
    for (int i = 0; i < 5; ++i) {
        cout << ". ";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(300));
    }
    cout << "Done!" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));

    cout << "The results of the dice roll:  ";
    for (int i = 0; i < 4; i++) {
        int roll = (rand() % 4);
        cout << Colors[roll] << " ";
        resultsColour.push_back(Colors[roll]);
        this_thread::sleep_for(chrono::milliseconds(250));
    }
    cout << endl;

    return resultsColour;
}

Player drawFortuneCard(Player player) {
    vector<string> cards = {"Suan Krua", "Moitgure", "Regular Customer", "Moldy Cutting Board", "The Kitchen", "Rainy Season", "Falling Mortar", "Falling Tray"};

    int randomCards = rand() % cards.size(); // สุ่มดัชนีการ์ด
    string selectedCard = cards[randomCards]; // เก็บการ์ดที่สุ่มได้

    // Determine the card text based on the selected card
    string cardText;
    if (selectedCard == "Suan Krua") {
        cardText = "Many of the spices in Chili Laap are found in Lanna gardens and today you have the opportunity to visit that garden and pick up the brown spices you want.";
    } else if (selectedCard == "Moitgure") {
        cardText = "Good chili paste is dry. Moisture causes chili paste to clump and mold. Your spices have moisture that will ruin your chili paste. Pick up 1 brown spice and return it to the center pile.";
    } else if (selectedCard == "Regular Customer") {
        cardText = "Being a regular at the butcher shop gives you the chance to choose quality meat before anyone else. Pick up one of the red tokens.";
    } else if (selectedCard == "Moldy Cutting Board") {
        cardText = "The cutting board for making larb must be dry and clean. Failure to store the cutting board causes mold and damages the meat. Pick up 1 red poden. Return to the center pile.";
    } else if (selectedCard == "The Kitchen") {
        cardText = "Many of the spices in chili paste are found in the kitchen garden. Just pick up one orange spice of your choice.";
    } else if (selectedCard == "Rainy Season") {
        cardText = "The humid rainy season brings forth many kinds of vegetables that are perfect for eating with laab. Pick up any green token you want.";
    } else if (selectedCard == "Falling Mortar") {
        cardText = "Mortar is a tool used to finely pound spices and turn them into chili paste. Your mortar spoiled the prepared spices. Pick up 1 orange spice and return it to the center pile.";
    } else if (selectedCard == "Falling Tray") {
        cardText = "You prepared the vegetables and the laab well, but unfortunately you made 1 piece of green yin poden tray back to the center.";
    }

    // Calculate frame dimensions
    int cardWidth = 70; // Adjust as needed
    int textPadding = 5; // Adjust as needed
    int namePadding = (cardWidth - selectedCard.length()) / 2;
    
    // Draw the top border
    cout << "+" << string(cardWidth - 2, '-') << " +" << endl;
    
    //print card name
    cout << "| " << setw(namePadding) << "" << selectedCard << setw(namePadding) << "" << "|" << endl;
    
    // Draw the card text within the frame
    int currentLineStart = 0;
    while (currentLineStart < cardText.length()) {
        int currentLineLength = cardWidth - (2 + 2 * textPadding); // Minus 2 for the '|' on each side, minus padding
        string currentLine = cardText.substr(currentLineStart, currentLineLength);
         int Padding = (cardWidth - 2 - currentLine.length())/2;
        cout << "| " << setw(textPadding) << "" <<  left << setw(currentLineLength) << currentLine << setw(textPadding) << "" << " |" << endl;
        currentLineStart += currentLineLength;
    }

    // Draw the bottom border
    cout << "+" << string(cardWidth - 2, '-') << " +" << endl;
    cout << endl;
    
    if (selectedCard == "Suan Krua") {
        player.herbs++;
        if (player.herbs > player.recipe.herbs.size()) {
            player.herbs--; // Remove the extra one

            // Distribute to other categories if available
            if (player.mainIngredients < player.recipe.mainIngredients.size()) {
                player.mainIngredients++;
            }
            else if (player.spices < player.recipe.spices.size()) {
                player.spices++;
            }
            else if (player.specialIngredients < player.recipe.specialIngredients.size()) {
                player.specialIngredients++;
            }
        }
    }
    else if (selectedCard == "Moitgure") {
        player.herbs--;
        if (player.herbs < 0) {
            player.herbs = 0;
        }
    }
    else if (selectedCard == "Regular Customer") {
        player.mainIngredients++;
        if (player.mainIngredients > player.recipe.mainIngredients.size()) {
             player.mainIngredients--;
            if (player.spices < player.recipe.spices.size()) {
                player.spices++;
            }
            else if (player.herbs < player.recipe.herbs.size()) {
                player.herbs++;
            }
            else if (player.specialIngredients < player.recipe.specialIngredients.size()) {
                player.specialIngredients++;
            }
        }
    }
    else if (selectedCard == "Moldy Cutting Board") {
        player.mainIngredients--;
        if (player.mainIngredients < 0) {
            player.mainIngredients = 0;
        }
    }
    else if (selectedCard == "The Kitchen") {
        player.spices++;
        if (player.spices > player.recipe.spices.size()) {
            player.spices--;
            if (player.mainIngredients < player.recipe.mainIngredients.size()) {
                player.mainIngredients++;
            }
            else if (player.herbs < player.recipe.herbs.size()) {
                player.herbs++;
            }
            else if (player.specialIngredients < player.recipe.specialIngredients.size()) {
                player.specialIngredients++;
            }
        }
    }
    else if (selectedCard == "Rainy Season") {
        player.specialIngredients++;
        if (player.specialIngredients > player.recipe.specialIngredients.size()) {
            player.specialIngredients--;
             if (player.mainIngredients < player.recipe.mainIngredients.size()) {
                player.mainIngredients++;
            }
            else if (player.spices < player.recipe.spices.size()) {
                player.spices++;
            }
            else if (player.herbs < player.recipe.herbs.size()) {
                player.herbs++;
            }
        }
    }
    else if (selectedCard == "Falling Mortar") {
        player.spices--;
        if (player.spices < 0) {
            player.spices = 0;
        }
    }
    else if (selectedCard == "Falling Tray") {
        player.specialIngredients--;
        if (player.specialIngredients < 0) {
            player.specialIngredients = 0;
        }
    }
    return player;
}


bool Winner(Player player){
    if(player.mainIngredients < player.recipe.mainIngredients.size()){
        return false;
    }
    if(player.spices < player.recipe.spices.size()){
        return false;
    }
    if(player.herbs < player.recipe.herbs.size()){
        return false;
    }
    if(player.specialIngredients < player.recipe.specialIngredients.size()){
        return false;
    }
    return true;
}

void shownPlayerItem(Player player) {
    cout << setw(50) << setfill('-') << "-" << endl;
    cout << setfill(' ');
    cout << "| " << setw(15) << left << "Category" << "| " << setw(10) << "Amount" << "| " << setw(15) << "Want More" << "|" << endl;
    cout << setw(50) << setfill('-') << "-" << endl;
    cout << setfill(' ');
    cout << "| " << setw(15) << left << "Meats" << "| " << setw(10) << player.mainIngredients << "| " << setw(15) << player.recipe.mainIngredients.size() - player.mainIngredients << "|" << endl;
    cout << "| " << setw(15) << left << "Spices" << "| " << setw(10) << player.spices << "| " << setw(15) << player.recipe.spices.size() - player.spices << "|" << endl;
    cout << "| " << setw(15) << left << "Herbs" << "| " << setw(10) << player.herbs << "| " << setw(15) << player.recipe.herbs.size() - player.herbs << "|" << endl;
    cout << "| " << setw(15) << left << "Vegetables" << "| " << setw(10) << player.specialIngredients << "| " << setw(15) << player.recipe.specialIngredients.size() - player.specialIngredients << "|" << endl;
    cout << setw(50) << setfill('-') << "-" << endl;
    cout << setfill(' ');
}

// ฟังก์ชันคืนค่ารายการสีที่ออกเพียงครั้งเดียว
vector<string> getUniqueColors(const vector<string>& resultsColour) {
    unordered_map<string, int> colorFrequency;
    unordered_map<string, int> colorCount;

    // นับจำนวนครั้งที่สีแต่ละสีปรากฏขึ้น
    for (const string& color : resultsColour) {
        colorFrequency[color]++;
    }

    // กำหนดค่า 1 ถ้าสีไม่ซ้ำ และ 0 ถ้าสีซ้ำ
    for (const string& color : resultsColour) {
        if (colorFrequency[color] == 1) {
            colorCount[color] = 1;
        } else {
            colorCount[color] = 0;
        }
    }


    // เก็บสีที่ออกแค่ครั้งเดียวลง vector
    vector<string> uniqueColors;
    for (const string& color : resultsColour) {  
        if (colorCount[color] != 0) {  // เฉพาะสีที่เจอครั้งเดียว
            uniqueColors.push_back(color);
        }
    }
    return uniqueColors;
}

void inputIngredientsByColor(Player& player, const vector<string>& colors) {
    // หาสีที่ออกมาแค่ครั้งเดียว
    vector<string> uniqueColors = getUniqueColors(colors);

    // แสดงสีที่มีให้เลือก
    cout << "DEBUG: สีที่ไม่ซ้ำกัน:\n";
    for (const string& color : uniqueColors) {
        cout << color << endl;
    }

    // เลือกส่วนผสมตามสีที่ไม่ซ้ำ
    for (const string& color : uniqueColors) {
        cout << "กรุณาใส่ส่วนผสมสำหรับสี " << color << ":" << endl;
        string ingredient;
        bool valid = false;

        while (!valid) {
            cout << "เลือกหมายเลขส่วนผสม: ";
            int index;
            cin >> index;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "กรุณาใส่หมายเลขที่ถูกต้อง\n";
                continue;
            }

            // ตรวจสอบและเลือกส่วนผสมตามประเภทสี
            if (color == "Red" && index > 0 && index <= player.recipe.mainIngredients.size()) {
                ingredient = player.recipe.mainIngredients[index - 1];
                player.mainIngredients++;
                valid = true;
            } else if (color == "Brown" && index > 0 && index <= player.recipe.herbs.size()) {
                ingredient = player.recipe.herbs[index - 1];
                valid = true;
            } else if (color == "Orange" && index > 0 && index <= player.recipe.spices.size()) {
                ingredient = player.recipe.spices[index - 1];
                valid = true;
            } else if (color == "Green" && index > 0 && index <= player.recipe.specialIngredients.size()) {
                ingredient = player.recipe.specialIngredients[index - 1];
                valid = true;
            } else {
                cout << "หมายเลขส่วนผสมไม่ถูกต้อง กรุณาลองใหม่\n";
            }
        }

        // บันทึกส่วนผสมที่เลือกลง Player
        player.ingredients.push_back(ingredient);
    }
}

bool checkIngredients(const Player& player) {
    set<string> requiredIngredients(player.recipe.mainIngredients.begin(), player.recipe.mainIngredients.end());
    requiredIngredients.insert(player.recipe.spices.begin(), player.recipe.spices.end());
    requiredIngredients.insert(player.recipe.herbs.begin(), player.recipe.herbs.end());
    requiredIngredients.insert(player.recipe.specialIngredients.begin(), player.recipe.specialIngredients.end());

    for (const string& ingredient : player.ingredients) {
        requiredIngredients.erase(ingredient);
    }

    return requiredIngredients.empty();
}

int main() {
    srand(time(0));
    int numPlayers;
    
    // รับจำนวนผู้เล่น
    do {
        cout << endl;
        cout << "\033[31m* * * * * * * * * * * * * * * * * * * * *\033[0m" << endl;
        cout << "\033[31m*\033[0m" << "     +--------------------------+      " << "\033[31m*\033[0m" << endl;
        cout << "\033[31m*\033[0m" << "     | Choose number of players |      " << "\033[31m*\033[0m" << endl;
        cout << "\033[31m*\033[0m" << "     +--------------------------+      " << "\033[31m*\033[0m" << endl;
        cout << "\033[31m*\033[0m" << "                                       " << "\033[31m*\033[0m" << endl;
        cout << "\033[31m*\033[0m" << " [\033[1;32m2\033[0m" << " players]  " << "[\033[1;32m3\033[0m"<<" players]  " <<"[\033[1;32m4\033[0m"<<" players] " << "\033[31m*\\033[0m" << endl;
        cout << "\033[31m*\\033[0m" << "                                       " << "\033[31m*\\033[0m" << endl;
        cout << "\033[31m* * * * * * * * * * * * * * * * * * * * * \033[0m" << endl;

        cout << endl << "\n      !! Players in this round : ";
        cin >> numPlayers;
        if (numPlayers > 4) {
            cout << "Too many players! Please enter again.\n";
        }
        if (numPlayers < 2) {
            cout << "Not enough players! Please enter again.\n";
        }
        if (cin.fail()) {
            cin.clear(); // ล้างสถานะผิดพลาด
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ลบข้อมูลที่ไม่ใช่ตัวเลขใน buffer
            cout << "Invalid input. Please enter again.\n";
        }
    } while (numPlayers > 4 || numPlayers < 2);
    
    vector<Player> players(numPlayers);
    
    // ตั้งค่าผู้เล่น
    cout << "\n------------------------------------------" << endl;
    cout << endl << "      [Member Player in this round] " << endl;
    
    for (int i = 0; i < numPlayers; i++) {
        cout << endl;
        cout << " Enter player " << i + 1 << " name: ";
        cin >> players[i].name;
     
    }
    cout << "\n------------------------------------------\n\n" << endl;
    cout << endl;
    cin.get();
    // สุ่มสูตรลาบ
    for (int i = 0; i < numPlayers; i++) {
    LarbRecipe recipe = drawLarbRecipe();
        cout << "=======================================================================================================\n" << endl;
        cout << players[i].name << "!!  Get your recipe [Enter]";
        cin.get();
        players[i].recipe = recipe;
        cout << "received recipe: " << players[i].recipe.name << "\n";
        printRecipe(recipe);
        shownPlayerItem(players[i]);
        cout << "\n=======================================================================================================\n\n" << endl;
    }
    int i = 0;
    while(true){
        cout << "This is your turn: " <<  players[i].name << endl;
        cout << "Press [Enter] for roll dice";
        cin.get();
        vector<string> resultsColour = rollFourSideDice();
        vector<string> uniqueColors = getUniqueColors(resultsColour);

        if(uniqueColors.size() == 4){
            cout << endl;
            printRecipe(players[i].recipe);
            inputIngredientsByColor(players[i], resultsColour); // ให้ผู้เล่นพิมพ์ส่วนผสมเองตามสีที่ได้
            cout << endl;
        } else {
            cout << endl;
            cout << "You must randomly draw a fortune card.!!!" << endl;
            cout << "Press [Enter] for to randomly select a card.\n";
            cin.get();
            players[i] = drawFortuneCard(players[i]);
            cout << endl;
            printRecipe(players[i].recipe);
            inputIngredientsByColor(players[i], resultsColour); // ให้ผู้เล่นพิมพ์ส่วนผสมเองตามสีที่ได้
        }
        
        cout << endl;

        if(checkIngredients(players[i])){
            cout << "The winner is " << players[i].name;
            break;
        }
        cout << endl;
        shownPlayerItem(players[i]);
        i++;
        if(i >= numPlayers){
            i = 0;
        }
    }
    return 0;
}