#include <stdio.h>
 
int main(void)
{
    int i,j,loop,rank[10],num[10],kor[10],eng[10],mat[10],total[10];
    double avgkor=0.0, avgeng=0.0, avgmat=0.0;
    double avg[100];
 	char a[6];
   printf("성적처리 프로그램");
 
    for(;;) 
    {
        printf("성적처리하려는 학생이 몇 명입니까?");
        scanf("%d",&loop);
        if(0<=loop && loop<=100) break; 
    }
    for(i=0;i<loop;i++){
        printf("%d번째 학생의 학번과 이름을  입력하고 Enter를 누르세요=",i+1);    
        scanf("%d %c",&num[i],&a[i]);
        printf("국어 점수를 입력하고 Enter를 누르세요=");
        scanf("%d",&kor[i]);
        printf("영어 점수를 입력하고 Enter를 누르세요=");
        scanf("%d",&eng[i]);
        printf("수학 점수를 입력하고 Enter를 누르세요=");
        scanf("%d",&mat[i]);
        total[i]=kor[i]+eng[i]+mat[i];
        avg[i]=total[i]/3.0;
        avgkor=avgkor+kor[i];
        avgeng=avgeng+eng[i];
        avgmat=avgmat+mat[i];
    }
 
    printf("학생들의 등수입니다.");
	printf("학번   총점     평균\n");
     
    
    for(i=0;i<loop;i++){
        rank[i] = 1;
        for(j = 0;j<loop;j++){
            if(total[i] < total[j])
            {
                rank[i] = rank[i] + 1;
            }
        }
    }
 
    int temp = 0;
    for(i=0;i<loop-1;i++){
        for(j=i+1;j<loop;j++){
            if(rank[i] > rank[j]){
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
 
                temp = total[i];
                total[i] = total[j];
                total[j] = temp;
 
                temp = avg[i];
                avg[i] = avg[j];
                avg[j] = temp;
            }
        }
    }
 
    for(i=0;i<loop;i++){
         printf("%3d %5c %6d    %7.2f\n",num[i],a[i],total[i],avg[i]);
    }
    printf("국어 평균: %g\n영어 평균: %g\n수학 평균: %g\n",avgkor/loop, avgeng/loop, avgmat/loop);         
    return 0;
}
