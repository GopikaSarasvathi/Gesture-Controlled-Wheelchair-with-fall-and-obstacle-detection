

int xPin   = A3; //X axis input
int yPin   = A2; //Y axis input


int Q1=8,Q2=9,Q3=10,Q4=11; //Output pins to be connected to 10, 11, 12, 13 of Decoder IC

long x; //Variabe for storing X coordinates
long y; //Variabe for storing Y coordinates


void setup()
{
  Serial.begin(9600);
  pinMode(Q1,OUTPUT);
  pinMode(Q2,OUTPUT);  
  pinMode(Q3,OUTPUT);
  pinMode(Q4,OUTPUT);

} 
void loop()
{
  x = analogRead(xPin); //Reads X coordinates
  y = analogRead(yPin); //Reads Y coordinates

    if((x>216 && x<235) && (y>191 && y<214))    // Change the value for adjusting sensitivity  
      front();
    else if((x>224 && x<239) && (y>250 && y<283))   // Change the value for adjusting sensitivity
      back();
    else if((x>199 && x<223) && (y>228 && y<254))   // Change the value for adjusting sensitivity
      left();
    else if((x>245 && x<266) && (y>224&& y<238))   // Change the value for adjusting sensitivity
      right();
    else
     stop_();
}

//Functions

void stop_()
{
  Serial.println("");
  Serial.println("STOP");
  digitalWrite(Q1,LOW);
  digitalWrite(Q2,LOW);
  digitalWrite(Q3,LOW);
  digitalWrite(Q4,LOW);
}
void back()
{
  Serial.println("");
  Serial.println("back");
  digitalWrite(Q1,HIGH);//high
  digitalWrite(Q2,LOW);//high
  digitalWrite(Q3,HIGH);
  digitalWrite(Q4,LOW);
}
void front()
{
  Serial.println("");
  Serial.println("front");
  digitalWrite(Q1,LOW);
  digitalWrite(Q2,HIGH);
  digitalWrite(Q3,LOW);
  digitalWrite(Q4,HIGH);
}
void left()
{
  Serial.println("");
  Serial.println("left");
    digitalWrite(Q1,LOW);
  digitalWrite(Q2,HIGH);
  digitalWrite(Q3,LOW);
  digitalWrite(Q4,LOW);
}
void right()
{
  Serial.println("");
  Serial.println("right");
  digitalWrite(Q1,LOW);
  digitalWrite(Q2,LOW);
  digitalWrite(Q3,LOW);
  digitalWrite(Q4,HIGH);

}
