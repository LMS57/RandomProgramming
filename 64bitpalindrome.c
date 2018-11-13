/*
	File was originally created to find all values above 32 bits that are palindromes in base 2, 10, and 16 at the same time,
ended up finding values that are palindormes in multiple bases at once
/*



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int bin[64];
char hex[16];
char dec[50];

int checknum(){

	unsigned long long decimal;
	sscanf(hex, "%llx", &decimal);
	sprintf(dec, "%llu", decimal);
//	decimal = 0;
	for(int i = 0; i < 64; i++)

		bin[i] = decimal>>i&1;
	for(int i = 0; i < 32; i++)
		if(bin[i] != bin[63-i])
			return 0;
	return 1;

	
	for(int i = 0; i < strlen(dec)/2;i++){
		if(dec[i] != dec[strlen(dec)-i-1])
			return 0;
	}
	return 1;
	for(int i = 0; i < 64; i++)
		bin[i] = decimal>>i&1;
	for(int i = 0; i < 32; i++)
		if(bin[i] != bin[63-i])
			return 0;
	return 1;
}

char num[20];

int  checkbin(int start){
	unsigned long long decimal;
	sscanf(num+start, "%llu", &decimal);
	//sprintf(dec, "%llu", decimal);
/*	//printf("%llu\n", decimal);
	for(int i = 0; i < 64; i++){
		bin[i] = decimal>>63-i&1;
	}
	int j=0;

	for(j = 0; j < 64; j++){
		if(bin[j])
			break;
	}
	for(int i = j; i < 64/2+j/2; i++)
		if(bin[i] != bin[63+j-i])
			return 0;
*/
	//convert to hex
	sprintf(hex, "%llx", decimal);
	printf("%s\n", hex);
	for(int i = 0; i < strlen(hex)+1/2;i++)
		//printf("%c %c", hex[i], hex[strlen(hex)-i]);
		if(hex[i] != hex[strlen(hex)-i])
			return 0;
	printf("%llu----\n", decimal);
	return 1;

}

void createdecimal(){

	for(int i = 0; i < 20; i++)
		num[i] = '0';
	unsigned long long large = 4297997924;
	int tmp;
	for(int i = 0;large;i++){
		num[19-i] = 48+large%10;
		large/=10;
	}
	int start = 10;
	int restart = 0;
	while(num[0]!=1){
		checkbin(start);

		while(num[0]!=1){//loop again
			
			for(int i = start+(20-start-1)/2; i !=start-1 ; i--){
				if(num[i] == '9'){
					if(i==start)
						restart = 1;
					num[i] = '0';
					num[19-(i-start)] = '0';

					continue;
				}
				if(i!=19-(i-start)){
					num[i]++;
					num[19-(i-start)]++;
				}
				else
					num[i]++;
				break;
	
			}
			if(restart){
				start--;
				num[start]='1';
				num[19]='1';
				restart = 0;
			}
				break;
		}
	}
}



int main(){
createdecimal();
return 0;
int a=0,b=0,c=0,d=0,e=0,f=0,g=0,l=0;
int j;
while(1){
	for(int i = 0; i < 8; i++){
		switch(i){
			case 0:
				j = a;
				break;
			case 1:
				j = b;
				break;
			case 2:
				j = c;
				break;
			case 3:
				j = d;
				break;
			case 4:
				j = e;
				break;
			case 5:
				j = f;
				break;
			case 6: 
				j = g;
				break;
			case 7:
				j = l;
				
		}	
		if(j > 9)
		{
			hex[i] = 65+j-10;
		}
		else
			hex[i] = 48+j;
		hex[15-i] = hex[i];
	}
//	long long test;
//	sscanf(hex, "%llx", &test);
//	printf("%s\n", hex);
//	return;	
	if(checknum()){
		printf("%s\n", hex);

	}
	l++;
	if(l==16)
		l=0;g++;
	if(g==16)
		g=0,f++;
	if(f==16)
		f=0,e++;
	if(e==16)
		e=0,d++;
	if(d==16)
	{
		d-=16;
		c++;
	}
	if(c==16)
		c-=16,b++;
	if(b==16)
		b-=16,a++;
	if(a==16)
		break;
}
printf("done\n");

}
