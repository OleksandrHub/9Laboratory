#include <stdio.h>
#include <math.h>
const float a = 0.98, c = 1.1;
const int n = 4 , m = 4;

float value_x(int i, float b[n][m]){
    float app_1 = 1, app_2 = 1;
    for (int j = 0; j < m; j++){
        app_1 *= b[i][j] + c;
        app_2 *= pow(b[i][j],2) + a;
    }
    return app_1/app_2;
}

float value_F(float b[n][m]){
    float sum_x, app_x = 1, xi;
    for (int i = 0; i < n; i++){
        xi = value_x(i, b);
        sum_x += xi;
        app_x *= xi;
    }
    return a*sum_x - 1/sqrt(app_x);
}

int main()
{
    float F;
    float b[n][m] = {
    {2.6, 3.7, 2.1, 2.7},
    {3.6, 2.6, 1.7, 1.5},
    {1.4, 4.3, 3.8, 1.4},
    {1.3, 2.8, 2.4, 2.7}
};
/*    float b[n][m];
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("b[%i][%i] = ",i,j);
            scanf("%f",&b[i][j]);
        }
    }*/
    F = value_F(b);
    printf("F = %f", F);
    return 0;
}
