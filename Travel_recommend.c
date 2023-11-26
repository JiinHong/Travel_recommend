#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_NAME_LENGTH 1000
#define MAX_DATA_LENGTH 1000

struct TravelDestination {
    char name[MAX_NAME_LENGTH];

    int beach_mountain_forest_river_plain;
    
    int culture_history;

    int nature_city;

    int wildlife;

    int inland_island;

    int children;

    int alone_friends_family_lover;

    int num_travelers;

    int adventure_leisure;

    int unfamiliar_familiar;

    int budget_range;

    int preference[MAX_DATA_LENGTH];
};

struct TravelDestination destinations[1000] = {0};
int numDestinations = 0;

struct UserAnswers {
    int beach;
    int mountain;
    int forest;
    int river;
    int plain;

    int culture;
    int history;

    int nature;
    int city;

    int no_wild_animal;
    int wild_animal;

    int inland;
    int island;
    
    int no_children;
    int children;

    int alone;
    int friends;
    int family;
    int lover;

    int budget;

    int unknown_number_of_people_traveling;
    int one;
    int two;
    int three;
    int four;
    int five;
    int six;
    int seven;
    int eight;
    int nine;

    int adventure;
    int relax;

    int unfamiliar;
    int familiar;

    int budget_range0;
    int budget_range1;
    int budget_range2;
    int budget_range3;
    int budget_range4;
    int budget_range5;
    int budget_range6;
    int budget_range7;
    int budget_range8;
    int budget_range9;

    int preference[MAX_DATA_LENGTH];
};

// 누적 데이터 구조체
struct CumulativeData {
   int beach;
    int mountain;
    int forest;
    int river;
    int plain;

    int culture;
    int history;

    int nature;
    int city;

    int no_wild_animal;
    int wild_animal;

    int inland;
    int island;
    
    int no_children;
    int children;

    int alone;
    int friends;
    int family;
    int lover;

    int budget;

    int unknown_number_of_people_traveling;
    int one;
    int two;
    int three;
    int four;
    int five;
    int six;
    int seven;
    int eight;
    int nine;

    int adventure;
    int relax;

    int unfamiliar;
    int familiar;

    int budget_range0;
    int budget_range1;
    int budget_range2;
    int budget_range3;
    int budget_range4;
    int budget_range5;
    int budget_range6;
    int budget_range7;
    int budget_range8;
    int budget_range9;
};

// 여행지 데이터 읽기
void readDestinationsFromFile() {
    FILE *file = fopen("destination_data.txt", "r");
    if (file == NULL) {
        printf("여행지데이터 파일을 열 수 없습니다.\n");
        exit(1);
    }

    char line[MAX_DATA_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
               destinations[numDestinations].name,
                &destinations[numDestinations].beach_mountain_forest_river_plain,
                &destinations[numDestinations].culture_history,
                &destinations[numDestinations].nature_city,
                &destinations[numDestinations].wildlife,
                &destinations[numDestinations].inland_island,
                &destinations[numDestinations].children,
                &destinations[numDestinations].alone_friends_family_lover,
                &destinations[numDestinations].num_travelers,
                &destinations[numDestinations].adventure_leisure,
                &destinations[numDestinations].unfamiliar_familiar,
                &destinations[numDestinations].budget_range,
               destinations[numDestinations].preference);

        numDestinations++;
    }

    fclose(file);
}

