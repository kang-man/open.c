#include <stdio.h>
 
int main(void)
{
    int i,j,loop,rank[10],num[10],kor[10],eng[10],mat[10],total[10];
    double avgkor=0.0, avgeng=0.0, avgmat=0.0;
    double avg[100];
 	char a[6];
   printf("����ó�� ���α׷�");
 
    for(;;) 
    {
        printf("����ó���Ϸ��� �л��� �� ���Դϱ�?");
        scanf("%d",&loop);
        if(0<=loop && loop<=100) break; 
    }
    for(i=0;i<loop;i++){
        printf("%d��° �л��� �й��� �̸���  �Է��ϰ� Enter�� ��������=",i+1);    
        scanf("%d %c",&num[i],&a[i]);
        printf("���� ������ �Է��ϰ� Enter�� ��������=");
        scanf("%d",&kor[i]);
        printf("���� ������ �Է��ϰ� Enter�� ��������=");
        scanf("%d",&eng[i]);
        printf("���� ������ �Է��ϰ� Enter�� ��������=");
        scanf("%d",&mat[i]);
        total[i]=kor[i]+eng[i]+mat[i];
        avg[i]=total[i]/3.0;
        avgkor=avgkor+kor[i];
        avgeng=avgeng+eng[i];
        avgmat=avgmat+mat[i];
    }
 
    printf("�л����� ����Դϴ�.");
	printf("�й�   ����     ���\n");
     
    
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
    printf("���� ���: %g\n���� ���: %g\n���� ���: %g\n",avgkor/loop, avgeng/loop, avgmat/loop);         
    return 0;
}
