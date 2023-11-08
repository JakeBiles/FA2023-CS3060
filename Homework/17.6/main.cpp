#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <string>

const char* FILE_NAME = "someWords.txt";

int main(){

    std::map<std::string,unsigned int> wordMap;
    std::string data; 
    std::ifstream wordFile;
    wordFile.open(FILE_NAME);

    if(wordFile){

        while(!wordFile.eof()){

            std::getline(wordFile, data, ' ');

            for(size_t i = 0, len = data.size(); i < len; i++){
               
                if(ispunct(data[i])){

                    data.erase(i--, 1);
                    len = data.size();

                }

            }

            std::transform(data.begin(), data.end(), data.begin(), tolower);

            if(wordMap.find(data) != wordMap.end()) wordMap[data] = wordMap.at(data) + 1;
            else wordMap[data] = 1;

        }
        
    } else std::cout << "Could not open file!";
    
    for(auto it : wordMap){

        std::cout << it.first << ": " << it.second << "\n";

    }
    
    return 0;

}