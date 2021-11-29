
#include <string>
#include <exception>
#include <Windows.h>
#include "VocabularyMaker.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>

using namespace std::chrono_literals;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string fileName = "puteshestviya-dushi.txt";
	VocabularyMaker vMaker;

	std::thread thApp([&]() {
		try {
			vMaker(fileName);
			vMaker.displayVocabulary(true); //false - lexicograph, true - count sort
		}
		catch (std::exception ex) {
			std::cerr << ex.what();
		}
		});

	float progressWork;
	std::vector<std::string> sony = {
		" /)_/)\n (^_^)\n(\\__ /)\n",
		"(\\__/)\n(='.'=)\n(\")_(\")\n" };
	int state = 0;
	do
	{
		system("cls");
		std::cout << "Найдено всего слов в тексте: " 
			<< vMaker.getPreCountWords() << '\n'
			<< "В словаре: " << vMaker.getVocabuarySize() << " слов\n";
		std::cout << std::fixed << std::setprecision(2) << "Текст обрабатывается: "
			<< vMaker.getProgress()
			<< "%\n\n" << sony[state ^= 1];
		progressWork = vMaker.getProgress();
		std::this_thread::sleep_for(150ms);
	} while (progressWork < 100.f);

		thApp.join();
	vMaker.finishMessage();
}