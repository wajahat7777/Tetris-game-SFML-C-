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
            int n=1+rand()%7;
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

 
             
 
 void lbreak()                               //function for breaking line
 {
 
   int check=0;
   int j=0,z=0,scr=0;
   for(j=M-1;j>=0;j--)                       //loop for rows from bottom to top if the specific bloack is empty or filled
   { 
       check=0;
       int z=0;
       int scr=0;
       for(int i=0; i< N; i++)             //loop for rows from left to right to check if the specific bloack is empty or filled
	{
 	  if(gameGrid[j][i] == 0)           
 	   check++;                          //the variables counts how much blocks are empty in a row 
 	} 
 	 
 	 if(check ==0)                       //if the whole row is filled 
 	{
 	for(int i =0; i<N; i++)              //loop to delete the whole row 
      	  gameGrid[j][i] =0; 
  	
  	for(int t=j; t>=0 ; t-- )            //loop to move row of blocks to the next row(deleted row)
   	  for(int i =0; i<N; i++)
      	  gameGrid[t][i] =gameGrid[t-1][i]; 
   		j++;
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

