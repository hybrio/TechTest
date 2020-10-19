#include <iostream>
#include <vector>
#include <string>

using namespace std;
int meanCalc(vector<int> input) {
    int total = 0;
    int size = 0;
    for (const int& val : input)
    {
        total+= val;
        size++;
    }
    return total/size;
}

string signatureToEnglish(string signature){
    string result = "";
    // remove everything before function name
    if (signature.rfind (' ') != string::npos){
        signature.erase(0,(signature.rfind(' ')+1));
    }
    // remove everything after opening bracket
    if (signature.find ('(') != string::npos){
        signature.erase(signature.find ('('),signature.length());
    }
    // remove the first 4 letters (the word "test")
    signature.erase(0,4);
    // iterate through what remains
    for (int i=1; i < signature.length(); i++){
        if (signature[i]>='A' && signature[i]<='Z'){
            // if it's a capital, make it lower case, add space in front then append to result
            char letter = tolower(signature[i]);
            result = result + " " + letter;
        } else {
            // if it's lowercase append to result
            result += signature[i];
        }
    }
    // capitalise then append the first letter of the function name onto the front of result
    char firstLetter = toupper(signature[0]);
    result = firstLetter + result;
    return result;
}


int main()
{
    vector<int> inputs {1,2,3,4,5};
    string methodSignature = "public void testCowsCanBeMilked()";
    cout<<"running meanCalc \nInputs: ";
    for (auto i = inputs.begin(); i != inputs.end(); ++i) std::cout << *i << ',';
    cout << "Result: " << meanCalc(inputs) << '\n';
    cout<<"running signatureToEnglish \n";
    cout << "Input: " << methodSignature << '\n';
    cout << "Result: " << signatureToEnglish(methodSignature) <<'\n';

}



