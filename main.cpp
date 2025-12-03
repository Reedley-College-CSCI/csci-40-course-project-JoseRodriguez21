// CSCI-40 Final Project
// Author: Jose Rodriguez and Daniel Hernandez

/* 
 * Description:
 *
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

const int MAX_RECIPES = 15;

class Recipe {
private:
    string name;
    int ingredientCount;
    string* ingredients;

public: 
    Recipe() {
        name = "";
        ingredientCount = 0;
        ingredients = nullptr;
    }
    ~Recipe() {
        delete[] ingredients;

    }
    void loadFile(ifstream& in) {
        getline(in, name);
        in >> ingredientCount;
        in.ignore();

        for (int i = 0; i < ingredientCount; i++) {
            getline(in, ingredients[i]);
        }
    }
};

void loadRecipes(Recipe recipeBook[], int& recipeCount);

int main() {
    string userName;
    int recipeCount = 0;
    int userChoice;
    Recipe recipeBook[MAX_RECIPES];

    loadRecipes(recipeBook, recipeCount);

    return 0;
}

void loadRecipes(Recipe recipeBook[], int& recipeCount) {
    ifstream inFile("recipes.txt");
}