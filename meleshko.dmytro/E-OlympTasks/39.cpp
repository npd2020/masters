#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<double> sum_of_2(vector<double>& num1_const, vector<double>& num2_const){
    vector<double> num1=num1_const, num2=num2_const;

    if(num1.size()<num2.size())
        num1.swap(num2);

    vector<double> sum_num;
    int fwd = 0, temp_val;
    for(unsigned it=0; it<num2.size(); it++){
        temp_val=num1[num1.size()-1-it]+num2[num2.size()-1-it]+fwd;
        sum_num.insert(sum_num.begin(), temp_val%10);
        fwd=temp_val/10;
    }

    if(num1.size()==num2.size() && fwd!=0){
         while(fwd!=0){
            sum_num.insert(sum_num.begin(), fwd%10);
            fwd=fwd/10;
        }
    }
    if(num1.size()>num2.size()){
        unsigned it=num2.size();
        while(it<num1.size()){
        temp_val=num1[num1.size()-1-it]+fwd;
        sum_num.insert(sum_num.begin(), temp_val%10);
        fwd=temp_val/10;
        it++;
        }
         while(fwd!=0){
            sum_num.insert(sum_num.begin(), fwd%10);
            fwd=fwd/10;
        }
    }
    return sum_num;
}

vector<double> res_of_2(vector<double>& num1_const, vector<double>& num2_const){
    vector<double> num1=num1_const, num2=num2_const;

    double flag=1;
    if(num1.size()<num2.size()){
        num1.swap(num2);
        flag=-1;
    }
    vector<double> res_num;
    unsigned it;

    int s=0;
    if(num1.size()==num2.size()){
        while(num1[s]==num2[s]){
            s++;
        }
        if(num1[s]<num2[s]){
                num1.swap(num2);
                flag=-1;
            }
        if(num1==num2)
            flag=1;
    }

    for(it=0; it<num2.size(); it++){
        if(num1[num1.size()-it-1]>=num2[num2.size()-it-1]){
        res_num.insert(res_num.begin(), num1[num1.size()-it-1]-num2[num2.size()-it-1]);
        }
        else{
            res_num.insert(res_num.begin(), 10+num1[num1.size()-it-1]-num2[num2.size()-it-1]);
            num1[num1.size()-it-2]--;
        }
    }
        for(unsigned i=it; i<num1.size(); i++){
            if(num1[num1.size()-i-1]>=0)
                res_num.insert(res_num.begin(), num1[num1.size()-i-1]);
            else{
                res_num.insert(res_num.begin(), 10+num1[num1.size()-i-1]);
                 num1[num1.size()-i-2]--;
            }
     }

     while(res_num[0]==0 && res_num.size()>1)
        res_num.erase(res_num.begin());

    res_num[0]*=flag;
    return res_num;
}

vector<double> prod_of_2(vector<double>& num1_const, vector<double>& num2_const){
    vector<double> num1=num1_const, num2=num2_const;

    if(num1.size()<num2.size())
        num1.swap(num2);

    vector<double> prod_num;
    int fwd = 0, temp_val;http://cpp.sh/#
    vector<double> temp;
    for(unsigned i=0; i<num2.size(); i++){
        for(unsigned j=0; j<num1.size(); j++){
            temp_val=num1[num1.size()-1-j]*num2[num2.size()-1-i]+fwd;
            temp.insert(temp.begin(), temp_val%10);
            fwd=temp_val/10;
        }
        while(fwd!=0){
            temp.insert(temp.begin(), fwd%10);
            fwd=fwd/10;
        }
        unsigned s = 0;
        while(s<i){
            temp.push_back(0);
            s++;
        }
        prod_num=sum_of_2(temp, prod_num);
        temp.clear();
    }

    return prod_num;
}

int main(){

    string str;
    vector<double> S, v_N, B;

    int i=0;
    cin >> str;
    while(i<str.length()){
        S.push_back(str[i]-'0');
        i++;
    }
    i=0;

    cin >> str;
    while(i<str.length()){
        v_N.push_back(str[i]-'0');
        i++;
    }

    i=0;
    cin >> str;
    while(i<str.length()){
        B.push_back(str[i]-'0');
        i++;
    }


    int i_N=0;
    for(unsigned it=0; it<v_N.size();it++){
      i_N+=(v_N[v_N.size()-1-it]*pow(10, it));
    }

    vector<vector<double>> price;
    vector<double> more;
    price.push_back(S);
    price.push_back(S);
    more.push_back(1);
    for(int it=2; it<i_N-1; it++){
        vector<double> temp;
        temp=sum_of_2(price[0], price[1]);
        temp=sum_of_2(temp, more);
        price.insert(price.begin(), temp);
        price.erase(price.end());
    }

    vector<double> rest, need;
    need = sum_of_2(price[0], price[1]);
    need = sum_of_2(need, more);
    rest=res_of_2(B, need);

    if(rest[0]>=0){
        for(unsigned it=0; it<rest.size(); it++)
            cout << rest[it];
        cout << "\n";
    }
    if(rest[0]<0){
        rest[0]*=-1;
        for(unsigned it=0; it<rest.size(); it++)
            cout << rest[it];
        cout << "\n";
    }

    return 0;
}
