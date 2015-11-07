/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isOlder(char *dob1, char *dob2) {
	int k = 0;
	int x = 0;
	int day1[3][4] = { 0 };
	int count = 0;
	int d1[3] = { 0 };
	int cnt = 1;
	for (int index = 0; dob1[index] != '\0'; index++){
		if (dob1[index] != '-'){
			if ((dob1[index] - '0') > 9){
				return -1;
			}
			day1[k][x] = dob1[index] - '0';
			x++;
		}
		else{
			day1[k][x] = -1;
			x = 0;
			cnt++;
			k++;
		}
	}
	if (cnt < 3)
		return -1;
	for (int index = 0; index <3; index++){
		for (int idx = 0; idx < 4; idx++){
			if (day1[index][idx] != -1){
				d1[index] = (d1[index] * 10) + day1[index][idx];
			}
			else
				break;
		}
	}
	k = 0;
	x = 0;
	int day2[3][4] = { 0 };
	count = 0;
	int d2[3] = { 0 };
	cnt = 1;
	for (int index = 0; dob2[index] != '\0'; index++){
		if (dob2[index] != '-'){
			if ((dob2[index] - '0') > 9){
				return -1;
			}
			day2[k][x] = dob2[index] - '0';
			x++;
		}
		else{
			day2[k][x] = -1;
			cnt++;
			x = 0;
			k++;
		}
	}
	for (int index = 0; index <3; index++){
		for (int idx = 0; idx < 4; idx++){
			if (day2[index][idx] != -1){
				d2[index] = (d2[index] * 10) + day2[index][idx];
			}
			else
				break;
		}
	}
	if (cnt < 3)
		return -1;
	int equal = 0;
	if (d1[1] > 12 || d2[1] > 12){
		return -1;
	}
	if ((d1[1] == 2 && d1[0] > 29) || (d2[1] == 2 && d2[0] > 29)){
		return -1;
	}
	if (d1[1] == 2 && d1[0] == 29){
		if ((d1[2] % 4 == 0 && d1[2] % 100 != 0) || d1[2] % 400 == 0){
			if (d2[1] == 2 && d2[0] == 29){
				if ((d2[2] % 4 == 0 && d2[2] % 100 != 0) || d2[2] % 400 == 0){
					for (int i = 2; i >= 0; i--){
						if (d1[i] < d2[i]){
							return 1;
						}
						else if (d1[i] > d2[i]){
							return 2;
						}
						else
							equal++;
					}
					if (equal == 3)
						return 0;
				}
				else
					return -1;
			}

		}
		else
			return -1;
	}
	for (int i = 2; i >= 0; i--){
		if (d1[i] < d2[i]){
			return 1;
		}
		else if (d1[i] > d2[i]){
			return 2;
		}
		else
			equal++;
	}
	if (equal == 3)
		return 0;

}
