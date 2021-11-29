
#include "VocabularyMaker.hpp"
#include "ListOfPrepositions.hpp"

#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string_view>
#include <exception>

VocabularyMaker::VocabularyMaker() :
	filePath(fs::current_path() / "src"),
	wordMaxLength(0),
	preCountWords(0),
	countProgress(0.f),
	savedVocabuaryFile(filePath)
{}

void VocabularyMaker::operator()(std::string_view fileName) {
	filePath /= fileName;
	checkFilePath();
	start();
}

void VocabularyMaker::displayVocabulary(
	bool isSortedByCount,
	bool isFileStream,
	std::string filename) 
{
	std::vector<std::pair<std::string, size_t>> wordCounts;
	wordCounts.reserve(vocabulary.size());
	std::move(begin(vocabulary), end(vocabulary),
		std::back_inserter(wordCounts));

	//ranged by counts
	if (isSortedByCount) {
		std::sort(begin(wordCounts), end(wordCounts),
			[](const auto& a, const auto& b) {
				return a.second > b.second;
			});
	}
	if (!isFileStream) {
		showData(wordCounts, std::cout);
		return;
	}
	savedVocabuaryFile /= filename;
	std::ofstream outFile{ savedVocabuaryFile };
	if (!outFile) {
		throw std::exception("Error. File for writting not open.\n");
	}
	showData(wordCounts, outFile);
	outFile.close();
	
}


fs::path VocabularyMaker::getFilePath() const {
	return filePath;
}

void  VocabularyMaker::checkFilePath() {
	if (!fs::exists(filePath))
		throw std::exception("Error. File is not found!\n");
}

size_t VocabularyMaker::getPreCountWords() const noexcept {
	return preCountWords;
}
float VocabularyMaker::getProgress() const noexcept {
	return countProgress;
}
size_t VocabularyMaker::getVocabuarySize() const noexcept
{
	return vocabulary.size();
}
void VocabularyMaker::preanalysis(std::ifstream& fin)
{
	std::string word;
	while (fin >> word) {
		++preCountWords;
	}
}

void VocabularyMaker::finishMessage() const noexcept
{
	std::cout << "\tVocabulary is saved.\n\tpath: "
		<< (savedVocabuaryFile).generic_string().c_str() << '\n';
}

void VocabularyMaker::start() {
	std::ifstream file(filePath);
	if (!file.is_open())
		throw std::exception("Error. Can not open the file.\n");
	preanalysis(file); //eof
	file.clear();
	file.seekg(0, std::ios::beg); //back to begin of the file

	std::string word;
	float curCountWord{ 1.f };
	//std::cout << "\tFonded " << preCountWords << " words.\n";
	while (file >> word) {
		auto filtered(filterPunctuation(word));//get word without other symbols
		countProgress =
			(curCountWord / preCountWords) * 100.f;
		++curCountWord;
		if (filtered.empty())
			continue;
		wordMaxLength = std::max<size_t>(wordMaxLength, filtered.length());
		++vocabulary[filtered]; //add word to vocabulary
		
	}
	file.close();
}

//TODO word)...word2 
std::string VocabularyMaker::filterPunctuation(const std::string& str) {
	const char* forbidden{ ".,:;!?()\"[]…{}*+0123456789—" };
	const auto idxBegin(str.find_first_not_of(forbidden));
	if (idxBegin == std::string::npos)
		return {};
	const auto idxEnd(str.find_last_not_of(forbidden));
	if (idxEnd == std::string::npos)
		return {};
	if (idxEnd - idxBegin < 2) //filtering short words (size < 2)
		return {};

	std::string result = str.substr(idxBegin, idxEnd - idxBegin + 1);
	std::for_each(begin(result), end(result),
		[&](char& ch) {
			if (ch >= 'A' && ch <= 'Z') ch = toLowerLatin(ch);
			else if (ch >= 'À' && ch <= 'ß') ch = toLowerRussian(ch);
		});

	if (isPreposition(result)) {
		return {};
	}
	return result;
}

void VocabularyMaker::showData(
	std::vector<std::pair<std::string, size_t>> container,
	std::ostream& out)
{
	out << std::setw(wordMaxLength) << "WORDS" << "\tCOUNTS\n";
	for (const auto& [word, count] : container) {
		out << std::setw(static_cast<std::streamsize>(wordMaxLength) + 2)
			<< word << ":\t" << count << '\n';
	}
}

char VocabularyMaker::toLowerRussian(const char& ch) {
	if (ch == '¨')
		return '¸';
	else return  ch + ('à' - 'À');
}

char VocabularyMaker::toLowerLatin(const char& ch) {
	return tolower(ch);
}

//to add states rus or eng for optimization and to ask by user
bool VocabularyMaker::isPreposition(const std::string& word) {
	for (const auto& prep : prepositionsRUS) {
		if (word == prep) return true;
	}
	for (const auto& prep : prepositionsLAT) {
		if (word == prep) return true;
	}
	return false;
}
