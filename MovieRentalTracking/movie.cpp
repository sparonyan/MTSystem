// ------------------------------- movie.h ----------------------------------
//
// Programmer Name: Satine Paronyan
// Course Section Number: CSS 502A
// Created: 02/23/2019
// Modified: 03/17/2019
//
//
// --------------------------------------------------------------------------
// PURPOSE:
// Represents a movie object for the rental store. This class will be
// used as a base class for Classics, Drama and Comedy classes.
// --------------------------------------------------------------------------
// Notes:
// Virtual methods must be overriden in the subclasses in order to perform
// the correct comparison operation.
// --------------------------------------------------------------------------

#include "movie.h"

// ---------------------- Movie Constructor -------------------------
// Description:
// Constructs and initializes Movie object.
// ------------------------------------------------------------------
Movie::Movie()
{
    genre = ' ';
    stock = 0;
    director = "";
    title = "";
    releaseYear = 0;
    releaseMonth = 0;
}

// ---------------------- Movie Destructor --------------------------
// Description:
// Destroys Movie object.
// ------------------------------------------------------------------
Movie::~Movie()
{
    genre = ' ';
    stock = 0;
    director = "";
    title = "";
    releaseYear = 0;
    releaseMonth = 0;
    actors.clear();
}


// --------------------------- setGenre -----------------------------
// Description:
// Sets genre of this Movie to the given char (either 'F' for comedy,
// 'D' for drama or 'C' for classics.
// ------------------------------------------------------------------
void Movie::setGenre(const char &val)
{
    if (val == COMEDY || val == DRAMA || val == CLASSICS)
    {
        genre = val;
    }
} // end of setGenre


// --------------------------- getGenre -----------------------------
// Description:
// Returns a char value representing the genre of this Movie
// ('F' for comedy, 'D' for drama or 'C' for classics.
// ------------------------------------------------------------------
char Movie::getGenre() const
{
    return genre;
} // end of getGenre


// --------------------------- setStock -----------------------------
// Description:
// Sets the stock of the movie to the given integer value.
// ------------------------------------------------------------------
void Movie::setStock(const int &val)
{
    if (val >= 0)
    {
        stock = val;
    }
} // end of setStock



// --------------------------- getStock -----------------------------
// Description:
// Returns the integer value representing the stock of this movie.
// ------------------------------------------------------------------
int Movie::getStock() const
{
    return stock;
} // end of getStock


// ------------------------- setDirector ----------------------------
// Description:
// Sets the Director full name of the movie to the given string value.
// The full name should be in the format: first name then last name,
// separated by space.
// ------------------------------------------------------------------
void Movie::setDirector(const std::string &val)
{
    director = val;
} //end of setDirector


// ------------------------- getDirector ----------------------------
// Description:
// Returns the Director full name of the movie.
// The full name is in the format: first name then last name,
// separated by space.
// ------------------------------------------------------------------
std::string Movie::getDirector() const
{
    return director;
} //end of getDirector


// ---------------------------- setTitle ----------------------------
// Description:
// Sets the Title of the movie to the given string value.
// ------------------------------------------------------------------
void Movie::setTitle(const std::string &val)
{
    title = val;
} //end of setTitle


// ---------------------------- getTitle ----------------------------
// Description:
// Returns the Title of the movie.
// ------------------------------------------------------------------
std::string Movie::getTitle() const
{
    return title;
}


// ------------------------- setReleaseYear --------------------------
// Description:
// Sets the release year of the movie to the given (four digit) int value.
// ------------------------------------------------------------------
void Movie::setReleaseYear(const int &val)
{
    // verify if the passed in year is in the format of four digits
    int num = val;
    int digits = 0;
    do {
        num /= 10;
        digits++;
    } while (num != 0);

    //set release year
    if (digits == 4)
    {
        releaseYear = val;
    }
} // end of setReleaseYear


// ------------------------- getReleaseYear -------------------------
// Description:
// Returns the release year of the movie (four digit int value).
// ------------------------------------------------------------------
int Movie::getReleaseYear() const
{
    return releaseYear;
} //end of getReleaseYear


// --------------------------- addActor -----------------------------
// Description:
// Adds the given major actor's name for this Classics movie.
// ------------------------------------------------------------------
void Movie::addActor(const std::string &val)
{
    actors.push_back(val);
} // end od addActor


// --------------------------- getActor -----------------------------
// Description:
// Returns the major actor's name for the Classics movie (if there more
// than one major actor, then will return the first read one).
// ------------------------------------------------------------------
std::string Movie::getActor() const
{
    return actors.at(0);
}


// ---------------------- getVectorOfActors -------------------------
// Description:
// Returns a vector of the major actors's for the Classics movie.
// ------------------------------------------------------------------
std::vector<std::string> Movie::getVectorOfActors() const
{
    return actors;
}


// ------------------------- containsActor --------------------------
// Description:
// Returns a vector of the major actors's for the Classics movie.
// ------------------------------------------------------------------
bool Movie::containsActor(const std::string &name) const
{
    for (std::string actor : actors)
    {
        if (actor == name)
        {
            return true;
        }
    }
    return false;
}


// ------------------------ setReleaseMonth -------------------------
// Description:
// Sets the release month of the movie to the given int value.
// The value representing month must be without preceding 0s, for example,
// to pass March -> 3 is passed instead of 03.
// ------------------------------------------------------------------
void Movie::setReleaseMonth(const int &val)
{
    releaseMonth = val;
} //end of setReleaseMonth


// ------------------------ getReleaseMonth -------------------------
// Description:
// Returns the release month of the movie.
// ------------------------------------------------------------------
int Movie::getReleaseMonth() const
{
    return releaseMonth;
} //end of getReleaseMonth



// ---------------------------- operator== ---------------------------
// Description:
// Returns true if two Movie objects are equal false otherwise.
// Movie objects are equal if they have the same title and release
// in the same year.
// ------------------------------------------------------------------
bool Movie::operator==(const Movie& other) const
{
    return (this->releaseYear == other.releaseYear &&
            this->director == other.director &&
            this->title == other.title);
} //end of isEqual


// ---------------------------- operator> ----------------------------
// Description:
// Returns true if this Movie is greater than the other passed
// argument Movie, false otherwise. This Movie objects is grater that the
// other movie, if this movie is released later, in case their release
// dates are equal, then the title's strings are compared.
// ------------------------------------------------------------------
bool Movie::operator>(const Movie& other) const
{
    if (this->title > other.title)
    {
        return true;
    }
    else if (this->releaseYear > other.releaseYear)
    {
        return true;
    }

    return false; // this movie is less than other movie
} //end of operator>



// ----------------------------- operator< ---------------------------
// Description:
// Returns true if this Movie is less than the other passed
// argument Movie, false otherwise. This Movie objects is less that the
// other movie, if this movie is released earlier, in case their release
// dates are equal, then the title's (strings) are compared.
// ------------------------------------------------------------------
bool Movie::operator<(const Movie& other) const
{
    return (!(*this == other) && !(*this > other));
}



