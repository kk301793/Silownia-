#include "StrengthExercise.h"

StrengthExercise::StrengthExercise()
{
}

StrengthExercise::StrengthExercise(string name, int difficultyLevel, string bodyPart, string typeOfExercise):Exercise(name,difficultyLevel)
{
	this->bodyPart = bodyPart;
	this->typeOfExercise = typeOfExercise;
}

StrengthExercise::StrengthExercise(const StrengthExercise& c): Exercise(c)
{
	bodyPart = c.bodyPart;
	typeOfExercise = c.typeOfExercise;
}

StrengthExercise& StrengthExercise::operator=(const StrengthExercise& c)
{
	(*this).Exercise::operator=(c);
	bodyPart = c.bodyPart;
	typeOfExercise = c.typeOfExercise;
	return *this;
}


string StrengthExercise::getDetails()
{
	return "Nazwa cwiczenia: " + name + ", poziom trudnosci: " + to_string(difficultyLevel) + ", partia ciala: " + bodyPart +
		", typ cwiczenia: "+typeOfExercise+ "\n";
}

StrengthExercise StrengthExercise::setExercise(StrengthExercise& ce)
{
	cin >> ce;
	return ce;
}

void StrengthExercise::set_bodyPart(string bodyPart)
{
	this->bodyPart = bodyPart;
}

void StrengthExercise::set_typeOfExercise(string typeOfExercise)
{
	this->typeOfExercise = typeOfExercise;
}

string StrengthExercise::get_bodyPart()
{
	return this->bodyPart;
}

string StrengthExercise::get_typeOfExercise()
{
	return this->typeOfExercise;
}

void StrengthExercise::show_Exercise()
{
	cout<< "Nazwa cwiczenia: " + name + ", poziom trudnosci: " + to_string(difficultyLevel) + ", partia ciala: " + bodyPart +
		", typ cwiczenia: " + typeOfExercise + "\n";
}

ostream& operator<<(ostream& ekran, const StrengthExercise& obj)
{
	ekran << obj.name << "," << obj.difficultyLevel << "," << obj.bodyPart <<"," <<obj.typeOfExercise<<endl;
	return ekran;
}

istream& operator>>(istream& in, StrengthExercise& c)
{

	cout << "Podaj nazwe cwiczenia: ";
	in >> c.name;
	cout << endl;
	cout << "Podaj poziom trudnosci (1-5): ";
	in >> c.difficultyLevel;
	cout << endl;
	cout << "Podaj czesc ciala: ";
	in >> c.bodyPart;
	cout << endl;
	cout << "Podaj rodzaj treningu(PUSH,PULL,LEGS):";
	in >> c.typeOfExercise;

	return in;
}
