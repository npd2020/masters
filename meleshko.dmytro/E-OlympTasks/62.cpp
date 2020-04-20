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
    /*
    string str1, str2;
    vector<int> num1, num2, sum, prod;
    cout << "Enter number 1: ";
    cin >> str1;
    cout << "Enter number 2: ";
    cin >> str2;


    for(unsigned i = 0; i < str1.length(); i++)
        num1.push_back(str1[i]-'0');
    for(unsigned i = 0; i < str2.length(); i++)
        num2.push_back(str2[i]-'0');

    sum = sum_of_2(num1, num2);
    prod = prod_of_2(num1, num2);

    cout << "\n=RESULTS=\nSum: ";
    for(unsigned it=0; it<sum.size(); it++)
        cout << sum[it];
    cout << "\nProd:";
    for(unsigned it=0; it<prod.size(); it++)
        cout << prod[it];
    cout << "\n";
    */

    string str;
    //cout << "Enter a number: ";
    cin >> str;
    vector<int> num, temp;
    temp.push_back(1);

    for(unsigned i = 0; i < str.length(); i++)
            num.push_back(str[i]-'0');


    int i_m=1;
    while(temp.size()<num.size() || (temp.size()==num.size() && temp[0]<num[0])){
        i_m++;
        vector<int> v_m;
        int s=i_m;
        while(s!=0){
            v_m.insert(v_m.begin(), s%10);
            s=s/10;
        }
        temp = prod_of_2(temp, v_m);
    }

    // for(unsigned it=0; it<temp.size(); it++)
    //     cout << temp[it];
    // cout << "\n";

    unsigned criteria=0;
    for(unsigned it=0; it<num.size(); it++)
        if(num.size()==temp.size() && num[it]==temp[it])
            criteria++;

    if(num.size()==criteria)
        cout << i_m << "\n";
    else
        cout << "No!";


    /*
    string str;
    cout << "Enter a number:";
    cin >> str;
    vector<int> num, temp, m, iter;
    temp.push_back(1);
    m.push_back(1);
    iter.push_back(1);

    for(unsigned i = 0; i < str.length(); i++)
            num.push_back(str[i]-'0');

    cout <<   "n=";
    for(unsigned it=0; it<num.size(); it++)
    cout << num[it];
    cout << "\n";

    while(m!=num){
        m = sum_of_2(m, iter);
        temp = prod_of_2(temp, m);
        // cout << "iter=";
        // for(unsigned it=0; it<iter.size(); it++)
        // cout << iter[it];
        // cout << "  m=";
        // for(unsigned it=0; it<m.size(); it++)
        // cout << m[it];
        // cout << "  m=";
        // for(unsigned it=0; it<temp.size(); it++)
        // cout << temp[it];
        // cout << "\n";
    }

    for(unsigned it=0; it<temp.size(); it++)
    cout << temp[it];
    cout << "\n";
    */
    cin >> str;

    return 0;
}
