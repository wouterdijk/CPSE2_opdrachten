#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
	std::ifstream file("Bible.txt");

	//1 : Lees alle karakters van deze file in, in een vector.
	std::vector<char> v(std::istreambuf_iterator<char>(file), {});

	//2 : Print hoeveel karakters de file bevat (vraag het aan de vector).
   	std::cout << "Size vector is " << v.size() << std::endl;

	//3 : Print hoeveel regels de file bevat (gebruik de vector en een STL algoritme).
	int lines = std::count(v.begin(), v.end(), '\n');
	std::cout << "Lines amount is " << lines << std::endl;

	//4 : Print hoeveel alfabetische karacters de file bevat (vector + algoritme).
	std::vector<char> a_v;
	std::for_each( v.begin(), v.end(), [&](char a) {
		if(std::isalpha(a)){
			a_v.push_back(a);
	}});
	std::cout << "Alfabetical charcters amount is " << a_v.size() << std::endl;

	//5 : Zet de letters in de vector om in kleine letters (max. 3 regels code).
	std::transform( a_v.begin(), a_v.end(), a_v.begin(), [&](auto a) {
		return tolower(a);
	});

	//6 : Tel in een lijst voor iedere letter (a..z) hoe vaak hij voorkomt in de vector (diverse manieren mogelijk).
	std::map< char, int> m;
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	std::for_each( alphabet.begin(), alphabet.end(), [&](auto a) {
		m[a] = std::count(a_v.begin(), a_v.end(), a);
	});

	//7 : Druk deze lijst af:
	//7.1: gesorteerd op lettervolgorde
	std::for_each( m.begin(), m.end(), [](auto& map) {
		std::cout << "7.1 Key: " << map.first << ",\tValue: " << map.second << std::endl;
	});
	std::cout << std::endl;

	//7.2 : gesorteerd op hoe vaak een letter voorkomt (gebruik een algoritme).
    std::multimap<int, char> MM;

	std::for_each( m.begin(), m.end(), [&](auto& map) {
		MM.insert({ map.second, map.first });
	});

	std::for_each( MM.begin(), MM.end(), [](auto& map) {
		std::cout << "7.2 Key: " << map.second << ",\tValue: " << map.first << std::endl;
	});
	std::cout << std::endl;

	//8 : Bepaal welke woorden er in de tekst voorkomen.
	//		Druk de 10 meest voorkomende woorden af.
	//		Een woord is een aaneengesloten reeks letters. (gebruik een map)

	std::map< std::string, int> words;
	std::multimap<int, std::string> WMM;
	int c = 0;
	std::string w = "";
	bool word = false;

	std::transform( v.begin(), v.end(), v.begin(), [&](auto a) {
		return tolower(a);
	});

	std::for_each( v.begin(), v.end(), [&](auto a) {
		if( std::isalpha(a) ){
			word = true;
			w.push_back(a);
		}else if(word){
			if(words[w] >= 0){
				words[w]++;
			}else{
				words[w] = 1;
			}
			w = "";
			word = false;
		}
	});

	std::for_each(words.begin() , words.end(), [&](auto map){
		WMM.insert({ map.second, map.first });
	});

	std::for_each( WMM.begin() , WMM.end(), [&](auto map) {
		if(c != 30){
			std::cout << "8 Key: " << map.second << ",\tValue: " << map.first << std::endl;
			c++;
		}
	});
}