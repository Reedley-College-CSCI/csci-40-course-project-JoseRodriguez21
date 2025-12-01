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
};

int main() {
    string userName;
    int recipeCount = 0;
    int userChoice;
    Recipe recipeBook[MAX_RECIPES];

    return 0;
}
