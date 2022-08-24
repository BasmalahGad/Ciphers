// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: All_Ciphers.cpp
// Program Description: program that allow to user to encrypt and decrypt a message with 9 different ciphers.
// Last Modification Date: 29/03/2022
// Author1 and ID and Group: Basmala Mohamed Sayed Gad, ID: 20210090, Group: s9,s10
// Author2 and ID and Group: Omar Khaled Mohamed Hamed, ID: 20210264, Group: s3,s4
// Author3 and ID and Group: Alan Samir Hakkoun, ID: 20210755, Group: s3,s4
// Teaching Assistant: Afaf Abdelmonem, Nessma Mohamed
// Purpose: program that allow to user to encrypt and decrypt a message with 9 different ciphers.

#include <iostream>
#include <list>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

char letters[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N',
                  'O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char letter2[26] = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M',
                    'L', 'K', 'J', 'I', 'H', 'J', 'F', 'E', 'D', 'C', 'B', 'A'};
char letters2D[5][5]={'A','B','C','D','E',
                      'F','G','H','I','K',
                      'L','M','N','O','P',
                      'Q','R','S','T','U',
                      'V','W','X','Y','Z'};
string code[26] = {"aaaaa", "aaaab", "aaaba", "aaabb", "aabaa", "aabab", "aabba",
                   "aabbb", "abaaa", "abaab", "ababa", "ababb", "abbaa", "abbab", "abbba",
                   "abbbb", "baaaa", "baaab", "baaba", "baabb", "babaa", "babab", "babba",
                   "babbb", "bbaaa", "bbaab"};
string morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
                    ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
int lettersValues[26]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,
                       14,15,16,17,18,19,20,21,22,23,24,25};


void cipher0Encryption(int a, int b );
void cipher0Decryption(int c , int b );
void cipher1Encryption(int shiftsNumber);
void cipher1Decryption(int shiftsNumber);
void cipher2Encryption(string plainText);
void cipher2Decryption(string plainText);
void cipher3Encryption(string plainText, string key);
void cipher3Decryption(string text, string key);
void cipher4Encryption(string plainText);
void cipher4Decryption(string text);
void cipher5Encryption();
void cipher5Decryption();
void cipher6Encryption(string key);
void cipher6Decryption(string key);
void cipher7Encryption(string plainText);
void cipher7Decryption(string plainText);
void cipher8Encryption(string message, char key);
void cipher8Decryption(string message, char key);




