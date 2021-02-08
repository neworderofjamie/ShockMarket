#include <iostream>
#include <string>
#include "./Eigen/Core"

#define string std::string


class GrowthModel
{
    public:
        GrowthModel(string startState);
        GrowthModel();
        string getState();
        float getEmission();
    private:
        string state;
        Eigen::Matrix<float,3,3> T;
    
};
