#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/***********************************************************
   Part A. Planet related functions
***********************************************************/

//You can consider using the following defines to improve
// readability of your code

#define PLANET_SIZE 20

#define ALIVE 'X' 
#define DEAD 'O'

//This function is provided for you to review file stream
//Use similar idea for the save_alien_planet() function

void init_alien_planet( const char filename[], char alienPlanet[][PLANET_SIZE])
{
    ifstream inf(filename);
    char temp;
    int i, j;

    //Ensure the file can be opened
    if (!inf.is_open()){
        cout << "Error in opening file!\n";
        return;
    }

    //Proceed to read the file content into char 2D array
    for (i = 0; i < PLANET_SIZE; i++){
        for (j = 0; j < PLANET_SIZE; j++){
            inf >> alienPlanet[i][j];
        }
    }
    inf.close();
}


void save_alien_planet(const char filename[], char matrix[][20])
{
    ofstream inf(filename);
    if(!inf.is_open()){
        cout<< "File cannot Open to Write\n";
        return;
    }
    for(int i=0; i<PLANET_SIZE;i++){
        for(int j=0;j<PLANET_SIZE;j++){
             inf<< matrix[i][j];
        }
        if(i<PLANET_SIZE) inf << endl;
    }
    inf.close();
}

// void print_planet20 (char matrix[][20]){
//      for (int i=0;i<20;i++){
//         for (int j=0;j<20;j++){
//             cout<< matrix[i][j]<< " ";
//         }
//         cout<<endl;
//     }
// }


// void print_planet (char matrix[][22]){
//      for (int i=0;i<22;i++){
       
//         for (int j=0;j<22;j++){
//             cout<< matrix[i][j]<< " ";
//         }
//     }
// }

/*
1. [Under‐population] Any live cell with fewer than two live neighbours dies.
2. [Survive] Any live cell with two or three live neighbours lives on to the next generation.
3. [Overpopulation] Any live cell with more than three live neighbours dies.
4. [Reproduction] Any dead cell with exactly three live neighbours becomes a live cell. 
 */
void evolve_alien_planet(char alienPlanet[][20], int nGeneration)
{
   for (int Mainloop =0; Mainloop<nGeneration;Mainloop++){
    /* Preparing the Dummy Array */
    char dummyPlanet [PLANET_SIZE+2][PLANET_SIZE+2] = {};
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                dummyPlanet[i+1][j+1]=alienPlanet[i][j];
            }
        }
    // print_planet(dummyPlanet);
    /* Looping for Generation */
     for ( int i=1; i<21 ; i++){
        for(int j=1; j<21; j++){
            char IT = dummyPlanet[i][j];
           // cout<<"START - "<<IT<< " i,j - " << i<< " " << j <<endl;
            if(IT == 'O'){ //Dead
                int count=0;
                for(int k=-1;k<2;k++)
                {
                    for(int l=-1;l<2;l++){
                       // cout<<" CHECK-"<<dummyPlanet[i+k][j+l] << "|" <<k <<","<<l<<"|"<< i+k <<","<< j+l;
                        if (dummyPlanet[i+k][j+l] == 'X'){
                            count++;
                        }
                    }
                    
                }
        
                if(count==3){
                    alienPlanet[i-1][j-1]='X';
                }
               // cout<<" Result=" <<"'"<<alienPlanet[i-1][j-1]<<"'"<< " Count="<<count <<endl;
            }
            else if(IT == 'X'){ // Live
                int count=-1;
                for(int k=-1;k<2;k++)
                {
                    for(int l=-1;l<2;l++){
                       // cout<<" CHECK-"<<dummyPlanet[i+k][j+l] << "|" <<k <<","<<l<<"|"<< i+k <<","<< j+l;
                         if (dummyPlanet[i+k][j+l] == 'X'){
                            count++;
                        }
                        
                    }
                   
                }
          
                if(count<2){
                    alienPlanet[i-1][j-1]='O';
                }
                else if (count>=2 && count<=3){
                    //Do nothing
                }
                else if (count >3){
                    alienPlanet[i-1][j-1]='O';
                }
                else{
                    cout<<"ERROR"<<endl;
                }
               // cout<<" Result=" <<alienPlanet[i-1][j-1]<< " Count="<<count <<endl;
            }
            else { // Dunno Error
                cout<<"Errors"<<endl;
            }
         }
     }
    // print_planet(dummyPlanet);
    // cout<<endl;
   //  print_planet20(alienPlanet);
   }
    //   print_planet20(alienPlanet);
}

/***********************************************************
   Main function
***********************************************************/


int main( )
{
	//Two points:
	//1. If you use the suggested defines above
	//    this can be written as "char myPlanet[PLANET_SIZE][PLANET_SIZE];
	//2. May want to think about easier ways to handle the
	//    boundaries....
	char myPlanet[20][20];

	/*****************
     *    Testing    *
	 *****************/
    init_alien_planet("planet_sample.txt", myPlanet);
    //print_planet20(myPlanet);
	evolve_alien_planet( myPlanet, 3);

	// //One example on how to use the save file
	 save_alien_planet("Your_Planet.txt", myPlanet);

    return 0;
}