// 누적 데이터 읽기
void readCumulativeData(struct CumulativeData *data) {
    FILE *file = fopen("accumulated_data.txt", "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        exit(1);
    }

    fscanf(file, "beach,%d\n", &data->adventure);
    fscanf(file, "mountain,%d\n", &data->mountain);
    fscanf(file, "forest,%d\n", &data->forest);
    fscanf(file, "river,%d\n", &data->river);
    fscanf(file, "plain,%d\n", &data->plain);
    fscanf(file, "culture,%d\n", &data->culture);
    fscanf(file, "history,%d\n", &data->history);
    fscanf(file, "nature,%d\n", &data->nature);
    fscanf(file, "city,%d\n", &data->city);
    fscanf(file, "no_wild_animal,%d\n", &data->no_wild_animal);
    fscanf(file, "wild_animal,%d\n", &data->wild_animal);
    fscanf(file, "inland,%d\n", &data->inland);
    fscanf(file, "island,%d\n", &data->island);
    fscanf(file, "no_children,%d\n", &data->no_children);
    fscanf(file, "children,%d\n", &data->children);
    fscanf(file, "alone,%d\n", &data->alone);
    fscanf(file, "friends,%d\n", &data->friends);
    fscanf(file, "family,%d\n", &data->family);
    fscanf(file, "lover,%d\n", &data->lover);
    fscanf(file, "unknown_number_of_people_traveling,%d\n", &data->unknown_number_of_people_traveling);
    fscanf(file, "one,%d\n", &data->one);
    fscanf(file, "two,%d\n", &data->two);
    fscanf(file, "three,%d\n", &data->three);
    fscanf(file, "four,%d\n", &data->four);
    fscanf(file, "five,%d\n", &data->five);
    fscanf(file, "six,%d\n", &data->six);
    fscanf(file, "seven,%d\n", &data->seven);
    fscanf(file, "eight,%d\n", &data->eight);
    fscanf(file, "nine,%d\n", &data->nine);
    fscanf(file, "adventure,%d\n", &data->adventure);
    fscanf(file, "relax,%d\n", &data->relax);
    fscanf(file, "unfamiliar,%d\n", &data->unfamiliar);
    fscanf(file, "familiar,%d\n", &data->familiar);
    fscanf(file, "budget_range0,%d\n", &data->budget_range0);
    fscanf(file, "budget_range1,%d\n", &data->budget_range1);
    fscanf(file, "budget_range2,%d\n", &data->budget_range2);
    fscanf(file, "budget_range3,%d\n", &data->budget_range3);
    fscanf(file, "budget_range4,%d\n", &data->budget_range4);
    fscanf(file, "budget_range5,%d\n", &data->budget_range5);
    fscanf(file, "budget_range6,%d\n", &data->budget_range6);
    fscanf(file, "budget_range7,%d\n", &data->budget_range7);
    fscanf(file, "budget_range8,%d\n", &data->budget_range8);
    fscanf(file, "budget_range9,%d\n", &data->budget_range9);

    fclose(file);
}

// 누적 데이터를 파일에 저장
void writeCumulativeData(struct CumulativeData *data) {
    FILE *file = fopen("accumulated_data.txt", "w");
    if (file == NULL) {
        printf("누적데이터 파일을 열 수 없습니다.\n");
        exit(1);
    }

    fprintf(file, "beach,%d\n", data->beach);
    fprintf(file, "mountain,%d\n", data->mountain);
    fprintf(file, "forest,%d\n", data->forest);
    fprintf(file, "river,%d\n", data->river);
    fprintf(file, "plain,%d\n", data->plain);
    fprintf(file, "culture,%d\n", data->culture);
    fprintf(file, "history,%d\n", data->history);
    fprintf(file, "nature,%d\n", data->nature);
    fprintf(file, "city,%d\n", data->city);
    fprintf(file, "no_wild_animal,%d\n", data->no_wild_animal);
    fprintf(file, "wild_animal,%d\n", data->wild_animal);
    fprintf(file, "inland,%d\n", data->inland);
    fprintf(file, "island,%d\n", data->island);
    fprintf(file, "no_children,%d\n", data->no_children);
    fprintf(file, "children,%d\n", data->children);
    fprintf(file, "alone,%d\n", data->alone);
    fprintf(file, "friends,%d\n", data->friends);
    fprintf(file, "family,%d\n", data->family);
    fprintf(file, "lover,%d\n", data->lover);
    fprintf(file, "unknown_number_of_people_traveling,%d\n", data->unknown_number_of_people_traveling);
    fprintf(file, "one,%d\n", data->one);
    fprintf(file, "two,%d\n", data->two);
    fprintf(file, "three,%d\n", data->three);
    fprintf(file, "four,%d\n", data->four);
    fprintf(file, "five,%d\n", data->five);
    fprintf(file, "six,%d\n", data->six);
    fprintf(file, "seven,%d\n", data->seven);
    fprintf(file, "eight,%d\n", data->eight);
    fprintf(file, "nine,%d\n", data->nine);
    fprintf(file, "adventure,%d\n", data->adventure);
    fprintf(file, "relax,%d\n", data->relax);
    fprintf(file, "unfamiliar,%d\n", data->unfamiliar);
    fprintf(file, "familiar,%d\n", data->familiar);
    fprintf(file, "budget_range0,%d\n", data->budget_range0);
    fprintf(file, "budget_range1,%d\n", data->budget_range1);
    fprintf(file, "budget_range2,%d\n", data->budget_range2);
    fprintf(file, "budget_range3,%d\n", data->budget_range3);
    fprintf(file, "budget_range4,%d\n", data->budget_range4);
    fprintf(file, "budget_range5,%d\n", data->budget_range5);
    fprintf(file, "budget_range6,%d\n", data->budget_range6);
    fprintf(file, "budget_range7,%d\n", data->budget_range7);
    fprintf(file, "budget_range8,%d\n", data->budget_range8);
    fprintf(file, "budget_range9,%d\n", data->budget_range9);
    
    fclose(file);
}

