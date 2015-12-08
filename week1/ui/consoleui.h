#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "services/service.h"
#include <string>

/**
 * @brief Holds commands that are available in the UI
 */
enum command {
    menu,
    add,
    display,
    search,
    sort,
    back,
    relations,
    quit,
    unknown
};

class ConsoleUI
{
public:
    ConsoleUI();

    /**
     * @brief start is the main run loop for the application
     * @return should indicate how the program exists, currently always safely
     */
    int start();

private:
    /**
     * @brief display serves as a router to according display functions
     */
    char display();

    /**
     * @brief readInput handles user input by settings commands or processing it
     */
    void readInput(char d);

    void displayMenu();
    void displayAddMenu(char ans);
    void displayAll(char ans);
    void displaySearchMenu(char ans);
    void displaySortMenu(char ans);
    void displayUnknownCommandMenu();
    void displayScientists(std::vector<Scientist> scientists);
    void displayComputers(std::vector<Computer> computers);
    char getSOrC();
    char getAns();

    /**
     * @brief addCommandHandler calls the addScientist or addComputer function and notifies the user how it went
     * @param userInput the input the user is trying to create a scientist from
     */
    void addCommandHandler(std::string userInput, char ans);

    /**
     * @brief sortCommandHandler calls the setSortS or setSortC function and notifies the user how it went
     * @param userInput the input the user is trying to change sort from
     */
    void sortCommandHandler(std::string userInput, char ans);

    /**
     * @brief searchCommandHandler calls the Service displays a list of filtered users
     * @param userInput a string sent as input to the search function
     */
    void searchCommandHandler(std::string userInput, char ans);

    void relationsCommandHandler(std::string userInput);

    /**
     * @brief addScientist attempts to add a scientist
     * @param data A string containing the user input
     * @return true if it was a success, false if it was a failure
     */
    bool addScientist(std::string data);

    /**
     * @brief addComputer attempts to add a computer
     * @param data A string containing the user input
     * @return true if it was a success, false if it was a failure
     */
    bool addComputer(std::string data);

    bool addRelations();
    /**
     * @brief setSort attempts to change how scientists will be sorted based on userinput
     * @param sortCommand the sort rule, rules are stored in constants.h
     * @return true if it was a success, false if it was a failure
     */
    bool setSortS(std::string sortCommand);

    /**
     * @brief setSort attempts to change how scientists will be sorted based on userinput
     * @param sortCommand the sort rule, rules are stored in constants.h
     * @return true if it was a success, false if it was a failure
     */
    bool setSortC(std::string sortCommand);
    void displayRelationsMenu();
    void displayError(std::string error);


    Service service;
    enum command lastCommand;
    char current;
    std::string sortBy;
    bool sortAscending;
};

#endif // CONSOLEUI_H
