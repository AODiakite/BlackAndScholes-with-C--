//
//  BlackAndShcoles.hpp
//  Options pricing cpp
//
//  Created by Abdoul Oudouss Diakite on 21/08/2022.
//

#ifndef BlackAndShcoles_h
#define BlackAndShcoles_h

class BlackAndScholes{
public:
    BlackAndScholes();
    void read();
    void print();
    double call();
    double put();
    double delta(std::string Type);
    double gamma();
    double vega();
    double theta(std::string Type);
    double rho(std::string Type);
private:
    double my_S;
    double my_K;
    double my_r;
    double my_sigma;
    double my_t;
    double my_T;
    double d1();
    double d2();
};

#endif /* BlackAndShcoles_h */
