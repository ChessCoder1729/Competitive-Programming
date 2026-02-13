 // iterate over all the subsets of the mask
for(int i = mask; i > 0; i = (i-1) & mask){
	F[mask] += A[i];
}


// SOS DP :
for(int i = 0; i<(1<<N); ++i)
	F[i] = A[i];

for(int i = 0;i < N; ++i){
   for(int mask = 0; mask < (1<<N); mask++){
		if(mask & (1<<i)){
			F[mask] += F[mask^(1<<i)]; // mask - (1<<i)
		}
   }
}
