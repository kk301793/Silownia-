#include "CardioExercise.h"


CardioExercise::CardioExercise()
{
}

CardioExercise::CardioExercise(string name, int difficultyLevel, string intensity):Exercise( name,difficultyLevel)
{
    this->intensity = intensity;
}

CardioExercise::CardioExercise(const CardioExercise& c) :Exercise(c)
{
    intensity = c.intensity;
}

CardioExercise& CardioExercise::operator=(const CardioExercise& c)
{
    (*this).Exercise::operator=(c);
    intensity = c.intensity;
    return *this;
}

ostream& operator<<(ostream& ekran, const CardioExercise& obj)
{
    ekran << obj.name << "," << obj.difficultyLevel << "," << obj.intensity << endl;
    return ekran;
}

istream& operator>>(istream& in, CardioExercise& c)
{
    cout << "Podaj nazwe cwiczenia: ";
    in >> c.name;
    cout << endl;
    cout << "Podaj poziom trudnosci (1-5): ";
    in >> c.difficultyLevel;
    cout << endl;
    cout << "Podaj intensywnosc (mala, srednia, duza): ";
    in >> c.intensity;
   
    return in;
}

string CardioExercise::getDetails()
{
    return "Nazwa cwiczenia: " + name + ", poziom trudnosci: " + to_string(difficultyLevel) +", intensywnosc: "+intensity+"\n";
}

void CardioExercise::set_intensity(string intensity)
{
    this->intensity = intensity;
}

string CardioExercise::get_intensity()
{
    return this->intensity;
}

CardioExercise CardioExercise::setExercise(CardioExercise& ce)
{

    cin >> ce;     // operator utawia cwicznenie 

    return ce;
}

void CardioExercise::show_Exercise()
{
    cout<< "Nazwa cwiczenia: " + name + ", poziom trudnosci: " + to_string(difficultyLevel) + ", intensywnosc: " + intensity + "\n";
}

