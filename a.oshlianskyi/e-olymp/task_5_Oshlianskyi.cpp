#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
using namespace std;
#include <bits/stdc++.h> 

void find_dividers(int x, vector<vector<int>> *divd, vector<double> *numb) {
    vector<vector<int>> dividers;
    vector<double> numbers;
    double s = 0.5;
    for (int i = 2; i <= pow(x, s); i++) {
        if (x % i == 0) {
            dividers.push_back({i, x/i});
            numbers.push_back(pow(3,i-1) * pow(2, x/i -1));
        }
    }

    *divd = dividers;
    *numb = numbers;
}




int main() {
    // int D = 100;
    
    int k_in;
    double D_array[2];

    scanf("%d", &k_in);
    D_array[0] = 2*k_in;
    D_array[1] = 2*k_in-1;
    for(int i = 0; i < 2; i++){
    
    int D=D_array[i];
    
    vector <double> N;
    N.push_back(pow(2, D-1));

    vector<vector<int>> A[5]; 
    vector<double> B[5]; 

    double coef = 1;
  
    find_dividers(D, &A[0], &B[0]);
    for (int i = 0; i<A[0].size(); i++)
    {
        coef = 1;
        N.push_back(coef*B[0][i]);
        if (A[0][i][0] <= pow(D, 1./3))
        {
            D = A[0][i][1];
            coef = pow(5, A[0][i][0] - 1);
            find_dividers(D, &A[1], &B[1]);
            for (int j = 0; j<A[1].size(); j++)
            {
                N.push_back(coef*B[1][j]);
                if (A[1][j][0] <= pow(D, 1./3))
                {
                    D = A[1][j][1];
                    coef = pow(7, A[0][i][0] - 1)*pow(5, A[1][j][0] - 1);
                    find_dividers(D, &A[2], &B[2]);
                    for (int k = 0; k<A[2].size(); k++)
                    {
                        N.push_back(coef*B[2][k]);
                        if (A[2][k][0] <= pow(D, 1./3))
                        {
                            D = A[2][k][1];
                            coef = pow(11, A[0][i][0] - 1)*pow(7, A[1][j][0] - 1)*pow(5, A[2][k][0] - 1);
                            find_dividers(D, &A[3], &B[3]);
                            for (int s = 0; s<A[3].size(); s++)
                            {
                                N.push_back(coef*B[3][s]);
                            }
                        }
                    }
                    
                }
            }
            
        }
        
    }
    
    
 


    // for (int i = 0; i<N.size(); i++) cout<<N[i]<<" ";
    D_array[i] = *min_element(N.begin(), N.end());

    }
    long int n = min(D_array[0], D_array[1]);
    printf("%lu", n);

}
