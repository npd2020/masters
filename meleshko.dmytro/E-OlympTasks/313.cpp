#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> sum_of_2(vector<int>& num1, vector<int>& num2){
    if(num1.size()<num2.size())
        num1.swap(num2);

    vector<int> sum_num;
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

vector<int> prod_of_2(vector<int>& num1, vector<int>& num2){
    if(num1.size()<num2.size())
        num1.swap(num2);

    vector<int> prod_num;
    int fwd = 0, temp_val;
    vector<int> temp;
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

int main()
{
    // string str;
    // vector<int> A,B,result;
    // int i=0;
    // cin >> str;

    // while(str[i]!='+'){
    //     A.push_back(str[i]-'0');
    //     i++;
    // }
    // i++;

    // while(i<str.length()){
    //     B.push_back(str[i]-'0');
    //     i++;
    // }
    // result=sum_of_2(A, B);

    // for(unsigned i=0; i<B.size(); i++)
    //     cout << B[i];
    // cout << "\n";


    string str;
    int N;
    vector<vector<int>> result;
    cin >> N;
    for(int it=0; it<N; it++){
        cin >> str;
        int i=0;
        vector<int> A,B,temp;
        while(str[i]!='+'){
            A.push_back(str[i]-'0');
            i++;
        }
        i++;
        while(i<str.length()){
            B.push_back(str[i]-'0');
            i++;
        }
        result.push_back(sum_of_2(A, B));
    }

    for(int it=0; it<N; it++){
        for(unsigned i=0; i<result[it].size(); i++)
            cout << result[it][i];
        cout << "\n";
    }


    return 0;
}
