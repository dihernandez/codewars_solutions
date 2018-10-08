#include <iostream>
#include <list>

struct prime_pair{
	int start_prime;
	int end_prime;
};

prime_pair stepsInPrimes(int params[]){
	int g, m, h, start_prime, end_prime;
	g = params[0];
	m = params[1];
	h = params[2];
	prime_pair result = {start_prime, end_prime};

	return result;
}

list<int> extractPrimes(int start, int end){
    list<int> visited_values, primes;
    int counter = start;
    if(start >= 2 >= min){ 
        primes.push_back(2);
    } else
    {   
       while(counter > end){
           for(int visited : visited_values){
       
       }
        
    }
}

int main(int argc, char *argv[]){
	int params[] = {2,2,50};
	prime_pair primes = stepsInPrimes(params);
	printf("steps are %d, %d \n", primes.start_prime,primes.end_prime);

	return 0;
}
