
/* 71A_way-too-long-words

simplified problem statement:
"words with lengh more than 10 should be replaced by abbreviation
rule of creating abbreviation are,
- first and last letter remains at the same position in a word
- letters in between are replace by its cardinality in decimal number system
"


Input
4
word
localization
internationalization
pneumonoultramicroscopicsilicovolcanoconiosis

Output
word
l10n
i18n
p43s
*/


#include<bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin>>test;
    cout<<endl;
    for(int t=0; t<test; t++) {
        int l;
        string s;
        cin>>s;  // input string
        l=s.length();  // calculate length of string
        if(l<11) {   // check if length is less than 11
            cout<<s<<endl;  // return the string as it is
            continue;
        }
        cout<<s[0]+to_string(l-2)+s[l-1]<<endl; // cast l-2 to string to append with first and last character
    }
    return 0;
}