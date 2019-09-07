/*
 * CSc103 Project 7: Towers of Hanoi
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours:
 */

// TODO: write the program.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <getopt.h> // to parse long arguments.
#include <cstdlib> // for atoi function
using namespace std;

void towers(int n, int start,int open,int end){
if(n==1){ //when the number of disk is at one, it gets put to the end, destination
	cout << start << "\t" << end <<endl;
	return;
}
towers(n-1,start,end,open); //the disk will be moved to the open slot for each n-1
//used for seperating the smallest away from the biggest
cout<<start << "\t" << end <<endl; //the last disk gets shed to the end slot
towers(n-1,open,start,end); //combining all of them to the end slot.
//smallest all fall into the biggest at the end location.
}

/* Here's a skeleton main function for processing the arguments. */
int main(int argc, char *argv[]) {
	// define long options
	static struct option long_opts[] = {
		{"start",        required_argument, 0, 's'},
		{"end",          required_argument, 0, 'e'},
		{"num-disks",    required_argument, 0, 'n'},
		{0,0,0,0} // this denotes the end of our options.
	};
	// now process the options:
	char c; // to hold the option
	int opt_index = 0;
	short n=0,start=0,end=0; /* to store inputs to the towers function. */
	while ((c = getopt_long(argc, argv, "s:e:n:", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 's': // process option s
				start = atoi(optarg);
				break;
			case 'e': // process option e
				end = atoi(optarg);
				break;
			case 'n': // process option n
				n = atoi(optarg);
				break;
			case '?': // this will catch unknown options.
				// here is where you would yell at the user.
				// although, getopt will already print an error message.
				return 1;
		}
	}

	/* TODO: now that you have the options and arguments,
	 * solve the puzzle. */
	if (start>0 && end>0 && n>0 && end <=3 && start <=3){
		//start is between 1 and 3, end is between 1 and 3, n is greater than 0.
		int open=0; //declaration of the open slot
		if (start==1){ //starting at 1
			if (end==2){ //ending at 2
				open=3; //open slot is 3
			}
			else if (end==3){ //ending at 3
				open=2; //open slot is 2
			}
		}
		else if (start==2){ //starting at 2
			if (end==1){ //ending at 1
				open=3; //open slot is 3
			}
			else if(end==3){ //ending at 3
				open=1; //open slot is 1
			}
		}
		else if (start==3){ //starting at 3
			if (end==1){ //ending at 1
				open=2; //open slot is 2
			}
			else if (end==2){ //ending at 2
				open=1; //open slot is 1
			}
		}
		towers (n,start,open,end); //using the vaules of n, start, open, and end to run the recursion
	}
	else{
		//in case a condition isn't satified.
		cout << "Check for your -n -s -e, default is 0" << endl;
		cout << "-n == " << n << "\t" << "has to be greater than 0" << endl;
		cout << "-s == " << start << "\t" << "has to be 1, 2, or 3" << endl;
		cout << "-e == " << end << "\t" << "has to be 1, 2, or 3" << endl;
	}
	return 0;
}
