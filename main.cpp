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
#include <unordered_set>
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
    int mainIngredients = 0;
    int spices = 0;
    int herbs = 0;
    int specialIngredients = 0;

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

void printIngredient(const vector<string>& ingredients) {
    for (int i = 0; i < ingredients.size(); i++) {
        if (i != 0) {
            cout << ", ";
        }
        cout << ingredients[i];
    }
}
//แสดงสูตรลาบ และส่วนผสม
void printRecipe(const LarbRecipe& recipe) {
    cout << endl;
    cout << left << setw(20) << "Category" << setw(60) << "Ingredients" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(20) << "\033[31mMeats:              \033[0m";
    printIngredient(recipe.mainIngredients);
    cout << endl;
    cout << setw(20) << "\033[38;5;214mSpices:             \033[0m";
    printIngredient(recipe.spices);
    cout << endl;
    cout << setw(20) << "\033[38;5;94mHerbs:              \033[0m";
    printIngredient(recipe.herbs);
    cout << endl;
    cout << setw(20) << "\033[32mVegetables:         \033[0m";
    printIngredient(recipe.specialIngredients);
    cout << "\n-------------------------------------------------------------------------------------------------------------\n" << "\n";
}
//ฟังก์ชันทอยลูกเต๋า
vector<string> rollFourSideDice() {
    vector<string> resultsColour;
    string Colors[] = {"\033[31mRed\033[0m", "\033[38;5;94mBrown\033[0m", "\033[38;5;214mOrange\033[0m", "\033[32mGreen\033[0m"};

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

void inputRedIngredients(Player& player) {
    static unordered_map<string, unordered_set<string>> selectedRedIngredientsPerPlayer; // เก็บวัตถุดิบที่เลือกไปแล้ว

    vector<string>& availableRedIngredients = player.recipe.mainIngredients;

    if (availableRedIngredients.empty()) {
        cout << "No available red ingredients.\n";
        return;
    }

    cout << "\nAvailable red ingredients:\n";
    for (size_t i = 0; i < availableRedIngredients.size(); ++i) {
        if(selectedRedIngredientsPerPlayer[player.name].find(availableRedIngredients[i]) != selectedRedIngredientsPerPlayer[player.name].end()){
            cout << i + 1 << ". " << availableRedIngredients[i] << " (\033[33mYou already slected\033[0m)\n";
        } else {
            cout << i + 1 << ". " << availableRedIngredients[i] << endl;
        }
    }

    bool valid = false;
    int index;
    while (!valid) {
        cout << "Select a red ingredient number (1 - " << availableRedIngredients.size() << "): ";
        cin >> index;

        if (cin.fail() || index < 1 || index > availableRedIngredients.size()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number.\n";
            continue;
        }

        string selectedIngredient = availableRedIngredients[index - 1];

        if (selectedRedIngredientsPerPlayer[player.name].find(selectedIngredient) != selectedRedIngredientsPerPlayer[player.name].end()) {
            cout << "You have already selected this ingredient. Please choose a different one.\n";
            continue;
        }

        player.mainIngredients++;
        selectedRedIngredientsPerPlayer[player.name].insert(selectedIngredient);
        player.ingredients.push_back(selectedIngredient);
        cout << "Added: " << selectedIngredient << " to your ingredients.\n";
        valid = true;
    }
}

void inputBrownIngredients(Player& player) {
    static unordered_map<string, unordered_set<string>> selectedBrownIngredientsPerPlayer;
    vector<string>& availableBrownIngredients = player.recipe.herbs;

    if (availableBrownIngredients.empty()) {
        cout << "No available brown ingredients.\n";
        return;
    }

    cout << "\nAvailable brown ingredients:\n";
    for (size_t i = 0; i < availableBrownIngredients.size(); ++i) {
        if(selectedBrownIngredientsPerPlayer.find(availableBrownIngredients[i]) != selectedBrownIngredientsPerPlayer.end()){
            cout << i + 1 << ". " << availableBrownIngredients[i] << " (\033[33mYou already slected\033[0m)\n";
        } else {
            cout << i + 1 << ". " << availableBrownIngredients[i] << endl;
        }
    }

    int index;
    while (true) {
        cout << "Select a brown ingredient number (1 - " << availableBrownIngredients.size() << "): ";
        cin >> index;

        if (cin.fail() || index < 1 || index > availableBrownIngredients.size()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number.\n";
            continue;
        }

        string selectedIngredient = availableBrownIngredients[index - 1];

        if (selectedBrownIngredientsPerPlayer[player.name].find(selectedIngredient) != selectedBrownIngredientsPerPlayer[player.name].end()) {
            cout << "You have already selected this ingredient. Choose a different one.\n";
            continue;
        }

        player.herbs++;
        selectedBrownIngredientsPerPlayer[player.name].insert(selectedIngredient);
        player.ingredients.push_back(selectedIngredient);
        cout << "Added: " << selectedIngredient << " to your ingredients.\n";
        break;
    }
}

void inputOrangeIngredients(Player& player) {
    static unordered_map<string, unordered_set<string>> selectedOrangeIngredientsPerPlayer; // เก็บวัตถุดิบที่เลือกไปแล้ว
    vector<string>& availableOrangeIngredients = player.recipe.spices;

    if (availableOrangeIngredients.empty()) {
        cout << "No available orange ingredients.\n";
        return;
    }

    cout << "\nAvailable orange ingredients:\n";
    for (size_t i = 0; i < availableOrangeIngredients.size(); ++i) {
        if(selectedOrangeIngredientsPerPlayer.find(availableOrangeIngredients[i]) != selectedOrangeIngredientsPerPlayer.end()){
            cout << i + 1 << ". " << availableOrangeIngredients[i] << " (\033[33mYou already slected\033[0m)\n";
        } else {
            cout << i + 1 << ". " << availableOrangeIngredients[i] << endl;
        }
    }

    int index;
    while (true) {
        cout << "Select an orange ingredient number (1 - " << availableOrangeIngredients.size() << "): ";
        cin >> index;

        if (cin.fail() || index < 1 || index > availableOrangeIngredients.size()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number.\n";
            continue;
        }

        string selectedIngredient = availableOrangeIngredients[index - 1];

        if (selectedOrangeIngredientsPerPlayer[player.name].find(selectedIngredient) != selectedOrangeIngredientsPerPlayer[player.name].end()) {
            cout << "You have already selected this ingredient. Choose a different one.\n";
            continue;
        }

        player.spices++;
        selectedOrangeIngredientsPerPlayer[player.name].insert(selectedIngredient);
        player.ingredients.push_back(selectedIngredient);
        cout << "Added: " << selectedIngredient << " to your ingredients.\n";
        break;
    }
}

void inputGreenIngredients(Player& player) {
    static unordered_map<string, unordered_set<string>> selectedGreenIngredientsPerPlayer;
    vector<string>& availableGreenIngredients = player.recipe.specialIngredients;

    if (availableGreenIngredients.empty()) {
        cout << "No available green ingredients.\n";
        return;
    }

    cout << "\nAvailable green ingredients:\n";
    for (size_t i = 0; i < availableGreenIngredients.size(); ++i) {
        if (selectedGreenIngredientsPerPlayer[player.name].find(availableGreenIngredients[i]) != selectedGreenIngredientsPerPlayer[player.name].end()) {
            cout << i + 1 << ". " << availableGreenIngredients[i] << " (\033[33mYou already selected\033[0m)\n";
        } else {
            cout << i + 1 << ". " << availableGreenIngredients[i] << endl;
        }
    }

    int index;
    while (true) {
        cout << "Select a green ingredient number (1 - " << availableGreenIngredients.size() << "): ";
        cin >> index;

        if (cin.fail() || index < 1 || index > availableGreenIngredients.size()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number.\n";
            continue;
        }

        string selectedIngredient = availableGreenIngredients[index - 1];

        if (selectedGreenIngredientsPerPlayer[player.name].find(selectedIngredient) != selectedGreenIngredientsPerPlayer[player.name].end()) {
            cout << "You have already selected this ingredient. Choose a different one.\n";
            continue;
        }

        player.specialIngredients++;
        selectedGreenIngredientsPerPlayer[player.name].insert(selectedIngredient);

        player.ingredients.push_back(selectedIngredient);
        cout << "Added: " << selectedIngredient << " to your ingredients.\n";
        break;
    }
}


void removeIngredient(Player& player, const string& colorCategory) {
    vector<string>* ingredientList;
    int* ingredientCount;

    // กำหนดรายการวัตถุดิบและตัวนับตามสีที่เลือก
    if (colorCategory == "Red") {
        ingredientList = &player.recipe.mainIngredients;
        ingredientCount = &player.mainIngredients;
    } else if (colorCategory == "Brown") {
        ingredientList = &player.recipe.herbs;
        ingredientCount = &player.herbs;
    } else if (colorCategory == "Orange") {
        ingredientList = &player.recipe.spices;
        ingredientCount = &player.spices;
    } else if (colorCategory == "Green") {
        ingredientList = &player.recipe.specialIngredients;
        ingredientCount = &player.specialIngredients;
    } else {
        cout << "Invalid color category.\n";
        return;
    }

    // ค้นหาวัตถุดิบที่ผู้เล่นมีอยู่ (ไม่ซ้ำกัน)
    unordered_set<string> ownedIngredientsSet; // ใช้ set เพื่อป้องกันวัตถุดิบซ้ำ
    for (const string& ingredient : player.ingredients) {
        if (find(ingredientList->begin(), ingredientList->end(), ingredient) != ingredientList->end()) {
            ownedIngredientsSet.insert(ingredient);
        }
    }

    if (ownedIngredientsSet.empty()) {
        cout << "You have no " << colorCategory << " ingredients to remove.\n";
        return;
    }

    // แปลง set เป็น vector เพื่อแสดงรายการ
    vector<string> ownedIngredients(ownedIngredientsSet.begin(), ownedIngredientsSet.end());

    // แสดงรายการที่สามารถลบได้
    cout << "\nAvailable " << colorCategory << " ingredients to remove:\n";
    for (size_t i = 0; i < ownedIngredients.size(); ++i) {
        cout << i + 1 << ". " << ownedIngredients[i] << endl;
    }

    int index;
    while (true) {
        cout << "Select an ingredient number to remove (1 - " << ownedIngredients.size() << "): ";
        cin >> index;

        if (cin.fail() || index < 1 || index > ownedIngredients.size()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number.\n";
            continue;
        }

        string removedIngredient = ownedIngredients[index - 1];

        // ลบจากรายการของผู้เล่น
        player.ingredients.erase(remove(player.ingredients.begin(), player.ingredients.end(), removedIngredient), player.ingredients.end());

        // ลดจำนวนของวัตถุดิบนั้น
        (*ingredientCount)--;

        cout << "Removed: " << removedIngredient << " from your ingredients.\n";
        break;
    }
}


Player handleCardEffect(Player player, const Card& card) {
    if (card.name == "Suan Krua") {
        inputBrownIngredients(player);
        if (player.herbs > player.recipe.herbs.size()) {
            player.herbs--; // Remove the extra one

            // Distribute to other categories if available
            if (player.mainIngredients < player.recipe.mainIngredients.size()) {
                inputRedIngredients(player);
            }
            else if (player.spices < player.recipe.spices.size()) {
                inputOrangeIngredients(player);
            }
            else if (player.specialIngredients < player.recipe.specialIngredients.size()) {
                inputGreenIngredients(player);
            }   
        }
    }
    else if (card.name == "Moitgure") {
        removeIngredient(player, "Brown");
        if (player.herbs < 0) {
            player.herbs = 0;
        }
    }
    else if (card.name == "Regular Customer") {
        inputRedIngredients(player);
        if (player.mainIngredients > player.recipe.mainIngredients.size()) {
            player.mainIngredients--;
            if (player.spices < player.recipe.spices.size()) {
                inputOrangeIngredients(player);
            }
            else if (player.herbs < player.recipe.herbs.size()) {
                inputBrownIngredients(player);
            }
            else if (player.specialIngredients < player.recipe.specialIngredients.size()) {
                inputGreenIngredients(player);
            }
        }
    }
    else if (card.name == "Moldy Cutting Board") {
        removeIngredient(player, "Red");
        if (player.mainIngredients < 0) {
            player.mainIngredients = 0;
        }
    }
    else if (card.name == "The Kitchen") {
        inputOrangeIngredients(player);
        if (player.spices > player.recipe.spices.size()) {
            player.spices--;
            if (player.mainIngredients < player.recipe.mainIngredients.size()) {
                inputRedIngredients(player);
            }
            else if (player.herbs < player.recipe.herbs.size()) {
                inputBrownIngredients(player);
            }
            else if (player.specialIngredients < player.recipe.specialIngredients.size()) {
                inputGreenIngredients(player);
            }
        }
    }
    else if (card.name == "Rainy Season") {
        inputGreenIngredients(player);
        if (player.specialIngredients > player.recipe.specialIngredients.size()) {
            player.specialIngredients--;
            if (player.mainIngredients < player.recipe.mainIngredients.size()) {
                inputRedIngredients(player);
            }
            else if (player.spices < player.recipe.spices.size()) {
                inputOrangeIngredients(player);
            }
            else if (player.herbs < player.recipe.herbs.size()) {
                inputBrownIngredients(player);
            }
        }
    }
    else if (card.name == "Falling Mortar") {
        removeIngredient(player, "Orange");
        if (player.spices < 0) {
            player.spices = 0;
        }
    }
    else if (card.name == "Falling Tray") {
        removeIngredient(player, "Green");
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

void shownPlayerItem(const Player& player) {
    // ป้องกันค่าติดลบโดยใช้ max()
    int needMeat = max(0, (int)player.recipe.mainIngredients.size() - player.mainIngredients);
    int needSpices = max(0, (int)player.recipe.spices.size() - player.spices);
    int needHerbs = max(0, (int)player.recipe.herbs.size() - player.herbs);
    int needVegetables = max(0, (int)player.recipe.specialIngredients.size() - player.specialIngredients);

    cout << "\n+------------------------------------------+\n";
    cout << "|            \033[1mYour Ingredients\033[0m              |\n";
    cout << "+------------------------------------------+\n";
    cout << "| Category     | Amount  | Need More       |\n";
    cout << "+--------------+---------+-----------------+\n";
    cout << "| \033[31mMeats       \033[0m | " << setw(7) << player.mainIngredients << " | " << setw(15) << needMeat << " |\n";
    cout << "| \033[38;5;214mSpices      \033[0m | " << setw(7) << player.spices << " | " << setw(15) << needSpices << " |\n";
    cout << "| \033[38;5;94mHerbs       \033[0m | " << setw(7) << player.herbs << " | " << setw(15) << needHerbs << " |\n";
    cout << "| \033[32mVegetables  \033[0m | " << setw(7) << player.specialIngredients << " | " << setw(15) << needVegetables << " |\n";
    cout << "+--------------+---------+-----------------+\n";
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
    vector<string> uniqueColors = getUniqueColors(colors);
    static unordered_map<string, unordered_map<string, unordered_set<int>>> selectedIndicesPerPlayer; // แยกตามผู้เล่น
    static unordered_map<string, unordered_map<string, unordered_set<string>>> selectedIngredientsPerPlayer; // แยก selectedIngredients ตามผู้เล่น
    unordered_map<string, vector<string>> ingredientMap = {
        {"\033[31mRed\033[0m", player.recipe.mainIngredients},
        {"\033[38;5;94mBrown\033[0m", player.recipe.herbs},
        {"\033[38;5;214mOrange\033[0m", player.recipe.spices},
        {"\033[32mGreen\033[0m", player.recipe.specialIngredients}
    };

    unordered_map<string, int*> ingredientCountMap = {
        {"\033[31mRed\033[0m", &player.mainIngredients},
        {"\033[38;5;94mBrown\033[0m", &player.herbs},
        {"\033[38;5;214mOrange\033[0m", &player.spices},
        {"\033[32mGreen\033[0m", &player.specialIngredients}
    };

    for (const string& color : uniqueColors) {
        if (ingredientMap.find(color) == ingredientMap.end()) {
            cout << "Unknown color category: " << color << endl;
            continue;
        }

        cout << "\nPlease select an ingredient for " << color << " category:\n";
        vector<string>& availableIngredients = ingredientMap[color];

        if (availableIngredients.empty()) {
            cout << "No available ingredients for " << color << "\n";
            continue;
        }

        for (size_t i = 0; i < availableIngredients.size(); ++i) {
            if (selectedIndicesPerPlayer[player.name][color].find(i + 1) != selectedIndicesPerPlayer[player.name][color].end()) {
                cout << i + 1 << ". " << availableIngredients[i] << " (\033[33mYou already selected\033[0m)\n";
            } else {
                cout << i + 1 << ". " << availableIngredients[i] << "\n";
            }
        }

        int index;
        while (true) {
            cout << "Select ingredient number (1 - " << availableIngredients.size() << "): ";
            cin >> index;

            if (cin.fail() || index < 1 || index > availableIngredients.size()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid number.\n";
                continue;
            }

            if (selectedIndicesPerPlayer[player.name][color].find(index) != selectedIndicesPerPlayer[player.name][color].end()) {
                cout << "\nThis ingredient has already been selected. Please choose another.\n\n";
                continue;
            }

            string selectedIngredient = availableIngredients[index - 1];
            player.ingredients.push_back(selectedIngredient);
            (*ingredientCountMap[color])++;
            selectedIndicesPerPlayer[player.name][color].insert(index);
            cout << "Added: " << selectedIngredient << " to your ingredients.\n";
            break;
        }
    }
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

bool isNameUnique(const vector<Player>& players, const string& name) {
    for (const auto& player : players) {
        if (player.name == name) {
            return false;
        }
    }
    return true;
}

// Function to get a valid player name
string validateName(const vector<Player>& players, int playerNumber) {
    string playerName;
    bool uniqueName = false;

    while (!uniqueName) {
        cout << "Enter player " << playerNumber << " name: ";
        getline(cin, playerName); // Use getline to handle spaces in names

        if (playerName.empty()) {
            cout << endl;
            cout << "Name cannot be empty. Please enter a valid name.\n";
            cout << endl;
            continue;
        }

        if (isNameUnique(players, playerName)) {
            uniqueName = true;
        } else {
            cout << endl;
            cout << "Name already taken. Please choose a different name.\n";
            cout << endl;
        }
    }
    return playerName;
}

void displayWinner(const string& winnerName) {
    cout << "\n******************************************\n";
    cout << "*                                        *\n";
    cout << "*           CONGRATULATIONS!             *\n";
    cout << "*    You are the Real gangster laab      *\n";
    cout << "*       "<< winnerName << " is the winner!               *\n";
    cout << "*                                        *\n";
    cout << "******************************************\n";
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
     cout << endl << "\033[m      [Member Player in this round] \033[0m" << endl;
    
    cin.ignore(); // Clear newline from previous input

    for (int i = 0; i < numPlayers; i++) {
        cout << endl;
        players[i].name = validateName(players, i + 1);
    }
    cout << "\n------------------------------------------\n\n" << endl;
    cout << endl;
    // สุ่มสูตรลาบ
    for (int i = 0; i < numPlayers; i++) {
    LarbRecipe recipe = drawLarbRecipe();
        cout << "=============================================================================================================\n" << endl;
        cout << players[i].name << "!!  Get your recipe [Enter]";
        cin.get();
        players[i].recipe = recipe;
        cout << "received recipe: " << players[i].recipe.name << "\n";
        printRecipe(recipe);
        shownPlayerItem(players[i]);
        cout << "\n=============================================================================================================\n\n\n" << endl;
    }
    int i = 0;
    while(true){
        cout << "\n\n\n";
        cin.get(); 
        cout << "\033[32m#############################################################################################################\033[0m" << "\n" << endl;
        cout << "This is your turn: " <<  players[i].name << endl;
        cout << "\nPress [Enter] for roll dice";
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

        if(Winner(players[i])){
            cout << endl;
            displayWinner(players[i].name); 
            break;

            
        } else {
            cout << endl;
            shownPlayerItem(players[i]);
            i++;
            if(i >= numPlayers){
                i = 0;
            }
            cout << "\n\033[32m#############################################################################################################\033[0m\n" << endl;
        }
       
    }
    return 0;
}
