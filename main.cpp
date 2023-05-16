#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
int main() {
    auto pliki=std::fstream();
    pliki.open("NamesOfFiles.txt",std::ios::out);
    //Sprawdzanie jakie foldery znajdują się w bieżącym folderze i zapisanie ich nazw do pliku
    std::string folderPath = ".";
    for (const auto &entry : std::filesystem::directory_iterator(folderPath)) {
        if (std::filesystem::is_regular_file(entry)) {
            std::cout << entry.path().string() << std::endl;
            pliki<<entry.path().string()<<std::endl;
        }
    }
    pliki.close();
    //Tworzenia streama który odczytuje nazwy plików z plika
    //wypisuje ich i pobiera scieżke do plika który chcę odczytać
    auto path=std::string();
    std::cout<<"Wybierz plik w folderze albo wpisz szcierzke:"<<std::endl;
    std::cin>>path;
    auto haslo="dupa";
    auto podane=std::string();
    std::cout<<"Podaj haslo do tego pliku:"<<std::endl;
    std::cin>>podane;
    while(podane!=haslo){
        std::cout<<"Nie prawidlowe haslo"<<std::endl;
        std::cin>>podane;
    }
    auto file=std::fstream();
    file.open(path,std::ios::in);
    auto line=std::string();
    while(std::getline(file,line)){
        std::cout<<line<<std::endl;
    }

}