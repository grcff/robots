#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define NUMCLANS 1
#define ROBOTSPERCLAN 3
#define ARENASIDELENGTH 300
#define NUMGENERATIONS 100
#define VISION 100
#define FOODXY 100
#define POISINXY 200
#define FEEDINGDISTANCE 25
#define ROBOTRADIUS 5
#define NUMGENERATIONS 100
#define NUMCYCLESPERGEN 500
#define DATALOGFILENAME "datalog.txt"

//struct linkedListNode;
//struct anotherLinkedListNode;

typedef struct linkedListNode{
	struct linkedListNode* prev;
	struct linkedListNode* next;
	int correspondingRobot;
} edibleQueueNode;

typedef struct anotherLinkedListNode
{
	struct anotherLinkedListNode* next;
	int correspondingRobot;
	int score;
} scoreListNode;

typedef struct bluuuhhhhhhh
{
	double x; // x-coordinate, from 0 to ARENASIDALENGTH
	double y; // y-coordinate, from 0 to ARENASIDALENGTH
	double o; // orientation, in radians
	double b; // brightness, from 0 to 1
	int s; // score
} indvStates;

typedef struct mrahhhhhh
{
	int* phenBool;
	int* phenInt;
} indvPhenotype;

/*
randomStates
input: an initialized initialStates array
output: random values are assigned
purpose: to give random initial values to robots
		 at the beginning of a generation
*/

void updateStatesXYOB(int states[5], int outputs[3]){
	int arcRadius, dir, relativeAngle, m, n, xmove, ymove, newx, newy, newo;

	/* Calculate new x and y coordinates
		This is a quick fix, I would love an algorithm written by
		someone who actually knows trigonometry */
	if (outputs[0] == outputs[1]) {
		if outputs[0] == 0{
			break;
		}
		arcRadius = pi * ROBOTRADIUS;
		relativeAngle = 0;
	} else {
		if (outputs[0] > outputs[1]) {
			m = outputs[0];
			n = outputs[1];
			dir = 0;
		} else {
			m = outputs[1];
			n = outputs[0];
			dir = 1;
		}
		relativeAngle = (m-n)*pi;
		if n==0
			arcRadius = ROBOTRADIUS;
		else
			arcRadius = ROBOTRADIUS*m/n;
	}	
	absoluteAngle = (relativeAngle + states[2]) % (2*pi);
	if (dir)
		absoluteAngle *= -1;
	xmove = sin(absoluteAngle) * arcRadius;
	ymove = (cos(absoluteAngle) - 1) * arcRadius;
	newx = xmove + states[0];
	newy = ymove + states[1];

	/* Robots shouldn't be allowed out of the boundaries.
		This boundry-collision algorithm is not very physics-like,
		I would love an algorithm that could be more accurate */
	if (newx <= 0)
		newx = 0;
	if (newx >= ARENASIDELENGTH)
		newx = ARENASIDELENGTH;
	if (newy <= 0)
		newy = 0;
	if (newy >= ARENASIDELENGTH)
		newy = ARENASIDELENGTH;

	/* Calculate new orientation */
	if (dir)
		newo = (absoluteAngle - (pi/2)) % (pi*2);
	else
		newo = (absoluteAngle + (pi/2)) % (pi*2);

	/* Assign new values */
	states[0] = newx;
	states[1] = newy;
	states[2] = newo;
	states[3] = outputs[2]; /* The brightness can directly transfer */
}
/*
void randomPhenotypes(indvPhenotype* robotPhenotypes){
	unsigned int iseed = (unsigned int)time(NULL);
  	srand (iseed);
  	indvPhenotype* robotPhenotypesIter = robotPhenotypes;
	int numRobots = NUMCLANS * ROBOTSPERCLAN;
	int i;
	for(i=0; i<numRobots; i++){
		
	}
}
*/
int main(){
	int numRobots = NUMCLANS * ROBOTSPERCLAN;
	int statesLength = numRobots * 5;
	indvStates* whutwhut = (indvStates*) malloc(sizeof(indvStates));
	whutwhut->x = 0;
}


