#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct housing{
	char loc1[50];
	char loc2[50];
	int price;
	int room;
	int bath;
	int carParks;
	char type[50];
	int area;
	char furnish[50];
}house[4000], loc;

struct HasilLoc1{
	char str[50];
	int banyak;
}Hloc1[70], large1, small1;
struct HasilLoc2{
	char str[50];
	int banyak;
}Hloc2[5], large2, small2;
struct Hasiltype{
	char str[50];
	int banyak;
}Htype[5], large3, small3;
struct Hasilfurnish{
	char str[50];
	int banyak;
}Hfurnish[5], large4, small4;

struct HasilRoom{
	int str;
	int banyak;
}Hroom[20], large5, small5;
struct HasilBath{
	int str;
	int banyak;
}Hbath[20], large6, small6;
struct HasilCarParks{
	int str;
	int banyak;
}HCarParks[20], large7, small7;

void read_data(int* n);

void readLoc1(struct housing* house, int n);
void readLoc2(struct housing* house, int n);
void readType(struct housing* house, int n);
void readFurnish(struct housing* house, int n);
void readRoom(struct housing* house, int n);
void readBath(struct housing* house, int n);
void readCarParks(struct housing* house, int n);

void price(struct housing* house, int n);
void area(struct housing* house, int n);

void print(int i, struct housing* house);
void find(int n);

void scan(int n);

int main(){
	
	int n, ch;
	read_data(&n);

	do{
		printf("\n*******************");
		printf("\n1. Describe");
		printf("\n2. Search");
		printf("\n0. EXIT");
		
		printf("\nEnter Your Choice : ");
		scanf("%d", &ch);
		getchar();
		puts("");
		
		switch(ch){
			case 1:
				scan(n);
				break;
			case 2:
				find(n);
				break;																								
		}
	}while(ch!=0);
	
return 0;
}

