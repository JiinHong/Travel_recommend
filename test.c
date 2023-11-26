#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_DATA_LENGTH 100

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
};

struct TravelDestination destinations[20];
int numDestinations = 0;

struct UserAnswers {
    int beach_mountain_forest_river_plain;
    
    int culture_history;

    int nature_city;

    int wildlife;

    int inland_island;

    int children;

    int alone_friends_family_lover;

    int budget_range;

    int adventure_leisure;

    int unfamiliar_familiar;

    char preference[MAX_DATA_LENGTH];
};

// 여행지 데이터 읽기
void readDestinationsFromFile() {
    FILE *file = fopen("destination_data.txt", "r");
    if (file == NULL) {
        printf("여행지 데이터 파일을 열 수 없습니다.\n");
        exit(1);
    }

    char line[MAX_DATA_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
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
               &destinations[numDestinations].budget_range);

        numDestinations++;
    }

    fclose(file);
}

// 사용자에게 질문 & 답변 저장
void askQuestions(struct UserAnswers *answers) {
    printf("가고 싶은 여행을 골라보세요!\n");
    printf("0.해변 1.산악 2.숲 3.강 4.평원: ");
    scanf("%d", &answers->beach_mountain_forest_river_plain);

    printf("문화를 즐기고 싶으신가요? 역사를 즐기고 싶으신가요?\n");
    printf("0.문화 1.역사: ");
    scanf("%d", &answers->culture_history);

    printf("자연을 선호하시나요, 도시를 선호하시나요?\n");
    printf("0.자연 1.도시: ");
    scanf("%d", &answers->nature_city);

    printf("야생동물을 관찰하고 싶으신가요? (0: 없음, 1: 있음): ");
    scanf("%d", &answers->wildlife);

    printf("여행지가 내륙에 있는지 섬에 있는지 선택하세요.\n");
    printf("0: 내륙 1: 섬(0 또는 1 중 선택): ");
    scanf("%d", &answers->inland_island);

    printf("어린이와 함께 가실 예정인가요? (0: 없음, 1: 있음): ");
    scanf("%d", &answers->children);

    printf("혼자 가실건가요, 친구와 함께 가실건가요, 가족과 함께 가실건가요, 아니면 연인과 함께 가실건가요?\n");
    printf("0: 혼자 1: 친구 2: 가족 3: 연인 (0부터 3까지 중 선택): ");
    scanf("%d", &answers->alone_friends_family_lover);

    printf("여행을 가는 인원수를 선택하세요. (0부터 9까지 중 선택): ");
    scanf("%d", &answers->num_travelers);

    printf("모험을 즐기실 건가요, 휴양을 즐기실 건가요? (0: 모험, 1: 휴양): ");
    scanf("%d", &answers->adventure_leisure);

    printf("여행지가 생소한 곳인지 익숙한 곳인지 선택하세요. (0: 생소, 1: 익숙): ");
    scanf("%d", &answers->unfamiliar_familiar);

    printf("여행 경비를 선택하세요. (0부터 9까지 중 선택): ");
    scanf("%d", &answers->budget_range);
}

// 여행지 추천
void recommendDestination(struct UserAnswers *answers) {
    printf("\n가고 싶은 여행지 추천!\n");

    int highestScore = -1;
    char recommendedDestinations[20][MAX_NAME_LENGTH];
    int recommendedCount = 0;

    for (int i = 0; i < numDestinations; i++) {
        int score = 0;
        score += destinations[i].beach_mountain_forest_river_plain == answers->beach_mountain_forest_river_plain ? 1 : 0;
        score += destinations[i].culture_history == answers->culture_history ? 1 : 0;
        score += destinations[i].nature_city == answers->nature_city ? 1 : 0;
        score += destinations[i].wildlife == answers->wildlife ? 1 : 0;
        score += destinations[i].inland_island == answers->inland_island ? 1 : 0;
        score += destinations[i].children == answers->children ? 1 : 0;
        score += destinations[i].alone_friends_family_lover == answers->alone_friends_family_lover ? 1 : 0;
        score += destinations[i].num_travelers == answers->num_travelers ? 1 : 0;
        score += destinations[i].adventure_leisure == answers->adventure_leisure ? 1 : 0;
        score += destinations[i].unfamiliar_familiar == answers->unfamiliar_familiar ? 1 : 0;
        score += destinations[i].budget_range == answers->budget_range ? 1 : 0;

        // 여행 선호도 문자열에 따른 추가 점수
        if (strcmp(destinations[i].preference, answers->preference) == 0) {
            score += 2;
        }

        if (score > highestScore) {
            highestScore = score;
            recommendedCount = 0;
            strcpy(recommendedDestinations[recommendedCount], destinations[i].name);
            recommendedCount++;
        } else if (score == highestScore) {
            strcpy(recommendedDestinations[recommendedCount], destinations[i].name);
            recommendedCount++;
        }
    }

    if (highestScore == 0) {
        printf("죄송합니다. 해당하는 여행지를 찾을 수 없습니다.\n");
    } else {
        printf("가장 적합한 여행지는 다음과 같습니다:\n");
        for (int i = 0; i < recommendedCount; i++) {
            printf("%s\n", recommendedDestinations[i]);
        }
    }
}

int main() {
    struct UserAnswers userAnswers;
    readDestinationsFromFile();
    askQuestions(&userAnswers);
    recommendDestination(&userAnswers);

    return 0;
}
