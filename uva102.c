#include<stdio.h>
#include<string.h>


/// strcmp 會逐一比對兩字串的大小，如果第一個字串順序有比較小的情況救回傳-1 一樣0 較大 1
int main(){

    char combination[6][4] = {"BGC", "BCG", "GBC", "GCB", "CBG", "CGB"};
    int result[6];
    int box[3][3];
    while (scanf("%d %d %d %d %d %d %d %d %d",
                &box[0][0], &box[0][1], &box[0][2],
                &box[1][0], &box[1][1], &box[1][2],
                &box[2][0], &box[2][1], &box[2][2]) == 9) {
                    
        int total = 0;
        int j, k;
        for(j=0;j<9;j++){
            total += box[j/3][j%3];
        }

        result[0] = total - box[0][0] - box[1][1] - box[2][2];
        result[1] = total - box[0][0] - box[1][2] - box[2][1];
        result[2] = total - box[0][1] - box[1][0] - box[2][2];
        result[3] = total - box[0][1] - box[1][2] - box[2][0];
        result[4] = total - box[0][2] - box[1][0] - box[2][1];
        result[5] = total - box[0][2] - box[1][1] - box[2][0];

        int ans = result[0];
        int combination_idx = 0;
        for(k=1;k<6;k++){
            if(result[k]==ans){
                if(strcmp(combination[k], combination[combination_idx])<0){
                    combination_idx = k;
                }
            }
            if(result[k]<ans){
                ans = result[k];
                combination_idx = k;
            }
        }

        printf("%s %d\n", combination[combination_idx], ans);
    }
    return 0;
}
