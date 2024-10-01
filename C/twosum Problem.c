typedef struct {
	int num;
	int idx;
	// Makes structure hashable
	UT_hash_handle hh;
} num_t;

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int* res = calloc((*returnSize = 2), sizeof(int));
	num_t *numsHash = NULL, *num = NULL, *tmp = NULL;

	for(int i = 0; i < numsSize; ++i){
		int toFind = target - nums[i];
		HASH_FIND_INT(numsHash, &toFind, num);

		if (num != NULL){
			res[0] = num->idx;
			res[1] = i;

			break;
		} else {
			num = malloc(sizeof(num_t));
			num->num = nums[i]; num->idx = i;

			HASH_ADD_INT(numsHash, num, num);
		}
	}

	HASH_ITER(hh, numsHash, num, tmp) {
		HASH_DEL(numsHash, num); free(num); 
	}

	return res;
}
