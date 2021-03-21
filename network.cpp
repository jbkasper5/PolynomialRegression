#include "network.h"
Network::Network(){
    ReceiveData();

    srand(time(NULL));
    for(int i = 0; i < numLayers - 1; ++i){
        Eigen::MatrixXd weight_layer = Eigen::MatrixXd::Random(architecture[i + 1], architecture[i]);
        weight_layer.array() += 1;
        w.push_back(weight_layer / 40);
        dw.push_back(weight_layer * 0);

        Eigen::MatrixXd bias_layer = Eigen::MatrixXd::Zero(architecture[i + 1], 1);
        b.push_back(bias_layer);
        db.push_back(bias_layer);
    }

    for(int i = 0; i < numLayers; ++i){
        Eigen::MatrixXd activation_layer = Eigen::MatrixXd::Zero(architecture[i], numExamples);
        a.push_back(activation_layer);
        if(i != 0){
            z.push_back(activation_layer);
        }
    }
}

void Network::ReceiveData(){
    architecture = data.architecture;
    numLayers = architecture.size();
    epochs = data.epochs;
    learningRate = data.learningRate;
    inputs = data.inputs;
    solutions = data.solutions;

    lossFunction = new Architecture::MeanSquaredError();
    numExamples = 1;

    for(int i = 0; i < data.activationArchitecture.size(); ++i){
        std::string functionName = data.activationArchitecture[i];
        for(int i = 0; i < functionName.size(); ++i){
            functionName[i] = tolower(functionName[i]);
        }
        if(functionName == "relu"){
            function.push_back(new Architecture::ReLu());
        }else if(functionName == "sigmoid"){
            function.push_back(new Architecture::Sigmoid());
        }else if(functionName == "leakyrelu"){
            function.push_back(new Architecture::LeakyRelu());
        }else if(functionName == "tanh"){
            function.push_back(new Architecture::Tanh());
        }else if(functionName == "linear"){
            function.push_back(new Architecture::Linear());
        }else{
            function.push_back(new Architecture::ReLu());
        }
    }
}

void Network::ForwardPropagation(){
    a[0](0) = inputs[netProgress % inputs.size()];
    currSolution = solutions[netProgress % solutions.size()];
    for(int i = 0; i < numLayers - 1; ++i){
        z[i] = w[i] * a[i];
        z[i].array() += b[i].array();
        a[i + 1] = function[i]->activationFunction(z[i]);
    }
}

void Network::BackPropagation(){
    Eigen::MatrixXd loss = lossFunction->lossFunctionDerivative(a[a.size() - 1], currSolution, a[0](0));
    db[db.size() - 1] = function[function.size() - 1]->activationFunctionDerivative(z[z.size() - 1]).array() * loss.array();
    for(int i = numLayers - 2; i > 0; --i){
        dw[i] = db[i] * (a[i].transpose());
        db[i - 1] = function[i]->activationFunctionDerivative(z[i - 1]).array() * (w[i].transpose() * db[i]).array();
    }
    dw[0] = db[0] * (a[0].transpose());
}

void Network::UpdateParameters(){
    for(int i = 0; i < b.size(); ++i){
        b[i] += (learningRate * db[i]);
    }

    for(int i = 0; i < w.size(); ++i){
        w[i] += (learningRate * dw[i]);
    }
}

void Network::DisplayResults(){
    for(int i = 0; i < a[a.size() - 1].rows(); ++i){
        std::cout << a[a.size() - 1](i, 0) << std::endl;
    }
}

int main(){
    Network net;
    for(net.netProgress = 1; net.netProgress < net.epochs + 1; ++net.netProgress){
        net.ForwardPropagation();
        net.BackPropagation();
        net.UpdateParameters();
        if(net.netProgress % (net.epochs / 20) == 0){
            std::cout << (double(net.netProgress) / net.epochs) * 100 << "%..." << std::endl;
        }
    }
    net.DisplayResults();
    return 0;
}
