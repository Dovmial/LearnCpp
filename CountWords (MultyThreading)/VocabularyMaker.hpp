#ifndef VOCABULARY_MAKER_HPP_
#define	VOCABULARY_MAKER_HPP_

/*
1. ������� ���������� ���������� ������� ������,
	a. ���������� �������� �� ������������ ��� ����� � �������� ��� ������
	b. ��� ������� ����� ��������� ������� ������ � ��������� ����
		������� ��� ������ ����� ������ � �����
	c. �� ������� ���� �������� �������� � �������
2. �� ����� ������� �� ���������� ������������ � �������������� ���,
	��� ������ ���(����������� ������)
*/

//c++17
#include <string_view>
#include <string>
#include <map>
#include <filesystem>
#include <utility>
#include <fstream>

namespace fs = std::filesystem;

class VocabularyMaker {
public:
	VocabularyMaker();

	void operator()(std::string_view fileName);
	void displayVocabulary(
		bool isSortedByCount = true,
		bool isFileStream = true,
		std::string filename = "vocabulary.txt");

	fs::path getFilePath() const;
	void  checkFilePath();
	size_t getPreCountWords() const noexcept;
	float getProgress() const noexcept;
	size_t getVocabuarySize() const noexcept;
	void finishMessage() const noexcept;
private:
	void start();
	std::string filterPunctuation(const std::string& str);

	//from vacabulary to file or consol
	void showData(
		std::vector<std::pair<std::string, size_t>> container,
		std::ostream& out);

	char toLowerRussian(const char& ch);
	char toLowerLatin(const char& ch);
	bool isPreposition(const std::string& word);
	void preanalysis(std::ifstream& fin);
	
private:
	fs::path filePath;
	std::map<std::string, size_t> vocabulary;
	size_t wordMaxLength;
	size_t preCountWords;
	float countProgress;
	fs::path savedVocabuaryFile;
};
#endif // !VOCABULARY_MAKER_HPP_

