# include<stdio.h>
# include<math.h>
# include<stdlib.h>

int janken(int hand, int com_hand);
void show_com_hand(int com_hand);

int main(void){
    int hand;
    char tmp;
    int result;
    int com_hand;
    int win;
    int lose;
    int draw;
    int win_count;
    int main_flag = 0;
    int flag;
    
    // グー:0, チョキ:1, パー:2
    printf("------------------------------\n");
    printf("-------じゃんけんゲーム-------\n");
    
    while(main_flag == 0){
        flag = 0;
        printf("--最初はグー,ジャンケン ほい--\n");
        while(flag == 0){
            tmp = '\0';
            printf("グー:(G), チョキ:(C), パー:(P)\n");
            scanf("%s", &tmp);
            
            // 入力された文字を数字に変換
            if(tmp == 'P' || tmp == 'p'){
                // パー:(P)
                hand = 2;
            }
            else if(tmp == 'G' || tmp == 'g'){
                // グー:(G)
                hand = 0;
            }
            else if(tmp == 'C' || tmp == 'c'){
                // チョキ:(C)
                hand = 1;
            }
            else if(tmp == 'E' || tmp == 'e'){
                // 戦績を表示
                printf("------------------------------\n");
                printf("---------%d勝%d敗%d分---------\n", win, lose, draw);
                return 0;
            }
            else{
                // 想定していない入力
                printf("------------------------------\n");
                printf("------エラー: 終了します------\n");
                return 0;
            }
            
            com_hand = rand() % 3;
            show_com_hand(com_hand);
            result = janken(hand, com_hand);
            
            // 戦績を保存する
            if(result == 0){
                lose++;
                win_count = 0;
                flag++;
            }
            else if(result == 1){
                draw++;
            }
            else if(result == 2){
                win++;
                win_count++;
                flag++;
            }
            if(win_count == 3){
                main_flag++;
                printf("------------------------------\n");
                printf("--------3連勝しました!--------\n");
                printf("---------おめでとう!----------\n");
                // 戦績を表示
                printf("---------%d勝%d敗%d分---------\n", win, lose, draw);
                return 0;
            }
        }
    }
    return 0;
}

void show_com_hand(int com_hand){
    if(com_hand == 0){
        printf("コンピュータ:グー\n");
    }
    else if(com_hand == 1){
        printf("コンピュータ:チョキ\n");
    }
    else if(com_hand == 2){
        printf("コンピュータ:パー\n");
    }
}

int janken(int hand, int com_hand){
    // ジャンケンの判定を行う
    // result 0:負け, 1:あいこ, 2:勝ち
    int result;
    if(hand == com_hand){
        // あいこ
        printf("あいこ\n");
        result = 1;
    }
    else if(hand == 0 && com_hand == 1){
        // グーで勝利
        printf("あなたの勝ち!\n");
        result = 2;
    }
    else if(hand == 0 && com_hand == 2){
        // グーで敗北
        printf("あなたの負け!\n");
        result = 0;
    }
    else if(hand == 1 && com_hand == 2){
        // チョキで勝利
        printf("あなたの勝ち!\n");
        result = 2;
    }
    else if(hand == 1 && com_hand == 0){
        // チョキで敗北
        printf("あなたの負け!\n");
        result = 0;
    }
    else if(hand == 2 && com_hand == 0){
        // パーで勝利
        printf("あなたの勝ち!\n");
        result = 2;
    }
    else if(hand == 2 && com_hand == 1){
        printf("あなたの負け!\n");
        result = 0;
    }

    return result;
}