void find(int n){
		
	printf("\n\n\t[DataX in ColumnName]\n");
	printf("Available columns are [loc1, loc2, type, and furnish]\n\n");
	printf("Input the data you want to search: ");
	
	char str1[50];
	char ch[10][50];
	
	scanf("%[^\n]", str1);
	int i, j=0, t, ctr=0;
	
	for(i=0; i<=(strlen(str1)); i++){
    	if(str1[i]==' '|| str1[i]=='\0'){
            ch[ctr][j]='\0';
            ctr++;  
            j=0;    
        }else{
            ch[ctr][j]=str1[i];
          	j++;
        }
	}
	int flag=0;
	if(strcmp(ch[2], "loc1") == 0){
			for(i = 0; i<n; i++){
				for(j=i+1; j<n; j++){
		         	if(strcmp(house[i].loc1, house[j].loc1)>0){
			            loc = house[i];
			            house[i] = house[j];
			            house[j] = loc;
		        	}
		      	}	
			}
			int hit=1;
			for(i = 0; i<n; i++){
		         if(strcmp(house[i].loc1, house[i+1].loc1)!=0){
		            hit++;
		         }
			}
			int beda = 0;
			int count = 1;
			for(i = 0; i<n; i++){
		        if(strcmp(house[i].loc1, house[i+1].loc1)==0){
		            count += 1;
		        }else if(strcmp(house[i].loc1, house[i+1].loc1)!=0){
		        	strcpy(Hloc1[beda].str, house[i].loc1);
		        	Hloc1[beda].banyak = count;
		        	count = 1;
		        	beda++;
				}
			}
			int check = 0;
			char cmp[50];
			for(t=0; t<hit-1; t++){
			    int k;
				flag = 0;
				char temp[50];
				char subTemp[50];
				
				strcpy(temp, Hloc1[t].str);
				strcpy(subTemp, ch[0]);
				
			    int arrLen = strlen(temp);
			    int subLen = strlen(subTemp);
			    for (i = 0; i < arrLen; i++) {
			        j = i;
			        k = 0;
			        while (j < arrLen && k < subLen && temp[j] == subTemp[k]) {
			            j++;
			            k++;
			        }
			        if (k == subLen) {
			            strcpy(cmp, temp);
			            check = 1;
			            break;
			        }
			    }							
			}
			
			for(i = 0; i<n; i++){
				if(check == 1){
					if(strcmp(house[i].loc1, cmp) == 0){
						print(i, house);
						flag=1;
					}
				}
				if(check != 1){
					if(strcmp(house[i].loc1, ch[0]) == 0){
						print(i, house);
						flag=1;
					}
				}
			}
	}else if(strcmp(ch[2], "loc2") == 0){
			for(i = 0; i<n; i++){
				for(j=i+1; j<n; j++){
			         if(strcmp(house[i].loc2, house[j].loc2)>0){
			            loc = house[i];
			            house[i] = house[j];
			            house[j] = loc;
			         }
		      	}
			}
			int hit=1;
			for(i = 0; i<n-1; i++){
		         if(strcmp(house[i].loc2, house[i+1].loc2)!=0){
		            hit++;
		         }
			}
			
			int beda = 0;
			int count = 1;
			for(i = 0; i<n; i++){
		        if(strcmp(house[i].loc2, house[i+1].loc2)==0){
		            count += 1;
		        }else if(strcmp(house[i].loc2, house[i+1].loc2)!=0){
		        	strcpy(Hloc2[beda].str, house[i].loc2);
		        	Hloc2[beda].banyak = count;
		        	count = 1;
		        	beda++;
				}
			}		
			int check = 0;
			char cmp[50];
			for(t=0; t<hit-1; t++){
			    int k;
				flag = 0;
				char temp[50];
				char subTemp[50];
				
				strcpy(temp, Hloc2[t].str);
				strcpy(subTemp, ch[0]);
				
			    int arrLen = strlen(temp);
			    int subLen = strlen(subTemp);
			    for (i = 0; i < arrLen; i++) {
			        j = i;
			        k = 0;
			        while (j < arrLen && k < subLen && temp[j] == subTemp[k]) {
			            j++;
			            k++;
			        }
			        if (k == subLen) {
			            strcpy(cmp, temp);
			            check = 1;
			            break;
			        }
			    }							
			}
			for(i = 0; i<n; i++){
				if(check == 1){
					if(strcmp(house[i].loc2, cmp) == 0){
						print(i, house);
						flag=1;
					}
				}
				if(check != 1){
					if(strcmp(house[i].loc2, ch[0]) == 0){
						print(i, house);
						flag=1;
					}
				}
			}
	}else if(strcmp(ch[2], "type") == 0){
			for(i = 0; i<n; i++){
				for(j=i+1; j<n; j++){
			         if(strcmp(house[i].type, house[j].type)>0){
			            loc = house[i];
			            house[i] = house[j];
			            house[j] = loc;
			         }
		      	}
			}
			int hit=1;
			for(i = 0; i<n-1; i++){
		         if(strcmp(house[i].type, house[i+1].type)!=0){
		            hit++;
		         }
			}
			int beda = 0;
			int count = 1;
			for(i = 0; i<n; i++){
		        if(strcmp(house[i].type, house[i+1].type)==0){
		            count += 1;
		        }else if(strcmp(house[i].type, house[i+1].type)!=0){
		        	strcpy(Htype[beda].str, house[i].type);
		        	Htype[beda].banyak = count;
		        	count = 1;
		        	beda++;
				}
			}
			int check = 0;
			char cmp[50];
			for(t=0; t<hit-1; t++){
			    int k;
				flag = 0;
				char temp[50];
				char subTemp[50];
				
				strcpy(temp, Htype[t].str);
				strcpy(subTemp, ch[0]);
				
			    int arrLen = strlen(temp);
			    int subLen = strlen(subTemp);
			    for (i = 0; i < arrLen; i++) {
			        j = i;
			        k = 0;
			        while (j < arrLen && k < subLen && temp[j] == subTemp[k]) {
			            j++;
			            k++;
			        }
			        if (k == subLen) {
			            strcpy(cmp, temp);
			            check = 1;
			            break;
			        }
			    }							
			}

			for(i = 0; i<n; i++){
				if(check == 1){
					if(strcmp(house[i].type, cmp) == 0){
						print(i, house);
						flag=1;
					}
				}
				if(check != 1){
					if(strcmp(house[i].type, ch[0]) == 0){
						print(i, house);
						flag=1;
					}
				}
			}			
	}else if(strcmp(ch[2], "furnish") == 0){
			for(i = 0; i<n; i++){
				for(j=i+1; j<n; j++){
			        if(strcmp(house[i].furnish, house[j].furnish)>0){
				        loc = house[i];
				        house[i] = house[j];
				        house[j] = loc;
			        }
		      }
			}
			int hit=1;
			for(i = 0; i<n-1; i++){
		         if(strcmp(house[i].furnish, house[i+1].furnish)!=0){
		            hit++;
		         }
			}	
			int beda = 0;
			int count = 1;
			for(i = 0; i<n; i++){
		        if(strcmp(house[i].furnish, house[i+1].furnish)==0){
		            count += 1;
		        }else if(strcmp(house[i].furnish, house[i+1].furnish)!=0){
		        	strcpy(Hfurnish[beda].str, house[i].furnish);
		        	Hfurnish[beda].banyak = count;
		        	count = 1;
		        	beda++;
				}
			}
			int check = 0;
			char cmp[50];
			for(t=0; t<hit-1; t++){
			    int k;
				flag = 0;
				char temp[50];
				char subTemp[50];
				
				strcpy(temp, Hfurnish[t].str);
				strcpy(subTemp, ch[0]);
				
			    int arrLen = strlen(temp);
			    int subLen = strlen(subTemp);
			    for (i = 0; i < arrLen; i++) {
			        j = i;
			        k = 0;
			        while (j < arrLen && k < subLen && temp[j] == subTemp[k]) {
			            j++;
			            k++;
			        }
			        if (k == subLen) {
			            strcpy(cmp, temp);
			            check = 1;
			            break;
			        }
			    }							
			}
			for(i = 0; i<n; i++){
				if(check == 1){
					if(strcmp(house[i].furnish, cmp) == 0){
						print(i, house);
						flag=1;
					}
				}
				if(check != 1){
					if(strcmp(house[i].furnish, ch[0]) == 0){
						print(i, house);
						flag=1;
					}
				}
			}				
	}
	if(flag == 0){
		printf("\n\tData not fount.\n");
	}
	
}

