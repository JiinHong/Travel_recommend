#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_DATA_LENGTH 100

struct TravelDestination {
    char name[MAX_NAME_LENGTH];

    int adventure_rest;
    
    int exciting_quiet;

    int family_friends_lover;

    int budget;

    int history_culture_nature;
    char preference[MAX_DATA_LENGTH];
};

struct TravelDestination destinations[20];
int numDestinations = 0;

struct UserAnswers {
    int adventure;
    int rest;
    
    int exciting;
    int quiet;

    int family;
    int friends;
    int lover;

    int budget;
    
    int history;
    int culture;
    int nature;
    char preference[MAX_DATA_LENGTH];
};

// 누적 데이터 구조체
struct CumulativeData {
    int adventure;
    int rest;
    int exciting;
    int quiet;
    int family;
    int friends;
    int lover;
    int budget;
    int history;
    int culture;
    int nature;
    int usageCount;
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
        sscanf(line, "%[^,],%d,%d,%d,%d,%s",
               destinations[numDestinations].name,
               &destinations[numDestinations].adventure_rest,
               &destinations[numDestinations].exciting_quiet,
               &destinations[numDestinations].family_friends_lover,
               &destinations[numDestinations].budget,
               &destinations[numDestinations].history_culture_nature,
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

    fscanf(file, "adventure,%d\n", &data->adventure);
    fscanf(file, "rest,%d\n", &data->rest);
    fscanf(file, "exciting,%d\n", &data->exciting);
    fscanf(file, "quiet,%d\n", &data->quiet);
    fscanf(file, "family,%d\n", &data->family);
    fscanf(file, "friends,%d\n", &data->friends);
    fscanf(file, "lover,%d\n", &data->lover);
    fscanf(file, "budget,%d\n", &data->budget);
    fscanf(file, "history,%d\n", &data->history);
    fscanf(file, "culture,%d\n", &data->culture);
    fscanf(file, "nature,%d\n", &data->nature);
    fscanf(file, "usageCount,%d\n", &data->usageCount); // 이용자들이 이용한 횟수

    fclose(file);
}

// 누적 데이터를 파일에 저장
void writeCumulativeData(struct CumulativeData *data) {
    FILE *file = fopen("누적데이터.txt", "w");
    if (file == NULL) {
        printf("누적데이터 파일을 열 수 없습니다.\n");
        exit(1);
    }

    fprintf(file, "adventure,%d\n", data->adventure);
    fprintf(file, "rest,%d\n", data->rest);
    fprintf(file, "exciting,%d\n", data->exciting);
    fprintf(file, "quiet,%d\n", data->quiet);
    fprintf(file, "family,%d\n", data->family);
    fprintf(file, "friends,%d\n", data->friends);
    fprintf(file, "lover,%d\n", data->lover);
    fprintf(file, "budget,%d\n", data->budget);
    fprintf(file, "history,%d\n", data->history);
    fprintf(file, "culture,%d\n", data->culture);
    fprintf(file, "nature,%d\n", data->nature);
    fprintf(file, "usageCount,%d\n", data->usageCount);

    fclose(file);
}

// 사용자에게 질문 & 답변 저장
void askQuestions(struct UserAnswers *answers) {
    printf("먼저 이용자의 MBTI는? ");
    scanf("%s", answers->preference);

    printf("너는 모험을 즐기니, 휴식과 휴양을 즐기니? (모험/휴양) ");
    scanf("%s", answers->preference);

    if (strcmp(answers->preference, "모험") == 0) {
        answers->adventure++;
    } else if (strcmp(answers->preference, "휴양") == 0) {
        answers->rest++;
    }

    printf("너는 분주한 걸 좋아하니, 한적한 걸 좋아하니? (분주/한적) ");
    scanf("%s", answers->preference);

    if (strcmp(answers->preference, "분주") == 0) {
        answers->exciting++;
    } else if (strcmp(answers->preference, "한적") == 0) {
        answers->quiet++;
    }

    printf("같이 가는 사람이 누구야? (가족/친구/연인) ");
    scanf("%s", answers->preference);

    if (strcmp(answers->preference, "가족") == 0) {
        answers->family++;
    } else if (strcmp(answers->preference, "친구") == 0) {
        answers->friends++;
    } else if (strcmp(answers->preference, "연인") == 0) {
        answers->lover++;
    }

    printf("여행 경비는 얼마로 잡을거야? ");
    scanf("%d", &answers->budget);

    printf("즐기고 싶은 요소는 뭐야? (역사/문화/자연) ");
    scanf("%s", answers->preference);
}

// 여행지 추천
void recommendDestination(struct UserAnswers *answers, struct CumulativeData *cumulativeData) {
    int highestScore = -1;
    char *recommendedDestination = NULL;

    for (int i = 0; i < numDestinations; i++) {
        int score = 0;
        score += destinations[i].adventure_rest * (answers->adventure + answers->rest);
        score += destinations[i].exciting_quiet * (answers->exciting + answers->quiet);
        score += destinations[i].family_friends_lover * (answers->family + answers->friends + answers->lover);
        if (destinations[i].budget <= answers->budget) {
            score++;
        }
        if (strcmp(destinations[i].preference, answers->preference) == 0) {
            score++;
        }

        if (score > highestScore) {
            highestScore = score;
            recommendedDestination = destinations[i].name;
        }
    }

    printf("\n추천 여행지: %s\n\n", recommendedDestination);
    
printf("\n\n이용자들의 선호도\n\n");

printf("모험 %.1f%% | 휴식 %.1f%%\n\n", 
    ((float)cumulativeData->adventure * 100) / (cumulativeData->usageCount),
    ((float)cumulativeData->rest * 100) / (cumulativeData->usageCount));

printf("분주 %.1f%% | 한적 %.1f%%\n\n", 
    ((float)cumulativeData->exciting * 100) / (cumulativeData->usageCount),
    ((float)cumulativeData->quiet * 100) / (cumulativeData->usageCount));

printf("가족 %.1f%% | 친구 %.1f%% | 연인 %.1f%%\n\n", 
    ((float)cumulativeData->family * 100) / (cumulativeData->usageCount),
    ((float)cumulativeData->friends * 100) / (cumulativeData->usageCount),
    ((float)cumulativeData->lover * 100) / (cumulativeData->usageCount));

    double averageBudget = (double)cumulativeData->budget / cumulativeData->usageCount;
    printf("평균 여행경비: %.2lf\n\n", averageBudget);
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
    cumulativeData.adventure += answers.adventure;
    cumulativeData.rest += answers.rest;
    cumulativeData.exciting += answers.exciting;
    cumulativeData.quiet += answers.quiet;
    cumulativeData.family += answers.family;
    cumulativeData.friends += answers.friends;
    cumulativeData.lover += answers.lover;
    cumulativeData.budget += answers.budget;
    cumulativeData.history += answers.history;
    cumulativeData.culture += answers.culture;
    cumulativeData.nature += answers.nature;
    cumulativeData.usageCount++;
    writeCumulativeData(&cumulativeData);

    recommendDestination(&answers, &cumulativeData);

    return 0;
}