int answer_beach_mountain_forest_river_plain;
int answer_culture_history;
int answer_nature_city;
int answer_wildlife;
int answer_inland_island;
int answer_children;
int answer_alone_friends_family_lover;
int answer_num_travelers;
int answer_adventure_leisure;
int answer_unfamiliar_familiar;
int answer_budget_range;


// 사용자에게 질문 & 답변 저장
void askQuestions(struct UserAnswers *answers) {


    // 사용자의 답변을 받고, 누적 데이터를 업데이트
    printf("가고 싶은 여행을 골라보세요!\n");
    printf("0.해변 1.산악 2.숲 3.강 4.평원: ");
    scanf("%d", answers->preference);
    if (*(answers->preference)==0) {
        answers->beach++;
    } else if (*(answers->preference)== 1) {
        answers->mountain++;
    } else if (*(answers->preference)== 2) {
        answers->forest++;
    } else if (*(answers->preference)== 3) {
        answers->river++;
    } else if (*(answers->preference)== 4) {
        answers->plain++;
    }
    answer_beach_mountain_forest_river_plain = answers->preference[0];

    printf("문화를 즐기고 싶으신가요? 역사를 즐기고 싶으신가요?\n");
    printf("0.문화 1.역사: ");
    scanf("%d", answers->preference);
    if (*(answers->preference)== 0) {
        answers->culture++;
    } else if (*(answers->preference)== 1) {
        answers->history++;
    }
    answer_culture_history = answers->preference[0];

    printf("자연을 선호하시나요, 도시를 선호하시나요?\n");
    printf("0.자연 1.도시: ");
    scanf("%d", answers->preference);
    if (*(answers->preference)== 0) {
        answers->nature++;
    } else if (*(answers->preference)== 1) {
        answers->city++;
    }
    answer_nature_city = answers->preference[0];

    printf("야생동물을 관찰하고 싶으신가요? (0: 없음, 1: 있음): ");
    scanf("%d", answers->preference);
    if (*(answers->preference)== 0) {
        answers->no_wild_animal++;
    } else if (*(answers->preference)== 1) {
        answers->wild_animal++;
    }
    answer_wildlife = answers->preference[0];

    printf("여행지가 내륙에 있는지 섬에 있는지 선택하세요.\n");
    printf("0: 내륙 1: 섬(0 또는 1 중 선택): ");
    scanf("%d", answers->preference);
    if (*(answers->preference)== 0) {
        answers->inland++;
    } else if (*(answers->preference)== 1) {
        answers->island++;
    }
    answer_inland_island = answers->preference[0];

    printf("어린이와 함께 가실 예정인가요? (0: 없음, 1: 있음): ");
    scanf("%d", answers->preference);
    if (*(answers->preference)== 0) {
        answers->no_children++;
    } else if (*(answers->preference)== 1) {
        answers->children++;
    }
    answer_children = answers->preference[0];

    printf("혼자 가실건가요, 친구와 함께 가실건가요, 가족과 함께 가실건가요, 아니면 연인과 함께 가실건가요?\n");
    printf("0: 혼자 1: 친구 2: 가족 3: 연인 (0부터 3까지 중 선택): ");
    scanf("%d", answers->preference);
    if (*(answers->preference)== 0) {
        answers->alone++;
    } else if (*(answers->preference)== 1) {
        answers->friends++;
    } else if (*(answers->preference)== 2) {
        answers->family++;
    } else if (*(answers->preference)== 3) {
        answers->lover++;
    }
    answer_alone_friends_family_lover = answers->preference[0];

    printf("여행을 가는 인원수를 선택하세요. (0부터 9까지 중 선택): ");
    scanf("%d", answers->preference);
    if (*(answers->preference)== 0) {
        answers->unknown_number_of_people_traveling++;
    } else if (*(answers->preference)== 1) {
        answers->one++;
    } else if (*(answers->preference)==2) {
        answers->two++;
    } else if (*(answers->preference)==3) {
        answers->three++;
    } else if (*(answers->preference)==4) {
        answers->four++;
    } else if (*(answers->preference)==5) {
        answers->five++;
    } else if (*(answers->preference)==6) {
        answers->six++;
    } else if (*(answers->preference)==7) {
        answers->seven++;
    } else if (*(answers->preference)==8) {
        answers->eight++;
    } else if (*(answers->preference)==9) {
        answers->nine++;
    }
    answer_num_travelers = answers->preference[0];

    printf("모험을 즐기실 건가요, 휴양을 즐기실 건가요? (0: 모험, 1: 휴양): ");
    scanf("%d", answers->preference);
    if (*(answers->preference)== 0) {
        answers->adventure++;
    } else if (*(answers->preference)== 1) {
        answers->relax++;
    }
    answer_adventure_leisure = answers->preference[0];

    printf("여행지가 생소한 곳인지 익숙한 곳인지 선택하세요. (0: 생소, 1: 익숙): ");
    scanf("%d", answers->preference);
    if (*(answers->preference)== 0) {
        answers->unfamiliar++;
    } else if (*(answers->preference)==1) {
        answers->familiar++;
    }
    answer_unfamiliar_familiar = *answers->preference;

    printf("여행 경비를 선택하세요. (0부터 9까지 중 선택): ");
    scanf("%d", answers->preference);
    if (*(answers->preference)== 0) {
        answers->budget_range0++;
    } else if (*(answers->preference)== 1) {
        answers->budget_range1++;
    } else if (*(answers->preference)==2) {
        answers->budget_range2++;
    } else if (*(answers->preference)==3) {
        answers->budget_range3++;
    } else if (*(answers->preference)==4) {
        answers->budget_range4++;
    } else if (*(answers->preference)==5) {
        answers->budget_range5++;
    } else if (*(answers->preference)==6) {
        answers->budget_range6++;
    } else if (*(answers->preference)==7) {
        answers->budget_range7++;
    } else if (*(answers->preference)==8) {
        answers->budget_range8++;
    } else if (*(answers->preference)==9) {
        answers->budget_range9++;
    }
    answer_budget_range = *answers->preference;
}