int main(){
    int nOperation;
    while (true){
        cout << "\nWelcome dear user :)" << "\n";
        cout << "Please chose cipher number from this list" << "\n";
        cout << "1)Affine Cipher" << "\n" << "2)Caesar Cipher" << "\n" << "3)Atbash Cipher"
             << "\n" << "4)Vignere Cipher" << "\n" << "5)Baconian Cipher" << "\n" << "6)Simple Substitution Cipher"
             << "\n" << "7)Polybius Square Cipher" << "\n" << "8)Morse Code"<< "\n" << "9)XOR Cipher" << "\n" << "10) Exit" << "\n";
        cout << "Please enter the number here: " << "\n";
        cin >> nOperation;

        if (nOperation == 1)
        {
            int a, b, c, operation0;
            cout << "Please enter a, b and c according to this equation: (a * c) % 26 = 1: " << "\n";
            cin >> a >> b >> c;

            while ((a * c) % 26 != 1 )
            {
                cout << "Sorry, this values cannot satisfied the equation. " << "\n";
                cout << "Please enter new values here: " << "\n";
                cin >> a >> b >> c;
            }
            cout << "\nWhat you want to do: " << "\n" << "1)Encrypt a message " << "\n" << "2)Decrypt a message " << "\n";
            cin >> operation0;
            if(operation0 == 1)
            {
                cipher0Encryption(a,b);
            }
            else if(operation0 == 2)
            {
                cipher0Decryption(c,b);
            }
            else
            {
                cout << "Please enter valid operation number: " << "\n";
                cin >> operation0;
            }
        }
        else if (nOperation == 2)
        {
            int nShifts, operation1;
            cout << "Please enter the number of shifts you want: " << "\n";
            cin >> nShifts;

            while (nShifts<0)
            {
                nShifts += 26;
            }
            nShifts = (nShifts)%26;

            cout << "\nWhat you want to do: " << "\n" << "1)Encrypt a message " << "\n" << "2)Decrypt a message " << "\n";
            cin >> operation1;
            if(operation1 == 1)
            {
                cipher1Encryption(nShifts);
            }
            else if (operation1==2)
            {
                cipher1Decryption(nShifts);

            }
            else
            {
                cout << "Please enter valid operation number: " << "\n" ;
                cin >> operation1;
            }
        }
        else if (nOperation == 3)
        {
            int operation2;
            string message;
            cout << "\nWhat you want to do: " << "\n" << "1)Encrypt a message " << "\n" << "2)Decrypt a message " << "\n";
            cin >> operation2;
            if(operation2 == 1)
            {
                cout << "Please enter the text you want to encrypt: " << "\n";
                cin.ignore();
                getline(cin, message);
                cipher2Encryption(message);
            }
            else if (operation2==2)
            {
                cout << "Please enter the text you want to decrypt: " << "\n";
                cin.ignore();
                getline(cin, message);
                cipher2Decryption(message);

            }
            else
            {
                cout << "Please enter valid operation number: " << "\n" ;
                cin >> operation2;
            }

        }
        else if (nOperation == 4)
        {
            string plainText, key;
            int operation3;
            cout << "\nWhat you want to do: " << "\n" << "1)Encrypt a message " << "\n" << "2)Decrypt a message " << "\n";
            cin >> operation3;

            cout << "Please enter Keyword: " << "\n";
            cin >> key;
            if (key.length() > 8)
            {
                cout << "Please enter a key less than 8 characters: " << "\n";
                cin >> key;
            }

            if(operation3 == 1)
            {
                cout << "Please enter the text you want to encrypt: " << "\n";
                cin.sync();
                cin.clear();
                getline(cin, plainText);
                if (plainText.length() > 80)
                {
                    cout << "Please enter a text less than 80 characters: " << "\n";
                    cin.sync();
                    cin.clear();
                    getline(cin, plainText);
                }
                cipher3Encryption(plainText,key);
            }
            else if (operation3==2)
            {
                cout << "Please enter the text you want to decrypt: " << "\n";
                cin.sync();
                cin.clear();
                getline(cin, plainText);
                if (plainText.length() > 80)
                {
                    cout << "Please enter a text less than 80 characters: " << "\n";
                    cin.sync();
                    cin.clear();
                    getline(cin, plainText);
                }
                cipher3Decryption(plainText,key);

            }
            else
            {
                cout << "Please enter valid operation number: " << "\n" ;
                cin >> operation3;
            }

        }else if (nOperation == 5)
        {
            int operation4;
            string message;
            cout << "\nWhat you want to do: " << "\n" << "1)Encrypt a message " << "\n" << "2)Decrypt a message " << "\n";
            cin >> operation4;
            if(operation4 == 1)
            {
                cout << "Please enter the text you want to encrypt: " << "\n";
                cin.ignore();
                getline(cin, message);
                cipher4Encryption(message);
            }
            else if (operation4==2)
            {
                cout << "Please enter the text you want to decrypt: " << "\n";
                cin.ignore();
                getline(cin, message);
                cipher4Decryption(message);

            }
            else
            {
                cout << "Please enter valid operation number: " << "\n" ;
                cin >> operation4;
            }

        }else if (nOperation == 6)
        {
            int operation5;
            cout << "\nWhat you want to do: " << "\n" << "1)Encrypt a message " << "\n" << "2)Decrypt a message " << "\n";
            cin >> operation5;
            if(operation5 == 1)
            {
                cipher5Encryption();
            }
            else if (operation5==2)
            {
                cipher5Decryption();

            }
            else
            {
                cout << "Please enter valid operation number: " << "\n" ;
                cin >> operation5;
            }
        }else if (nOperation == 7)
        {
            int operation6;
            string key;
            cout << "\nWhat you want to do: " << "\n" << "1)Encrypt a message " << "\n" << "2)Decrypt a message " << "\n";
            cin >> operation6;
            cout << "Please enter the key of message: " << "\n";
            cin >> key;
            if(operation6 == 1)
            {
                cipher6Encryption(key);
            }
            else if (operation6==2)
            {
                cipher6Decryption(key);

            }
            else
            {
                cout << "Please enter valid operation number: " << "\n" ;
                cin >> operation6;
            }
        }else if (nOperation == 8)
        {
            int operation7;
            string message;
            cout << "\nWhat you want to do: " << "\n" << "1)Encrypt a message " << "\n" << "2)Decrypt a message " << "\n";
            cin >> operation7;
            if(operation7 == 1)
            {
                cout << "Please enter the text you want to encrypt: " << "\n";
                cin.ignore();
                getline(cin, message);
                cipher7Encryption(message);
            }
            else if (operation7==2)
            {
                cout << "Please enter the text you want to decrypt: " << "\n";
                cin.ignore();
                getline(cin, message);
                cipher7Decryption(message);

            }
            else
            {
                cout << "Please enter valid operation number: " << "\n" ;
                cin >> operation7;
            }


        }else if (nOperation == 9)
        {
            int operation8;
            string message;
            char key;
            cout << "\nWhat you want to do: " << "\n" << "1)Encrypt a message " << "\n" << "2)Decrypt a message " << "\n";
            cin >> operation8;
            if(operation8 == 1)
            {
                cout << "Please enter encryption key: " << endl;
                cin >> key;
                cout << "Please enter the text you want to encrypt: " << "\n";
                cin.ignore();
                getline(cin, message);
                cipher8Encryption(message,key);
            }
            else if (operation8==2)
            {
                cout << "Please enter decryption key: " << endl;
                cin >> key;
                cout << "Please enter the text you want to decrypt: " << "\n";
                cin.ignore();
                getline(cin, message);
                cipher8Decryption(message,key);

            }
            else
            {
                cout << "Please enter valid operation number: " << "\n" ;
                cin >> operation8;
            }
        }

        else if (nOperation == 10)
        {
            cout << "Thank you for using this program :) " << "\n";
            break;

        }
        else
        {
            cout << "Please enter valid cipher number:" << "\n";
            cin >> nOperation;
        }
    }

    return 0;
}


