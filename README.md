[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/7mdzU3H2)
# CS1 Final Project - Recipe Book - Jose Rodriguez - Daniel Hernandez 

## 1. Overview
- What problem does your project solve?
- This project makes having all your recipes stored more accessible and easier to store than having them on a physical copy.
- Briefly describe the purpose and key features of your program.
- The purpose of this program is to enable the user to be able to save recipes, delete them, and search them. The key feature is being able
to see all of them at once without having to flip through pages like a regular recipe book.
- My partner and I created a program to solve the problem of sorting, organizing, and saving recipes for users, allowing them to enter the name and the number of ingredients, naming the ingredients, and store it in memory. 
---

## 2. Design Decisions
- What fundamental programming constructs and data types did you use, and why?
- I use a lot of for loops that are key to checking for something when searching or deleting. The switch statement was another construct
  That was utilized in my program for when the user enters a value. The data types used were integers and strings, which were the only types I utilized.  
- Why did you choose to structure your data using structs?
- I didn't use a struct in my program; instead, I opted to use classes and functions that combine data and behavior together.
- How did you implement searching and sorting? What algorithms did you use and why?
- The program only has a searching system to find the recipe, and it's the same one to find it and to delete it; the one used was the linear search algorithm.
Other algorithms used were inputting values into the text file or gathering the data.
- How do you ensure data persistence between program runs?
- The way the data was saved between runs is creating a recipe text file once the first recipe was inputted. This helps keep the recipes inputted from the user
into the next run.
- Did you consider alternative approaches? If so, why did you not use them?
- The alternative approach for this program was using a class, which I ended up using. This left the first approach of using a struct out of the way. This change occurred
because the ingredients weren't consistent from recipe to recipe.
-  For this project me my partner and used C++ features that we learned throughout the semester to build our recipe management program. I chose strings to store recipes, names, and ingredients, and integers to track things and menu choices. All the recipes are stored in a fixed sized array because the program only allows up to 5 recipes. Inside each recipe object, I used a dynamic array of strings so that every recipe has its own number of ingredients.  We used loops, if-statements, and separate functions to keep the code organized. 
---

## 3. Testing Summary
- **Structured Testing Log:** Include a table with test cases, expected output, actual output, and pass/fail status.  
- What testing methods did you use?
- I ran the program and tried the options from the menu displayed in the program.
- Provide examples of test inputs (valid and invalid) and describe how your program responds.
- Test Case | Description              | Input              | Expected                 | Actual               | P/F
- TC-01     | Add recipe               | Add pasta,         | Recipe saved             | Recipe saved         | P
- TC-02     | Empty recipe name        | Name = ""          |Recipe can't be empty     | Recipe can't be empty| P
- TC-03     | Max recipes reached      | Add 16th recipe    |Maximum reached           |Maximum reached       | P
- TC-04     | Search existing recipe   | Search "Pasta"     | Recipe: Pasta            | Recipe: Pasta         | P
- TC-05     | Leave ingredients blank  | ingredient #1:     | Ingredient can't be empty| Ingredient #2:       | F





---

## 4. Technical Walkthrough
- Explain the main functionality of your program.  
- **Include a link to your required video demonstration** showcasing how the project works (**3-7 minutes**). 
    Ensure it is shareable without requiring approval.
  https://youtu.be/ROlPna1SoJQ
  [(https://youtu.be/lQagGYHq_fA)

---

## 5. Challenges and Lessons Learned
- What challenges did you encounter while working on this project?
- The main challenge was how to make this program not crash in certain situations, which was the reason why I had difficulty adding more features.
- What key lessons did you learn about programming and problem-solving?
- I learned that even though you have an idea of how your code is going to be, some things can change in the process. Also, coding the project takes time because you have to take
account for any problems the user might encounter that can break the program.

---

## 6. Future Improvements
- If you had more time, what changes or enhancements would you make?
- If I had more time or started earlier, I would add an option to edit the recipes, which was something that this program would have had but didn't manage to finish in time.
This feature could have brought this program to the next level and made it more interactive.






