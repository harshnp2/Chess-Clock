#include <LiquidCrystal.h>
int buttonPin1 = 13, buttonPin2 = 4;
int buttonRead1, buttonRead2;
int rs = 12, e = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs,e,d4,d5,d6,d7);
int TimeA[] = {0,0}, TimeB[] = {0,0};
int minPlacementA = 1, secPlacementA = 5;
int minPlacementB = 10, secPlacementB = 14;
int finished = 1, finished2 = 1, reset = 1, play = 0;
int OGTimeB, OGTimeA;
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);

}

void loop() {
do{
  buttonRead1 = digitalRead(buttonPin1);
  buttonRead2 = digitalRead(buttonPin2);
  Serial.print(buttonRead1);
  Serial.print(", ");
  Serial.println(buttonRead2);
  delay(200);
  lcd.setCursor(0,0);
  lcd.print("Insert time");
  if(TimeA[0] < 10){
  lcd.setCursor(0,1);
  lcd.print("0");
  minPlacementA = 1;
  }
  else if(TimeA[0] >= 10){
    minPlacementA = 0;
  }
    
  lcd.setCursor(minPlacementA,1);
  lcd.print(TimeA[0]);
  lcd.setCursor(2,1);
  lcd.print(":");
  if(TimeA[1] < 10){
  lcd.setCursor(4,1);
  lcd.print("0");
  secPlacementA = 5;
  }
  else if(TimeA[1] >= 10){
    secPlacementA = 4;
  }
  lcd.setCursor(secPlacementA,1);
  lcd.print(TimeA[1]);
  

  if(TimeB[0] < 10){
  lcd.setCursor(9,1);
  lcd.print("0");
  minPlacementB = 10;
  }
  else if(TimeB[0] >= 10){
    minPlacementB = 9;
  }
  lcd.setCursor(minPlacementB,1);
  lcd.print(TimeB[0]);
  lcd.setCursor(11,1);
  lcd.print(":");
  if(TimeB[1] < 10){
    lcd.setCursor(13,1);
    lcd.print("0");
    secPlacementB = 14;
  }
  else if(TimeB[1] >= 10){
    secPlacementB = 13;
  }
  lcd.setCursor(secPlacementB,1);
  lcd.print(TimeB[1]);

  if(buttonRead1 == 0 && buttonRead2 == 1){
    TimeA[0]++;
  }

  else if(buttonRead2 == 0 && buttonRead1 == 1){
    TimeB[0]++;
  }

 
}while(buttonRead1 == 1 or buttonRead2 == 1 && play == 0);
lcd.clear();
if(buttonRead1 == 0 && buttonRead2 == 0){
  lcd.clear();
  do{
  for(TimeA[1] + 1; TimeA[1] >= 0; TimeA[1] --){
    buttonRead1 = digitalRead(buttonPin1);
    buttonRead2 = digitalRead(buttonPin2);
    Serial.print(buttonRead1);
    Serial.print(", ");
    Serial.println(buttonRead2);

    if(TimeA[0] < 10){
      lcd.setCursor(0,1);
      lcd.print("0");
    }
    lcd.setCursor(minPlacementA,1);
    lcd.print(TimeA[0]);
    lcd.setCursor(2,1);
    lcd.print(":");
    if(TimeA[1] < 10){
      lcd.setCursor(4,1);
      lcd.print("0");
      secPlacementA = 5;
    }
    else if(TimeA[1] >= 10){
      secPlacementA = 4;
    }
    lcd.setCursor(secPlacementA,1);
    lcd.print(TimeA[1]);

    if(TimeB[0] < 10){
      lcd.setCursor(9,1);
      lcd.print("0");
    }
    lcd.setCursor(minPlacementB,1);
    lcd.print(TimeB[0]);
    lcd.setCursor(11,1);
    lcd.print(":");
    if(TimeB[1] < 10){
      lcd.setCursor(13,1);
      lcd.print("0");
      secPlacementB = 14;
    }
    else if(TimeB[1] >= 10){
      secPlacementB = 13;
    }
    lcd.setCursor(secPlacementB,1);
    lcd.print(TimeB[1]);
    delay(1000);
    lcd.clear();

    if(TimeA[0] > 0 && TimeA[1] == 0){
        TimeA[0]--;
        TimeA[1] = 60;
    }

    if(buttonRead1 == 0 && buttonRead2 == 1){
      do{
      for(TimeB[1]; TimeB[1] >= 0; TimeB[1]--){
      buttonRead1 = digitalRead(buttonPin1);
      buttonRead2 = digitalRead(buttonPin2);
      Serial.print(buttonRead1);
      Serial.print(", ");
      Serial.println(buttonRead2);
      if(TimeA[0] < 10){
        lcd.setCursor(0,1);
        lcd.print("0");
      }
      lcd.setCursor(minPlacementA,1);
      lcd.print(TimeA[0]);
      lcd.setCursor(2,1);
      lcd.print(":");
      if(TimeA[1] < 10){
        lcd.setCursor(4,1);
        lcd.print("0");
        secPlacementA = 5;
      }
      else if(TimeA[1] >= 10){
        secPlacementA = 4;
      }
      lcd.setCursor(secPlacementA,1);
      lcd.print(TimeA[1]);
  
      if(TimeB[0] < 10){
        lcd.setCursor(9,1);
        lcd.print("0");
      }
      lcd.setCursor(minPlacementB,1);
      lcd.print(TimeB[0]);
      lcd.setCursor(11,1);
      lcd.print(":");
      if(TimeB[1] < 10){
        lcd.setCursor(13,1);
        lcd.print("0");
        secPlacementB = 14;
      }
      else if(TimeB[1] >= 10){
        secPlacementB = 13;
      }
      lcd.setCursor(secPlacementB,1);
      lcd.print(TimeB[1]);
      delay(1000);
      lcd.clear();

      if(TimeB[0] > 0 && TimeB[1] == 0){
        TimeB[0]--;
        TimeB[1] = 60;
      }

       if(buttonRead2 == 0 && buttonRead1 == 1){
        finished2 = 0;
        OGTimeB = TimeB[1];
        TimeB[1] = -1;
       }

      if((TimeB[0] == 0) && (TimeB[1] == 0)){
        TimeB[1] = 0;
        finished2 = 0;
        finished = 0;
        reset = 1;
        OGTimeA = TimeA[1];
        TimeA[1] = 0;
      }

      }
      TimeB[1] = OGTimeB;
      }while(finished2 == 1);
      finished2 = 1; 
    }
    

    if((TimeA[0] == 0) && (TimeA[1] == 0)){
      finished = 0;
      reset = 1;
    }

    
  }
  TimeA[1] = OGTimeA;
  }while(finished == 1);
}
if(OGTimeA == 0){
  do{
    buttonRead1 = digitalRead(buttonPin1);
    buttonRead2 = digitalRead(buttonPin2);
    Serial.print(buttonRead1);
    Serial.print(", ");
    Serial.println(buttonRead2);
    lcd.setCursor(0,0);
    lcd.print("Player 1 lost,");
    lcd.setCursor(0,1);
    lcd.print("they suck!");
    delay(2000);
    lcd.clear();

    buttonRead1 = digitalRead(buttonPin1);
    buttonRead2 = digitalRead(buttonPin2);
    Serial.print(buttonRead1);
    Serial.print(", ");
    Serial.println(buttonRead2);
    lcd.setCursor(0,0);
    lcd.print("Press button 1");
    lcd.setCursor(0,1);
    lcd.print("to reset");
    delay(2000);
    lcd.clear();

    if(buttonRead1 == 0){
      reset = 0;
      play = 0;
      TimeA[0] = 0;
      TimeA[1] = 0;
      TimeB[0] = 0;
      TimeB[1] = 0;
   
    }
    
  }while(reset == 1);
}

if(OGTimeB == 0){
  do{
    buttonRead1 = digitalRead(buttonPin1);
    buttonRead2 = digitalRead(buttonPin2);
    Serial.print(buttonRead1);
    Serial.print(", ");
    Serial.println(buttonRead2);
    lcd.setCursor(0,0);
    lcd.print("Player 2 lost,");
    lcd.setCursor(0,1);
    lcd.print("they suck!");
    delay(2000);
    lcd.clear();

    buttonRead1 = digitalRead(buttonPin1);
    buttonRead2 = digitalRead(buttonPin2);
    Serial.print(buttonRead1);
    Serial.print(", ");
    Serial.println(buttonRead2);
    lcd.setCursor(0,0);
    lcd.print("Press button 2");
    lcd.setCursor(0,1);
    lcd.print("to reset");
    delay(2000);
    lcd.clear();

    if(buttonRead2 == 0){
      reset = 0;
      play = 0;
      TimeA[0] = 0;
      TimeA[1] = 0;
      TimeB[0] = 0;
      TimeB[1] = 0;
    }
    
  }while(reset == 1);
}

  

}