// 여행지 추천
void recommendDestination(struct UserAnswers *answers, struct CumulativeData *cumulativeData) {
    // 점수가 가장 높은 여행지들을 모두 출력
    // answers_[질문] 변수에는 사용자의 답변이 저장되어 있음
    // 그 변수들을 이용하여 가장 높은 점수를 가진 여행지들을 출력
    // 여행지 데이터는 destinations 배열에 저장되어 있음
    int highestScore = -1;
    int score_arr[1000];
    char answer_destinations[1000][20];

        for (int i = 0; i < numDestinations; i++) {
        int score = 0;        
        score += destinations[i].beach_mountain_forest_river_plain == answer_beach_mountain_forest_river_plain ? 1 : 0;
        score += destinations[i].culture_history == answer_culture_history ? 1 : 0;
        score += destinations[i].nature_city == answer_nature_city ? 1 : 0;
        score += destinations[i].wildlife == answer_wildlife ? 1 : 0;
        score += destinations[i].inland_island == answer_inland_island ? 1 : 0;
        score += destinations[i].children == answer_children ? 1 : 0;
        score += destinations[i].alone_friends_family_lover == answer_alone_friends_family_lover ? 1 : 0;
        score += destinations[i].num_travelers == answer_num_travelers ? 1 : 0;
        score += destinations[i].adventure_leisure == answer_adventure_leisure ? 1 : 0;
        score += destinations[i].unfamiliar_familiar == answer_unfamiliar_familiar ? 1 : 0;
        score += destinations[i].budget_range == answer_budget_range ? 1 : 0;
        score_arr[i] = score;

        if (score > highestScore) {
            highestScore = score;
        }
        }

        for (int i = 0; i < numDestinations; i++) {
        if (score_arr[i] == highestScore) {
            strcpy(answer_destinations[i], destinations[i].name);
        }
        else {
            strcpy(answer_destinations[i], "none");
        }
        }
printf("\n추천 여행지: ");
for (int i = 0; i < numDestinations; i++) {
    if (strcmp(answer_destinations[i], "none") != 0) {
        printf("%s ", answer_destinations[i]);
    }
}

printf("\n\n이용자들의 선호도\n\n");

int sum = cumulativeData->beach + cumulativeData->mountain + cumulativeData->forest + cumulativeData->river + cumulativeData->plain;
printf("해변 %.1f%% | 산악 %.1f%% | 숲 %.1f%% | 강 %.1f%% | 평원 %.1f%% \n\n", 
    ((float)cumulativeData->beach * 100) / (sum),
    ((float)cumulativeData->mountain * 100) / (sum),
    ((float)cumulativeData->forest * 100) / (sum),
    ((float)cumulativeData->river * 100) / (sum),
    ((float)cumulativeData->plain * 100) / (sum));

sum = cumulativeData->culture + cumulativeData->history;
printf("문화 %.1f%% | 역사 %.1f%% \n\n", 
    ((float)cumulativeData->culture * 100) / (sum),
    ((float)cumulativeData->history * 100) / (sum));

sum = cumulativeData->nature + cumulativeData->city;
printf("자연 %.1f%% | 도시 %.1f%% \n\n", 
    ((float)cumulativeData->nature * 100) / (sum),
    ((float)cumulativeData->city * 100) / (sum));

sum = cumulativeData->no_wild_animal + cumulativeData->wild_animal;
printf("야생동물x %.1f%% | 야생동물o %.1f%% \n\n", 
    ((float)cumulativeData->no_wild_animal * 100) / (sum),
    ((float)cumulativeData->wild_animal * 100) / (sum));

sum = cumulativeData->inland + cumulativeData->island;
printf("내륙 %.1f%% | 섬 %.1f%% \n\n", 
    ((float)cumulativeData->inland * 100) / (sum),
    ((float)cumulativeData->island * 100) / (sum));

sum = cumulativeData->no_children + cumulativeData->children;
printf("어린이x %.1f%% | 어린이o %.1f%% \n\n", 
    ((float)cumulativeData->no_children * 100) / (sum),
    ((float)cumulativeData->children * 100) / (sum));

sum = cumulativeData->alone + cumulativeData->friends + cumulativeData->family + cumulativeData->lover;
printf("혼자 %.1f%% | 친구 %.1f%% | 가족 %.1f%% | 연인 %.1f%% \n\n", 
    ((float)cumulativeData->alone * 100) / (sum),
    ((float)cumulativeData->friends * 100) / (sum),
    ((float)cumulativeData->family * 100) / (sum),
    ((float)cumulativeData->lover * 100) / (sum));

sum = cumulativeData->unknown_number_of_people_traveling + cumulativeData->one + cumulativeData->two + cumulativeData->three + cumulativeData->four + cumulativeData->five + cumulativeData->six + cumulativeData->seven + cumulativeData->eight + cumulativeData->nine;
printf("인원수 미정 %.1f%% | 1명 %.1f%% | 2명 %.1f%% | 3명 %.1f%% | 4명 %.1f%% | 5명 %.1f%% | 6명 %.1f%% | 7명 %.1f%% | 8명 %.1f%% | 9명 %.1f%% \n\n", 
    ((float)cumulativeData->unknown_number_of_people_traveling * 100) / (sum),
    ((float)cumulativeData->one * 100) / (sum),
    ((float)cumulativeData->two * 100) / (sum),
    ((float)cumulativeData->three * 100) / (sum),
    ((float)cumulativeData->four * 100) / (sum),
    ((float)cumulativeData->five * 100) / (sum),
    ((float)cumulativeData->six * 100) / (sum),
    ((float)cumulativeData->seven * 100) / (sum),
    ((float)cumulativeData->eight * 100) / (sum),
    ((float)cumulativeData->nine * 100) / (sum));

sum = cumulativeData->adventure + cumulativeData->relax;
printf("모험 %.1f%% | 휴양 %.1f%% \n\n", 
    ((float)cumulativeData->adventure * 100) / (sum),
    ((float)cumulativeData->relax * 100) / (sum));

sum = cumulativeData->unfamiliar + cumulativeData->familiar;
printf("생소 %.1f%% | 익숙 %.1f%% \n\n", 
    ((float)cumulativeData->unfamiliar * 100) / (sum),
    ((float)cumulativeData->familiar * 100) / (sum));

sum = cumulativeData->budget_range0 * 125000 + 
          cumulativeData->budget_range1 * 375000 +
          cumulativeData->budget_range2 * 625000 +
          cumulativeData->budget_range3 * 875000 +
          cumulativeData->budget_range4 * 1125000 +
          cumulativeData->budget_range5 * 1375000 + 
          cumulativeData->budget_range6 * 1625000 +
          cumulativeData->budget_range7 * 1875000 +
          cumulativeData->budget_range8 * 2125000 +
          cumulativeData->budget_range9 * 2375000;

int sum1 = cumulativeData->budget_range0 + 
          cumulativeData->budget_range1 +
          cumulativeData->budget_range2 +
          cumulativeData->budget_range3 +
          cumulativeData->budget_range4 +
          cumulativeData->budget_range5 + 
          cumulativeData->budget_range6 +
          cumulativeData->budget_range7 +
          cumulativeData->budget_range8 +
          cumulativeData->budget_range9;

printf("평균 여행경비 %d원\n\n" , sum / sum1);
}

