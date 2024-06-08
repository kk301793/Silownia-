#pragma once
#include"Libraries.h"
#include"FileReader.h"
#include"StrengthExercise.h"
#include"Filter.h"
class StrengthExerciseBase
{
public:
	vector<StrengthExercise> get_StrengthExercise();
	vector<StrengthExercise> get_StrengthExercise(Filter f);
	void add_StrengthExercise(StrengthExercise ce);
	void delete_Exercise(int number);
};

