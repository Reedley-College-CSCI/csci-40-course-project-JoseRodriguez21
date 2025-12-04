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

    cout << "Enter your name: ";
    getline(cin, userName);

    cout << "\nWelcome, " << userName << "! Let's manage your recipe book." << endl;

    while (true) {
        displayMenu();
        
        while (!(cin >> userChoice)) {
            cout << "Invalid input, try again: ";
            cin.clear();
            cin.ignore(999, '\n');
        }
        cin.ignore();

        if (userChoice == -99)
            break;

        switch (userChoice) {
            case 1: addRecipe(recipeBook, recipeCount); break;
        }
        
    }

    return 0;
}

void displayMenu() {
    cout << "\n        RECIPE BOOK     " << endl;
    cout << "------------------------------" << endl;
    cout << "1 - Add a recipe" << endl;
    cout << "2 - Search for a recipe" << endl;
    cout << "3 - Display all recipes" << endl;
    cout << "4 - Delete a recipe" << endl;
    cout << "-99 - exit the program" << endl;
    cout << "------------------------------" << endl;
    cout << "Enter a choice: ";
}

void loadRecipes(Recipe recipeBook[], int& recipeCount) {
    ifstream inFile("recipes.txt");

    if (!inFile) {
        cout << "/nNo saved recipes found." << endl;
        return;
    }

    inFile >> recipeCount;
    inFile.ignore();

    for (int i = 0; i < recipeCount; i++) {
        recipeBook[i].loadFile(inFile);
    }

    cout << "\nLoaded " << recipeCount << " saved recipes." << endl;


}

void addRecipe(Recipe recipeBook[], int& recipeCount) {
    if (recipeCount == MAX_RECIPES) {
        cout << "\nMaximum of 15 recipes reached." << endl;
        return;
    }

    recipeBook[recipeCount].inputRecipe(recipeCoount + 1);
    recipeCount++;
}




