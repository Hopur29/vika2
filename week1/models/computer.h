#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>


class Computer
{
public:
    Computer(std::string name, int buildYear, std::string type, bool isBuilt);

    std::string getName() const;
    int getBuiltYear() const;
    std::string getType() const;
    bool getIsBuilt() const;

    bool contains(std::string searchTerm);
private:
    std::string name;
    int buildYear;
    std::string type;
    bool isBuilt;
};

#endif // COMPUTER_H
