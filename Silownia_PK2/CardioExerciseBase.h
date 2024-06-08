#pragma once
#include"Libraries.h"
#include"FileReader.h"
#include"CardioExercise.h"
#include"Filter.h"
class CardioExerciseBase
{
public:

	vector<CardioExercise> get_CardioExercises();
	vector<CardioExercise> get_CardioExercises(Filter f);
	void add_CardioExercise(CardioExercise ce);
	void delete_Exercise(int number);


};