void print(int i, struct housing* house){
	printf("%s\t\t\t\t| %s\t\t| %d | %d | %d | %d | %s | %d | %s\n", 
	           	house[i].loc1,house[i].loc2,house[i].price,
				house[i].room,house[i].bath,house[i].carParks,
				house[i].type,house[i].area,house[i].furnish);
	fflush(stdin);		
}

void scan(int n){
  	char column[50];
	printf("\n[loc1, loc2, price, room, bathrooms, carparks, type, area, or furnish]\n\n");
	printf("Input the column you want to describe: ");
  	scanf("%s", column); getchar();
	  
	int i;
  	for(i = 0; i<strlen(column); i++){
  		column[i] = tolower(column[i]);
	}
  	puts("");

	if(strcmp(column,"loc1") == 0){
		readLoc1(house, n);
	}else if(strcmp(column,"loc2") == 0){
		readLoc2(house, n);
	}else if(strcmp(column,"price") == 0){
		price(house, n);
	}else if(strcmp(column,"room") == 0){
		readRoom(house, n);
	}else if(strcmp(column,"bathrooms") == 0){
		readBath(house, n);
	}else if(strcmp(column,"carparks") == 0){
		readCarParks(house, n);
	}else if(strcmp(column,"type") == 0){
		readType(house, n);
	}else if(strcmp(column,"area") == 0){
		area(house, n);
	}else if(strcmp(column,"furnish") == 0){
		readFurnish(house, n);
	}	
}
void read_data(int* n) {
	
	FILE *fp = fopen("file.csv", "r");
	if(fp == NULL){
		printf("Unable to open the file.\n");
		exit(1);
	}
	
	int i, records=0;
	int read = 0; 

	char buffer[100];
	fgets(buffer, 100, fp);
	do{
		read = fscanf(fp,"%[^,],%[^,],%d,%d,%d,%d,%[^,],%d,%s\n", 
					&house[records].loc1,&house[records].loc2,&house[records].price,
					&house[records].room,&house[records].bath,&house[records].carParks,
					&house[records].type,&house[records].area,&house[records].furnish);
					
		records++;
		
		if(read != 9 && !feof(fp)){
	      printf("File format incorrect.\n");
	      exit(1);
	    }
		
		if(ferror(fp)){
	      printf("Error reading file.\n");
	      exit(1);
	    }
	    
	}while(!feof(fp));
	
	*n = records;
//	for (i = 0; i < records; i++)
//		printf("%s,%s,%d,%d,%d,%d,%s,%d,%s\n", 
//           	house[i].loc1,house[i].loc2,house[i].price,
//			house[i].room,house[i].bath,house[i].carParks,
//			house[i].type,house[i].area,house[i].furnish);
//			
//	printf("\nTotal records : %d\n", records);

	fclose(fp);
}

