#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>
#include <algorithm>
#include <iomanip>
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
    {"Black pepper", "herb"}, {"Long pepper", "herb"}, {"Cinnamon", "herb"}, {"Clove", "herb"}
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
    cout << "\n------------------------------------------------------------------------------------------------------\n" << "\n\n\n";
}

//ฟังก์ชันทอยลูกเต๋า
vector<string> rollFourSideDice(){
    vector<string> resultsColour;
    srand(time(0));
    string Colors[] = {"Red","Brown","Orange","Green"};

    cout << "The results of the dice roll:  ";
    for (int i = 0; i < 4; i++){
        int roll = (rand() % 4);
        cout << Colors[roll] << " "; 
        resultsColour.push_back(Colors[roll]);
    }
    cout << endl;
    
    sort(resultsColour.begin(),resultsColour.end());
    vector<string>::iterator uniqueColour;
    uniqueColour = unique(resultsColour.begin(),resultsColour.end());
    resultsColour.resize(distance(resultsColour.begin(),uniqueColour));
    return resultsColour;
}

Player drawFortuneCard(Player player) {
    vector<string> cards = {"Suan Krua", "Moitgure", "Regular Customer", "Moldy Cutting Board", "The Kitchen", "Rainy Season", "Falling Mortar", "Falling Tray"};
    
    int randomCards = rand() % cards.size(); // สุ่มดัชนีการ์ด
    string selectedCard = cards[randomCards]; // เก็บการ์ดที่สุ่มได้

    cout << "Gangster's Fortune Card: " << selectedCard << endl;

    if (selectedCard == "Suan Krua") {
        cout << "Many of the spices in Chili Laap are found in Lanna gardens and today you have the opportunity to visit that garden and pick up the brown spices you want.\n";
        player.herbs++;
        if(player.herbs >= player.recipe.herbs.size()){
            player.herbs--;
            if(player.mainIngredients < player.recipe.mainIngredients.size()){
                player.mainIngredients++;
            }else if(player.spices < player.recipe.spices.size()){
                player.spices++;
            }else if(player.specialIngredients < player.recipe.specialIngredients.size()){
                player.specialIngredients++;
            }
        }
    } else if (selectedCard == "Moitgure") {
        cout << "Good chili paste is dry. Moisture causes chili paste to clump and mold. Your spices have moisture that will ruin your chili paste. Pick up 1 brown spice and return it to the center pile.\n";
        player.herbs--;
        if(player.herbs < 0){
            player.herbs++;
        }
    } else if (selectedCard == "Regular Customer") {
        cout << "Being a regular at the butcher shop gives you the chance to choose quality meat before anyone else. Pick up one of the red tokens.\n";
        player.mainIngredients++;
        if(player.mainIngredients >= player.recipe.mainIngredients.size()){
            player.mainIngredients--;
            if(player.spices < player.recipe.spices.size()){
                player.spices++;
            }else if(player.herbs < player.recipe.herbs.size()){
                player.herbs++;
            }else if(player.specialIngredients < player.recipe.specialIngredients.size()){
                player.specialIngredients++;
            }
        }
    } else if (selectedCard == "Moldy Cutting Board") {
        cout << "The cutting board for making larb must be dry and clean. Failure to store the cutting board causes mold and damages the meat. Pick up 1 red poden. Return to the center pile.\n";
        player.mainIngredients--;
        if(player.mainIngredients < 0){
            player.mainIngredients++;
        }
    } else if (selectedCard == "The Kitchen") {
        cout << "Many of the spices in chili paste are found in the kitchen garden. Just pick up one orange spice of your choice.\n";
        player.spices++;
        if(player.spices >= player.recipe.spices.size()){
            player.spices--;
            if(player.mainIngredients < player.recipe.mainIngredients.size()){
                player.mainIngredients++;
            }else if(player.herbs < player.recipe.herbs.size()){
                player.herbs++;
            }else if(player.specialIngredients < player.recipe.specialIngredients.size()){
                player.specialIngredients++;
            }
        }
    } else if (selectedCard == "Rainy Season") {
        cout << "The humid rainy season brings forth many kinds of vegetables that are perfect for eating with laab. Pick up any green token you want.\n";
        player.specialIngredients++;
        if(player.specialIngredients >= player.recipe.specialIngredients.size()){
            player.specialIngredients--;
            if(player.mainIngredients < player.recipe.mainIngredients.size()){
                player.mainIngredients++;
            }else if(player.spices < player.recipe.spices.size()){
                player.spices++;
            }else if(player.herbs < player.recipe.herbs.size()){
                player.herbs++;
            }
        }
    } else if (selectedCard == "Falling Mortar") {
        cout << "Mortar is a tool used to finely pound spices and turn them into chili paste. Your mortar spoiled the prepared spices. Pick up 1 orange spice and return it to the center pile.\n";
        player.spices--;
        if(player.spices < 0){
            player.spices++;
        }
    } else if(selectedCard == "Falling Tray") {
        cout << "You prepared the vegetables and the laab well, but unfortunately you made 1 piece of green yin poden tray back to the center.\n";
        player.specialIngredients--;
        if(player.specialIngredients < 0){
            player.specialIngredients++;
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

void shownPlayerItem(Player player){
    cout << "**Item inventory**" << endl;
    cout << "Meats: " << player.mainIngredients << "(want more: " <<  player.recipe.mainIngredients.size() - player.mainIngredients << " )" << endl;
    cout << "Spices: " << player.spices << "(want more: " <<  player.recipe.spices.size() - player.spices << " )" << endl;
    cout << "Herbs: " << player.herbs << "(want more: " <<  player.recipe.herbs.size() - player.herbs << " )" << endl;
    cout << "Vetgetables: " << player.specialIngredients << "(want more: " <<  player.recipe.specialIngredients.size() - player.specialIngredients << " )" << endl;
}

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
    
    // สุ่มสูตรลาบ
    for (int i = 0; i < numPlayers; i++) {
    LarbRecipe recipe = drawLarbRecipe();
        players[i].recipe = recipe;
        cout << players[i].name << " Received recipe: " << players[i].recipe.name << "\n";
        printRecipe(recipe);
    }
    int i = 0;
    while(true){
        cin.ignore();
        cout << "This is your turn:" <<  players[i].name << endl;
        cout << "Press [Enter] for roll dice";
        cin.get();
        vector<string> resultsColour = rollFourSideDice();

        if(resultsColour.size() == 4){
            cout << "You get the ingrediant!!!";
            for(int j = 4; j > 0; j--){
             if(players[i].mainIngredients < players[i].recipe.mainIngredients.size()){
                players[i].mainIngredients++; 
                j--;
                if(j == 0) break;

            }
             if(players[i].spices < players[i].recipe.spices.size()){
                players[i].spices++; 
                j--;
                if(j == 0) break;
            }
              if(players[i].herbs < players[i].recipe.herbs.size()){
                players[i].herbs++; 
                j--;
                if(j == 0) break;
            }
             if(players[i].specialIngredients < players[i].recipe.specialIngredients.size()){
                players[i].specialIngredients++; 
                j--;
                if(j == 0) break;
            }
            cout << endl;
        }
        

        //เรียกใช้การ์ดดวง
        }else{
        players[i] = drawFortuneCard(players[i]);
        cout << endl;
        }

        if(Winner(players[i])){
            cout << "The winner is " << players[i].name;
            break;
        }

        shownPlayerItem(players[i]);
        i++;
        if(i >= numPlayers){
            i = 0;
        }
    }
        return 0;
}