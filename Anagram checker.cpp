#include<iostream>
#include<string>
using namespace std;

bool areTheyAnagram(string string1,string string2){
    if(string1.length()!=string2.length()){
        return false;
    }
    int counter1[26]={0};
    int counter2[26]={0};  
    for(int i=0;i<string1.length();i++){
        counter1[string1[i]-'a']++;
        counter2[string2[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(counter1[i]!=counter2 [i]){
            return false;
        }   
    }     
    return true;
}
int main(){
    string string1;
    string string2;
    cout << "Enter first string: " << endl;
    cin >> string1;
    cout << "Enter second string: " << endl;
    cin >> string2;
    
    if(areTheyAnagram(string1,string2)){
        cout << "These strings are anagrams of each other." << endl;
    }
    else{
        cout << "These strings are not anagram of each other." << endl;
    }    
    return 0;
}