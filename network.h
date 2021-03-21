#include "architecture.h"
#include "data.h"
#include <eigen3/Eigen/Core>
#include <iostream>
#include <vector>

class Network{
public:

    //Methods
    Network();
    void ForwardPropagation();
    void BackPropagation();
    void UpdateParameters();
    void DisplayResults();

    //Variables
    int epochs;
    int netProgress;
private:
    void ReceiveData();
    std::vector<Eigen::MatrixXd> a;
    std::vector<Eigen::MatrixXd> z;
    std::vector<Eigen::MatrixXd> w;
    std::vector<Eigen::MatrixXd> b;

    std::vector<Eigen::MatrixXd> dw;
    std::vector<Eigen::MatrixXd> db;

    std::vector<int> architecture;
    std::vector<double> inputs;
    std::vector<double> solutions;

    std::vector<Architecture::ActivationFunctions*> function;
    Architecture::LossFunctions* lossFunction;
    Data data;

    double currInput;
    double currSolution;
    int numLayers;
    int numExamples;
    double learningRate;
};

