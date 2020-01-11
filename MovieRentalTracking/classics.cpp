// ------------------------------- classics.cpp -----------------------------
//
// Programmer Name: Satine Paronyan
// Course Section Number: CSS 502A
// Created: 02/23/2019
// Modified: 03/17/2019
//
//
// --------------------------------------------------------------------------
// PURPOSE:
// Represents a Classics movie object for the rental store. Subclass of Movie.
// --------------------------------------------------------------------------
// Notes:
// The comparison methods are overriden in order to perform
// the correct comparison operation.
// --------------------------------------------------------------------------

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>  // using to format output
#include "movie.h"
#include "classics.h"

// ------------------ Classics default Constructor ------------------
// Description:
// Constructs and initializes Classics object.
// ------------------------------------------------------------------
Classics::Classics() {}


// ------------------ Classics copy Constructor ------------------
// Description:
// Constructs and initializes Classics object to the value of passed
// argument.
//
// C, Stock, Director, Title, Major actor Release date
// ------------------------------------------------------------------
Classics::Classics(const Classics &obj)
{
    this->setGenre(obj.getGenre());
    this->setStock(obj.getStock());
    this->setDirector(obj.getDirector());
    this->setTitle(obj.getTitle());
    this->setReleaseMonth(obj.getReleaseMonth());
    this->setReleaseYear(obj.getReleaseYear());

    std::vector<std::string> actorVector = obj.getVectorOfActors();
    for (auto el : actorVector)
    {
        this->addActor(el);
    }
}


// --------------------- Classics  Constructor ----------------------
// Description:
// Constructs and initializes Classics object from the given string.
//
// The given string argument must be in the format:
//  C, Stock, Director, Title, Major actor Release date
// ------------------------------------------------------------------
Classics::Classics(const std::string &line)
{

    std::string sTemp = line;

    // read the first four values from the given string:
    // genre, stock, director, title (those are separated by comma + space
    std::string separtr1 = ", ";
    std::string arr[4];

    for (int i = 0; i < 4; i++)
    {
        arr[i] = sTemp.substr(0, sTemp.find(separtr1));
        //erase the value read + space from the given string
        sTemp.erase(0, arr[i].length() + separtr1.length());
    }

    this->setGenre(arr[0][0]);  // char
    int num = std::stoi(arr[1]);
    this->setStock(num);  // integer
    this->setDirector(arr[2]);
    this->setTitle(arr[3]);

    // read the last four values from the given string:
    // major actor's name (first, last), month and year of release
    std::string separtr2 = " ";
    for (int j = 0; j < 4; j++)
    {
        arr[j] = sTemp.substr(0, sTemp.find(separtr2));
        //erase the value read + space from the given string
        sTemp.erase(0, arr[j].length() + separtr2.length());

    }

    this->addActor((arr[0] + " " + arr[1]));
    this->setReleaseMonth(std::stoi(arr[2]));
    this->setReleaseYear(std::stoi(arr[3]));

} // end of Classics(std::string line) constructor


// ---------------------- Classics Destructor -----------------------
// Description:
// Destroys Classics object.
// ------------------------------------------------------------------
Classics::~Classics() {}


// ------------------------- getReleaseYear -------------------------
// Description:
// Returns true if two Classics movie objects are equal false otherwise.
// Classics movie objects are equal if they have the same release date
// and actor.
// @Override
// ------------------------------------------------------------------
bool Classics::operator==(const Movie& other) const
{
     //if the classics movie has the same director, title, release year
     //this->getReleaseYear() == other.getReleaseYear() &&
     return (this->getReleaseMonth() == other.getReleaseMonth() &&
             this->getActor() == other.getActor());
}


// ---------------------------- isGreater ---------------------------
// Description:
// Returns true if this Classics movie is greater than the other passed
// argument Classics, false otherwise. This Movie objects is grater than
// the other movie, if this movie is released later, in case their release
// dates are equal, then the major actor's (strings) are compared.
// @Override
// ------------------------------------------------------------------
bool Classics::operator>(const Movie& other) const
{
    if (this->getReleaseYear() != other.getReleaseYear())
    {
        return this->getReleaseYear() > other.getReleaseYear();
    }

    if (this->getReleaseMonth() != other.getReleaseMonth())
    {
        // if release years are equal then
        // compare release months
        return (this->getReleaseMonth() > other.getReleaseMonth());
    }

    // if release dates (year and month) are equal then
    // compare major actors
    return (this->getActor() > other.getActor());
}

// ---------------------------- isLess ------------------------------
// Description:
// Returns true if this Movie is less than the other passed
// argument Movie, false otherwise. This Movie objects is less that the
// other movie, if this movie is released earlier, in case their release
// dates are equal, then the major actor's (strings) are compared.
// @Override
// ------------------------------------------------------------------
bool Classics::operator<(const Movie& other) const
{
    return (!(*this == other) && !(*this > other));
}


// ----------------------------- operator<< -----------------------------
// Description:
// Overloaded operator :
// Outputs this classics objects value in the following format:
// C, Stock, Director, Title, Major actor Release date
// ----------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const Classics& cl)
{
    std::vector<std::string> actors = cl.getVectorOfActors();

    std::cout << std::setw(4) << cl.getStock() << std::setw(36) << cl.getTitle()
            << std::setw(25) << cl.getDirector();

    for (int i = 0; i < actors.size(); i++)
    {
        if (i == 0)
        {
            std::cout << std::setw(23) << actors.at(i) << std::setw(7) << cl.getReleaseMonth()
                    << std::setw(5) << cl.getReleaseYear() << std::endl;
        }
        else
        {
            std::cout << std::setw(88) << actors.at(i) << std:: endl;
        }
    }

    return os;
}