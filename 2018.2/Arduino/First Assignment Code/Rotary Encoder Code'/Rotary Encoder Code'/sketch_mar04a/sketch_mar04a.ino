 #define rot_enc1_outputA 1
 #define rot_enc1_outputB 0

 #define rot_enc2_outputA 3
 #define rot_enc2_outputB 2

 #define rot_enc3_outputA 5
 #define rot_enc3_outputB 4

 #define rot_enc4_outputA 7
 #define rot_enc4_outputB 6

 #define rot_enc5_outputA 12
 #define rot_enc5_outputB 13

 int rot_enc1_counter = 0;
 int rot_enc1_aState = 0;
 int rot_encl_aLastState = 0;

 int rot_enc2_counter = 0;
 int rot_enc2_aState = 0;
 int rot_enc2_aLastState = 0;

 int rot_enc3_counter = 0;
 int rot_enc3_aState = 0;
 int rot_enc3_aLastState = 0;

 int rot_enc4_counter = 0;
 int rot_enc4_aState = 0;
 int rot_enc4_aLastState = 0;

 int rot_enc5_counter = 0;
 int rot_enc5_aState = 0;
 int rot_enc5_aLastState = 0;

 void setup() { 
   pinMode (rot_enc1_outputA,INPUT);
   pinMode (rot_enc1_outputB,INPUT);

   pinMode (rot_enc2_outputA,INPUT);
   pinMode (rot_enc2_outputB,INPUT);

   pinMode (rot_enc3_outputA,INPUT);
   pinMode (rot_enc3_outputB,INPUT);

   pinMode (rot_enc4_outputA,INPUT);
   pinMode (rot_enc4_outputB,INPUT);

   pinMode (rot_enc5_outputA,INPUT);
   pinMode (rot_enc5_outputB,INPUT);
   
   Serial.begin (9600);
   
   rot_encl_aLastState = digitalRead(rot_enc1_outputA);
   rot_enc2_aLastState = digitalRead(rot_enc2_outputA);
   rot_enc3_aLastState = digitalRead(rot_enc3_outputA);
   rot_enc4_aLastState = digitalRead(rot_enc4_outputA);
   rot_enc5_aLastState = digitalRead(rot_enc5_outputA);
 } 

 void loop() { 
  
   rot_enc1_aState = digitalRead(rot_enc1_outputA);
   rot_enc2_aState = digitalRead(rot_enc2_outputA);
   rot_enc3_aState = digitalRead(rot_enc3_outputA);
   rot_enc4_aState = digitalRead(rot_enc4_outputA);
   rot_enc5_aState = digitalRead(rot_enc5_outputA);
   
   if (rot_enc1_aState != rot_encl_aLastState)
   {     
     if (digitalRead(rot_enc1_outputB) != rot_enc1_aState) 
     { 
       rot_enc1_counter ++;
     } 
     else 
     {
       rot_enc1_counter --;
     }
     
     Serial.print("Rot_Enc1 Position ");
     Serial.println(rot_enc1_counter);
   } 

   if (rot_enc2_aState != rot_enc2_aLastState)
   {     
     if (digitalRead(rot_enc2_outputB) != rot_enc2_aState) 
     { 
       rot_enc2_counter ++;
     } 
     else 
     {
       rot_enc2_counter --;
     }
     
     Serial.print("Rot_Enc2 Position: ");
     Serial.println(rot_enc2_counter);
   } 

   if (rot_enc3_aState != rot_enc3_aLastState)
   {     
     if (digitalRead(rot_enc3_outputB) != rot_enc3_aState) 
     { 
       rot_enc3_counter ++;
     } 
     else 
     {
       rot_enc3_counter --;
     }
     
     Serial.print("Rot_Enc3 Position: ");
     Serial.println(rot_enc3_counter);
   } 

   if (rot_enc4_aState != rot_enc4_aLastState)
   {     
     if (digitalRead(rot_enc4_outputB) != rot_enc4_aState) 
     { 
       rot_enc4_counter ++;
     } 
     else 
     {
       rot_enc4_counter --;
     }
     
     Serial.print("Rot_Enc4 Position: ");
     Serial.println(rot_enc4_counter);
   }

   if (rot_enc5_aState != rot_enc5_aLastState)
   {     
     if (digitalRead(rot_enc5_outputB) != rot_enc5_aState) 
     { 
       rot_enc5_counter ++;
       rot_enc4_counter ++;
       rot_enc3_counter ++;
       rot_enc2_counter ++;
       rot_enc1_counter ++;
     } 
     else 
     {
       rot_enc5_counter --;
       rot_enc4_counter --;
       rot_enc3_counter --;
       rot_enc2_counter --;
       rot_enc1_counter --;
     }
     
     Serial.print("Rot_Enc1 Position: ");
     Serial.println(rot_enc1_counter);

     Serial.print("Rot_Enc2 Position: ");
     Serial.println(rot_enc2_counter);

     Serial.print("Rot_Enc3 Position: ");
     Serial.println(rot_enc3_counter);

     Serial.print("Rot_Enc4 Position: ");
     Serial.println(rot_enc4_counter);

     Serial.print("Rot_Enc5 Position: ");
     Serial.println(rot_enc5_counter);
   } 

   rot_encl_aLastState = rot_enc1_aState;
   rot_enc2_aLastState = rot_enc2_aState;
   rot_enc3_aLastState = rot_enc3_aState;
   rot_enc4_aLastState = rot_enc4_aState;
   rot_enc5_aLastState = rot_enc5_aState;
 }
