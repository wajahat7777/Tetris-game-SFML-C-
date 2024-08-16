//WAJAHAT ULLAH KHAN
//22I-0776
//SECTION G

/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */

//---Piece Starts to Fall When Game Starts---//
#include <iostream>
using namespace std;
void fallingPiece(float& timer, float& delay,int& colorNum){
    if (timer>delay){
        for (int i=0;i<4;i++){
        
           point_2[i][0]=point_1[i][0];
           point_2[i][1]=point_1[i][1];
            point_1[i][1]+=1;                   //How much units downward
          delay=0.3;
        }
        
       
        if (!anamoly()){
            for(int i=0; i<4;i++)
                gameGrid[point_2[i][1]][point_2[i][0]]=colorNum;
                colorNum=1+rand()%7;
            int n=1+rand()%10;
                       delay=0.3;
            //--- Un-Comment this Part When You Make BLOCKS array---//
                   
                
            
                for (int i=0;i<4;i++){
                    point_1[i][0] = BLOCKS[n][i] % 2;
                    point_1[i][1] = BLOCKS[n][i] / 2;
                }
       
        }
        timer=0;
    }
}
          

/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///
     
  void   movement(int &delta_x){
          for (int i=0;i<4;i++){                  //loop to prevent blocks from overwriting each other
        
            
            point_2[i][1]=point_1[i][1];
            point_2[i][0]=point_1[i][0];
                     
           point_1[i][0]+=delta_x;             //delta_x increments in the coordinates
       }

           if(!anamoly()){                    //calling function to prevent block from overwriting into the sides boundary
               for (int i=0;i<4;i++){
       
               
                 point_1[i][1]=point_2[i][1];
                   point_1[i][0]=point_2[i][0];      
            }
       }	
   
             delta_x=0;         
            
  }
   
int score = 0;



    void rotation(bool &rotate){   
 
         if (rotate==true) {
    
    
           int x_center=point_1[1][0];       //block around which rotation happens         
           int y_center=point_1[1][1];       //block around which rotation happens               
           
           rotate=0;
           for(int i=0; i<4 ;i++){
          
            point_2[i][0]= point_1[i][0];         //loop prevent blocks from overwriting each other
            point_2[i][1]= point_1[i][1];
          
          
            int x= point_1[i][1] - y_center;       // x and y coordinates being found with respect to rotation origin
            int y= point_1[i][0] - x_center;
           
            point_1[i][1]=y_center +  y;
            point_1[i][0]= x_center - x;
           
           }
           
           if(!anamoly()){                    //calling function to prevent block from overwriting into the sides boundary
             for (int i=0;i<4;i++){
       
            point_1[i][1]=point_2[i][1];   
            point_1[i][0]=point_2[i][0];   
          }
       }
       
    }
 
 }

 
             
 
void lbreak() {
    int check = 0;
    for (int j = M - 1; j >= 0; j--) {
        check = 0;
        for (int i = 0; i < N; i++) {
            if (gameGrid[j][i] == 0) {
                check++;  // Count how many blocks are empty
            }
        }
        
        if (check == 0) {  // Row is full
            std::cout << "Line " << j << " is full, breaking it." << std::endl;
            for (int i = 0; i < N; i++) {
                gameGrid[j][i] = 0;
            }
            
            for (int t = j; t > 0; t--) {
                for (int i = 0; i < N; i++) {
                    gameGrid[t][i] = gameGrid[t-1][i];
                }
            }
            j++;  // Re-check the current row after collapsing rows above

            score += 100;  // Increment score
            std::cout << "Score incremented to: " << score << std::endl;
        }
    }
}


      void GameEnd(bool& game_end)
      {
          for (int i=0;i<N;i++){         //loop checks first row and each column to check if theres any element filled
             
             if (gameGrid[0][i]!=0){
                 game_end=true;
              }
          }
       
      }
 
///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
