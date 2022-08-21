//
//  main.cpp
//  Options pricing cpp
//
//  Created by Abdoul Oudouss Diakite on 21/08/2022.
//

#include <iostream>
#include "BlackAndScholes.h"
using namespace std;

int main(int argc, const char * argv[]) {
    BlackAndScholes produit;
    produit.read();
    produit.print();
    return 0;
}
