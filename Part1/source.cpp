#include <iostream>
#include <vector>
#include "general_purpose.h++"

using namespace std;


class StatisticalFunctions : public GeneralPurpose
{
private:
    vector<float> data_vector;
public:
    StatisticalFunctions(vector<float> class_input);
    ~StatisticalFunctions();
    //central tread measures
    float find_median();
    float find_mean();
    float find_mode();
    bool is_unimodal();
    //variability measures
    float find_range();
    float find_variance();
};

StatisticalFunctions::StatisticalFunctions(vector<float> class_input)
{
    data_vector = class_input;
}

StatisticalFunctions::~StatisticalFunctions()
{
}

float StatisticalFunctions::find_mean(){
    return mean(data_vector);
}

float StatisticalFunctions::find_median(){
    return median(data_vector);
}

float StatisticalFunctions::find_mode(){
    // not implemented yet
    return 0;
}

float StatisticalFunctions::find_range(){
    return range(data_vector);
}

float StatisticalFunctions::find_variance(){
    return variance(data_vector);
}


int main(){
    vector<float> arg = {1, 6, 3, 100};
    StatisticalFunctions service(arg);
    cout << endl << "median is: " << service.find_median() << endl;
    cout << "mean value is: " << service.find_mean() << endl << "_______" << endl;
    cout << "Variability measures" << endl;
    cout << "range value is: " << service.find_range() << endl;
    cout << "variance value is: " << service.find_variance() << endl;
    return 0;
}