void readLoc1(struct housing* house, int n){
	
	int i, j=0;
	char temp;
	
	for(i = 0; i<n; i++){
		for(j=i+1; j<n; j++){
         if(strcmp(house[i].loc1, house[j].loc1)>0){
            loc = house[i];
            house[i] = house[j];
            house[j] = loc;
         }
      }
	}
	
	int hit=1;
	for(i = 0; i<n; i++){
         if(strcmp(house[i].loc1, house[i+1].loc1)!=0){
            hit++;
         }
	}
	
	int beda = 0;
	int count = 1;
	for(i = 0; i<n; i++){
        if(strcmp(house[i].loc1, house[i+1].loc1)==0){
            count += 1;
        }else if(strcmp(house[i].loc1, house[i+1].loc1)!=0){
        	strcpy(Hloc1[beda].str, house[i].loc1);
        	Hloc1[beda].banyak = count;
        	count = 1;
        	beda++;
		}
	}
	for(j=0; j<hit-1; j++){
		printf("%s: %d\n", Hloc1[j].str, Hloc1[j].banyak);
	}
	
	large1 = small1 = Hloc1[0];
	for(i = 1; i<hit-1; i++){
      	if(Hloc1[i].banyak>large1.banyak)
    		large1 = Hloc1[i];
      	if(Hloc1[i].banyak<small1.banyak)
			small1 = Hloc1[i];
   }
	printf("Maximum value: %s with frequency: %d\n", large1.str, large1.banyak);
	printf("Minimum value: %s with frequency: %d\n", small1.str, small1.banyak);		
}
void readLoc2(struct housing* house, int n){
	
	int i, j=0;
	char temp;
	
	for(i = 0; i<n; i++){
		for(j=i+1; j<n; j++){
         if(strcmp(house[i].loc2, house[j].loc2)>0){
            loc = house[i];
            house[i] = house[j];
            house[j] = loc;
         }
      }
	}
	
	int hit=1;
	for(i = 0; i<n-1; i++){
         if(strcmp(house[i].loc2, house[i+1].loc2)!=0){
            hit++;
         }
	}
	
	int beda = 0;
	int count = 1;
	for(i = 0; i<n; i++){
        if(strcmp(house[i].loc2, house[i+1].loc2)==0){
            count += 1;
        }else if(strcmp(house[i].loc2, house[i+1].loc2)!=0){
        	strcpy(Hloc2[beda].str, house[i].loc2);
        	Hloc2[beda].banyak = count;
        	count = 1;
        	beda++;
		}
	}
	for(j=0; j<hit; j++){
		printf("%s : %d\n", Hloc2[j].str, Hloc2[j].banyak);
	}
	
	large2 = small2 = Hloc2[0];
	for(i = 1; i<hit-1; i++){
      	if(Hloc2[i].banyak>large2.banyak)
    		large2 = Hloc2[i];
      	if(Hloc2[i].banyak<small2.banyak)
			small2 = Hloc2[i];
   }
	printf("Maximum value: %s with frequency: %d\n", large2.str, large2.banyak);
	printf("Minimum value: %s with frequency: %d\n", small2.str, small2.banyak);
}
void readType(struct housing* house, int n){
	
	int i, j=0;
	char temp;
	
	for(i = 0; i<n; i++){
		for(j=i+1; j<n; j++){
         if(strcmp(house[i].type, house[j].type)>0){
            loc = house[i];
            house[i] = house[j];
            house[j] = loc;
         }
      }
	}
	
	int hit=1;
	for(i = 0; i<n-1; i++){
         if(strcmp(house[i].type, house[i+1].type)!=0){
            hit++;
         }
	}
	
	int beda = 0;
	int count = 1;
	for(i = 0; i<n; i++){
        if(strcmp(house[i].type, house[i+1].type)==0){
            count += 1;
        }else if(strcmp(house[i].type, house[i+1].type)!=0){
        	strcpy(Htype[beda].str, house[i].type);
        	Htype[beda].banyak = count;
        	count = 1;
        	beda++;
		}
	}
	for(j=0; j<hit; j++){
		printf("%s : %d\n", Htype[j].str, Htype[j].banyak);
	}
	
	large3 = small3 = Htype[0];
	for(i = 1; i<hit; i++){
      	if(Htype[i].banyak>large3.banyak)
    		large3 = Htype[i];
      	if(Htype[i].banyak<small3.banyak)
			small3 = Htype[i];
   }
	printf("Maximum value: %s with frequency: %d\n", large3.str, large3.banyak);
	printf("Minimum value: %s with frequency: %d\n", small3.str, small3.banyak);
}
void readFurnish(struct housing* house, int n){
	
	int i, j=0;
	char temp;
	
	for(i = 0; i<n; i++){
		for(j=i+1; j<n; j++){
         if(strcmp(house[i].furnish, house[j].furnish)>0){
            loc = house[i];
            house[i] = house[j];
            house[j] = loc;
         }
      }
	}
	
	int hit=1;
	for(i = 0; i<n-1; i++){
         if(strcmp(house[i].furnish, house[i+1].furnish)!=0){
            hit++;
         }
	}
	
	int beda = 0;
	int count = 1;
	for(i = 0; i<n; i++){
        if(strcmp(house[i].furnish, house[i+1].furnish)==0){
            count += 1;
        }else if(strcmp(house[i].furnish, house[i+1].furnish)!=0){
        	strcpy(Hfurnish[beda].str, house[i].furnish);
        	Hfurnish[beda].banyak = count;
        	count = 1;
        	beda++;
		}
	}
	for(j=0; j<hit; j++){
		printf("%s : %d\n", Hfurnish[j].str, Hfurnish[j].banyak);
	}
	
	large4 = small4 = Hfurnish[0];
	for(i = 1; i<hit; i++){
      	if(Hfurnish[i].banyak>large4.banyak)
    		large4 = Hfurnish[i];
      	if(Hfurnish[i].banyak<small4.banyak)
			small4 = Hfurnish[i];
   }
	printf("Maximum value: %s with frequency: %d\n", large4.str, large4.banyak);
	printf("Minimum value: %s with frequency: %d\n", small4.str, small4.banyak);
}

