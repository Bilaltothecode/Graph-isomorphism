#include<iostream>   //header
using namespace std;            //assigning std:: 
#define max 100                 //my max value for this program

//the following are my functions list so the main function knows thier present

void generation(int[max][max], int*); //tells my code to look for generating function
void display(int[max][max], int*);  //tells my code to look for displaying function
int checkdegree(int[max][max], int*, int[max]); //tells my code to look for funcction that checks the degree
void sort(int[max], int*); //predefined function to sort
int isomorphic(int[max], int[max], int*); //initializing intergers
int N, n, Y, y; //initializing integers
int main(void)  //main function
{
	int A[max][max], B[max][max], vertex, degA[max], degB[max], degreeA = 0, degreeB = 0, flag = 0;  //initializing
	system("clear"); 
	char ans; //ans is used for yes and no later to say if you want to run the program again
    //following two cout function are describing isomorphism
	cout << "\n\tGraph generation:\n\tAssume Simple, Symmetric, Undirected, Unweighted Graph\n";
	cout << "\n\tTwo graphs are Isomorphic if: both have same number of vertices, edges & same number of vertices having equal degree.\n\n";
    //the following loops are the program running
	do {	
		cout << "\n\tEnter number of vertex of Graph A: ";  //asks for number of vertices of A
		cin >> vertex;                                      //user inputs number of vertices of A here
		flag = vertex;                                      //Flag gets set to equal the vertex
		generation(A, &vertex);                             //generates the graph matrice
		vertex = 0;                                         //initializes the vertex to 0 for B
		cout << "\n\tEnter number of vertex of Graph B: ";  //asks for number of vertices of B
		cin >> vertex;                                      //user inputs number of vertices of B here
		generation(B, &vertex);                             //generates the graph matrice
		cout << "\n\tgraph A:\n";                           //This section displays the matrice of the graphs
		display(A, &flag);                                  //calls display to display A
		cout << "\n\tgraph B:\n";
		display(B, &vertex);                                //calls display to display A
		if (flag == vertex)                                 //this if first compares flag to vertex if equal this executes
		{
			degreeA = checkdegree(A, &vertex, degA);        //figuring out the degree of A and B
			degreeB = checkdegree(B, &vertex, degB);
			flag = 0;                                       //initialize flag to equal 0 for the next part
			if (degreeA == degreeB)                         //to compare the two degrees
			{
				sort(degA, &vertex);                        //calls sort function
				sort(degB, &vertex);                        //calls sort function
				flag = isomorphic(degA, degB, &vertex);     
				if (flag == 1)                              //the flag is either 1 or 0 and if 0 their isomorphic and if 1 they are not isomorphic
					cout << "\n\tBoth graphs are Not Isomorphic!\n";
				else if (flag == 0)
					cout << "\n\tBoth graphs are Isomorphic!\n";
			}
			else
				cout << "\n\tBoth graphs are Not Isomorphic!\n";    //if any of the if statements fail we cout not isomorphic
		}
		else
			cout << "\n\tBoth graphs are Not Isomorphic!\n";        //if any of the if statements fail we cout not isomorphic

cout << "Do you want to do another test? (y/n) ";                   //this is if you want to do another example without having to rerun the program
cin >> ans;                                                         //iinput answer Y or y to continue N n to not
} while (ans == 'y' || ans == 'Y');
};
//the following are where my call functions are defined

void generation(int A[max][max], int *vertex) //this is to generate the graph, this is good for when you write it in the format A B C D or other ways instead of like a matrice
{
	for (int i = 0; i < (*vertex); i++)
	{
		for (int j = 0; j < (*vertex); j++)
		{
			cin >> A[i][j];
		}
	}
	return;
}

void display(int A[max][max], int *vertex)      //this is to display what is generated
{
	for (int i = 0; i < (*vertex); i++)
	{
		for (int j = 0; j < (*vertex); j++)
		{
			printf(" %d", A[i][j]);
		}
		printf("\n");
	}
	return;
}

int checkdegree(int A[max][max], int *vertex, int degA[max])    //this section checks the degree or as I like to call it a the degree test, just includes loops that is called to the main function which is then used to test the degree of A and B and assess if they qualify to pass for isomorphism so it can continue the loop.
{
	int i = 0, j, degreeA, k = 0;
	for (; i < (*vertex); i++, k++)
	{
		j = 0, degreeA = 0;
		for (; j < (*vertex); j++)
		{
			if (A[i][j] == 1)
				degreeA++;
		}
		degA[k] = degreeA;
	}
	degreeA = 0;
	for (k = 0; k < (*vertex); k++)
	{
		degreeA = (degreeA + degA[k]);
	}
	return(degreeA);
}

void sort(int degA[max], int *vertex)       //this sorts A and B 
{
	int i = 0, j, temp = 0;
	for (; i < (*vertex); i++)
	{
		j = 0;
		for (; j < (*vertex) - i - 1; j++)
		{
			if (degA[j] > degA[j + 1])
			{
				temp = degA[j];
				degA[j] = degA[j + 1];
				degA[j + 1] = temp;
			}
		}
	}
	return;
}

int isomorphic(int degA[max], int degB[max], int *vertex)   //final test weather they are isomorphic or not
{
	int flag = 0, i = 0, j = 0;
	for (; i < (*vertex); i++, j++)
	{
		if (degA[i] != degB[j])
		{
			flag = 1;               //if the it isnt isomorphic flag is set to 1 which in the main program is then used to out not isomorphic 
			break;
		}
	}
	return(flag);
	return 0;
}