// Marissa Foster
// CIS1202 - 800
// Assignment 15a

#include <string>
#include <iostream>

using namespace std;

class invalidCharacterExcpeption
{

};

class invalidRangeException 
{

};
class caseConversionException
{

};

char character(char, int);

int main()
{


}

char character(char start, int offset)
{
	int startAsciiValue = int(start);
	int target = startAsciiValue + offset;

    try {
        //if start is not lower case letter or upper case letter throw invalidCharacterExcpeption
        if (startAsciiValue < 65 || (startAsciiValue > 90 && startAsciiValue < 97) || startAsciiValue > 122)
        {
            throw invalidCharacterExcpeption();
        }

        //else if target is not lower case letter or upper case letter throw invalidRangeException
        else if (target < 65 || (target > 90 && target < 97) || target > 122)
        {
            throw invalidRangeException();
        }

        //else if target is lower case and start is upper case or target is upper case and start is lower case then throw caseConversionException
        else if ((target >= 65 && target <= 90 && startAsciiValue >= 95 && startAsciiValue <= 122) || (target >= 95 && target <= 122 && startAsciiValue >= 65 && startAsciiValue <= 90))
        {
            throw caseConversionException();
        }
    }

    catch (invalidCharacterExcpeption exception1)
    {
        cout << " Invalid Character Exception " << endl;
        return ' ';
    }
    catch (invalidRangeException exception2)
    {
        cout << " Invalid Range Exception " << endl;
        return ' ';
    }
    catch (caseConversionException exception3)
    {
        cout << " Cannot make case changes from upper to lower or otherwise " << endl;
        return ' ';
    }

    //if no exception was catched return the character value of target
    return char(target);

}