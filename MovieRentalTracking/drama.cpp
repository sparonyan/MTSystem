// ------------------------------- drama.cpp --------------------------------
//
// Programmer Name: Satine Paronyan
// Course Section Number: CSS 502A
// Created: 02/23/2019
// Modified: 03/17/2019
//
//
// --------------------------------------------------------------------------
// PURPOSE:
// Represents a Drama movie object for the rental store. Subclass of Movie.
// --------------------------------------------------------------------------
// Notes:
// The comparison methods are overriden in order to perform
// the correct comparison operation.
// --------------------------------------------------------------------------

#include <iomanip>  // using to format output
#include "drama.h"


// ------------------ Drama default Constructor ------------------
// Description:
// Constructs and initializes Drama movie object.
// ------------------------------------------------------------------
Drama::Drama() {}


// --------------------- Drama  Constructor ----------------------
// Description:
// Constructs and initializes Drama movie object from the given string.
//
// The given string argument must be in the format:
//  D, Stock, Director, Title, Year it released
//
//  ex. D, 10, Steven Spielberg, Schindler's List, 1993
// ------------------------------------------------------------------
Drama::Drama(const std::string &line) {

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


// ---------------------- Drama Destructor -----------------------
// Description:
// Destroys Drama object.
// ------------------------------------------------------------------
Drama::~Drama() {}


// ------------------ Drama copy Constructor ------------------
// Description:
// Constructs and initializes Drama movie object to the value of passed
// argument.
//
// D, Stock, Director, Title, Year it released
// ------------------------------------------------------------------
Drama::Drama(const Drama &obj)
{
    this->setGenre(obj.getGenre());
    this->setStock(obj.getStock());
    this->setDirector(obj.getDirector());
    this->setTitle(obj.getTitle());
    this->setReleaseYear(obj.getReleaseYear());
}


// ------------------------------ operator== --------------------------
// Description:
// Returns true if two Drama movie objects are equal false otherwise.
// Drama movie objects are equal if they have the same director name
// and title.
// @Override
// ------------------------------------------------------------------
bool Drama::operator==(const Movie& other) const
{
    return (this->getDirector() == other.getDirector() &&
        this->getTitle() == other.getTitle());
}

// ---------------------------- operator> ---------------------------
// Description:
// Returns true if this Drama movie is greater than the other passed
// argument Drama, false otherwise. The comparison is done by comparing
// director names and titles.
// @Override
// ------------------------------------------------------------------
bool Drama::operator>(const Movie &other) const
{
    if (this->getDirector() != other.getDirector()) {
        return this->getDirector() > other.getDirector();
    }
    if (this->getTitle() != other.getTitle()) {
        // compare titles
        return (this->getTitle() > other.getTitle());
    }

    return (this->getReleaseYear() > other.getReleaseYear());
}


// ---------------------------- operator< -----------------------------
// Description:
// Returns true if this Movie is less than the other passed
// argument Movie, false otherwise. The comparison is done by comparing
// director names and titles.
// @Override
// ------------------------------------------------------------------
bool Drama::operator<(const Movie& other) const
{
    return (!(*this == other) && !(*this > other));
}


// ----------------------------- operator<< -----------------------------
// Description:
// Overloaded operator :
// Outputs this drama movie's values.
// ----------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const Drama& dr)
{
    std::cout << std::setw(4) << dr.getStock()
              << std::setw(35) << dr.getTitle()
              << std::setw(24) << dr.getDirector()
              << std::setw(10) << dr.getReleaseYear() << std::endl;

    return os;
}
