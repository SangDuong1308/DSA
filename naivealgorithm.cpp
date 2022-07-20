#include <iostream>
#include <string>
using namespace std;
/**
 * For each character in the text, check if the pattern matches the text starting from that character
 * 
 * @param pat The pattern we're searching for
 * @param txt The text to be searched.
 */
void search(string pat, string txt){
    int M = pat.size();
    int N = txt.size();
    for (int i = 0; i <= N-M; i++){
        int j;
        for (j = 0 ; j< M ;j++){
            if (txt[i+j] != pat[j]) break;
        }
        if (j==M) {
            cout<<"Pattern found at index: "<<i<<endl;
        }
    }
}
int main()
{
    string pat,txt;
    cin>>txt>>pat;
    search(pat,txt);
}