void cipher0Encryption(int a, int b ){
    string plainText , encryptedText ;
    int lettersIndex , valuesIndex , x , functionResult ;
    encryptedText = "" ;

    cout << "Please enter the text you want to encrypt: " << "\n";
    // using these function (sync,clear,getline) to get string with spaces in one variable.
    cin.sync() ;
    cin.clear() ;
    getline(cin ,plainText) ;

    for (int i = 0; i < plainText.length() ; ++i) {
        plainText[i] = toupper(plainText[i]) ;
        if (plainText[i]==' '){    // to print the text with its spaces.
            encryptedText = encryptedText + plainText[i] ;
            continue ;
        }
        for (int j = 0; j < 26 ; ++j) {
            if (plainText[i]==letters[j]){   // to get letter index in letters array.
                lettersIndex = j ;
                break;
            }
        }
        x = lettersValues[lettersIndex] ;    // to get letter value from values array.
        functionResult = (((a*x)+b)%26) ;
        valuesIndex = functionResult ;
        for (int j = 0; j < 26 ; ++j) {
            if(valuesIndex==j){
                encryptedText = encryptedText + letters[j] ;
            }
        }

    }
    cout << "Encryption Text: " << encryptedText << "\n" ;
}

void cipher0Decryption(int c , int b ){
    string plainText , decryptedText ;
    int lettersIndex , valuesIndex , y , functionResult ;
    decryptedText = "" ;

    cout << "Please enter the text you want to decrypt: " << "\n";
    cin.sync() ;
    cin.clear() ;
    getline(cin ,plainText) ;

    for (int i = 0; i < plainText.length() ; ++i) {
        plainText[i] = toupper(plainText[i]) ;
        if (plainText[i]==' '){    // to print the text with its spaces.
            decryptedText = decryptedText + plainText[i] ;
            continue ;
        }
        for (int j = 0; j < 26 ; ++j) {
            if (plainText[i]==letters[j]){   // to get letter index in letters array
                lettersIndex = j ;
                break;
            }
        }
        y = lettersValues[lettersIndex] ;   // to get letter value from values array
        functionResult = (((c*(y-b))%26)+26)%26 ;  // this rule used to make sure that result is +ve then get the correct letter
        cout << functionResult ;
        valuesIndex = functionResult ;
        for (int j = 0; j < 26 ; ++j) {
            if(valuesIndex==j){
                decryptedText = decryptedText + letters[j] ;
            }
        }
    }
    cout << "Decryption Text: " << decryptedText << "\n";
}


