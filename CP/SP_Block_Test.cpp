#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace std::chrono;

// Helper function to lowercase a string
string toLower(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main()
{
    // atomic number -> (element name, symbol)
    unordered_map<int, pair<string, string>> atomicData = {
        {1, {"Hydrogen", "H"}}, {2, {"Helium", "He"}}, {3, {"Lithium", "Li"}}, {4, {"Beryllium", "Be"}}, {5, {"Boron", "B"}}, {6, {"Carbon", "C"}}, {7, {"Nitrogen", "N"}}, {8, {"Oxygen", "O"}}, {9, {"Fluorine", "F"}}, {10, {"Neon", "Ne"}}, {11, {"Sodium", "Na"}}, {12, {"Magnesium", "Mg"}}, {13, {"Aluminium", "Al"}}, {14, {"Silicon", "Si"}}, {15, {"Phosphorus", "P"}}, {16, {"Sulfur", "S"}}, {17, {"Chlorine", "Cl"}}, {18, {"Argon", "Ar"}}, {19, {"Potassium", "K"}}, {20, {"Calcium", "Ca"}}, {31, {"Gallium", "Ga"}}, {32, {"Germanium", "Ge"}}, {33, {"Arsenic", "As"}}, {34, {"Selenium", "Se"}}, {35, {"Bromine", "Br"}}, {36, {"Krypton", "Kr"}}, {37, {"Rubidium", "Rb"}}, {38, {"Strontium", "Sr"}}, {49, {"Indium", "In"}}, {50, {"Tin", "Sn"}}, {51, {"Antimony", "Sb"}}, {52, {"Tellurium", "Te"}}, {53, {"Iodine", "I"}}, {54, {"Xenon", "Xe"}}, {55, {"Cesium", "Cs"}}, {56, {"Barium", "Ba"}}, {81, {"Thallium", "Tl"}}, {82, {"Lead", "Pb"}}, {83, {"Bismuth", "Bi"}}, {84, {"Polonium", "Po"}}, {85, {"Astatine", "At"}}, {86, {"Radon", "Rn"}}, {87, {"Francium", "Fr"}}, {88, {"Radium", "Ra"}}};

    vector<int> atomicNumbers;
    for (const auto &pair : atomicData)
    {
        atomicNumbers.push_back(pair.first);
    }

    srand(time(0));
    string restartChoice;

    // Store incorrect atomic numbers
    set<int> mistakes;

    do
    {
        int randomIndex = rng() % atomicNumbers.size();
        int atomicNumber = atomicNumbers[randomIndex];
        string elementName = atomicData[atomicNumber].first;
        string elementSymbol = atomicData[atomicNumber].second;

        cout << "\nWhat is the element with atomic number " << atomicNumber << "?\n";

        auto startTime = steady_clock::now();

        while (true)
        {
            cout << "Your Answer: ";
            string userInput;
            getline(cin, userInput);
            userInput.erase(remove_if(userInput.begin(), userInput.end(), ::isspace), userInput.end());
            string userLower = toLower(userInput);

            if (userLower == "idk")
            {
                cout << "The correct answer is: " << elementName << " (" << elementSymbol << ")\n";
                mistakes.insert(atomicNumber);
                break;
            }

            string nameLower = toLower(elementName);
            string symbolLower = toLower(elementSymbol);

            if (userLower == nameLower || userLower == symbolLower)
            {
                cout << "Correct! The correct answer is: " << elementName << " (" << elementSymbol << ")\n";
                break;
            }
            else
            {
                cout << "Wrong. Try again...\n";
                mistakes.insert(atomicNumber);
            }
        }

        auto endTime = steady_clock::now();
        auto duration = duration_cast<seconds>(endTime - startTime);
        cout << "Time taken for this question: " << duration.count() << " seconds.\n";

        cout << "Do you want to try another atomic number? (Y/N): ";
        getline(cin, restartChoice);

    } while (restartChoice == "Y" || restartChoice == "y");

    // Summary of mistakes
    if (!mistakes.empty())
    {
        cout << "\nYou had trouble with these atomic numbers:\n";
        for (int num : mistakes)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    cout << "Goodbye!\n";
    return 0;
}
