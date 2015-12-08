#include "ui/consoleui.h"
#include "utilities/constants.h"
#include "utilities/utils.h"

#include <iostream>
#include <iomanip>

using namespace std;

ConsoleUI::ConsoleUI()
{
    lastCommand = command::menu;
    sortBy = "name";
    sortAscending = true;
}

int ConsoleUI::start()
{
    while(lastCommand != command::quit)
    {
        char d = display();
        readInput(d);
    }

    return 0;
}

char ConsoleUI::display()
{
    char ans = ' ';

    switch (lastCommand)
    {
        case command::menu:
            displayMenu();
            return ans;
            break;
        case command::add:
            ans = getSOrC();
            displayAddMenu(ans);
            return ans;
            break;
        case command::display:
            ans = getSOrC();
            displayAll(ans);
            return ans;
            break;
        case command::search:
            ans = getSOrC();
            displaySearchMenu(ans);
            return ans;
            break;
        case command::sort:
            ans = getSOrC();
            displaySortMenu(ans);
            return ans;
            break;
        default:
            displayUnknownCommandMenu();
            return ans;
            break;
    }
}

void ConsoleUI::readInput(char ans)
{
    if (lastCommand == command::display)
    {
        lastCommand = command::sort;
        return;
    }

    string userInput;
    getline(cin, userInput);

    cout << "\n\n";

    bool shouldTreatInputAsCommand = (lastCommand != command::search);

    if (userInput == "display" && shouldTreatInputAsCommand)
    {
        lastCommand = command::sort;
    }
    else if (userInput == "add" && shouldTreatInputAsCommand)
    {
        lastCommand = command::add;
    }
    else if (userInput == "search" && shouldTreatInputAsCommand)
    {
        lastCommand = command::search;
    }
    else if (userInput == "back")
    {
        lastCommand = command::menu;
    }
    else if (userInput == "quit")
    {
        lastCommand = command::quit;
    }
    else
    {
        if (lastCommand == command::add)
        {
            addCommandHandler(userInput, ans);
        }
        else if (lastCommand == command::sort)
        {
            sortCommandHandler(userInput, ans);
        }
        else if (lastCommand == command::search)
        {
            searchCommandHandler(userInput, ans);
        }
        else
        {
            lastCommand = command::unknown;
        }
    }
}

char ConsoleUI::getSOrC()
{
    string ans;
    cout << "write s for scientist and write c for computer: ";
    getline(cin,ans);
    return ans[0];
}

void ConsoleUI::addCommandHandler(string userInput, char ans)
{
    if(ans == 's')
    {
        if (addScientist(userInput))
        {
            cout << "Successfully added a scientist\n\n";
            lastCommand = command::menu;
        }
        else
        {
            displayError("There was an error in your input.");
        }
    }
    else if(ans == 'c')
    {
        if (addComputer(userInput))
        {
            cout << "Successfully added a computer\n\n";
            lastCommand = command::menu;
        }
        else
        {
            displayError("There was an error in your input.");
        }
    }

}

void ConsoleUI::sortCommandHandler(std::string userInput, char ans)
{
    if(ans == 's')
    {
        if (setSortS(userInput))
        {
            lastCommand = command::display;
        }
        else
        {
            displayError("Your input did not match any of the sort commands");
        }
    }
     if(ans == 'c')
    {
        if (setSortC(userInput))
        {
            lastCommand = command::display;
        }
        else
        {
            displayError("Your input did not match any of the sort commands");
        }
    }
}

void ConsoleUI::searchCommandHandler(string userInput, char ans)
{
    if(ans == 's')
    {
        displayScientists(service.searchForScientists(userInput));
    }
    else if(ans == 'c')
    {
        displayComputers(service.searchForComputers(userInput));
    }
}

void ConsoleUI::displayMenu()
{
    cout << "Enter a command:\n\n";
    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "add:" << "Adds a scientist\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "display:" << "Displays scientists\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "search:" << "Search for a scientist\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "quit:" << "Quits the program\n\n";

    cout << "Command: ";
}

