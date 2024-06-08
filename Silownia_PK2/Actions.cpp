#include "Actions.h"

Actions::Actions()
{
}

Actions::~Actions()
{
}

void Actions::display_menu()
{
	while (Actions::option != 6) {
		system("CLS");
		cout << "-----JAKA CZYNNOSC CHCESZ WYKONAC-----" << endl;
		cout << endl << "1 - WYSZUKIWANIE CWICZEN Z BAZY DANYCH " << endl;
		cout << "2 - DODAWANIE CWICZEN DO BAZY DANYCH" << endl;
		cout << "3 - USUWANIE CWICZEN Z BAZY DANYCH" << endl;
		cout << "4 - ZAPISZ NOWY PLAN TRENINGOWY" << endl;
		cout << "5 - POKAZ PLAN TRENINGOWY" << endl;
		cout << "6 - WYJSCIE" << endl;
		cin >> Actions::option;

		switch (option)
		{
		case 1:
			show_exercise();
			break;
		case 2:
			add_exercise();
			break;
		case 3:
			delete_exercise();
			break;
		case 4:
			create_trainingPlan();
			break;
		case 5:
			show_trainingPlan();
			break;
		case 6:
			exit(0);
		default:
			cout << "Zla opcja" << endl;
			break;
		}

	}
}

void Actions::add_exercise()
{
	char x;
	cout << "CHCESZ DODAC CWICZENIE CARDIO CZY SILOWE?" << endl;
	cout << "1 - CARDIO" << endl;
	cout << "2 - SILOWE" << endl;

	cin >> Actions::option;
	switch (option)
	{
	case 1:
		do {
			CardioExerciseBase cardioExerciseBase;
			CardioExercise cardioExercise;
			cardioExercise.setExercise(cardioExercise);
			cardioExerciseBase.add_CardioExercise(cardioExercise);
			cout << "Cwiczenie zostalo pomyslnie dodane" << endl;
			cout << "Chcesz dodac jeszcze?(y/n)";
			cin >> x;
			system("CLS");
		} while (x == 'y');
		//system("pause");
		display_menu();
	case 2:
		do {
			StrengthExerciseBase strengthExerciseBase;
			StrengthExercise strengthExercise;
			strengthExercise.setExercise(strengthExercise);
			strengthExerciseBase.add_StrengthExercise(strengthExercise);
			cout << "Cwiczenie zostalo pomyslnie dodane" << endl;
			cout << "Chcesz dodac jeszcze?(y/n)";
			cin >> x;
			system("CLS");
		} while (x == 'y');
		//system("pause");
		display_menu();
	
	default:
		cout << "Zla opcja";
		break;
	}
}

void Actions::create_trainingPlan()
{
	std::remove("training_plan.txt");
	string inputDay;
	char x;
	cout << "DODAJ CWICZENIA DO TWOJEGO PLANU" << endl;
	do {
		cout << "PODAJ DZIEN TRENINGU?" << endl;
		cin >> inputDay;
		trainingForDay(inputDay);
		cout << "CHCESZ DODAC TRENING NA INNY DZIEN(y/n)?" << endl;
		cin >> x;
	} while (x == 'y');
	

}

void Actions::trainingForDay(string day)
{
	for (int i = 0; i < day.length(); i++) {
		day[i] = toupper(day[i]);
	}
	
	cout << endl << "CWICZENIA NA DZIEN " + day << endl;
	char k, s;
	int strength, cardio;
	cout << "CZY CHCESZ DODAC CWICZENIA CARDIO?" << endl;
	cout << "1- TAK, 2-NIE" << endl;
	cin >> cardio;
	if (cardio == 1) {
		
		do {
			show_cardioExercises();
			cout << "WYBIERZ NUMER CWICZENIA CARDIO" << endl;
			cin >> Actions::choice;
			cardioExerciceToPlan.push_back(cardioEx.at(choice));
			cout << "CHCESZ DODAC JESZCE CWICZENIE ?(y/n)" << endl;
			cin >> k;
		} while (k == 'y');
	}
	cout << "CZY CHCESZ DODAC CWICZENIA SILOWE?" << endl;
	cout << "1- TAK, 2-NIE" << endl;
	cin >> strength;
	if (strength == 1) {
		
		do {
			show_strenghtExercises();
			cout << "WYBIERZ NUMER CWICZENIA SILOWEGO" << endl;
			cin >> Actions::choice;
			strengthExerciceToPlan.push_back(strengthEx.at(choice));
			cout << "CHCESZ DODAC JESZCE?(y/n)" << endl;
			cin >> s;
		} while (s == 'y');
	}
	

	save_trainingPlan(day);

}

