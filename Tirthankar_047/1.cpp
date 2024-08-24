#include <iostream>
#include <vector>
#include <string.h>

class Person {
public:
    char name[50];
    char dateOfBirth[11];

    Person(const char* name, const char* dateOfBirth) {
        strcpy(this->name, name);
        strcpy(this->dateOfBirth, dateOfBirth);
    }
};

void findPersonsByDOB(const std::vector<Person>& persons, const char* dob) {
    for (size_t i = 0; i < persons.size(); ++i) {
        if (strcmp(persons[i].dateOfBirth, dob) == 0) {
            std::cout << persons[i].name << std::endl;
        }
    }
}

int main() {
    std::vector<Person> persons = {
        Person("Tirthankar Khatiwada", "2062-06-20"),
        Person("Purushottam Khatiwada", "2025-07-04"),
        Person("Kamala Niroula", "2033-05-06")
    };

    char inputDOB[11];
    std::cout << "Enter date of birth (YYYY-MM-DD): ";
    std::cin >> inputDOB;

    std::cout << "Persons with date of birth " << inputDOB << ":" << std::endl;
    findPersonsByDOB(persons, inputDOB);

    return 0;
}