void cipher1Encryption(int shiftsNumber){
    string  plainText, encryptedText;
    encryptedText = "";
    int letterIndex;
    cout <<"please enter the text you want to encrypt: " << "\n";
    cin >> plainText;
    for (int i=0; i < plainText.length(); i++){
        if(plainText [i]==' '){
            encryptedText = encryptedText + ' ';
            continue;
        }
        for (int j=0; j<26; j++){
            if(toupper(plainText [i])== letters[j]){
                letterIndex = (j + shiftsNumber)%26;
                encryptedText = encryptedText + letters [letterIndex];
            }
        }
    }
    cout <<"Encrypted Text: " << encryptedText <<"\n";
}


void cipher1Decryption(int shiftsNumber){
    string plainText, decryptedText;
    int letterIndex ;
    decryptedText = "";
    cout << "Please enter the text you want to decrypt: " << "\n";
    // using these function (sync,clear,getline) to get string with spaces in one variable.
    cin.sync();
    cin.clear();
    getline(cin, plainText);

    for (int i = 0; i < plainText.length(); ++i) {
        plainText[i] = toupper(plainText[i]);
        if (plainText[i] == ' ') {    // to print the text with its spaces.
            decryptedText = decryptedText + plainText[i];
            continue;
        }
        for (int j = 0; j < 26; ++j) {
            if (plainText[i] == letters[j]) {
                // to get letter index in letters array according to shifts number.
                if(j >= shiftsNumber){
                    letterIndex = j -shiftsNumber ;
                }else {
                    letterIndex = 26 - (shiftsNumber-j) ;
                }
                letterIndex = letterIndex % 26 ;
                decryptedText = decryptedText + letters[letterIndex];
                break;
            }
        }
    }
    cout << "Decryption Text: " << decryptedText << "\n" ;
}


