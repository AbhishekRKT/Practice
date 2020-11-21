#include<bits/stdc++.h>
#include<string>
using namespace std;


void rev(string &s, int point){
    int k = point, j = s.length()-1;
    while(k < j){
        swap(s,k,j);
        k++;
        j--;
    }
}
        void swap(string &s, int j , int k)
        {
            char c = s[j];
            s[j] = s[k];
            s[k] = c;
        }
    int NGE(int num){
        string s = to_string(num);
        int j = s.size()-2;
        while(j>=0 && s[j+1] <= s[j]){
            j--;
        }
        if(j < 0)
        return -1;
        int k = s.length()-1;
        while(k >= 0 && s[k] <= s[j]){
            k--;
        }
        swap(s,j,k);
        rev(s,j+1);
        try{
            int sol = std :: stoi(s);
            return sol;
        }
        catch(exception ex){
            return -1;
        }
    }
int main ()
{
    int num;
    cin >> num;
    cout<<NGE(num) << endl;
}