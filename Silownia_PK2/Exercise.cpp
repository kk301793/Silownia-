#include "Exercise.h"

Exercise::Exercise()
{
}

Exercise::Exercise(string name, int difficultyLevel)
{
	this->name = name;
	this->difficultyLevel = difficultyLevel;
}

Exercise::Exercise(const Exercise& e)
{
	name = e.name;
	difficultyLevel = e.difficultyLevel;
}

Exercise::~Exercise()
{
}

Exercise& Exercise::operator=(const Exercise& e)
{
	name = e.name;
	difficultyLevel = e.difficultyLevel;

	return *this;
}

ostream& operator<<(ostream& ekran, const Exercise& obj)
{
	ekran << obj.name << "," << obj.difficultyLevel << endl;
	return ekran;
}

istream& operator>>(istream& in, Exercise& c)
{

	cout << "Podaj nazwe cwiczenia: ";
	in >> c.name;
	cout << endl;
	cout << "Podaj poziom trudnosci (1-5): ";
	in >> c.difficultyLevel;
	

	return in;
}

void Exercise::set_name(string name)
{
	this->name = name;
}

void Exercise::set_difficultyLevel(int difficultyLevel)
{
	this->difficultyLevel = difficultyLevel;
}

string Exercise::get_name()
{
	return this->name;
}

int Exercise::get_difficultyLevel()
{
	return this->difficultyLevel;
}

string Exercise::getDetails()
{
	return "Nazwa cwiczenia: "+name + " ,poziom trudnosci: "+to_string(difficultyLevel)+"\n";
}
