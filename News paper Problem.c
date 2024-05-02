#include<stdio.h>

int main()
{
    char typesOfNewsDay;
    int randomTypesOfNewsday[20],randomDemand[20],noOfNewspaper,demand[20],n,i,j,k,check[1];
    float salvageScrap[20],revenueFromSales[20],process[4],costOfNewspaper[20],
    lostProfitExcessDemand[20],dailyProfit[20],max[1],total[1];


    for(i=0;i<4;i++){

        printf("Number of Newspaper : ");
        scanf("%d",&noOfNewspaper);
        printf("Number of day to simulate : ");
        scanf("%d",&n);
        printf("__________________________________________________________________________________________________________\n");
        printf("!     !  Random Digits  !  Type  !   Random   !        !  Revenue  !  Lost profit !  Salvage  !          !\n");
        printf("! Day !       for       !   of   ! digits for ! Demand !    from   !  from excess ! from sale !   Daily  !\n");
        printf("!     ! Types of Newsday! Newsday!   Demand   !        !    sales  !     Demand   !  of slope !   profit !\n");
        printf("__________________________________________________________________________________________________________\n");

        total[0]=0;

        for(j=0;j<n;j++)
        {
            randomTypesOfNewsday[j]=rand()%100+1;

            if(randomTypesOfNewsday[j]<=35)
                typesOfNewsDay='g';
            else if(randomTypesOfNewsday[j]<=80)
                typesOfNewsDay='f';
            else if(randomTypesOfNewsday[j]<=100)
                typesOfNewsDay='p';

            randomDemand[j]=rand()%100+1;

            if(typesOfNewsDay=='g'){
                if(randomDemand[j]<=3)
                    demand[j]=40;
                else if(randomDemand[j]<=8)
                    demand[j]=50;
                else if(randomDemand[j]<=23)
                    demand[j]=60;
                else if(randomDemand[j]<=43)
                    demand[j]=70;
                else if(randomDemand[j]<=78)
                    demand[j]=80;
                else if(randomDemand[j]<=93)
                    demand[j]=90;
                else if(randomDemand[j]<=100)
                    demand[j]=100;
            }
            else if(typesOfNewsDay=='f'){
                if(randomDemand[j]<=10)
                    demand[j]=40;
                else if(randomDemand[j]<=28)
                    demand[j]=50;
                else if(randomDemand[j]<=68)
                    demand[j]=60;
                else if(randomDemand[j]<=88)
                    demand[j]=70;
                else if(randomDemand[j]<=96)
                    demand[j]=80;
                else if(randomDemand[j]<=100)
                    demand[j]=100;
            }
            else if(typesOfNewsDay=='p'){
                if(randomDemand[j]<=44)
                    demand[j]=40;
                else if(randomDemand[j]<=66)
                    demand[j]=50;
                else if(randomDemand[j]<=82)
                    demand[j]=60;
                else if(randomDemand[j]<=94)
                    demand[j]=70;
                else if(randomDemand[j]<=100)
                    demand[j]=80;
            }

            if(demand[j]>=noOfNewspaper){
                revenueFromSales[j]=noOfNewspaper*0.5;
            }
            else{
                revenueFromSales[j]=demand[j]*0.5;
            }

            costOfNewspaper[j]=noOfNewspaper*0.33;

            if(demand[j]>noOfNewspaper){
                lostProfitExcessDemand[j]=(demand[j]-noOfNewspaper)*0.17;
            }
            else{
                lostProfitExcessDemand[j]=0;
            }

            if(demand[j]<noOfNewspaper){
                salvageScrap[j]=(noOfNewspaper-demand[j])*0.05;
            }
            else{
                salvageScrap[j]=0;
            }

            dailyProfit[j]=(revenueFromSales[j]+salvageScrap[j])-(costOfNewspaper[j]+lostProfitExcessDemand[j]);
            total[0]=total[0]+dailyProfit[j];

            if(typesOfNewsDay=='g')
                printf("! %d  !        %d       !  Good  !     %d     !    %d  !     %.2f  !     %.2f     !    %.2f   !    %.2f  !\n",j+1,randomTypesOfNewsday[j],randomDemand[j],demand[j],revenueFromSales[j],lostProfitExcessDemand[j],salvageScrap[j],dailyProfit[j]);
            else if(typesOfNewsDay=='f')
                printf("! %d  !        %d       !  Fair  !     %d     !    %d  !     %.2f  !     %.2f     !    %.2f   !    %.2f  !\n",j+1,randomTypesOfNewsday[j],randomDemand[j],demand[j],revenueFromSales[j],lostProfitExcessDemand[j],salvageScrap[j],dailyProfit[j]);
            else if(typesOfNewsDay=='p')
                printf("! %d  !        %d       !  Poor  !     %d     !    %d  !     %.2f  !     %.2f     !    %.2f   !    %.2f  !\n",j+1,randomTypesOfNewsday[j],randomDemand[j],demand[j],revenueFromSales[j],lostProfitExcessDemand[j],salvageScrap[j],dailyProfit[j]);
        }

            process[i]=total[0]/n;
            printf("\nThe Average Daily Profit %.2f\n",process[i]);

            if(i==0){
                max[0]=process[0];
                check[0]=noOfNewspaper;
            }
            else if(i<4){
                if(max[0]<process[i]){
                    max[0]=process[i];
                    check[0]=noOfNewspaper;
                }
            }
    }
    printf("\n\n");
    printf("Better result for %d newspaper \n\n",check[0]);

    return 0;
}
