#include <stdio.h>
#include <limits.h> // defines INT_MIN and INT_MAX

int any_bit_one(int x) {
    // Fill in code for part A here.
	return (!!x); 	// If x has 1 in any bit, !x will be 0, and !! x will give 1.
}

int any_bit_zero(int x) {
    // Fill in code for part B here.
	int inverted = ~x;
	return (!!inverted); 	// If x has 0 in any bit meaning that ~x has 1 in any bit, and works same as part A.
}


int lsb_one(int x) {
    // Fill in code for part C here.
	int temp = 0xFF;
	int result = x & temp;
	return (!!result);
}

int msb_zero(int x) {
    // Fill in code for part D here.
	int shift_val = (sizeof(int)-1)<<3;
	int xright = x >> shift_val;
	int inverted = ~(xright & 0xFF);
	int combining = (0x000000FF & inverted);
	return any_bit_one(combining);
}

int main() {
    int x;
    // Test all integer values
    for (x = INT_MIN; x <= INT_MAX; x++) {
	if (any_bit_one(x) != (x != 0)) {
	    printf("Any bit in x equal to 1	FAILED!\n");
	    break;
	}
	if (any_bit_zero(x) != (x != -1)) {
	    printf("Any bit in x equal to 0 FAILED!\n");	
	    break;
	}
	if (lsb_one(x) != ((char)x != 0)) {
	    printf("Any bit in least significant byte in x equal to 1 FAILED!\n");	
	    break;
	}
	if (msb_zero(x) != (*((char*)&x + 3) != -1)) {
	    printf("Any bit in most significant byte in x equal to 0 FAILED!\n");	
	    break;
	}

	// Print out something so you know that stuff is happening
	if (x % 100000000 == 0) {
	    printf("%d\n", x);	
	}

	// Have to have a way to break out before we loop around to INT_MIN
	if (x == INT_MAX) {
	    printf("All tests passed!\n");	
	    break;
	}
    }
	
	
    // Enter the numbers you want to test
    int any_bit_one_test_cases[5] = {0,1,-1,256,-1024};
    int i;
    for (i = 0; i < 5; i++) {
	printf("any_bit_one(0x%08x) = %d\n", any_bit_one_test_cases[i],
	       any_bit_one(any_bit_one_test_cases[i]));
    }

    printf("\n");
    // Enter new set of test cases
    int any_bit_zero_test_cases[5] = {0,1,-1,256,-1024};
    for (i = 0; i < 5; i++) {
	printf("any_bit_zero(0x%08x) = %d\n", any_bit_zero_test_cases[i],
	       any_bit_zero(any_bit_zero_test_cases[i]));
    }

    printf("\n");
    // Enter new set of test cases
    int lsb_one_test_cases[5] = {0,1,-1,256,-1024};
    for (i = 0; i < 5; i++) {
	printf("lsb_one(0x%08x) = %d\n", lsb_one_test_cases[i],
	       lsb_one(lsb_one_test_cases[i]));
    }

    printf("\n");
    // Enter new set of test cases
    int msb_zero_test_cases[5] = {0,1,-1,256,-1024};
    for (i = 0; i < 5; i++) {
	printf("msb_zero(0x%08x) = %d\n", msb_zero_test_cases[i],
	       msb_zero(msb_zero_test_cases[i]));
    }

    return 0;	
}