void cipher2Encryption(string plainText)
{
    string encryptedText = "";

    for (int i = 0; i < plainText.length(); i++)
    {
        if (isalpha(plainText[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (toupper(plainText[i]) == letters[j])
                {
                    encryptedText = encryptedText + letter2[j];
                    break;
                }
            }
        }
        else if(plainText[i] == ' ')
        {
            encryptedText += ' ';
        }
        else
        {
            encryptedText = plainText[i] + " ";
        }
    }
    cout <<"Encrypted Text: " << encryptedText <<"\n";
}


void cipher2Decryption(string plainText)
{
    string decryptedText = "";

    for (int i = 0; i < plainText.length(); i++)
    {
        if (isalpha(plainText[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (toupper(plainText[i]) == letter2[j])
                {
                    decryptedText = decryptedText + letters[j];
                    break;
                }
            }
        }
        else if(plainText[i] == ' ')
        {
            decryptedText += ' ';
        }
        else
        {
            decryptedText = plainText[i] + " ";
        }
    }
    cout << "Decryption Text: " << decryptedText << "\n";
}



void cipher3Encryption(string plainText, string key)
{
    string encryptedText = "";
    while (plainText.length() > key.length())
    {
        key += key;
    }
    for (int i = 0; i < plainText.length(); i++)
    {
        if (plainText[i] == ' ')
        {
            encryptedText += ' ';
            continue;
        }
        else if (!isalpha(plainText[i]))
        {
            encryptedText += plainText[i];
            continue;
        }
        int number = (toupper(plainText[i]) + toupper(key[i])) % 26;
        char letter = 65 + number;
        encryptedText += letter;
    }
    cout <<"Encrypted Text: " << encryptedText <<"\n";
}


void cipher3Decryption(string text, string key)
{
    string decryptedText = "";
    while (text.length() > key.length())
    {
        key += key;
    }
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ')
        {
            decryptedText += ' ';
            continue;
        }
        else if (!isalpha(text[i]))
        {
            decryptedText += text[i];
            continue;
        }
        int number = (((text[i] - key[i])%26)+26)%26;
        char letter = 65 + number;
        decryptedText += letter;
    }
    cout << "Decryption Text: " << decryptedText << "\n";
}

void cipher4Encryption(string plainText)
{
    string encryptedText = "";

    for (int i = 0; i < plainText.length(); i++)
    {
        // only encrypting alphabet characters.
        if (isalpha(plainText[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (toupper(plainText[i]) == letters[j])
                {
                    encryptedText = encryptedText + code[j] + " ";
                    break;
                }
            }
        }
        else if(plainText[i] == ' ')
        {
            encryptedText += "";
        }
        else
        {
            encryptedText = plainText[i];
        }
    }
    cout <<"Encrypted Text: " << encryptedText <<"\n";
}

void cipher4Decryption(string text)
{
    string decryptedText = "";

    // looping according to how many 5 characters are beside each other without a space (1 code).
    for (int i = 0; i < (text.length() / 5); i++)
    {
        // do nothing if the index is more than the text length, which indicates an extra loop.
        if (i * 6 > text.length())
        {
            continue;
        }
        // storing every 5-character words in a variable to match it with one of the codes in the code array.
        string word = text.substr(i * 6, 5);
        for (int j = 0; j < 26; j++)
        {
            if (word == code[j])
            {
                decryptedText += letters[j];
            }
        }
    }
    cout << "Decryption Text: " << decryptedText << "\n";
}



void cipher5Encryption(){
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string key, msg, cipherAlphabet, cipherText, decipherText;
    int indexLetter;
    bool isThere = false;
    cipherText.clear();
    cin.ignore();
    cout << "Please enter the text you want to encrypt: " << "\n";
    getline(cin, msg);
    transform(msg.begin(),msg.end(),msg.begin(),::tolower);
    cout << "Please enter Keyword:";
    cin >>key;
    cipherAlphabet = cipherAlphabet + key;
    for(int i = 0; i < alphabet.length(); i++){
        for(int j = 0; j < key.length(); j++) {
            if (key[j] == alphabet[i]) {
                isThere = true;
                break;
            } else {
                isThere = false;
            }
        }
        if(isThere){
            cipherAlphabet = cipherAlphabet;
        } else {
            cipherAlphabet = cipherAlphabet + alphabet[i];
        }
    }
    for(int i = 0; i < msg.length();i++){
        if(msg[i] != ' ') {
            auto it = find(alphabet.begin(), alphabet.end(), msg[i]);
            if(it != alphabet.end()){
                indexLetter = it - alphabet.begin();
            }
            cipherText = cipherText + cipherAlphabet[indexLetter];
        } else {
            cipherText = cipherText + " ";
        }

    }
    cout << "Encrypted Text:  " << cipherText << "\n";
}

void cipher5Decryption(){
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string key, msg, cipherAlphabet, cipherText, decipherText;
    int indexLetter;
    bool isThere = false;
    decipherText.clear();
    cin.ignore();
    cout << "Please enter the text you want to decrypt:";
    getline(cin, msg);
    transform(msg.begin(),msg.end(),msg.begin(),::tolower);
    cout << "Please enter Keyword:";
    cin >> key;
    cipherAlphabet = "";
    cipherAlphabet = cipherAlphabet + key;
    for(int i = 0; i < alphabet.length(); i++){
        for(int j = 0; j < key.length(); j++) {
            if (key[j] == alphabet[i]) {
                isThere = true;
                break;
            } else {
                isThere = false;
            }
        }
        if(isThere){
            cipherAlphabet = cipherAlphabet;
        } else {
            cipherAlphabet = cipherAlphabet + alphabet[i];
        }
    }
    for(int i = 0; i < msg.length();i++){
        if(msg[i] != ' ') {
            auto it = find(cipherAlphabet.begin(), cipherAlphabet.end(), msg[i]);
            if(it != cipherAlphabet.end()){
                indexLetter = it - cipherAlphabet.begin();
            }
            decipherText = decipherText + alphabet[indexLetter];
        } else {
            decipherText = decipherText + " ";
        }

    }
    cout << "Decryption Text: " << decipherText << "\n";
}


void cipher6Encryption(string key){
    string plainText, encryptedText;
    encryptedText = "";
    cout << "Please enter the text you want to encrypt: " << "\n";
    // using these function (sync,clear,getline) to get string with spaces in one variable.
    cin.sync();
    cin.clear();
    getline(cin ,plainText);

    for(char i : plainText) {
        if (i != ' ') {
            if (toupper(i) == 'J'){
                encryptedText = encryptedText + to_string(1) + to_string(3);
                continue;
            }
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    if (toupper(i) == letters2D[j][k]) {
                        encryptedText = encryptedText + to_string(j) + to_string(k);
                        break;
                    }
                }

            }
        } else if(i == ' ') {
            encryptedText = encryptedText + ' ';
        }
    }


    for (int i = 0; i < encryptedText.length(); ++i) {
        if(encryptedText[i]==' '){
            continue;
        }else if (encryptedText[i]=='0'){
            encryptedText[i]=key[0];
        }else if (encryptedText[i]=='1'){
            encryptedText[i]=key[1];
        }else if (encryptedText[i]=='2'){
            encryptedText[i]=key[2];
        }else if (encryptedText[i]=='3'){
            encryptedText[i]=key[3];
        }else if (encryptedText[i]=='4'){
            encryptedText[i]=key[4];
        }
    }
    cout << "Encryption Text: " << encryptedText << "\n";
}

