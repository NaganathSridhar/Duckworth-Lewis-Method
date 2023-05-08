/*
 * main.c
 *
 *  Created on: 18-Feb-2023
 *      Author: Naganath
 */

#include <stdio.h>

//DL RESORCE TABLE FOR A 20 OVERS MATCH
/*
 *  This is the Resource table that was collected by referring to
 *  "Duckworth-Lewis and Twenty20 Cricket"
 *
 *  In this we have 3 types of conditions which we have dedicated functions to handle those functions.
 */
float res[20][10]={{100,96.8,92.6,86.7,78.8,68.2,54.4,37.5,21.3,8.3},
			{96.1,93.3,89.2,83.9,76.7,66.6,53.5,37.3,21,8.3},
			{92.2,89.6,85.9,81.1,74.2,65,52.7,36.9,21,8.3},
			{88.2,85.7,82.5,77.9,71.7,63.3,51.6,36.6,21,8.3},
			{84.1,81.8,79,74.7,69.1,61.3,50.4,36.2,20.8,8.3},
			{79.9,77.9,75.3,71.6,66.4,59.2,49.1,35.7,20.8,8.3},
			{75.4,73.7,71.4,68,63.4,56.9,47.7,35.2,20.8,8.3},
			{71,69.4,67.3,64.5,60.4,54.4,46.1,34.5,20.7,8.3},
			{66.4,65,63.3,60.6,57.1,51.9,44.3,33.6,20.5,8.3},
			{61.7,60.4,59,56.7,53.7,49.1,42.4,32.7,20.3,8.3},
			{56.7,55.8,54.4,52.7,50,46.1,440.3,31.6,20.1,8.3},
			{51.8,51.1,49.8,48.4,46.1,42.8,37.8,30.2,19.8,8.3},
			{46.6,45.9,45.1,43.8,42,39.4,35.2,28.6,19.3,8.3},
			{41.3,40.8,40.1,39.2,37.8,35.5,32.2,26.9,18.6,8.3},
			{35.9,35.5,35,34.3,33.2,31.4,29,24.6,17.8,8.1},
			{30.4,30,29.7,29.2,28.4,27.2,25.3,22.1,16.6,8.1},
			{24.6,24.4,24.2,23.9,23.3,22.4,21.2,18.9,14.8,8},
			{18.7,18.6,18.4,18.2,18,17.5,16.8,15.4,12.7,7.4},
			{12.7,12.5,12.5,12.4,12.4,12,11.7,11,9.7,6.5},
			{6.4,6.4,6.4,6.4,6.4,6.2,6.2,6,5.7,4.4}};

// Function Prototype
/*
 *  Function Name: D_L_Scenario_1()
 *  Function Definition: This is a dedicated function to handle the Condition 1
 */
void D_L_Scenario_1()
{
	//INTERRUPTION AND ABANDONMENT IN 2ND INNINGS
	int r1;
	printf("Enter the team 1's score in 20 overs: ");
	scanf("%d",&r1);

	int r2,o2,w2;
	printf("Enter runs scored, wickets lost and overs played by team 2 when the match is interrupted: ");
	scanf("%d %d %d",&r2,&w2,&o2);

	float par_score=(100-res[o2][w2])*r1/100;

	if(r2>=par_score)
	{
		printf("Team 2 wins by %d runs",(int)(r2-par_score));
	}
	else
	{
		printf("Team 1 wins by %d runs",(int)(par_score-r2));
	}
}

// Function Prototype
/*
 *  Function Name: D_L_Scenario_3()
 *  Function Definition: This is a dedicated function to handle the Condition 3
 */
void D_L_Scenario_2()
{
	//INTERRUPTION IN 1ST INNINGS AND NUMBER OF OVERS IS REDUCED
	int r1,o1,w1;
	printf("Enter the team 1's score, overs faced and wickets lost at the time of interruption: ");
	scanf("%d %d %d",&r1,&o1,&w1);

	int rem_run1,rem_o1;
	printf("Enter the remaining overs that the team 1 has and runs scored in the remaining overs: ");
	scanf("%d %d",&rem_o1,&rem_run1);

	float target;

	float res1=res[o1][w1];

	float res2=res[20-rem_o1][w1];

	res1=100-(res1-res2);

	float res_team2=res[20-(o1+rem_o1)][0];

	float diff=res_team2-res1;

	target=(diff*1.5)+r1+rem_run1;

	printf("\nTarget for team 2 is %d in %d overs.",(int)target,o1+rem_o1);

}

// Function Prototype
/*
 *  Function Name: D_L_Scenario_2()
 *  Function Definition: This is a dedicated function to handle the Condition 2
 */
void D_L_Scenario_3()
{
	//INTERRUPTION IN 2ND INNINGS AND TOTAL NUMBER OF OVERS IS REDUCED
	int r1,o1;
	printf("Enter team 1's total score and overs played: ");
	scanf("%d %d",&r1,&o1);

	int r2,w2,o2;
	printf("Enter team 2's score, overs played and wickets lost at the time of interruption: ");
	scanf("%d %d %d",&r2,&o2,&w2);

	float res1=res[20-o1][0];

	float res2=res[o2][w2];

	int rem_o2;

	printf("Enter the remaining overs available for team 2: ");
	scanf("%d",&rem_o2);

	float rem_res2=res1-(res2-res[20-rem_o2][w2]);

	int target=r1*rem_res2/res1;

	printf("\n\nTarget for team 2 is %d\n\n",target);

	printf("Team 2 requires %d runs in %d overs",target-r2,rem_o2);

}

int main()
{
	int ch;
	printf("\t\t\t****D/L METHOD****\n\n");
	printf("1. Interruption and abandonment of match in 2nd innings");
	printf("\n2. Interruption in 1st innings and the total number of overs in reduced");
	printf("\n3. Interruption in 2nd innings and number of overs available is reduced");
	printf("\n\nEnter your choice: ");
	scanf("%d",&ch);

	switch(ch)
	{
	case 1: D_L_Scenario_1();
			break;

	case 2: D_L_Scenario_2();
			break;

	case 3: D_L_Scenario_3();
			break;

	case 4: exit(0);
			break;

	default: printf("Invalid choice");
			 getchar();
			 getchar();
	}

	getchar();
	getchar();

	return 0;
}
