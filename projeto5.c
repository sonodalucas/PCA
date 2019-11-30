#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct applicant{
    char name[80], placing[80];
    float prog, eng, essay, softSkill, final, average;
    int pos;
}applicant;


float finalScore(float prog, float eng, float essay, float softSkill){
    float score;
    score = (prog + eng + essay + softSkill) / 4;
    return score;
}

applicant scanApplicant(){
    applicant new;
    getchar();
    scanf(" %s", new.name);
    scanf("%f %f %f %f", &new.prog, &new.eng, &new.essay, &new.softSkill);
    new.average = finalScore(new.prog, new.eng, new.essay, new.softSkill);
    return new;
}


void sortNames(applicant* array, int size){
    
    // Ordenação utilizando insertion sort
    float keyScore;
    char keyName[80], keyPlacing[80];
    int j, keyPos;
    for (int i = 1; i < size; i++){
        j = i - 1;
        keyScore = array[i].average;
        strcpy(keyName, array[i].name);
        strcpy(keyPlacing, array[i].placing);
        keyPos = array[i].pos;
        strcpy(keyName, array[i].name);
        while (j >= 0 && strcmp(array[j].name, keyName) > 0){
            array[j+1].average = array[j].average;
            strcpy(array[j+1].name, array[j].name);
            strcpy(array[j+1].placing, array[j].placing);
            array[j+1].pos = array[j].pos;
            j--;
        }
        array[j+1].average = keyScore;
        strcpy(array[j+1].name, keyName);
        array[j+1].pos = keyPos;
        strcpy(array[j+1].placing, keyPlacing);
    }
}

void sortScores(applicant* array, int size){
    
    float keyScore;
    char keyName[80], keyPlacing[80];
    int j, keyPos;
    for (int i = 1; i < size; i++){
        j = i - 1;
        keyScore = array[i].average;
        strcpy(keyName, array[i].name);
        strcpy(keyPlacing, array[i].placing);
        keyPos = array[i].pos;
        while (j >= 0 && array[j].average < keyScore){
            array[j+1].average = array[j].average;
            strcpy(array[j+1].name, array[j].name);
            strcpy(array[j+1].placing, array[j].placing);
            array[j+1].pos = array[j].pos;
            j--;
        }
        array[j+1].average = keyScore;
        strcpy(array[j+1].name, keyName);
        array[j+1].pos = keyPos;
        strcpy(array[j+1].placing, keyPlacing);
    }
}

void printAll(applicant* array, int size){
    for(int i = 0; i < size; i++){
        printf("%s %.2f %d %s\n", array[i].name, array[i].average, array[i].pos, array[i].placing);
    }
}

int main(){
    int nSpots, nApplicants;
    scanf("%d %d", &nSpots, &nApplicants);

    applicant *applicantList = (applicant*) malloc(nApplicants*sizeof(applicant));
    for(int i = 0; i < nApplicants; i++){
        applicantList[i] = scanApplicant();
    }
    
    sortScores(applicantList, nApplicants);
    for(int i = 0; i < nApplicants; i++){
        if(applicantList[i].average > 7){
            if(i+1 <= nSpots){
                strcpy(applicantList[i].placing, "Aprovado");
                applicantList[i].pos = i+1;
            }else if(applicantList[i].average >= 7){
                strcpy(applicantList[i].placing, "Classificado");
                applicantList[i].pos = i + 1;
            }
        }else{
            strcpy(applicantList[i].placing, "Desclassificado");
            applicantList[i].pos = i + 1;
        }
        
    }
    
    sortNames(applicantList, nApplicants);
    printAll(applicantList, nApplicants);
    free(applicantList);

    return 0;
}