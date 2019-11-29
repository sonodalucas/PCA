#include <stdio.h>
#include <strings.h>
#include <ctype.h>
#include <stdlib.h>

struct applicant{
    char name[80], placing[80];
    float prog, eng, essay, softSkill, final, average;
    int pos;
}
typedef applicant, applicant;


float finalScore(float prog, float eng, float essay, float softSkill){
    float score;
    score = (prog + eng + essay + softSkill) / 4;
    return score;
}

applicant scanApplicant(){
    applicant new;
    getchar();
    scanf(" %s", &new.name);
    scanf("%f %f %f %f", &new.prog, &new.eng, &new.essay, &new.softSkill);
    new.average = finalScore(new.prog, new.eng, new.essay, new.softSkill);
    return new;
}


void sortNames(applicant* array, int size){
    
    // Ordenação utilizando insertion sort
    char key[80];
    int j;
    for (int i = 1; i < size; i++){
        j = i - 1;
        strcpy(key, array[i].name);
        while (j >= 0 && strcmp(array[j].name, key) > 0){
            strcpy(array[j+1].name, array[j].name);
         //   array[j+1].average = array[j].average;    
            j--;
        }
        strcpy(array[j+1].name, key);
       // array[j+1].average = array[i].average;
    }
}

void sortScores(applicant* array, int size){
    
    float key;
    int j;
    for (int i = 1; i < size; i++){
        j = i - 1;
        key = array[i].average;
        while (j >= 0 && array[j].average < key){
            array[j+1].average = array[j].average;
         //   strcpy(array[j+1].name, array[j].name);
            j--;
        }
        array[j+1].average = key;
       // strcpy(array[j+1].name, array[i].name);
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

    return 0;
}