#include<bits/stdc++.h>
using namespace std;
string reverse(string n){
    int n_size=n.size()-1;
    string result="";
    while(n_size>=0){
        result = result+n[n_size];
        n_size--;
    }
    return result;
}
string addBinary(string a, string b){
    string result=""; int carry=0; int length_a=a.size(); int length_b=b.size();

    while(length_a>0 && length_b>0){
        if((a[length_a-1]-48)==0 && (b[length_b-1]-48)==0){
            result=result+to_string(carry);
            carry=0;
            length_a--;
            length_b--;
        }
        else if(((a[length_a-1]-48)==1 && (b[length_b-1]-48)==0) || ((a[length_a-1]-48)==0 && (b[length_b-1]-48)==1)){
            if(carry==1){
                result=result+to_string(0);
                carry=1;
            }
            else{
                result=result+to_string(1);
                carry = 0;
            }
            length_a--;
            length_b--;
        }
        else{
            result=result+to_string(carry);
            carry = 1;
            length_a--;
            length_b--;
        }
    }
    while(length_a>0){
        if(carry==1){
            if((a[length_a-1]-48)==1){
                result=result+to_string(0);
                carry=1;
            }else{
                result=result+to_string(1);
                carry =0;
            }
        }else
            result=result+to_string((a[length_a-1]-48));
        
        length_a--;
    }
    while(length_b>0){
        if(carry==1){
            if((b[length_b-1]-48)==1){
                result=result+to_string(0);
                carry=1;
            }else{
                result=result+to_string(1);
                carry =0;
            }
        }else
            result=result+to_string((b[length_b-1]-48));
        
        length_b--;
    }
    if(carry==1)
        result=result+to_string(1);
    
    return reverse(result);
}
int main(){
    string num1, num2;
    cin>>num1>>num2;

    cout<<addBinary(num1,num2)<<endl;

    return 0;
}