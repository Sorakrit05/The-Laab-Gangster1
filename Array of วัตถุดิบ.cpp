#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Ingredient {
    string name;
    string type;
};

vector<Ingredient> meats = {
    {"Beef", "meat"},
    {"Pork", "meat"},
    {"Chicken", "meat"},
    {"Beef broth", "meat"},
    {"Fried garlic", "meat"},
    {"Buffalo", "meat"},
    {"Bile", "meat"},
    {"Blood", "meat"},
    {"Offal", "meat"}
};

vector<Ingredient> herbs = {
    {"Makwaen", "herb"},
    {"Coriander", "herb"},
    {"Nut meg", "herb"},
    {"Star Anise", "herb"},
    {"black pepper", "herb"},
    {"Long pepper", "herb"},
    {"Cinnamon", "herb"},
    {"Clove", "herb"}
};

vector<Ingredient> vegetables = {
    {"Matoom", "vegetable"},
    {"KaowTong", "vegetable"},
    {"Oreille", "vegetable"},
    {"Deeplygung", "vegetable"},
    {"Makwen-infused fish sauce", "vegetable"},
    {"Dried Fennel Seed", "vegetable"},
    {"Phak paem", "vegetable"},
    {"Vietnamese Coriander", "vegetable"},
    {"Damocles tree", "vegetable"},
    {"Parsley", "vegetable"},
    {"Para cress", "vegetable"},
    {"Olive", "vegetable"}
};

vector<Ingredient> spice = {
    {"Makwaen", "spice"},
    {"Fragrant", "spice"},
    {"Fennel Seed", "spice"},
    {"Dried Galangal", "spice"},
    {"Cardamom", "spice"},
    {"Chili Spur Pepper", "spice"},
    {"Caraway", "spice"}
};

