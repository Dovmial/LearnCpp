
#include <iostream>
#include <cstdlib>
#include <ctype.h>
#include <cstring>
#include <string>

using namespace std;
int main()
{
    //Caesar
    /*int key = 6;
    char s[] = "345 ABC TYUYzzyy ^&4";
    const int size = strlen(s)+1;
    char code[size] ={} ;

    cout<<"Key = "<<key<<endl;


    for(int i = 0; i<size; ++i)
    {
        if(isupper(s[i]))
        {
            code[i] = s[i]+key;
            if('Z'< code[i])
                code[i] -= 26;

        }
        else if(islower(s[i]))
        {
            code[i] = s[i]+key;

            if('z'< code[i])
                code[i] -= 26;
        }

        else
            code[i]=s[i];

    }
    cout<<"Code: "<<code<<endl<<"String: "<<s<<endl;
    cout<<char('z'+12);
*/

    //vigenere

    string key = "ab";
    int sizeKey = key.size();
    const char STring[] = "This... is CS50!";

    string s;
    s.append(STring);
    for(size_t i = 0,Size = s.size(), j=0; i<Size; ++i)
    {
            if(isupper(s.at(i)))
            {
                int k = ((int)key[j%sizeKey]-97);
                s[i]+= k;
                if(s.at(i)>'Z')
                    s[i] -= 26;
                cout<<"s["<<i<<"] = "<<s[i]<<endl;
                ++j;

            }
            else if(islower(s.at(i)))
            {
                int k = (int)key[j%sizeKey]-97;
                s[i] += k;
                if(s.at(i)>'z')
                    s[i] -= 26;
                cout<<"s["<<i<<"] = "<<s[i]<<endl;
                ++j;
            }

    }

    cout<<"String: "<<STring<<endl;
    cout<<"Shiffr: "<<s<<endl;
    cout<<key<<endl<<sizeKey;


}
