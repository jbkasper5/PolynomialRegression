#include "architecture.h"

//RELU
Eigen::MatrixXd Architecture::ReLu::activationFunction(Eigen::MatrixXd mat){
    return mat.array().max(0);
}

Eigen::MatrixXd Architecture::ReLu::activationFunctionDerivative(Eigen::MatrixXd mat){
    return mat.array().max(0) / mat.array();
}

//LINEAR
Eigen::MatrixXd Architecture::Linear::activationFunction(Eigen::MatrixXd mat){
    return mat;
}

Eigen::MatrixXd Architecture::Linear::activationFunctionDerivative(Eigen::MatrixXd mat){
    return mat.array() / mat.array();
}

//SIGMOID
Eigen::MatrixXd Architecture::Sigmoid::activationFunction(Eigen::MatrixXd mat){
    return (1 / (1 + exp(-mat.array())));;
}

Eigen::MatrixXd Architecture::Sigmoid::activationFunctionDerivative(Eigen::MatrixXd mat){
    return Architecture::Sigmoid::activationFunction(mat).array() - Architecture::Sigmoid::activationFunction(mat).array().pow(2);
}

//TANH
Eigen::MatrixXd Architecture::Tanh::activationFunction(Eigen::MatrixXd mat){
    return tanh(mat.array());
}

Eigen::MatrixXd Architecture::Tanh::activationFunctionDerivative(Eigen::MatrixXd mat){
    return 1 - Architecture::Tanh::activationFunction(mat).array().pow(2);
}

//LEAKYRELU
Eigen::MatrixXd Architecture::LeakyRelu::activationFunction(Eigen::MatrixXd mat){
    return (mat.array().max(0.01 * mat.array()));
}

Eigen::MatrixXd Architecture::LeakyRelu::activationFunctionDerivative(Eigen::MatrixXd mat){
    return (mat.array().max(0.01 * mat.array()) / mat.array());
}

//LOSS FUNCTIONS
Eigen::MatrixXd Architecture::MeanSquaredError::lossFunctionDerivative(Eigen::MatrixXd mat, double sol, double input){
    double prediction = 0;
    for(int i = 0; i < mat.rows(); ++i){
        prediction += mat(i, 0) * pow(input, i);
    }
    Eigen::MatrixXd temp(mat.rows(), 1);
    for(int i = 0; i < temp.rows(); ++i){
        temp(i, 0) = 2 * (sol - prediction) * pow(input, i);
    }
    return temp;
}
