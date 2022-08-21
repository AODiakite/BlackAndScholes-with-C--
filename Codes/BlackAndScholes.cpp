//
//  BlackAndScholes.cpp
//  Options pricing cpp
//
//  Created by Abdoul Oudouss Diakite on 21/08/2022.
//

#include <iostream>
#include "BlackAndScholes.h"
#include <cmath>
#include <random>
#include <iomanip>

using namespace std;

// Phi(-∞, x) aka N(x)
double normalCDF(double x)
{
    return erfc(-x/std::sqrt(2))/2;
}
//normalPDF denotes the standard normal probability density function
double normalPDF(double x){
    return (1/sqrt(2*M_PI))*exp(-x*x/2);
}
BlackAndScholes::BlackAndScholes(){
    
}

// Calculation of d1
double BlackAndScholes::d1(){
    return (1/(my_sigma*sqrt(my_T-my_t)))*
    (log(my_S/my_K)+(my_r+pow(my_sigma, 2)/2)*(my_T - my_t));
}

// Calculation of d1
double BlackAndScholes::d2(){
    return d1() - (my_sigma*sqrt(my_T-my_t));
}

/* The value of a call option for a non-dividend-paying
 underlying stock in terms of the Black–Scholes parameters is*/
double BlackAndScholes::call(){
    return my_S*normalCDF(d1()) - my_K*normalCDF(d2())*exp(-my_r*(my_T-my_t));
}

/*The price of a corresponding put
 option based on put–call parity with*/
double BlackAndScholes::put(){
    return my_K*normalCDF(-d2())*exp(-my_r*(my_T-my_t)) - my_S*normalCDF(-d1()) ;
}

/*The Greeks for Black–Scholes are given below.
 They can be obtained by differentiation of the Black–Scholes formula.*/
// Delta
double BlackAndScholes::delta(string Type){
    if (Type == "C")
        return normalCDF(d1());
    return normalCDF(d1())-1;
}

// Gamma
double BlackAndScholes::gamma(){
    return normalPDF(d1())/(my_S*my_sigma*sqrt(my_T-my_t));
}
// Vega
double BlackAndScholes::vega(){
    return my_S*normalPDF(d1())*sqrt(my_T-my_t);
}
// Theta
double BlackAndScholes::theta(string Type){
    if (Type == "C")
        return -(my_S*normalPDF(d1())*my_sigma)/(2*sqrt(my_T-my_t))
        -my_r*my_K*exp(-my_r*(my_T-my_t))*normalCDF(d2());
    return -(my_S*normalPDF(d1())*my_sigma)/(2*sqrt(my_T-my_t))
    +my_r*my_K*exp(-my_r*(my_T-my_t))*normalCDF(-d2());
}

// Rho
double BlackAndScholes::rho(string Type){
    if (Type == "C")
        return my_K*(my_T-my_t)*exp(-my_r*(my_T-my_t))*normalCDF(d2());
    return -my_K*(my_T-my_t)*exp(-my_r*(my_T-my_t))*normalCDF(-d2());
}

// reading
void BlackAndScholes::read(){
    
    // get t
    cout << "Starting time t =";
    cin >>my_t;
    cout<<endl;
    // get T
    cout << "time of option expiration T =";
    cin >> my_T;
    cout<<endl;
    // get S
    cout << "Price of the underlying asset at time t, St =";
    cin >> my_S;
    cout<<endl;
    // get K
    cout << "The strike price of the option K =";
    cin >> my_K;
    cout<<endl;
    // get r
    cout << "The annualized risk-free interest rate r =";
    cin >> my_r;
    cout<<endl;
    // get sigma
    cout << "The standard deviation of the stock's returns sigma =";
    cin >> my_sigma;
    cout<<endl;

}

// print
void BlackAndScholes::print(){
    
    // Call and Put price
    cout << "The value an option for a non-dividend-paying underlying stock in terms of the Black–Scholes parameters is : \n"<<"---------------------\n"<<
    "Call :  "<<setprecision(3)<<call()<<
    "   Put :  "<<setw(3)<<setprecision(3)<<put();
    cout<<endl;
    cout<<"*************************\n";
    // Call and Put price
    cout << "The Greeks for Black-Scholes are given below : \n"<<
    "----------------------------\n"<<
    "Delta Call :  "<<setprecision(3)<<delta("C")<<
    "   Delta Put :  "<<setprecision(3)<<delta("P");
    cout<<endl;
    // Theta
    cout<<"*************************\n"<<
    "Theta Call :  "<<setprecision(3)<<theta("C")<<
    "  Theta Put :  "<<setprecision(3)<<theta("P");
    cout<<endl;
    // Rho
    cout<<"*************************\n"<<
    "Rho Call :  "<<setprecision(3)<<rho("C")<<
    "   Rho Put :  "<<setprecision(3)<<rho("P");
    cout<<endl;
    // Vega & Gamma
    cout<<"*************************\n"<<
    "Vega :  "<<setprecision(3)<<vega()<<
    "   Gamma :  "<<setprecision(3)<<gamma()<<endl;
    cout<<endl;

    

}
