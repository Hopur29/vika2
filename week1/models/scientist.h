#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>

enum sexType {
    female,
    male
};

/**
 * @brief The data model for scientists
 */
class Scientist
{
public:
    Scientist(std::string name, sexType sex, int yearBorn, std::string nationality);
    Scientist(std::string name, sexType sex, int yearBorn, int yearDied, std::string nationality);

    std::string getName() const;
    enum sexType getSex() const;
    int getYearBorn() const;
    int getYearDied() const;
    std::string getNationality() const;

    bool contains(std::string searchTerm);

private:
    std::string name;
    enum sexType sex;
    int yearBorn;
    int yearDied;
    std::string nationality;
};

#endif // SCIENTIST_H
