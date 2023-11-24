# (유닉스 프로그래밍을 이용한) 여행지 추천 시스템 프로젝트

## 개요

사용자의 여행 선호도와 과거 누적 데이터를 기반으로 여행지를 추천하는 간단한 여행지 추천 시스템을 구현해보았습니다.

## 사용되는 데이터 파일

- **destination_data.txt**: 여행지 정보가 저장된 파일로, 각 여행지의 이름, 모험/휴양, 분주/한적, 가족/친구/연인 여부, 예산, 역사/문화/자연 선호도, 그리고 이용자들의 선호도가 포함되어 있습니다.

- **accumulated_data.txt**: 누적 데이터가 저장된 파일로, 이용자들의 여행 선호도 및 여행 경비의 누적 정보가 저장되어 있습니다.

## 프로젝트 실행 방법

프로젝트를 실행하려면 다음 단계를 따르세요:

1. 프로젝트 파일을 컴파일하고, 실행시킵니다.

```bash
gcc -o travel_recommendation main.c
```

```bash
./travel_recommendation
```

3. 사용자의 답변을 기반으로 여행지를 추천합니다.

4. 또한, 누적 데이터(모험, 휴식, 분주, 한적, 가족, 친구, 연인, 여행경비의 평균)가 표시됩니다.

## 데이터 파일 수정 및 확장

새로운 여행지 정보를 추가하려면 **destination_data.txt** 파일을 수정하고, 새로운 누적 데이터를 추가하려면 **accumulated_data.txt** 파일을 수정하면 됩니다.

- **destination_data.txt** 형식: `여행지이름,모험/휴양,분주/한적,가족/친구/연인,예산,역사/문화/자연,사용자선호도`

- **accumulated_data.txt** 형식: `누적데이터이름,데이터값`



## 개선할 점

1. 유닉스 프로그래밍만을 사용하여, read(), write(), open() 등을 활용해야하는 과제였기에 제한된 환경에서 구현했지만, 데이터베이스로 관리하는 것이 나중에 확장하거나 데이터를 분석할 때도 좋을 것입니다.

2. 질문이 조금 부족한 면이 있어서, 꼭 필요한 질문을 다양하게 처리하여서 더 정확한 추천을 해줄 수 있을 것 같습니다.
