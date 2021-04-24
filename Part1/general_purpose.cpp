#include "general_purpose.h++"

float GeneralPurpose::mean(std::vector<float> input){
        float mean = accumulate( input.begin(), input.end(), 0.0) / input.size();
        return mean;
    }

float GeneralPurpose::sqr(float input){
    return input * input;
}

float GeneralPurpose::median(std::vector<float> input){
    sort(input.begin(), input.end());
    float median;
    float mid_idx = round(float(input.size()) / 2.0) - 1;
    int is_odd = input.size() % 2;
    if (is_odd){
        median = input[mid_idx];
    }
    else{
        median = input[mid_idx] / 2 + input[mid_idx + 1] / 2;
    }
    return median;
}

float GeneralPurpose::range(std::vector<float> input){
    float max = *std::max_element(input.begin(), input.end());
    float min = *std::min_element(input.begin(), input.end());
    return max - min;
}
    
float GeneralPurpose::variance(std::vector<float> input){
    float mean = GeneralPurpose::mean(input);
    float sum = 0;
    for (auto item : input){
        sum += GeneralPurpose::sqr(item - mean);
    }
    return sum / input.size();
}