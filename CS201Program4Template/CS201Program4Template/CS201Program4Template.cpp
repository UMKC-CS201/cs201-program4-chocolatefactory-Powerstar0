//Name: Johnny Diep
//Date: 02/03/2023
//PROGRAM 4: Chocolate Factory
//Purpose: Allows the user to help efficiently make orders for their chocolate warehouse
//allowing them to first use up their large bars, then medium, and then small as well as
//calculate the total cost of each order. Inventory of each bar type is checked so
//the program can let the user know when they can't fill an order. Program can be looped.

// CS201Program4Template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Pseudocode
// SET barInventory: smBars = 700
// SET barCost: smCost = 14.99
// SET barInventory: mdBars  = 500
// SET barCost: mdCost = 21.99
// SET barInventory: lgBars  = 620
// SET barCost: lgCost = 27.99

// SET goAgain = 'Y'
// While (goAgain == 'Y')
//   GET custPounds
//
//   SET lgBarsNeeded = custPounds / 5     //Large Bars needed
//   IF (lgBarsNeeded > lgBars)
//     lgBarsNeeded = lgBars           //Get as many large bars as possible if there isn't enough in stock
//   custPounds = custPounds - (lgBarsNeeded * 5) //Subtract from total pounds needed
//
//   SET mdBarsNeeded = custPounds / 3     //Medium Bars needed
//   IF (mdBarsNeeded > mdBars)
//     mdBarsNeeded = mdBars           //Get as many medium bars as possible if there isn't enough in stock
//   custPounds = custPounds - (mdBarsNeeded * 3) //Subtract from total pounds needed
//
//   SET mdBarsNeeded = custPounds     //Small Bars needed
//   IF (mdBarsNeeded > mdBars)
//     PRINT "Your order was too large"          //Tell user order was too large
//   Else
//     SUBTRACT lgBarsNeeded from lgBars (Inventory)
//     SUBTRACT mdBarsNeeded from mdBars (Inventory)
//     SUBTRACT smBarsNeeded from smBars (Inventory)
//     CALCULATE/SET total_cost: (lgBarsNeeded * lgCost) + (mdBarsNeeded * mdCost) + (smBarsNeeded * smCost)
//     PRINT lgBarsNeeded
//     PRINT mdBarsNeeded
//     PRINT smBarsNeeded
//     PRINT total_cost
//     PRINT REMAINING INVENTORY (lgBars, mdBars, smBars)
//     PROMPT user if they would like to process more orders ('Y')


#include <iostream>
# include <iomanip>
using namespace std;

int main()
{
    // Set Initial Inventory of Bar Sizes as well as Prices
    int barInventorySmall = 700;
    int barInventoryMedium = 500;
    int barInventoryLarge = 620;
    double barCostSmall = 14.99;
    double barCostMedium = 21.99;
    double barCostLarge = 27.99;
    // Sets userInput to 'Y' for first loop and initializes userPounds
    char userInput = 'Y';
    int userPounds;
    cout << "WELCOME TO MY CHOCOLATE FACTORY" << endl;
    // Main Loop while userInput == 'Y' or 'y'
    while ((userInput == 'Y') or (userInput == 'y')){
        // Asks User for pounds of chocolate and assigns it to userPounds
        cout << "Enter total number of pounds of chocolate you would like: ";
        cin >> userPounds;
        int lgBarsNeeded = userPounds / 5; //Sets lgBarsNeeded
        if (lgBarsNeeded > barInventoryLarge) {
            lgBarsNeeded = barInventoryLarge; // Sets lgBarsNeeded to Inventory amount if there's not enough
        }
        userPounds -= lgBarsNeeded * 5; // Subtract from total
        int mdBarsNeeded = userPounds / 3; // Sets mdBarsNeeded
        if (mdBarsNeeded > barInventoryMedium){
            mdBarsNeeded = barInventoryMedium; // Sets mdBarsNeeded to Inventory amount if there's not enough
        }
        userPounds -= mdBarsNeeded * 3; //Subtract from total
        int smBarsNeeded = userPounds; //Sets smBarsNeeded
        if (smBarsNeeded > barInventorySmall){
            cout << "Your order was too large to be filled." << endl; // Lets user know that order was too large
        }
        else{
            // Subtracts bars needed from inventory
            barInventorySmall -= smBarsNeeded;
            barInventoryMedium -= mdBarsNeeded;
            barInventoryLarge -= lgBarsNeeded;
            // Calculates the total cost of each bar as well as their total
            double totalSmallBarCost = smBarsNeeded * barCostSmall;
            double totalMediumBarCost = mdBarsNeeded * barCostMedium;
            double totalLargeBarCost = lgBarsNeeded * barCostLarge;
            double total = totalSmallBarCost + totalMediumBarCost + totalLargeBarCost;
            // Prints out the bar amounts and cost associated with order
            cout << "Your order has been filled:" << endl;
            cout << setw(12) << "Small bars:" << setw(4) << smBarsNeeded << " =" << setw(9) << fixed << setprecision(2) << totalSmallBarCost << endl;
            cout << setw(12) << "Medium bars:" << setw(4) << mdBarsNeeded << " =" << setw(9) << totalMediumBarCost << endl;
            cout << setw(12) << "Large bars:" << setw(4) << lgBarsNeeded << " =" << setw(9) << totalLargeBarCost << endl;
            cout << "Total cost: " << setw(15) << total << endl;
            cout << endl;
            //Prints out the remaining inventory of bars
            cout << "Remaining Inventory:" << endl;
            cout << setw(12) << "Small bars" << ':' << setw(6) << barInventorySmall << endl;
            cout << setw(12) << "Medium bars" << ':' << setw(6) << barInventoryMedium << endl;
            cout << setw(12) << "Large bars" << ':' << setw(6) << barInventoryLarge << endl;
            cout << endl;
            cout << endl;
        }
        //Prompts user again if they'd like to process more orders and assigns it to userInput
        cout << "Enter Y to process more orders: ";
        cin >> userInput;
    }
}
 