void cipher6Decryption(string key){
    string plainText, decryptedText;
    decryptedText = "";
    cout << "Please enter the text you want to decrypt: " << "\n";
    // using these function (sync,clear,getline) to get string with spaces in one variable.
    cin.sync();
    cin.clear();
    getline(cin ,plainText);

    for (int i = 0; i < plainText.length(); ++i) {
        if(plainText[i]==' '){
            continue;
        }else if (plainText[i]==key[0]){
            plainText[i] = '0';
        }else if (plainText[i]==key[1]){
            plainText[i] = '1';
        }else if (plainText[i]==key[2]){
            plainText[i] = '2';
        }else if (plainText[i]==key[3]){
            plainText[i] = '3';
        }else if (plainText[i]==key[4]){
            plainText[i] = '4';
        }
    }
    for (int i = 0; i < plainText.length(); ++i) {
        if(plainText[i]==' '){
            decryptedText = decryptedText + ' ';
        }
        else{
            int j = toupper(plainText[i])-'0';
            int k = toupper(plainText[i+1])-'0';
            decryptedText = decryptedText + letters2D[j][k];
            i+=1;
        }
    }
    cout << "Decryption Text: " << decryptedText << "\n";
}

void cipher7Encryption(string plainText)
{
    string encryptedText = "";

    for (int i = 0; i < plainText.length(); i++)
    {
        if (isalpha(plainText[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (toupper(plainText[i]) == letters[j])
                {
                    encryptedText = encryptedText + morse[j] + ' ';
                    break;
                }
            }
        }
        else if(plainText[i] == ' ')
        {
            encryptedText += " ";
        }
        else
        {
            encryptedText = plainText[i] + " ";
        }
    }
    cout << "Encryption Text: " << encryptedText << "\n";
}

void cipher7Decryption(string plainText)
{
    string decryptedText = "";
    string word = "";
    int spaces = 0;

    for (int i = 0; i < plainText.length(); i++)
    {
        if ((plainText[i] == '.' || plainText[i] == '-') && (i != plainText.length() - 1))
        {
            word += plainText[i];
        }
        else if ((plainText[i] == ' ') || (plainText[i] == plainText[plainText.length() - 1]))
        {
            if(i == plainText.length() -1){
                word += plainText[i];
            }

            for (int j = 0; j < 26; j++)
            {
                if (word == morse[j])
                {
                    decryptedText += letters[j];
                    word = "";
                    break;
                } else {
                    decryptedText = decryptedText;
                    continue;
                }
            }

            if (plainText[i+1] == ' ')
            {
                decryptedText += " ";
            }
        }
    }
    cout << "Decryption Text: " << decryptedText << "\n";
}


void cipher8Encryption(string message, char key)
{
    string encryptedText = "";
    char letter;
    for (int i = 0; i < message.length(); i++)
    {
        letter = (message[i] ^ key) ;
        encryptedText += letter;
    }
    cout << "Encryption Text: " << encryptedText << endl;
    cout << "Hexa Encryption Text: " ;
    for (auto i: encryptedText)
    {
        cout << setw(2) << hex << int(i) << setfill('0') ;

    }
    cout << endl << endl;
}

void cipher8Decryption(string message, char key)
{
    string asciiText;
    int number;
    cout << "Decryption Text: ";
    for (int i = 0; i < message.length(); i+=2) {
        string fi(1,message[i]);
        string se(1,message[i+1]);
        asciiText = fi + se;
        number = stoi(asciiText, nullptr,16);
        cout << (char)(number^key);
    }
    cout << endl;
}