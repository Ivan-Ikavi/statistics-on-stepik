#include <iostream>
#include <vector>
#include "general_purpose.h++"

using namespace std;

void print_vector(const vector<float>& input_vector){
    for (auto item : input_vector){
        cout << item << " ";
    }
    cout << endl;
}

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
    float find_rms();
    //data processing
    vector<float> do_normalization();
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

float StatisticalFunctions::find_rms(){
    // for one sample of data rms would be called standard deviation and also the devider should be changed
    // from n to n-1
    // while for the general population this parameter is called sigma
    return sqrt(variance(data_vector));
}

vector<float> StatisticalFunctions::do_normalization(){
    vector<float>  normalized; 
    for (auto item : data_vector){
        auto normalized_val = (item - find_mean()) / find_rms();
        normalized.push_back(normalized_val);
    }
    return normalized;
}


int main(){
    vector<float> arg = {1, 6, 3, 10};
    cout << endl;
    print_vector(arg);
    StatisticalFunctions service(arg);
    cout << endl << "median is: " << service.find_median() << endl;
    cout << "mean value is: " << service.find_mean() << endl << "_______" << endl;
    cout << "Variability measures" << endl;
    cout << "range value is: " << service.find_range() << endl;
    cout << "variance value is: " << service.find_variance() << endl;
    cout << "root mean square is:" << service.find_rms() << endl;
    vector<float> normalized = service.do_normalization();
    cout << endl;
    print_vector(normalized);
    StatisticalFunctions service_for_normolized(normalized);
    cout << endl << "median is: " << service_for_normolized.find_median() << endl;
    cout << "mean value is: " << service_for_normolized.find_mean() << endl << "_______" << endl;
    cout << "Variability measures" << endl;
    cout << "range value is: " << service_for_normolized.find_range() << endl;
    cout << "variance value is: " << service_for_normolized.find_variance() << endl;
    cout << "root mean square is:" << service_for_normolized.find_rms() << endl;
    return 0;
}