#include <eigen3/Eigen/Core>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
class Data{
public:
    Data();

    std::vector<int> architecture;
    std::vector<std::string> activationArchitecture;
    std::vector<double> inputs;
    std::vector<double> solutions;
    
    int epochs;
    double learningRate;

    std::ifstream file;
private:
    void ReadArchitecture();
    void ReadActivationArchitecture();
    void ReadLearningRate();
    void ReadEpochs();
    void ReadInputData();
};
