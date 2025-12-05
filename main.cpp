// CSCI-40 Final Project
// Author: Jose Rodriguez and Daniel Hernandez

/* 
 * Description: This program takes the idea of a physical recipe book and makes it into a digital version.
 * Giving the user the opportunity to input up to 15 recipes, having several options over their own recipe 
 * book. Making it easier and more accessible for users compared to a physical copy.
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

    void copyFrom(const Recipe& other) {
        name = other.name;
        ingredientCount = other.ingredientCount;

        delete[] ingredients;
        if (ingredientCount > 0) {
            ingredients = new string[ingredientCount];
            for (int i = 0; i < ingredientCount; i++) {
                ingredients[i] = other.ingredients[i];
            }
        } 
        else {
            ingredients = nullptr;
        }

        
    }

    void inputRecipe(int recipeNum) {
        cout << "\nEnter the name of recipe #" << recipeNum << ": ";
        getline(cin, name);
        
        cout << "How many ingredients does " << name << " have?";
        
        while (!(cin >> ingredientCount) || ingredientCount < 1) {
            cout << "Invalid, re-enter the number of ingredients: ";
            cin.clear();
            cin.ignore(999, '\n');
        }
        cin.ignore();

        delete[] ingredients;
        ingredients = new string[ingredientCount];

        cout << "Enter each ingredient: " << endl;
        
        for (int i = 0; i < ingredientCount; i++) {
            cout << "Ingredient #" << (i + 1) << ": ";
            getline(cin, ingredients[i]);
        }      
    }

    void display() const {
        cout << "\nRecipe: " << name << endl;
        cout << "Ingredients: " << endl;

        for (int i = 0; i < ingredientCount; i++) {
            cout << " - " << ingredients[i] << endl;
        }
    }

    string getName() const {
        return name;
    }

    int getIngredientCount() const {
        return ingredientCount;
    }

    void saveFile(ofstream& out) const {
        out << name << endl;
        out << ingredientCount << endl;
        for (int i = 0; i < ingredientCount; i++) {
            out << ingredients[i] << endl;
        }
    }

    void loadFile(ifstream& in) {
        getline(in, name);
        in >> ingredientCount;
        in.ignore();
        
        delete[] ingredients;
        ingredients = new string[ingredientCount];

        for (int i = 0; i < ingredientCount; i++) {
            getline(in, ingredients[i]);
        }
    }
};

void displayMenu();
void loadRecipes(Recipe recipeBook[], int& recipeCount);
void saveRecipes(Recipe recipeBook[], int recipeCount);
void addRecipe(Recipe recipeBook[], int& recipeCount);
void searchRecipe(Recipe recipeBook[], int recipeCount);
void displayAllRecipes(Recipe recipeBook[], int recipeCount, const string& userName);
void deleteRecipe(Recipe recipeBook[], int& recipeCount);

int main() {
    string userName;
    int recipeCount = 0;
    int userChoice;
    Recipe recipeBook[MAX_RECIPES];

    loadRecipes(recipeBook, recipeCount);

    cout << "Enter your name: ";
    getline(cin, userName);

    while (userName == "") {
        cout << "Name cannot be blank. Enter again: ";
        getline(cin, userName);
    }

    cout << "\nWelcome, " << userName << "! Let's manage your recipe book." << endl;

    while (true) {
        displayMenu();
        
        while (!(cin >> userChoice)) {
            cin.clear();
            cin.ignore(999, '\n');
        }
        cin.ignore();

        if (userChoice == -99)
            break;

        switch (userChoice) {
            case 1: addRecipe(recipeBook, recipeCount); break;
            case 2: searchRecipe(recipeBook, recipeCount); break;
            case 3: displayAllRecipes(recipeBook, recipeCount, userName); break;
            case 4: deleteRecipe(recipeBook, recipeCount); break;
            default: cout << "\nInvalid option." << endl; break;
        }
        
    }

    saveRecipes(recipeBook, recipeCount);

    cout << "\nGoodbye, " << userName << "!" << endl;

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
        cout << "\nNo saved recipes found." << endl;
        return;
    }

    inFile >> recipeCount;
    inFile.ignore();

    if (recipeCount < 0 || recipeCount > MAX_RECIPES) {
        recipeCount = 0;
        return;
    }
    
    for (int i = 0; i < recipeCount; i++) {
        recipeBook[i].loadFile(inFile);
    }

    cout << "\nLoaded " << recipeCount << " saved recipes." << endl;


}

void saveRecipes(Recipe recipeBook[], int recipeCount) {
    ofstream fileOut("recipes.txt");

    fileOut << recipeCount << endl;

    for (int i = 0; i < recipeCount; i++) {
        recipeBook[i].saveFile(fileOut);
    }

    cout << "\nRecipes saved to recipes.txt" << endl;
}

void addRecipe(Recipe recipeBook[], int& recipeCount) {
    if (recipeCount == MAX_RECIPES) {
        cout << "\nMaximum of 15 recipes reached." << endl;
        return;
    }

    recipeBook[recipeCount].inputRecipe(recipeCount + 1);
    recipeCount++;

    cout << "\nRecipe added successfully " << endl;
}

void searchRecipe(Recipe recipeBook[], int recipeCount) {
    string searchName;
    cout << "\nEnter recipe name to search: ";
    getline(cin, searchName);

    for (int i = 0; i < searchName.length(); i++) {
        searchName[i] = tolower(searchName[i]);
    }

    for (int i = 0; i < recipeCount; i++) {
        string recipeName = recipeBook[i].getName();

        for (int j = 0; j < recipeName.length(); j++) {
            recipeName[j] = tolower(recipeName[j]);
        }
        
        if (recipeName == searchName) {
            cout << "\nRecipe found!" << endl;
            recipeBook[i].display();
            return;
        }
    }

    cout << "\nRecipe not found." << endl;
}

void displayAllRecipes(Recipe recipeBook[], int recipeCount, const string& userName) {
    if (recipeCount == 0) {
        cout << "\nNo recipes to display." << endl;
        return;
    }

    cout << "\n" << userName << "'s Recipe Book" << endl;
    cout << "------------------------------" << endl;

    for (int i = 0; i < recipeCount; i++) {
        recipeBook[i].display();
    }
}

void deleteRecipe(Recipe recipeBook[], int& recipeCount) {
    if (recipeCount == 0) {
        cout << "\nNo recipes to delete." << endl;
        return;
    }

    string deleteName;
    cout << "\nEnter recipe name to delete: ";
    getline(cin, deleteName);

    for (int i = 0; i < recipeCount; i++) {
        if (recipeBook[i].getName() == deleteName) {

            for (int j = i; j < recipeCount - 1; j++) {
                recipeBook[j].copyFrom(recipeBook[j + 1]);
            }

            recipeCount--;

            cout << "\nRecipe " << deleteName << " deleted." << endl;
            return;
        }
    }
    cout << "\nRecipe not found." << endl;
}






