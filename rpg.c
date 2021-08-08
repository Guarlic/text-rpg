#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int xp = 0;
int lv = 0;
int x;
int y;
int z;
int a = 1;
int d;
int h;
char c;
char str[100];

void mon(int x);
void attack(int x);
void damage(int x);
void xpup(int x);
void field(void);

int main(void) {
    printf("=== 게임 시작! ===\n");
    printf("=== 메인 로비 ===\n\n\n");
    
    printf("직업을 선택하세요. 1)기사 2)궁수 3)마법사 4)탱커 ");
    scanf("%d", &y);
    
    while (1) {
        if (a == 1) {
            switch (y) {
                case 1:
                    strcpy(str, "기사");
                    h = 100 + lv / 3;
                    break;
                case 2:
                    strcpy(str, "궁수");
                    h = 50 + lv / 3;
                    break;
                case 3:
                    strcpy(str, "마법사");
                    h = 25 + lv / 3;
                    break;
                case 4:
                    strcpy(str, "탱커");
                    h = 300 + lv / 3;
                    break;
            }
        }
        else {
            if (!strcmp(str, "드래곤나이트") || !strcmp(str, "헌터")) {
                h = 100 + lv / 3;
            }
            else if (!strcmp(str, "아처퀸") || !strcmp(str, "아처킹")) {
                h = 50 + lv / 3;
            }
            else if (!strcmp(str, "대마법사") || !strcmp(str, "힐러")) {
                h = 25 + lv / 3;
            }
        }
        if (lv >= 30 && y != 4 && a != 2) {
            printf("레벨이 30레벨 이상이 되었습니다.\n");
            printf("2차 전직 하시겠습니까?(y/n) ");
            getchar();
            scanf("%c", &c);
            
            if (c == 'y') {
                a = 2;
                
                printf("2차 전직할 직업을 선택하세요. ");
                
                switch (y) {
                    case 1:
                        printf("1)드래곤나이트 2)헌터 ");
                        break;
                    case 2:
                        printf("1)아처퀸 2)아처킹 ");
                        break;
                    case 3:
                        printf("1)대마법사 2)힐러 ");
                        break;
                }
                
                scanf("%d", &y);
                
                if (!strcmp(str, "기사")) {
                    h = 100;
                    
                    if (y == 1) {
                        strcpy(str, "드래곤나이트");
                    }
                    else {
                        strcpy(str, "헌터");
                    }
                }
                else if (!strcmp(str, "궁수")) {
                    h = 50;
                    
                    if (y == 1) {
                        strcpy(str, "아처퀸");
                    }
                    else {
                        strcpy(str, "아처킹");
                    }
                }
                else if (!strcmp(str, "마법사")) {
                    h = 25;
                    
                    if (y == 1) {
                        strcpy(str, "대마법사");
                    }
                    else {
                        strcpy(str, "힐러");
                    }
                }
            }
        }
        
        lv += xp / 100;
        xp = xp % 100;
        
        printf("=== 메인 로비 ===\n\n\n");
        printf("직업: %s\n레벨: %d\n경험치: %d\n", str, lv, xp);
        
        printf("어디로 갑니까? 1)필드 2)마을 ");
        scanf("%d", &z);
        
        switch (z) {
            case 1:
                field();
                break;
            case 2:
                printf("아직 마을이 구현되지 않았습니다.\n");
                break;
        }
        
        if (lv >= 100) {
            printf("축하드립니다!! 100렙이라니, 만렙에 달성하셨군요!\n");
            printf("당신에겐 이 게임을 끝낼 권리를 드리겠습니다!\n\n\n");
            printf("=== 게임 종료! ===\n");
            
            break;
        }
    }
    
    return 0;
}

void mon(int x) {
    switch (x) {
        case 1:
            printf("\n슬라임이 나타났다!\n");
            printf("hp: 50\n");
            d = 50;
            break;
        case 2:
            printf("\n꿀버리가 나타났다!\n");
            printf("hp: 35\n");
            d = 35;
            break;
        case 3:
            printf("\n여왕꿀버리가 나타났다!\n");
            printf("hp: 100\n");
            d = 100;
            break;
        case 4:
            printf("\n드래곤이 나타났다!\n");
            printf("hp: 200\n");
            d = 200;
            break;
    }
}

void attack(int x) {
    printf("%d만큼의 피해를 입혔습니다.\n", x);
    
    d -= x;
}

void damage(int x) {
    printf("%d만큼의 데미지를 입었습니다.\n", x);
    
    h -= x;
}

void xpup(int x) {
    printf("%d만큼의 경험치를 획득했습니다.\n", x);
    
    xp += x;
}

void field(void) {
    srand((unsigned)time(NULL));
    
    x = rand() % 4 + 1;
    mon(x);
    
    while (1) {
        if (d <= 0) {
            printf("몬스터가 사망했습니다.\n");
            
            switch (x) {
                case 1:
                    xpup(20);
                    break;
                case 2:
                    xpup(25);
                    break;
                case 3:
                    xpup(40);
                    break;
                case 4:
                    xpup(100);
                    break;
            }
            if (xp >= 100) {
                printf("레벨업!\n");
            }
            
            break;
        }
        if (h <= 0) {
            printf("플레이어가 사망했습니다.\n");
            
            break;
        }
        
        printf("공격합니까?(y/n)\n");
        getchar();
        scanf("%c", &c);
        
        if (c == 'y') {
            if (a == 1) {
                switch (y) {
                    case 1:
                        attack(20);
                        break;
                    case 2:
                        z = rand() % 2;
                        
                        if (!z) {
                            attack(30);
                        }
                        else {
                            break;
                        }
                        break;
                    case 3:
                        attack(45);
                        break;
                    case 4:
                        attack(35);
                        break;
                }
                
                z = rand() % 2;
                
                if (!z) {
                    switch (x) {
                        case 1:
                            damage(7);
                            break;
                        case 2:
                            damage(12);
                            break;
                        case 3:
                            damage(22);
                            break;
                        case 4:
                            damage(52);
                            break;
                    }
                }
            }
            else {
                if (!strcmp(str, "드래곤나이트")) {
                    switch (x) {
                        case 4:
                            attack(50);
                            break;
                        default:
                            attack(20);
                            break;
                    }
                }
                else if (!strcmp(str, "헌터")) {
                    attack(30);
                }
                else if (!strcmp(str, "아처퀸")) {
                    attack(30);
                }
                else if (!strcmp(str, "아처킹")) {
                    z = rand() % 2;
                    
                    if (!z) {
                        attack(45);
                    }
                }
                else if (!strcmp(str, "대마법사")) {
                    attack(50);
                }
                else {
                    attack(45);
                    
                    printf("힐을 합니까?(y/n) ");
                    getchar();
                    scanf("%c", &c);
                    
                    if (c == 'y') {
                        z = rand() % 26;
                        h += z;
                        
                        printf("%d만큼을 회복했습니다.\n", z);
                    }
                }
            }
        }
        else {
            switch (x) {
                case 1:
                    damage(5);
                    break;
                case 2:
                    damage(10);
                    break;
                case 3:
                    damage(20);
                    break;
                case 4:
                    damage(50);
                    break;
            }
            
            z = rand() % 2;
            
            if (!z) {
                switch (x) {
                    case 1:
                        damage(7);
                        break;
                    case 2:
                        damage(12);
                        break;
                    case 3:
                        damage(22);
                        break;
                    case 4:
                        damage(52);
                        break;
                }
            }
        }
    }
}
