/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and 
removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric 
characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.
*/

#include <bits/stdc++.h>
using namespace std;

bool isAlphanumeric(char character);
bool isPalindrome(string s, int size);
int main(){
    string s = "aa";
    bool result;
    int size = s.length();
    // char a;
    // a = tolower('(');
    // cout<<a;
    result = isPalindrome(s,size);
    cout<<"result: "<<result;

}

bool isPalindrome(string s, int size){
    int i, left_pointer = 0, right_pointer = size - 1;
    bool is_left_char_alphanumeric, is_right_char_alphanumeric, found_non_alpha_neumeric = false;
    
    while(left_pointer <= right_pointer){
        is_left_char_alphanumeric = isAlphanumeric(s[left_pointer]);
        is_right_char_alphanumeric = isAlphanumeric(s[right_pointer]);
        // cout<<"isLApn: "<<is_left_char_alphanumeric<<" char: "<<s[left_pointer]<<endl;
        // cout<<"isRApn: "<<is_right_char_alphanumeric<<" char: "<<s[right_pointer]<<endl;

        if(!is_left_char_alphanumeric) {
            found_non_alpha_neumeric = true;
            left_pointer++;
        }
        if(!is_right_char_alphanumeric) {
            found_non_alpha_neumeric = true;
            right_pointer--;
        }
        if(found_non_alpha_neumeric) {

            found_non_alpha_neumeric = false;
            continue;
        }
        else{
            char left_char = tolower( s[left_pointer] ),right_char = tolower( s[right_pointer] );
            // cout<<"left pointer: "<<left_pointer<<" right pointer: "<<right_pointer<<endl;
            // cout<<"leftchar: "<<left_char<<" right_char: "<<right_char<<endl;

            if(left_char == right_char){
            // cout<<"leftchar: "<<left_char<<" right_char: "<<right_char<<endl;
                left_pointer++;
                right_pointer--;
            }
            else break;
        }

    }
    // cout<<"left: "<<left_pointer<<"right: "<<right_pointer<<endl;
    // if(l)
    if(left_pointer > right_pointer) return true;
    else return false;
}

bool isAlphanumeric(char character){
    if( (character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z') || (character >= '0' && character <= '9')  ){
        return true;
    }
    else return false;
}