void readRoom(struct housing* house, int n){
	
	int i, j=0;
	char temp;
	
	for(i = 0; i<n; i++){
		for(j=i+1; j<n; j++){
         if(house[i].room > house[j].room){
            loc = house[i];
            house[i] = house[j];
            house[j] = loc;
         }
      }
	}
	
	int hit=1;
	for(i = 0; i<n; i++){
         if(house[i].room != house[i+1].room){
            hit++;
         }
	}
	
	int beda = 0;
	int count = 1;
	for(i = 0; i<n; i++){
        if(house[i].room == house[i+1].room){
            count += 1;
        }else if(house[i].room != house[i+1].room){
        	Hroom[beda].str = house[i].room;
        	Hroom[beda].banyak = count;
        	count = 1;
        	beda++;
		}
	}
	for(j=0; j<hit-1; j++){
		printf("%d: %d\n", Hroom[j].str, Hroom[j].banyak);
	}
	
	large5 = small5 = Hroom[0];
	for(i = 1; i<hit-1; i++){
      	if(Hroom[i].banyak>large5.banyak)
    		large5 = Hroom[i];
      	if(Hroom[i].banyak<small5.banyak)
			small5 = Hroom[i];
   }
	printf("Maximum value: %d with frequency: %d\n", large5.str, large5.banyak);
	printf("Minimum value: %d with frequency: %d\n", small5.str, small5.banyak);		
}
void readBath(struct housing* house, int n){
	
	int i, j=0;
	char temp;
	
	for(i = 0; i<n; i++){
		for(j=i+1; j<n; j++){
         if(house[i].bath > house[j].bath){
            loc = house[i];
            house[i] = house[j];
            house[j] = loc;
         }
      }
	}
	
	int hit=1;
	for(i = 0; i<n; i++){
         if(house[i].bath != house[i+1].bath){
            hit++;
         }
	}
	
	int beda = 0;
	int count = 1;
	for(i = 0; i<n; i++){
        if(house[i].bath == house[i+1].bath){
            count += 1;
        }else if(house[i].bath != house[i+1].bath){
        	Hbath[beda].str = house[i].bath;
        	Hbath[beda].banyak = count;
        	count = 1;
        	beda++;
		}
	}
	for(j=0; j<hit-1; j++){
		printf("%d: %d\n", Hbath[j].str, Hbath[j].banyak);
	}
	
	large6 = small6 = Hbath[0];
	for(i = 1; i<hit-1; i++){
      	if(Hbath[i].banyak>large6.banyak)
    		large6 = Hbath[i];
      	if(Hbath[i].banyak<small6.banyak)
			small6 = Hbath[i];
   }
	printf("Maximum value: %d with frequency: %d\n", large6.str, large6.banyak);
	printf("Minimum value: %d with frequency: %d\n", small6.str, small6.banyak);		
}
void readCarParks(struct housing* house, int n){
	
	int i, j=0;
	char temp;
	
	for(i = 0; i<n; i++){
		for(j=i+1; j<n; j++){
         if(house[i].carParks > house[j].carParks){
            loc = house[i];
            house[i] = house[j];
            house[j] = loc;
         }
      }
	}
	
	int hit=1;
	for(i = 0; i<n; i++){
         if(house[i].carParks != house[i+1].carParks){
            hit++;
         }
	}
	
	int beda = 0;
	int count = 1;
	for(i = 0; i<n; i++){
        if(house[i].carParks == house[i+1].carParks){
            count += 1;
        }else if(house[i].carParks != house[i+1].carParks){
        	HCarParks[beda].str = house[i].carParks;
        	HCarParks[beda].banyak = count;
        	count = 1;
        	beda++;
		}
	}
	for(j=0; j<hit; j++){
		printf("%d: %d\n", HCarParks[j].str, HCarParks[j].banyak);
	}
	
	large7 = small7 = HCarParks[0];
	for(i = 1; i<hit; i++){
      	if(HCarParks[i].banyak>large7.banyak)
    		large7 = HCarParks[i];
      	if(HCarParks[i].banyak<small7.banyak)
			small7 = HCarParks[i];
   }
	printf("Maximum value: %d with frequency: %d\n", large7.str, large7.banyak);
	printf("Minimum value: %d with frequency: %d\n", small7.str, small7.banyak);		
}

void price(struct housing* house, int n){
	
	int min, max, i, j=0;
	long int total = 0;
	
	for(i = 0; i<n; i++){
		total += house[i].price;
	}
	double average = 0;
	average = total/n;
	
	max = min = house[0].price;
	for(i = 1; i<n; i++){
      	if(house[i].price>max)
    		max = house[i].price;
      	if(house[i].price<min)
			min = house[i].price;
   }
	printf("Maximum value : %d\n", max);
	printf("Minimum value : %d\n", min);
	printf("Average value : %.2lf\n", average);
}
void area(struct housing* house, int n){
	
	int min, max, i, j=0;
	long int total = 0;
	
	for(i = 0; i<n; i++){
		total += house[i].area;
	}
	double average = 0;
	average = total/n;
	
	max = min = house[0].area;
	for(i = 1; i<n; i++){
      	if(house[i].area>max)
    		max = house[i].area;
      	if(house[i].price<min)
			min = house[i].area;
   }
	printf("Maximum value : %d\n", max);
	printf("Minimum value : %d\n", min);
	printf("Average value : %.2lf\n", average);
}
