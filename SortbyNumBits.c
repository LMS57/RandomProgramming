/*
Creates an array of 64 bit sized number then sorts them by the number of 1's in the binary, just a simple bubble sort
/*


int main(){//works
	srand(time(0));
	int k = rand()+rand();

	long long array[52];
	int counts[52];
	int counter;
	for(int i = 0; i < 52; i++){
		counter = 0;
		array[i] = (long long)(rand() + rand())*RAND_MAX + rand() + rand();
		for(int j = 0; j < 64; j++){
			if(array[i]>>j&1)
				counter++;
		}
		counts[i]=counter;
	}
	long long tmp;
	for(int i = 0; i < 52; i++){
		for(int j = 0; j < 51;j++){
			if(counts[j] > counts[j+1]){
				counts[j] += counts[j+1];
				counts[j+1] = counts[j]-counts[j+1];
				counts[j] -= counts[j+1];
				tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
			}
		}
	}
	for(int i = 0; i < 52; i++){
		printf("%lld\n", array[i]);

	}

}
