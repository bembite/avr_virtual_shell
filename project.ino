#define led 13
String input_string = "";
const String Led_off = "switch led off";
const String Led_on = "switch led on";
const String Help = "help";



bool led_running;

void setup() {
  Serial.begin(9600);
    pinMode(led, OUTPUT);
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

 




    
    Serial.print("\nbembi@arduino:~$ ");

    
}

void loop() {
  while (Serial.available() > 0) {
    char c = Serial.read();
    if (c == '\n') { 
      //Serial.print("bembi@arduino:~$ ");
      Serial.print(input_string);
      switch ( parse(input_string, Led_off, Led_on) ) {
        case 10:
          led_running=false;
          Serial.println("\nSwitching off is done");
          break;
        case 11:
          led_running=true;
          Serial.println("\nSwitching on is done");
          break;
        case 01:
         Serial.print("commands:");
         Serial.print("\n"+Led_on+" ");
         Serial.print("  Turns on light at build in led      ");
         Serial.print("\n"+Led_off+" ");
         Serial.print("  Turns off light at build in led      ");
         Serial.print("\n");
         break;
        case 0:
          Serial.println("\ninvalid String");
          break;
      }
      Serial.print("bembi@arduino:~$ ");

      input_string = "";
         if(led_running)
      {
              digitalWrite(led, HIGH);

      }
     else {
              digitalWrite(led, LOW);

              
    }
    } else {
      input_string += c;

    }

  }
}

byte parse(String input_string, const String Led_off, const String Led_on) {
  if (input_string.equals(Led_off) == true) {
    return 10;
  }
  else if (input_string.equals(Led_on) == true) {
    return 11;
  }
    else if (input_string.equals(Help) == true) {
    return 01;
  }
  
  else return 0;
}
