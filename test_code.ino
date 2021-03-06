
void setup() {
  
  initialise_arm();   //attach servos and set initial positions to 90 degrees
  Serial.begin(9600);
  print_pos();        //print startup positions
pinMode(12, OUTPUT);
digitalWrite(12,LOW);
}


void loop() {

  int flag1 =0;
  
    while (flag1 == 0){   // continually loop, doing nothing, until serial input, then loop once and exit back to waiting for serial input
      
      if (Serial.available()>0){  //serial buffer filled? if yes proced to inner code, otherwise wait
        
        String Finger = Serial.readString();  //finger name to be set entered by user, names are servo object names
        flag1=1;  //exit condition, allows exit of this loop on next iteration attempt
          Serial.println(Finger);
          Finger.trim();
              if (Finger == "play")      //option to randomly set fingers based on rock paper sicissors positions
                play();
                
              else if (Finger == "thumb" || Finger == "first" || Finger == "second" || Finger == "third" || Finger == "fourth")  //for any other input, print invalid message
                {
                  reset_actions();
                  increment_multipul(Finger);   //call function to set new value of specified finger
                  
                }

              else if( Finger == "ripple"){
              ripple_fingers();
              }
              
              else if (Finger== "in_n_out"){
                in_and_out();
              }

              else if (Finger == "come here"){
                beckoning();
              }
              else
              {
                reset_actions;
                Serial.println("");         
                Serial.println ("invalid finger name");
                Serial.println("");
                }
      }
    }
          
  flag1=0;    //code exacuted, reset flag
  
  print_pos();  //print current positions, only prints once while loop exits, ie once something happens
}