void ConsoleUI::displayAddMenu(char ans)
{
    if(ans == 's')
    {
        cout << "To add a scientist, type in:\n";
        cout << "Name,sex,yearBorn,yearDied (optional)\n";
        cout << "Comma separated like in the example above.\n\n";
        cout << "If you would like to go back to the main menu, please type: back\n";
        cout << "Input: ";
    }
    else if(ans == 'c')
    {
        cout << "To add a computer, type in:\n";
        cout << "Name,year built,type, completed or not(true or false)\n";
        cout << "Comma separated like in the example above.\n\n";
        cout << "If you would like to go back to the main menu, please type: back\n";
        cout << "Input: ";
    }
}

void ConsoleUI::displayAll(char ans)
{
    if(ans == 's')
    {
        vector<Scientist> scientists = service.getAllScientists(sortBy, sortAscending);

        displayScientists(scientists);
    }
    else if(ans == 'c')
    {
        vector<Computer> computers = service.getAllComputers(sortBy, sortAscending);

        displayComputers(computers);
    }

    cout << '\n';

    lastCommand = command::display;
}

void ConsoleUI::displaySearchMenu(char ans)
{
    if(ans == 's')
    {
        cout << "Search for a scientist.\n\n";

        cout << "If you would like to go back to the main menu, please type: back\n";
        cout << "Input: ";
    }
    else if(ans == 'c')
    {
        cout << "Search for a computer.\n\n";

        cout << "If you would like to go back to the main menu, please type: back\n";
        cout << "Input: ";
    }
}

void ConsoleUI::displaySortMenu(char ans)
{
    if(ans == 's')
    {
        cout << "How should the list be sorted:\n\n";
        cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
             << constants::SORT_SCIENTIST_NAME_ASCENDING << "Sorts by name, ascending.\n";

        cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
             << constants::SORT_SCIENTIST_NAME_DESCENDING << "Sorts by name, descending.\n";

        cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
             << constants::SORT_SCIENTIST_YEAR_BORN_ASCENDING << "Sorts by year born, ascending.\n";

        cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
             << constants::SORT_SCIENTIST_YEAR_BORN_DESCENDING << "Sorts by year born, descending.\n";

        cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
             << constants::SORT_SCIENTIST_YEAR_DIED_ASCENDING << "Sorts by year died, ascending.\n";

        cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
             << constants::SORT_SCIENTIST_YEAR_DIED_DESCENDING << "Sorts by year died, descending.\n\n";
    }
    else if(ans == 'c')
    {
        cout << "How should the list be sorted:\n\n";
        cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
             << constants::SORT_COMPUTER_NAME_ASCENDING << "Sorts by name, ascending.\n";

        cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
             << constants::SORT_COMPUTER_NAME_DESCENDING << "Sorts by name, descending.\n";

        cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
             << constants::SORT_COMPUTER_YEAR_BUILT_ASCENDING << "Sorts by year built, ascending.\n";

        cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
             << constants::SORT_COMPUTER_YEAR_BUILT_DESCENDING << "Sorts by year built, descending.\n";

        cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
             << constants::SORT_COMPUTER_TYPE_ASCENDING << "Sorts by type, ascending.\n";

        cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
             << constants::SORT_COMPUTER_TYPE_DESCENDING << "Sorts by type, descending.\n\n";
    }


    cout << "If you would like to go back to the main menu, please type: back\n";

    cout << "Command: ";
}

void ConsoleUI::displayUnknownCommandMenu()
{
    displayError("Unknown command");
    cout << "Command: ";
}

void ConsoleUI::displayScientists(std::vector<Scientist> scientists)
{
    if (scientists.size() == 0)
    {
        cout << "No scientist found.\n";
        return;
    }

    cout << "Printing all scientists:\n";

    cout << setw(20) << std::left << "Name:"
         << setw(8) << std::left << "Sex:"
         << setw(12) << std::left << "Year born:"
         << setw(12) << std::left << "Year died:" << endl;

    for (unsigned int i = 0; i < scientists.size(); i++)
    {
        string scientistSex = (scientists.at(i).getSex() == sexType::male) ? "Male" : "Female";

        int yearDied = scientists.at(i).getYearDied();
        string died = (yearDied == constants::YEAR_DIED_DEFAULT_VALUE) ? "Alive" : utils::intToString(yearDied);

        cout << setw(20) << std::left << scientists.at(i).getName()
             << setw(8) << std::left << scientistSex
             << setw(12) << std::left << scientists.at(i).getYearBorn()
             << setw(12) << std::left << died << endl;
    }
}

