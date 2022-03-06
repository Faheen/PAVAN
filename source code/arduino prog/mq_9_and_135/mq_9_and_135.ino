int mq9 = A0;
int mq135 = A3;
float R0 = 0.50;
void setup() {
  Serial.begin(9600);
  pinMode(mq9,INPUT);
  pinMode(mq135,INPUT);
}
 
void loop() {
  
  float sensor_volt;
  float RS_gas; // Get value of RS in a GAS
  float ratio; // Get ratio RS_GAS/RS_air
  int sensorValue9 = analogRead(A0);
  int sensorValue135 = analogRead(A3);
  sensor_volt=(float)sensorValue9/1024*5.0;
  RS_gas = (5.0-sensor_volt)/sensor_volt; // omit *RL
  
  /*-Replace the name "R0" with the value of R0 in the demo of First Test -*/
  ratio = RS_gas/R0;  // ratio = RS/R0 
  /*-----------------------------------------------------------------------*/
  Serial.println("MQ-9 CARBON VALUE");
  Serial.print("sensor_volt = ");
  Serial.println(sensor_volt);
  Serial.print("RS_ratio = ");
  Serial.println(RS_gas);
  Serial.print("Rs/R0 = ");
  Serial.println(ratio);
  
  Serial.print("\n\n");

  Serial.println("MQ-135 NITROGEN VALUE");
  Serial.print("SENSOR VALUE =  ");
  Serial.println(sensorValue135);

  Serial.print("\n\n");
  
  delay(1000);

}

