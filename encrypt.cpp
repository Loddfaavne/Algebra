#include "encrypt.h"

string encrypt(string message) {
    vector<char> coded;
    for(int i = size(message)-1; i >= 0; i--) {
        coded.push_back(static_cast<char>(mobiusFunction((char)message[i])*phiFunction((char)message[i]) + tauFunction((char)message[i])+ message[i]));
    }
    cout << endl;
    string final;
    for(auto x : coded) {
        final += x;
    }
    return final;
}