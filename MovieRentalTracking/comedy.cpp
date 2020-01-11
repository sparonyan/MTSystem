// ------------------------------- comedy.h ---------------------------------
//
// Programmer Name: Satine Paronyan
// Course Section Number: CSS 502A
// Created: 02/23/2019
// Modified: 03/17/2019
//
//
// --------------------------------------------------------------------------
// PURPOSE:
// Represents a Comedy movie object for the rental store. Subclass of Movie.
// --------------------------------------------------------------------------
// Notes:
// The comparison methods are overriden in order to perform
// the correct comparison operation.
// --------------------------------------------------------------------------

#include <iomanip>  // using to format output
#include "comedy.h"

// ------------------ Comedy default Constructor ------------------
// Description:
// Constructs and initializes Comedy movie object.
// ------------------------------------------------------------------
Comedy::Comedy() {}


// ------------------ Comedy copy Constructor ------------------
// Description:
// Constructs and initializes Comedy movie object to the value of the
// passed argument.

//  F, Stock, Director, Title, Year it released
// ------------------------------------------------------------------
Comedy::Comedy(const Comedy &obj)
{
    this->setGenre(obj.getGenre());
    this->setStock(obj.getStock());
    this->setDirector(obj.getDirector());
    this->setTitle(obj.getTitle());
    this->setReleaseYear(obj.getReleaseYear());
}


// ----------------------- Comedy Constructor ----------------------
// Description:
// Constructs and initializes Comedy movie object from the given string.
//
// The given string argument must be in the format:
//  F, Stock, Director, Title, Year it released
// ex. F, 10, Nora Ephron, You've Got Mail, 1998
// ------------------------------------------------------------------
Comedy::Comedy(const std::string &line)
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

    int year = std::stoi(sTemp);
    this->setReleaseYear(year);
}


// ---------------------- Comedy Destructor -----------------------
// Description:
// Destroys Drama object.
// ------------------------------------------------------------------
Comedy::~Comedy() {}

// ------------------------------ operator== --------------------------
// Description:
// Returns true if two Comedy movie objects are equal, false otherwise.
// Comedy movie objects are equal if they have the same title and
// release year.
// @Override
// ------------------------------------------------------------------
bool Comedy::operator==(const Movie& other) const
{
    return (this->getTitle() == other.getTitle() &&
        this->getReleaseYear() == other.getReleaseYear());
}


// ---------------------------- operator> ---------------------------
// Description:
// Returns true if this Comedy movie is greater than the other passed
// argument Drama, false otherwise. The comparison is done by comparing
// titles and release years.
// @Override
// ------------------------------------------------------------------
bool Comedy::operator>(const Movie& other) const
{
    if (this->getTitle() > other.getTitle())
    {
        return true;
    }
    else if (this->getTitle() == other.getTitle())
    {
        return (this->getReleaseYear() > other.getReleaseYear());
    }
    return false;
}


// ---------------------------- operator< -----------------------------
// Description:
// Returns true if this Comedy is less than the other passed
// argument Movie, false otherwise. The comparison is done by comparing
// titles and release years.
// @Override
// ------------------------------------------------------------------
bool Comedy::operator<(const Movie& other) const
{
    return (!(*this == other) && !(*this > other));
}


// ----------------------------- operator<< -----------------------------
// Description:
// Overloaded operator :
// Outputs this comedy object in the following format:
// D, Stock, Director, Title, Year it released
// ----------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const Comedy& cmd)
{
    std::cout << std::setw(4) << cmd.getStock()
              << std::setw(35) << cmd.getTitle()
              << std::setw(24) << cmd.getDirector()
              << std::setw(10) << cmd.getReleaseYear() << std::endl;
    return os;
}