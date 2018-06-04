#define led 13
String input_string = "";

void args_to_arr(String TheArray[], int n, String input);
int get_split(String input);
String check_spaces(String line);




void setup() {
  Serial.begin(9600);
    for(int a=0;a < 13;a++){
       pinMode(a, OUTPUT);
    }
    //_________________HELLO__________________
   // $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
   
   
Serial.print("\n  _/      _/  _/              _/                          _/ ");  
Serial.print("\n _/      _/      _/  _/_/  _/_/_/_/  _/    _/    _/_/_/  _/  ");    
Serial.print("\n_/      _/  _/  _/_/        _/      _/    _/  _/    _/  _/   ");    
Serial.print("\n _/  _/    _/  _/          _/      _/    _/  _/    _/  _/    ");    
Serial.print("\n  _/      _/  _/            _/_/    _/_/_/    _/_/_/  _/     ");    
Serial.print("\n");  
Serial.print("\n");  
Serial.print("\n      _/_/                          ");  
Serial.print("\n   _/    _/  _/      _/  _/  _/_/   ");  
Serial.print("\n  _/_/_/_/  _/      _/  _/_/        ");  
Serial.print("\n _/    _/    _/  _/    _/           ");  
Serial.print("\n_/    _/      _/      _/            ");  
Serial.print("\n");  
Serial.print("\n ");  
Serial.print("\n #####  ");  
Serial.print("\n#  #  # ");  
Serial.print("\n#  #    ");  
Serial.print("\n #####  ");  
Serial.print("\n   #  # ");  
Serial.print("\n#  #  # ");  
Serial.print("\n #####  ");  


Serial.print("\n  "); 
Serial.print("https://github.com/bembite/avr_virtual_shell");
Serial.print("\n  "); 
Serial.print("ver. 0.0.1"); 
Serial.print("\n  "); 
Serial.print("release: beta");
Serial.print("\n  "); 
Serial.print("type help for USAGE");
 




    
    Serial.print("\nbembi@arduino:~$ ");

    
}

void loop() {
  while (Serial.available() > 0) {
    char c = Serial.read();
    if (c == '\n') { 
          //Serial.print("bembi@arduino:~$ ");
          Serial.print(input_string);
          
          //parser there!!!
          String MyArray[5];
          args_to_arr(MyArray,5,input_string);
          //result
          if( MyArray[0]=="help") 
          {
          Serial.print("\n");
          Serial.print("USAGE: [digital|analog] -p [pin] -s|-d [d-for digital(delay in ms), s-for analog(sample=1 sec)] [num]");
          }
          else if(MyArray[0]=="analog")//analog--------------------------
          {
            if(MyArray[1]=="-p")//pin
            {
              if((MyArray[2].toInt()<6)&&(MyArray[2].toInt()>=0))//pin num check
              {
                //delay
                if(MyArray[3]=="-s")//samples
                {
                       if(MyArray[4].toInt()<60) 
                       {
                          Serial.print("\n");
                          Serial.print("analog output");
                          for(int k=0; k<MyArray[4].toInt(); k++)
                          {
                          int val = analogRead(MyArray[2].toInt());     // read the input pin
                          Serial.print('\n');
                          Serial.print("Analog val from pin " +MyArray[2]+" = ");
                          Serial.print(val);          
                          delay(1000);
                          }
                          
          
                       }
                       else
                       {
                       Serial.print("\n");
                       Serial.print("Invalid input");
                       }
                       
                }
                 else//4
                 {
                 Serial.print("\n");
                 Serial.print("Invalid input");
                  }
                }
                 else//3
                 {
                 Serial.print("\n");
                 Serial.print("Invalid input");
                  }
              }
              else//2
              {
              Serial.print("\n");
              Serial.print("Invalid input");
              }
          }
          else if(MyArray[0]=="digital")//digital--------------------------
          {
            if(MyArray[1]=="-p")//pin
            {
              if((MyArray[2].toInt()<14)&&(MyArray[2].toInt()>=0))//pin num check
              {
                //delay
                if(MyArray[3]=="-d")//pin
                {
                       if(MyArray[4].toInt()<60000) 
                       {
                          Serial.print("\n");
                          Serial.print("digital output");
                          digitalWrite(MyArray[2].toInt(), HIGH);
                          delay(MyArray[4].toInt());
                          digitalWrite(MyArray[2].toInt(), LOW);
          
                       }
                       else
                       {
                       Serial.print("\n");
                       Serial.print("Invalid input");
                       }
                       
                }
                 else//4
                 {
                 Serial.print("\n");
                 Serial.print("Invalid input");
                  }
                }
                 else//3
                 {
                 Serial.print("\n");
                 Serial.print("Invalid input");
                  }
              }
              else//2
              {
              Serial.print("\n");
              Serial.print("Invalid input");
              }
            }

          else //0
          {
          Serial.print("\n");
          Serial.print("Invalid input");
          }
      //end
          Serial.print("\n");
          Serial.print("bembi@arduino:~$ ");

          input_string = "";

    }
  
     else {
      input_string += c;

    }
  }
}     


void args_to_arr(String TheArray[], int n, String input)
{
 
 String our_line=check_spaces(input);
 int count=0;
 while(count<n)
 {
   int split=get_split(our_line);
   if(split)
   {
   TheArray[count]  = our_line.substring(0, split);
   our_line=check_spaces(our_line.substring(split+1));
   count++;
   }
   else
   {
   TheArray[count]  = our_line;

   break; 
   }
   
   
 }
 
 
 
}
int get_split(String input)
{
for(int i=0; i<input_string.length(); i++)
  {
    if (input.substring(i, i+1) == " ") {
      return i;
      break;
    }
  }
  return 0;  
}






String check_spaces(String line)
{  
  //Serial.print(line[0]);
  while(line[0]==' ')
  {
    line.remove(0,1);
  }
  return line;
}