void Actions::save_trainingPlan(string day)
{
	ofstream file;
	file.open("training_plan.txt", ios::out | ios::app);
	if (!file.is_open()) {
		cout << "Nie udalo sie otworzyc pliku" << endl;
		//exit(0);
	}
	else {
		file << day << endl;
		for (StrengthExercise e:strengthExerciceToPlan) {
			file << e;
		}
		for (CardioExercise e : cardioExerciceToPlan) {
			file << e;
		}
		file.close();
		strengthExerciceToPlan.clear();
		cardioExerciceToPlan.clear();
	}
}



void Actions::show_exercise()
{
	cout << "JAKIEGO RODZAJU CWICZENIA CHCESZ WYSZUKAC " << endl;
	cout << "1-CARDIO" << endl;
	cout << "2-SILOWE " << endl;
	cin >> Actions::option;
	cout << endl;
	if (option == 1) {
		show_cardioExercises();
	}
	else if (option == 2) {
		show_strenghtExercises();
	}
	
	
}

void Actions::show_strenghtExercises()
{
	Filter f;
	int x;
	string inputString;
	StrengthExerciseBase strengthExerciseBase;

	cout << "CZY SZUKASZ JAKIS KONKRETNYCH CWICZEN?" << endl;
	cout << "1- TAK || 2- NIE" << endl;
	cin >> x;
	system("CLS");
	if (x == 1) {
		cout << "Minimalny poziom trudnosci: ";
		cin.ignore();
		getline(cin, inputString);
		f.set_minDifficultyLevel(inputString);
		system("cls");
		cout << "Maksymalny poziom trudnosci: ";
		getline(cin, inputString);
		f.set_maxDifficultyLevel(inputString);
		system("cls");
		cout << "Partia ciala: ";
			getline(cin, inputString);
			f.set_bodyPart(inputString);
			system("CLS");
			cout << "Rodzaj treningu(PUSH,PULL,LEGS): ";
			getline(cin, inputString);
			f.set_typeOfExercise(inputString);
			system("CLS");
			strengthEx = strengthExerciseBase.get_StrengthExercise(f);
	}
	else {
		 strengthEx = strengthExerciseBase.get_StrengthExercise();
		}
	int counter = 0;
	if (strengthEx.size() == 0) {
			cout << "Brak cwiczen w bazie" << endl;
		}
		else {

			for (StrengthExercise ce : strengthEx) {
				cout << counter << ". " << ce.getDetails();
				counter++;
			}
		
			system("pause");
		}
	
}