void ConsoleUI::displayComputers(std::vector<Computer> computers)
{
    if (computers.size() == 0)
    {
        cout << "No scientist found.\n";
        return;
    }

    cout << "Printing all computers:\n";

    cout << setw(20) << std::left << "Name:"
         << setw(8) << std::left << "Year built:"
         << setw(12) << std::left << "Type:"
         << setw(12) << std::left << "Is built:" << endl;

    for (unsigned int i = 0; i < computers.size(); i++)
    {
        string isBuilt;
        if(computers.at(i).getIsBuilt())
        {
            isBuilt = "it is built";
        }
        else
        {
            isBuilt = "it is not built";
        }

        cout << setw(20) << std::left << computers.at(i).getName()
             << setw(8) << std::left << computers.at(i).getBuiltYear()
             << setw(12) << std::left << computers.at(i).getType()
             << setw(12) << std::left << isBuilt << endl;
    }
}

bool ConsoleUI::addScientist(string data)
{
    vector<string> fields = utils::splitString(data, ',');

    if (fields.size() > 2 && fields.size() < 5)
    {
        string name = fields.at(0);

        enum sexType sex;
        if (fields.at(1) == "male")
        {
            sex = sexType::male;
        }
        else
        {
            sex = sexType::female;
        }
        int yearBorn = utils::stringToInt(fields.at(2));

        if (fields.size() == 3)
        {
            return service.addScientist(Scientist(name, sex, yearBorn));
        }
        else
        {
            int yearDied = utils::stringToInt(fields.at(3));

            return service.addScientist(Scientist(name, sex, yearBorn, yearDied));
        }
    }

    return false;
}

bool ConsoleUI::addComputer(string data)
{
    vector<string> fields = utils::splitString(data, ',');

    if (fields.size() > 3 && fields.size() < 5)
    {
        string name = fields.at(0);
        int yearBuilt = utils::stringToInt(fields.at(1));
        string type = fields.at(2);
        bool isBuilt = utils::stringToBool(fields.at(3));

        return service.addComputer(Computer(name, yearBuilt, type, isBuilt));

    }

    return false;
}


bool ConsoleUI::setSortS(string sortCommand)
{
    if (sortCommand == constants::SORT_SCIENTIST_NAME_ASCENDING)
    {
        sortBy = "name";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_NAME_DESCENDING)
    {
        sortBy = "name";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_BORN_ASCENDING)
    {
        sortBy = "yearBorn";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_BORN_DESCENDING)
    {
        sortBy = "yearBorn";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_DIED_ASCENDING)
    {
        sortBy = "yearDied";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_DIED_DESCENDING)
    {
        sortBy = "yearDied";
        sortAscending = false;
    }
    else
    {
        return false;
    }

    return true;
}

bool ConsoleUI::setSortC(std::string sortCommand)
{
    if (sortCommand == constants::SORT_COMPUTER_NAME_ASCENDING)
    {
        sortBy = "name";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_COMPUTER_NAME_DESCENDING)
    {
        sortBy = "name";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_COMPUTER_YEAR_BUILT_ASCENDING)
    {
        sortBy = "yearBuilt";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_COMPUTER_YEAR_BUILT_DESCENDING)
    {
        sortBy = "yearBuilt";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_COMPUTER_TYPE_ASCENDING)
    {
        sortBy = "type";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_COMPUTER_TYPE_DESCENDING)
    {
        sortBy = "type";
        sortAscending = false;
    }
    else
    {
        return false;
    }

    return true;
}

void ConsoleUI::displayError(string error)
{
    cout << "There was an error: " << error << "\n";
    cout << "Please try again or type 'back' to go back.\n\n";
}
