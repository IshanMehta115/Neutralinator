int buf[10],temp;
unsigned long int avgValue;
float AvgPhValue;
float volume_;
/////////////////////////////////
#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
/////////////////////////////////
byte h=0,v=0;
const int period=50;
int kdelay=0;              
const byte rows=4;         
const byte columns=4;
const byte Output[rows]={8,9,10,11;
const byte Input[columns]={A0,A2,13,A1};
double volume=0;
int point=0;
int p=1;
int enter=0;
//////////////////////////////////
float t;
void setup()
{
  Serial.begin(9600);
  Serial.println("Ready");
  lcd.begin(16,2);
}
void loop()
{
  AvgPhValue=ph();
  delay(5000);
  if(AvgPhValue<6)
  {
    lcd.setCursor(0,0);          
    lcd.print("volume");
    volume_=take_volume();
    lcd.clear();
    lcd.setCursor(0,0);          
    lcd.print(volume_);
    delay(3000);
    t=((volume_)*9)/5;
    t=t*1000;
    pinMode(12,OUTPUT);
    digitalWrite(12,LOW);
    delay(t);
    digitalWrite(12,HIGH);
    while(1)
    {
      
    }
  }
    else
    {
      lcd.clear();
      lcd.setCursor(0,0);          
      lcd.print("Water is safe");
      while(1)
      {
        
      }
  }
}
float ph()
{
  float c=0;
  pinMode(A3,INPUT);
  for(int i=0;i<100;i++)
  {
    float x = analogRead(A3);
    x = 0.0261627*x-3.73418;
    c=c+x;
  }
  c=c/100;
  lcd.setCursor(0,0);          
  lcd.print(c);
  delay(5000);
  return c;
}
byte keypad()                   
  {
    static bool no_press_flag=0;    
    for(byte x=0;x<columns;x++)     
    {
      if (digitalRead(Input[x])==HIGH);   
      else
      break;
      if(x==(columns-1))        
      {
        no_press_flag=1;
        h=0;
        v=0;
      }
    }
    if(no_press_flag==1)  
    {
      for(byte r=0;r<rows;r++)  
      digitalWrite(Output[r],LOW);
      for(h=0;h<columns;h++)  
      {
        if(digitalRead(Input[h])==HIGH) 
        continue;
        else   
        {
          for(v=0;v<rows;v++)    
          {
            digitalWrite(Output[v],HIGH);   
            if(digitalRead(Input[h])==HIGH)  
            {
              no_press_flag=0;               
              for(byte w=0;w<rows;w++)  
              digitalWrite(Output[w],LOW);
              return v*4+h;
            }
          }
        }
      }
    }
    return 50;
  }
float take_volume()
{
  for(byte i=0;i<rows;i++)
  {
  pinMode(Output[i],OUTPUT);
  }
  for(byte s=0;s<columns;s++)
  {
    pinMode(Input[s],INPUT_PULLUP);
  }
  Serial.begin(9600); 
  while(enter==0)
  {
    if(millis()-kdelay>period)
    {
      kdelay=millis();  
      switch (keypad())     
      {
            case 0:
            {
              if(point==0)
              {
                volume=(volume*10)+1;
                lcd.clear();
                lcd.setCursor(0,0);          
                lcd.print(volume);
              }
              else
              {
                p=p*10;
                volume=volume+(float(1)/p);
                lcd.clear();
                lcd.setCursor(0,0);          
                lcd.print(volume);
              }
              Serial.println(volume);
            }
            break;  
            case 1:
            {
              if(point==0)
              {
                volume=(volume*10)+2;
                lcd.clear();
                lcd.setCursor(0,0);          
                lcd.print(volume);
              }
              else
              {
                p=p*10;
                volume=volume+(float(2)/p);
                lcd.clear();
                lcd.setCursor(0,0);          
                lcd.print(volume);
              }
              Serial.println(volume);
            }
            break;
            case 2:
            {
              if(point==0)
              {
                volume=(volume*10)+3;
                lcd.clear();
                lcd.setCursor(0,0);          
                lcd.print(volume);
              }
              else
              {
                p=p*10;
                volume=volume+(float(3)/p);
                lcd.clear();
                lcd.setCursor(0,0);          
                lcd.print(volume);
              }
              Serial.println(volume);
            }
            break;
            case 3:
            {
              if(point==0)
              {
                volume=(volume*10)+4;
                lcd.clear();
                lcd.setCursor(0,0);          
                lcd.print(volume);
              }
              else
              {
                p=p*10;
                volume=volume+(float(4)/p);
                lcd.clear();
                lcd.setCursor(0,0);          
                lcd.print(volume);
              }
              Serial.println(volume);
            }
            break;
            case 4:
            {
              if(point==0)
              {
                volume=(volume*10)+5;
                lcd.clear();
                lcd.setCursor(0,0);          
                lcd.print(volume);
              }
              else
              {
                p=p*10;
                volume=volume+(float(5)/p);
                lcd.clear();
                lcd.setCursor(0,0);          
                lcd.print(volume);
              }
              Serial.println(volume);
            }
            break;
            case 5:
            {
              if(point==0)
              {
                volume=(volume*10)+6;
                lcd.clear();
                lcd.setCursor(0,0);          
                lcd.print(volume);
              }
              else
              {
                p=p*10;
                volume=volume+(float(6)/p);
                lcd.clear();
                lcd.setCursor(0,0);          
                lcd.print(volume);
              }
              Serial.println(volume);
            }
            break;
            case 6:
            {
              if(point==0)
              {
                volume=(volume*10)+7;
                lcd.clear();
                lcd.setCursor(0,0);          
                lcd.print(volume);
              }
              else
              {
                p=p*10;
                volume=volume+(float(7)/p);
                lcd.clear();
                lcd.setCursor(0,0);          
                lcd.print(volume);
              }
              Serial.println(volume);
            }
            break;
            case 7:
            {
              if(point==0)
              {
                volume=(volume*10)+8;
                lcd.clear();
                lcd.setCursor(0,0);          
                lcd.print(volume);
              }
              else
              {
                p=p*10;
                volume=volume+(float(8)/p);
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print(volume);
              }
              Serial.println(volume);
            }
            break;
            case 8:
            {
              if(point==0)
              {
                volume=(volume*10)+9;
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print(volume);
              }
              else
              {
                p=p*10;
                volume=volume+(float(9)/p);
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print(volume);
              }
              Serial.println(volume);
            }
            break;
            case 9:
            {
              if(point==0)
              {
                volume=(volume*10)+0;
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print(volume);
              }
              else
              {
                p=p*10;
                volume=volume+(float(0)/p);
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print(volume);
              }
              Serial.println(volume);
            }
            break;
            case 10:
            {
              point=1;
            }
            break;
            case 11:
            enter=1;
            break;
            case 12:
            {
              
            }
            break;
            case 13:
            {
              
            }
            break;
            case 14:
            {
              
            }
            break;
            case 15:
            {
              
            }
            break;
            default:
            ;
      }
    }
  }
  return volume;
}
