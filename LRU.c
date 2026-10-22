#include <stdio.h>
int main(){
    freopen("in.txt","r" , stdin);
    freopen("out.txt","w" , stdout);
    int capacity , num_of_pages;
    printf("Enter Resident Set Capacity : ");
    scanf("%d",&capacity);
    
    printf("Enter number of pages : ");
    scanf("%d",&num_of_pages);

    int refrence[num_of_pages];
    int pages[capacity];
    int last_usage[capacity];

    int  page_fault = 0 , page_hit = 0 ;

    for(int i= 0 ; i< capacity ; i++){
        pages[i]  = -1;
        last_usage[i] = -1;
    }

    printf("Enter the refrences \n");
    for(int i = 0 ;i<num_of_pages ; i++ ){
        scanf("%d" , &refrence[i]);
    }
    for (int i =0 ;i< num_of_pages ; i++){
        int p = refrence[i];
        int found= -1;

        for (int j = 0 ; j <capacity ; j++){
            if(p == pages[j]){
                found = j ;
                break;
            }
        }
        if(found != -1){
            page_hit++;
            last_usage[found] = i;
        }
        else{
            page_fault++;
            int vic = 0;    
            for(int j=0 ; j<capacity ; j++){
                if(pages[j] == -1){
                    vic = j ;
                    break;
                }
                if(last_usage[j] < last_usage[vic] ){
                    vic = j;
                }
            }
            pages[vic] = p ;
            last_usage[vic] = i;
        }
    
    }
printf("\nPage faults = %d\n", page_fault);
printf("Page hits   = %d\n", page_hit);

    return 0;
}