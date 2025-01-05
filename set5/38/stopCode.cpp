#include "address.ih"

string Address::stopCode(string postalCode)
{
    postalCode[postalCode.size() - 1]++; 
    //increase the last digit by one to know 
    //when to stop erasing postCodes

    return postalCode;
}