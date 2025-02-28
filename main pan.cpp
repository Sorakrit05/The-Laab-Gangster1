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
#include <unordered_map>
#include <string>
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

struct Card {
    string name;
    string description;
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

struct IngredientInventory {
    map<string, int> inventory; // map ingredients names with its count
};

// สูตรลาบพร้อมส่วนผสมที่ต้องใช้
vector<LarbRecipe> recipes = {
        {"Laab Wua Khom", {"Beef", "Fried garlic", "Bile", "Blood"}, {"Dry Makwaen", "Coriander", "Nutmeg", "Star Anise", "Black Pepper", "Long Pepper", "Cinnamon", "Clove"}, {"Makwaen", "Fragrant", "Fennel Seed", "Dried Galangal", "Cardamom", "Chili Spur Pepper", "Caraway"}, {"KaowTong","Parsley", "Vietnamese Coriander"}},
        {"Laab Lor", {"Beef", "Buffalo", "Fried Garlic", "Blood", "Offal"}, {"Dry Makwaen", "Coriander", "Nutmeg", "Star Anise", "Black Pepper", "Long Pepper", "Cinnamon", "Clove"}, {"Makwaen", "Fragrant", "Fennel Seed", "Dried Galangal", "Cardamom", "Chili Spur Pepper", "Caraway"}, {"Matoom","Phak Paem","Dried Fennel Seed" }},
        {"Laab Mi", {"Fried Garlic", "Blood", "Offal"}, {"Dry Makwaen", "Coriander", "Nutmeg", "Star Anise", "Black Pepper", "Long Pepper", "Cinnamon", "Clove"}, {"Makwaen", "Fragrant", "Fennel Seed", "Dried Galangal", "Cardamom", "Chili Spur Pepper", "Caraway"}, {"Deeplygung", "Makwen-infused Fish Sauce", "Para Cress", "Olive"}},
        {"Laab Wua Niao", {"Beef", "Fried Garlic", "Blood", "Offal"}, {"Dry Makwaen", "Coriander", "Nutmeg", "Star Anise", "Black Pepper", "Long Pepper", "Cinnamon", "Clove"}, {"Makwaen", "Fragrant", "Fennel Seed", "Dried Galangal", "Cardamom", "Chili Spur Pepper", "Caraway"}, {"Makwen-infused Fish Sauce", "Damocles Tree", "Para Cress"}},
        {"Laab Khwai Khom", {"Buffalo", "Fried Garlic", "Bile", "Blood"}, {"Dry Makwaen", "Coriander", "Nutmeg", "Star Anise", "Black Pepper", "Long Pepper", "Cinnamon", "Clove"}, {"Makwaen", "Fragrant", "Fennel Seed", "Dried Galangal", "Cardamom", "Chili Spur Pepper", "Caraway"}, {"Oreille", "Para Cress", "Olive"}},
        {"Laab Khwai Niao", {"Buffalo", "Fried Garlic", "Blood", "Offal"}, {"Dry Makwaen", "Coriander", "Nutmeg", "Star Anise", "Black Pepper", "Long Pepper", "Cinnamon", "Clove"}, {"Makwaen", "Fragrant", "Fennel Seed", "Dried Galangal", "Cardamom", "Chili Spur Pepper", "Caraway"}, {"KaowTong", "Vietnamese Coriander", "Parsley"}},
        {"Laab Khwai Khua Nam", {"Buffalo", "Fried Garlic", "Beef Broth", "Blood"}, {"Dry Makwaen", "Coriander", "Nutmeg", "Star Anise", "Black Pepper", "Long Pepper", "Cinnamon", "Clove"}, {"Makwaen", "Fragrant", "Fennel Seed", "Dried Galangal", "Cardamom", "Chili Spur Pepper", "Caraway"}, {"Matoom","Damocles Tree", "Parsley"}},
        {"Laab Mu Khua Haeng", {"Beef", "Offal", "Fried Garlic"}, {"Dry Makwaen", "Coriander", "Nutmeg", "Star Anise", "Black Pepper", "Long Pepper", "Cinnamon", "Clove"}, {"Makwaen", "Fragrant", "Fennel Seed", "Dried Galangal", "Cardamom", "Chili Spur Pepper", "Caraway"}, {"Oreille", "Deeplygung", "Dried Fennel Seed", "Damocles Tree", "Para Cress"}},
        {"Laab Wua Khua Nam", {"Beef", "Fried Garlic", "Beef Broth", "Blood"}, {"Dry Makwaen", "Coriander", "Nutmeg", "Star Anise", "Black Pepper", "Long Pepper", "Cinnamon", "Clove"}, {"Makwaen", "Fragrant", "Fennel Seed", "Dried Galangal", "Cardamom", "Chili Spur Pepper", "Caraway"}, {"Matoom", "Damocles Tree","Olive"}},
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
    {"Dry Makwaen", "spices"}, {"Fragrant", "spices"}, {"Fennel Seed", "spices"}, {"Dried Galangal", "spices"},
    {"Cardamom", "spices"}, {"Chili Spur Pepper", "spices"}, {"Caraway", "spices"}
};

// ฟังก์ชันสุ่มสูตรลาบ
LarbRecipe drawLarbRecipe() {
    return recipes[rand() % recipes.size()];
}

void printIngredient(vector<string> Ingredient) {
    for (int i = 0; i < Ingredient.size(); i++) {
        if (i != 0) {
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
    cout << setw(20) << "\033[31mMeats: \033[0m";
    printIngredient(recipe.mainIngredients);
    cout << endl;
    cout << setw(20) << "\033[38;5;214mSpices: \033[0m";
    printIngredient(recipe.spices);
    cout << endl;
    cout << setw(20) << "\033[38;5;94mHerbs: \033[0m";
    printIngredient(recipe.herbs);
    cout << endl;
    cout << setw(20) << "\033[32mVegetables: \033[0m";
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
        std::this_thread::sleep_for(chrono::milliseconds(300));
    }
    cout << "Done!" << endl;
    std::this_thread::sleep_for(chrono::milliseconds(500));

    cout << "The results of the dice roll:  ";
    for (int i = 0; i < 4; i++) {
        int roll = (rand() % 4);
        cout << Colors[roll] << " ";
        resultsColour.push_back(Colors[roll]);
        std::this_thread::sleep_for(chrono::milliseconds(250));
    }
    cout << endl;

    return resultsColour;
}

Card drawFortuneCard() {
    vector<Card> cards = {
        {"Suan Krua", "Many of the spices in Chili Laap are found in Lanna gardens and today you have the opportunity to visit that garden and pick up the brown spices you want."},
        {"Moitgure", "Good chili paste is dry. Moisture causes chili paste to clump and mold. Your spices have moisture that will ruin your chili paste. Pick up 1 brown spice and return it to the center pile."},
        {"Regular Customer", "Being a regular at the butcher shop gives you the chance to choose quality meat before anyone else. Pick up one of the red tokens."},
        {"Moldy Cutting Board", "The cutting board for making larb must be dry and clean. Failure to store the cutting board causes mold and damages the meat. Pick up 1 red poden. Return to the center pile."},
        {"The Kitchen", "Many of the spices in chili paste are found in the kitchen garden. Just pick up one orange spice of your choice."},
        {"Rainy Season", "The humid rainy season brings forth many kinds of vegetables that are perfect for eating with laab. Pick up any green token you want."},
        {"Falling Mortar", "Mortar is a tool used to finely pound spices and turn them into chili paste. Your mortar spoiled the prepared spices. Pick up 1 orange spice and return it to the center pile."},
        {"Falling Tray", "You prepared the vegetables and the laab well, but unfortunately you made 1 piece of green yin poden tray back to the center."}
    };

    int randomCards = rand() % cards.size();
    return cards[randomCards];
}

Player handleCardEffect(Player player, const Card& card) {
    if (card.name == "Suan Krua") {
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
    else if (card.name == "Moitgure") {
        player.herbs--;
        if (player.herbs < 0) {
            player.herbs = 0;
        }
    }
    else if (card.name == "Regular Customer") {
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
    else if (card.name == "Moldy Cutting Board") {
        player.mainIngredients--;
        if (player.mainIngredients < 0) {
            player.mainIngredients = 0;
        }
    }
    else if (card.name == "The Kitchen") {
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
    else if (card.name == "Rainy Season") {
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
    else if (card.name == "Falling Mortar") {
        player.spices--;
        if (player.spices < 0) {
            player.spices = 0;
        }
    }
    else if (card.name == "Falling Tray") {
        player.specialIngredients--;
        if (player.specialIngredients < 0) {
            player.specialIngredients = 0;
        }
    }
    return player;
}

void displayCard(const Card& card) {
    // Calculate frame dimensions
    int cardWidth = 70; // Adjust as needed
    int textPadding = 5; // Adjust as needed
    int namePadding = (cardWidth - card.name.length()) / 2;

    // Draw the top border
    cout << "+" << string(cardWidth - 2, '-') << " +" << endl;

    // Print card name
    cout << "| " << setw(namePadding) << "" << card.name << setw(namePadding) << "" << "|" << endl;

    // Draw the card text within the frame
    int currentLineStart = 0;
    while (currentLineStart < card.description.length()) {
        int currentLineLength = cardWidth - (2 + 2 * textPadding); // Minus 2 for the '|' on each side, minus padding
        string currentLine = card.description.substr(currentLineStart, currentLineLength);
        int Padding = (cardWidth - 2 - currentLine.length()) / 2;
        cout << "| " << setw(textPadding) << "" << left << setw(currentLineLength) << currentLine << setw(textPadding) << "" << " |" << endl;
        currentLineStart += currentLineLength;
    }

    // Draw the bottom border
    cout << "+" << string(cardWidth - 2, '-') << " +" << endl;
    cout << endl;
}

void shownPlayerItem(Player player) {
    cout << setw(50) << setfill('-') << "-" << endl;
    cout << setfill(' ');
    cout << "| " << setw(15) << left << "Category" << "| " << setw(10) << "Amount" << "| " << setw(15) << "Want More" << "|" << endl;
    cout << setw(50) << setfill('-') << "-" << endl;
    cout << setfill(' ');
    cout << "| " << setw(15) << left << "\033[1m\033[31mMeats\033[0m" << "| " << setw(10) << player.mainIngredients << "| " << setw(15) << player.recipe.mainIngredients.size() - player.mainIngredients << "|" << endl;
    cout << "| " << setw(15) << left << "\033[1m\033[38;5;214mSpices\033[0m" << "| " << setw(10) << player.spices << "| " << setw(15) << player.recipe.spices.size() - player.spices << "|" << endl;
    cout << "| " << setw(15) << left << "\033[1m\033[38;5;94mHerbs\033[0m" << "| " << setw(10) << player.herbs << "| " << setw(15) << player.recipe.herbs.size() - player.herbs << "|" << endl;
    cout << "| " << setw(15) << left << "\033[1m\033[32mVegetables\033[0m" << "| " << setw(10) << player.specialIngredients << "| " << setw(15) << player.recipe.specialIngredients.size() - player.specialIngredients << "|" << endl;
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
    cout << "DEBUG: Scan color:\n";
    for (const string& color : uniqueColors) {
        cout << color << endl;
    }

    // เลือกส่วนผสมตามสีที่ไม่ซ้ำ
    for (const string& color : uniqueColors) {
        cout << "Please add the ingredients for the color. " << color << ":" << endl;
        string ingredient;
        bool valid = false;

        while (!valid) {
            cout << "Select ingredient number: ";
            int index;
            cin >> index;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a valid number.\n";
                continue;
            }

            // ตรวจสอบและเลือกส่วนผสมตามประเภทสี
            if (color == "Red") {
                if(player.mainIngredients >= player.recipe.mainIngredients.size()){
                    cout << "You have already reached the maximum main ingredients" << endl;
                    continue;
                }
        
            } else if (color == "Brown"){
                if(player.herbs >= player.recipe.herbs.size()){
                    cout << "You have already reached the maximum herbs" << endl;
                    continue;
                }
        
            } else if (color == "Orange") {
                 if(player.spices >= player.recipe.spices.size()){
                    cout << "You have already reached the maximum spices" << endl;
                    continue;
                }
            } else if (color == "Green") {
                 if(player.specialIngredients >= player.recipe.specialIngredients.size()){
                    cout << "You have already reached the maximum specialIngredients" << endl;
                    continue;
                }
            }else{
                cout << "Color invalid." << endl;
                continue;
            }

        // บันทึกส่วนผสมที่เลือกลง Player
        player.ingredients.push_back(ingredient);
    }
}
}

bool checkIngredients(const Player& player){
    set<string> requiredIngredients(player.recipe.mainIngredients.begin(), player.recipe.mainIngredients.end());
    requiredIngredients.insert(player.recipe.spices.begin(), player.recipe.spices.end());
    requiredIngredients.insert(player.recipe.herbs.begin(), player.recipe.herbs.end());
    requiredIngredients.insert(player.recipe.specialIngredients.begin(), player.recipe.specialIngredients.end());

    for (const string& ingredient : player.ingredients) {
        requiredIngredients.erase(ingredient);
    }

    return requiredIngredients.empty();
}

bool isNameUnique(const vector<Player>& players, const string& name) {
    for (const auto& player : players) {
        if (player.name == name) {
            return false; // ถ้าชื่อซ้ำจะส่งค่าผลลัพธ์เป็น false
        }
    }
    return true; // ถ้าชื่อไม่ซ้ำ
}

string getColorForIngredientType(const string& ingredientType) {
    if (ingredientType == "meat") return "\033[31m";  // Red for meat
    if (ingredientType == "herb") return "\033[38;5;94m";  // Brown for herb
    if (ingredientType == "spice") return "\033[38;5;214m";  // orange for spices
    if (ingredientType == "vegetable") return "\033[32m";  // Green for vegetables
    return "\033[0m";  // Reset for default
}



int main(){
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
        cout << "\033[31m*\033[0m" << " [\033[1;32m2\033[0m" << " players]  " << "[\033[1;32m3\033[0m"<<" players]  " <<"[\033[1;32m4\033[0m"<<" players] " << "\033[31m*\033[0m" << endl;
        cout << "\033[31m*\033[0m" << "                                       " << "\033[31m*\033[0m" << endl;
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
    
    cin.ignore(); // กำจัดบรรทัดที่ค้างจากการรับค่า numPlayers
    for (int i = 0; i < numPlayers; i++) {
        cout << endl;
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
                cout << endl;
                cout << "Name already taken. Please choose a different name.\n";
                cout << endl;
            }
        }
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
            Card card = drawFortuneCard(); // Draw a card
            displayCard(card); // Display the card
            players[i] = handleCardEffect(players[i],card);
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