int main() {

    readDestinationsFromFile();
    
    struct CumulativeData cumulativeData;
    memset(&cumulativeData, 0, sizeof(struct CumulativeData));
    readCumulativeData(&cumulativeData);

    struct UserAnswers answers;
    memset(&answers, 0, sizeof(struct UserAnswers));

    askQuestions(&answers);

    // 누적 데이터 업데이트
    cumulativeData.beach += answers.beach;
    cumulativeData.mountain += answers.mountain;
    cumulativeData.forest += answers.forest;
    cumulativeData.river += answers.river;
    cumulativeData.plain += answers.plain;
    cumulativeData.culture += answers.culture;
    cumulativeData.history += answers.history;
    cumulativeData.nature += answers.nature;
    cumulativeData.city += answers.city;
    cumulativeData.no_wild_animal += answers.no_wild_animal;
    cumulativeData.wild_animal += answers.wild_animal;
    cumulativeData.inland += answers.inland;
    cumulativeData.island += answers.island;
    cumulativeData.no_children += answers.no_children;
    cumulativeData.children += answers.children;
    cumulativeData.alone += answers.alone;
    cumulativeData.friends += answers.friends;
    cumulativeData.family += answers.family;
    cumulativeData.lover += answers.lover;
    cumulativeData.unknown_number_of_people_traveling += answers.unknown_number_of_people_traveling;
    cumulativeData.one += answers.one;
    cumulativeData.two += answers.two;
    cumulativeData.three += answers.three;
    cumulativeData.four += answers.four;
    cumulativeData.five += answers.five;
    cumulativeData.six += answers.six;
    cumulativeData.seven += answers.seven;
    cumulativeData.eight += answers.eight;
    cumulativeData.nine += answers.nine;
    cumulativeData.adventure += answers.adventure;
    cumulativeData.relax += answers.relax;
    cumulativeData.unfamiliar += answers.unfamiliar;
    cumulativeData.familiar += answers.familiar;
    cumulativeData.budget_range0 += answers.budget_range0;
    cumulativeData.budget_range1 += answers.budget_range1;
    cumulativeData.budget_range2 += answers.budget_range2;
    cumulativeData.budget_range3 += answers.budget_range3;
    cumulativeData.budget_range4 += answers.budget_range4;
    cumulativeData.budget_range5 += answers.budget_range5;
    cumulativeData.budget_range6 += answers.budget_range6;
    cumulativeData.budget_range7 += answers.budget_range7;
    cumulativeData.budget_range8 += answers.budget_range8;
    cumulativeData.budget_range9 += answers.budget_range9;

    writeCumulativeData(&cumulativeData);

    recommendDestination(&answers, &cumulativeData);

    return 0;
}
