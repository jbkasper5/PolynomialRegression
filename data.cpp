#include "data.h"
Data::Data(){
    file.open("input.txt");
    ReadArchitecture();
    ReadActivationArchitecture();
    ReadLearningRate();
    ReadEpochs();
    ReadInputData();
    file.close();
}

void Data::ReadArchitecture(){
    std::string information;
    if(file.is_open()){
        getline(file, information);
        information.erase(remove_if(information.begin(), information.end(), isspace), information.end());
        information = information.erase(0, information.find(":") + 1);
        while(information.find(",") != std::string::npos){
            architecture.push_back(std::stoi(information.substr(0, information.find(","))));
            information = information.erase(0, information.find(",") + 1);
        }
        architecture.push_back(stoi(information));
    }
}

void Data::ReadActivationArchitecture(){
    std::string information;
    if(file.is_open()){
        getline(file, information);
        information.erase(remove_if(information.begin(), information.end(), isspace), information.end());
        information = information.erase(0, information.find(":") + 1);
        while(information.find(",") != std::string::npos){
            activationArchitecture.push_back(information.substr(0, information.find(",")));
            information = information.erase(0, information.find(",") + 1);
        }
        activationArchitecture.push_back(information);
    }
}

void Data::ReadLearningRate(){
    std::string information;
    if(file.is_open()){
        getline(file, information);
        information.erase(remove_if(information.begin(), information.end(), isspace), information.end());
        information = information.erase(0, information.find(":") + 1);
        learningRate = stod(information);
    }
}

void Data::ReadEpochs(){
    std::string information;
    if(file.is_open()){
        getline(file, information);
        information.erase(remove_if(information.begin(), information.end(), isspace), information.end());
        information = information.erase(0, information.find(":") + 1);
        epochs = stoi(information);
    }
}

void Data::ReadInputData(){
    std::string information;
    getline(file, information);
    if(file.is_open()){
        while(getline(file, information)){
            information.erase(remove_if(information.begin(), information.end(), isspace), information.end());
            inputs.push_back(stod(information.substr(information.find("(") + 1, information.find(",") - 1)));
            information.erase(information.find(")"), information.find(")"));
            solutions.push_back(stod(information.substr(information.find(",") + 1, information.size() - 1)));
        }
    }
}
