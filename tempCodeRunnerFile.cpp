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