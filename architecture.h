#include <eigen3/Eigen/Core>
#include <iostream>
#include <vector>
#include <cmath>

class Architecture{
public:

    //Absract classes
    class ActivationFunctions{
    public:
        virtual Eigen::MatrixXd activationFunction(Eigen::MatrixXd mat) = 0;
        virtual Eigen::MatrixXd activationFunctionDerivative(Eigen::MatrixXd mat) = 0;
    };

    class LossFunctions{
    public:
        virtual Eigen::MatrixXd lossFunctionDerivative(Eigen::MatrixXd mat, double sol, double input) = 0;
    };

    //Activation Functions
    class ReLu: public ActivationFunctions{
    public:
        Eigen::MatrixXd activationFunction(Eigen::MatrixXd mat);
        Eigen::MatrixXd activationFunctionDerivative(Eigen::MatrixXd mat);
    };

    class Sigmoid: public ActivationFunctions{
    public:
        Eigen::MatrixXd activationFunction(Eigen::MatrixXd mat);
        Eigen::MatrixXd activationFunctionDerivative(Eigen::MatrixXd mat);
    };

    class Tanh: public ActivationFunctions{
    public:
        Eigen::MatrixXd activationFunction(Eigen::MatrixXd mat);
        Eigen::MatrixXd activationFunctionDerivative(Eigen::MatrixXd mat);
    };

    class LeakyRelu: public ActivationFunctions{
    public:
        Eigen::MatrixXd activationFunction(Eigen::MatrixXd mat);
        Eigen::MatrixXd activationFunctionDerivative(Eigen::MatrixXd mat);
    };

    class Linear: public ActivationFunctions{
    public:
        Eigen::MatrixXd activationFunction(Eigen::MatrixXd mat);
        Eigen::MatrixXd activationFunctionDerivative(Eigen::MatrixXd mat);
    };

    //Loss function
    class MeanSquaredError: public LossFunctions{
    public:
        Eigen::MatrixXd lossFunctionDerivative(Eigen::MatrixXd mat, double sol, double input);
    };
};
