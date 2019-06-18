#include <bits/stdc++.h>

using namespace std;
string s , p ;
const int N = 2e5 + 9 ;
int arr[N] ; // The array contains the longest matching prefix
void pre_process(string pat , int M ){
    int j = 0;
    int i = 1 ;
    arr[j] = 0;
    while(i < M) {
        if(pat[i] == pat[j]) {
            j++ ;
            arr[i] = j ;
            i++;
        }
        else{
            if(j!=0){
                j = arr[j -1];
            }
            else{
                arr[i++] = j ;
            }
        }
    }

}
void KMP(string str , string pat){
    int n = str.size() ;
    int m = pat.size() ;
    pre_process(str , n) ;
    for(int i = 0 , k = 0 ; i < n ; ++i){
        while( k > 0 && pat[k]!=str[i]) k = arr[k - 1];

        if(pat[k] == str[i])k++;

        if(k == m ){
            cout << i - m + 1 << "\n" ; // the staring positions of matching strings
            k = arr[k - 1];


        }
    }

}

int main()
{
    KMP("aaaa" , "aa");

    return 0;
}
