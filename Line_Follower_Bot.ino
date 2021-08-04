//Line follower bot using 2 IR sensors
//Motor Connections
//Right
int enableR = 3;
int in1R = 6;
int in2R = 7;
//Left
int enableL = 5;
int in1L = 8;
int in2L = 10;
//Sensor Pins
int ir_left = 11;
int ir_right = 2;
int sensor_left;
int sensor_right;
void setup() {
  pinMode(enableR, OUTPUT);
  pinMode(in1R,OUTPUT);
  pinMode(in2R,OUTPUT);
  pinMode(enableL, OUTPUT);
  pinMode(in1L,OUTPUT);
  pinMode(in2L,OUTPUT);
  pinMode(ir_right,INPUT);
  pinMode(ir_left,INPUT);
  digitalWrite(enableR,HIGH);
  digitalWrite(enableL,HIGH);
}
void loop() {
  sensor_left = digitalRead(ir_left);//Getting readings from both the sensors
  sensor_right = digitalRead(ir_right);
  //0 is white and 1 is black
  if (sensor_left == 0 && sensor_right == 0){// Both sense white
    front();//Move forward
  }
  else if (sensor_left == 1 && sensor_right == 1){//Both sense black
    hault();//Stop
  }
  else if (sensor_left == 1 && sensor_right == 0){//Left senses black
    left();//Move left
    delayMicroseconds(100);
  }
  else if (sensor_left == 0 && sensor_right == 1){//Right senses black
    right();//Move right
    delayMicroseconds(100);
  }
}
void right()
{
  digitalWrite(in1R,HIGH);
  digitalWrite(in2R,LOW);
  digitalWrite(in1L,LOW);
  digitalWrite(in2L,HIGH);
}
void left()
{
  digitalWrite(in1R,LOW);
  digitalWrite(in2R,HIGH);
  digitalWrite(in1L,HIGH);
  digitalWrite(in2L,LOW);
}
void hault()
{
  digitalWrite(in1R,LOW);
  digitalWrite(in2R,LOW);
  digitalWrite(in1L,LOW);
  digitalWrite(in2L,LOW);
}
void front()
{
  digitalWrite(in1R,LOW);
  digitalWrite(in2R,HIGH);
  digitalWrite(in1L,LOW);
  digitalWrite(in2L,HIGH);
}