void Actions::show_cardioExercises()
{
	Filter f;
	int x;
	string inputString;
	CardioExerciseBase cardioExerciseBase;



	cout << "CZY SZUKASZ JAKIS KONKRETNYCH CWICZEN?" << endl;
	cout << "1- TAK || 2- NIE" << endl;
	cin >> x;
	system("CLS");
	if (x == 1) {
		cout << "Minimalny poziom trudnosci: ";
		cin.ignore();
		getline(cin, inputString);
		f.set_minDifficultyLevel(inputString);
		system("cls");
		cout << "Maksymalny poziom trudnosci: ";
		getline(cin, inputString);
		f.set_maxDifficultyLevel(inputString);
		system("cls");

		cout << "Intensywnosc(mala,srednia,duza): ";
		getline(cin, inputString);
		f.set_intensity(inputString);
		system("CLS");

		cardioEx = cardioExerciseBase.get_CardioExercises(f);

	}
	else {
		cardioEx = cardioExerciseBase.get_CardioExercises();

	}
		
		int counter = 0;

	
		if (cardioEx.size() == 0) {
			cout << "Brak cwiczen w bazie" << endl;
		}
		else {

			for (CardioExercise ce : cardioEx) {
				cout << counter << ". " << ce.getDetails();
				counter++;
			}

			system("pause");
		}
}
// ZADANIE - Sprawdzian
void Actions::show_Exercises()
{
	CardioExerciseBase cardioExerciseBase;
	StrengthExerciseBase strengthExerciseBase;
	cardioEx = cardioExerciseBase.get_CardioExercises();
	strengthEx = strengthExerciseBase.get_StrengthExercise();
	
	
	
	for (CardioExercise e : cardioEx) {
		Exercise* exerciseC = new CardioExercise(e);
		this->exercises.push_back(exerciseC);
	}

	for (StrengthExercise e : strengthEx) {
		Exercise* exerciseS = new StrengthExercise(e);
		this->exercises.push_back(exerciseS);
	}

	for (Exercise* e : exercises) {
		cout<<e->getDetails();
	}
	
}

void Actions::show_trainingPlan()
{
	FileReader f;
	vector<vector<string>>trainingData = f.readFile("training_plan.txt");
	vector<CardioExercise> cardioExercises;
	vector<StrengthExercise> strengthExercises;
	vector<string>days;
	
	for (vector<string>ce : trainingData) {
		int counter = 0;
		for (const auto& element : ce) {
			counter++;
		}
		
		
		if (counter == 1) {
			cout << "-----------------------" << endl;
			cout << "****** "<<ce[0]<<" ******" << endl;
		}
		 else if (counter==3) {
			CardioExercise c(ce[0], stoi(ce[1]), ce[2]);
			cardioExercises.push_back(c);
			
		}
		else if(counter==4){
			StrengthExercise c(ce[0], stoi(ce[1]), ce[2], ce[3]);
			strengthExercises.push_back(c);
			
		}
		for (CardioExercise ce : cardioExercises) {
			cout << ce.getDetails();
		}
		for (StrengthExercise se : strengthExercises) {
			cout << se.getDetails();
		}
		
		cardioExercises.clear();
		strengthExercises.clear();
		
	}
	cout << endl;
	
	system("pause");
}

void Actions::delete_exercise()
{
	int c, toDelete;
	char p;
	StrengthExerciseBase strengthExerciseBase;
	vector<StrengthExercise>seV= strengthExerciseBase.get_StrengthExercise();
	CardioExerciseBase cardioExerciseBase;
	vector<CardioExercise>ceV = cardioExerciseBase.get_CardioExercises();
	cout << "JAKIE CWICZENIE CHCESZ USUNAC?" << endl;
	cout << "1-SILOWE 2-CARDIO" << endl;
	cin >> c;
	if (c == 1) {
		int counter = 0;
		if (seV.size() == 0) {
			cout << "Brak cwiczen w bazie" << endl;
		}
		else {

			for (StrengthExercise ce : seV) {
				cout << counter << ". " << ce.getDetails();
				counter++;
			}
			
			system("pause");
			do {
				cout << "WYBIERZ CWICZENIE KTORE CHCESZ USUNAC" << endl;
				cin >> toDelete;
				strengthExerciseBase.delete_Exercise(toDelete);
				cout << "CHCESZ USUNAC JESZCZE?(y/n)" << endl;
				cin >> p;
			} while (p == 'y');
			
		}
	}else if (c == 2) {
		int counter = 0;
		if (ceV.size() == 0) {
			cout << "Brak cwiczen w bazie" << endl;
		}
		else {

			for (CardioExercise ce : ceV) {
				cout << counter << ". " << ce.getDetails();
				counter++;
			}

			system("pause");
			do {
				cout << "WYBIERZ CWICZENIE KTORE CHCESZ USUNAC" << endl;
				cin >> toDelete;
				cardioExerciseBase.delete_Exercise(toDelete);
				cout << "CHCESZ USUNAC JESZCZE?(y/n)" << endl;
				cin >> p;
			} while (p == 'y');
			
		}
	}

	


}
