#include "ustinova_favouriteTea.h"
#include <iostream>

ustinova_favouriteTea::ustinova_favouriteTea() {
};
ustinova_favouriteTea::~ustinova_favouriteTea() {
};

IMPLEMENT_SERIAL(ustinova_favouriteTea, ustinova_tea, 1);

void ustinova_favouriteTea::c_in() {
	ustinova_tea::c_in();
	std::cout << "Введите вашу оценку: ";
	std::cin >> personal_rate;
}

void ustinova_favouriteTea::c_out() {
	ustinova_tea::c_out();
	std::cout << "Ваша оценка : " << personal_rate<<"\n";
}

void ustinova_favouriteTea::Serialize(CArchive& arch) {
	ustinova_tea::Serialize(arch);
	if (arch.IsStoring()) {
		arch << personal_rate;
	}
	else {
		arch >> personal_rate;
	}
}