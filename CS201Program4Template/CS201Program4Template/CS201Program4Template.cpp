// CS201Program4Template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Pseudocode
// SET barInventory: smBars = 700
// SET barCost: smCost = 14.99

// While (goAgain == 'Y')
//   GET custPounds
//   SET lgBardsNeeded = custPounds / 5 //Large Bars needed
//   IF (lgBarsNeeded > lgBars)
//     lgBardsNeeded = lgBars

#include <iostream>
# include <iomanip>
using namespace std;

int main()
{
    int barInventorySmall = 700;
    int barInventoryMedium = 500;
    int barInventoryLarge = 620;
    double barCostSmall = 14.99;
    double barCostMedium = 21.99;
    double barCostLarge = 27.99;
    char userInput = 'Y';
    int userPounds;
    cout << "WELCOME TO MY CHOCOLATE FACTORY" << endl;
    while (userInput == 'Y'){
        cout << "Enter total number of pounds of chocolate you would like: ";
        cin >> userPounds;
        int lgBarsNeeded = userPounds / 5;
        if (lgBarsNeeded > barInventoryLarge) {
            lgBarsNeeded = barInventoryLarge;
        }
        userPounds -= lgBarsNeeded * 5;
        int mdBarsNeeded = userPounds / 3;
        if (mdBarsNeeded > barInventoryMedium){
            mdBarsNeeded = barInventoryMedium;
        }
        userPounds -= mdBarsNeeded * 3;
        int smBarsNeeded = userPounds;
        if (smBarsNeeded > barInventorySmall){
            cout << "Your order was too large to be filled." << endl;
        }
        else{
            barInventorySmall -= smBarsNeeded;
            barInventoryMedium -= mdBarsNeeded;
            barInventoryLarge -= lgBarsNeeded;
            double totalSmallBarCost = smBarsNeeded * barCostSmall;
            double totalMediumBarCost = mdBarsNeeded * barCostMedium;
            double totalLargeBarCost = lgBarsNeeded * barCostLarge;
            double total = totalSmallBarCost + totalMediumBarCost + totalLargeBarCost;
            cout << "Your order has been filled:" << endl;
            cout << setw(12) << "Small bars:" << setw(4) << smBarsNeeded << " =" << setw(9) << fixed << setprecision(2) << totalSmallBarCost << endl;
            cout << setw(12) << "Medium bars:" << setw(4) << mdBarsNeeded << " =" << setw(9) << totalMediumBarCost << endl;
            cout << setw(12) << "Large bars:" << setw(4) << lgBarsNeeded << " =" << setw(9) << totalLargeBarCost << endl;
            cout << "Total cost: " << setw(15) << total << endl;
            cout << endl;
            cout << "Remaining Inventory:" << endl;
            cout << setw(12) << "Small bars" << ':' << setw(6) << barInventorySmall << endl;
            cout << setw(12) << "Medium bars" << ':' << setw(6) << barInventoryMedium << endl;
            cout << setw(12) << "Large bars" << ':' << setw(6) << barInventoryLarge << endl;
            cout << endl;
            cout << endl;
        }
        cout << "Enter Y to process more orders: ";
        cin >> userInput;
    }
}
 