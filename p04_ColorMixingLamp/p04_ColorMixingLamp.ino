const int greenLEDPin=9;
const int redLEDPin=10;
const int blueLEDPin=11;

const int redSensorPin=A0;
const int greenSensorPin=A1;
const int blueSensorPin=A2;

int redValue=0;
int greenValue=0;
int blueValue=0;

int redSensorValue=0;
int greenSensorValue=0;
int blueSensorValue=0;

void setup() {
Serial.begin(9600);

pinMode(greenLEDPin, OUTPUT);
pinMode(redLEDPin, OUTPUT);
pinMode(blueLEDPin, OUTPUT);
}

void loop() {
redSensorValue=analogRead(redSensorPin);
greenSensorValue=analogRead(greenSensorPin);
blueSensorValue=analogRead(blueSensorPin);

Serial.print("Raw Sensor Values \t red: ");
Serial.print(redSensorValue);
Serial.print("\t green: ");
Serial.print(greenSensorValue);
Serial.print("\t blue: ");
Serial.println(blueSensorValue);

redValue=redSensorValue/4;                                    
greenValue=greenSensorValue/4;
blueValue=blueSensorValue/4;                                      

Serial.print("Mapped Sensor Values \t red: ");
Serial.print(redValue);
Serial.print("\t green: ");
Serial.print(greenValue);
Serial.print("\t blue: ");
Serial.println(blueValue);

analogWrite(redLEDPin, redValue);
analogWrite(greenLEDPin, greenValue);
analogWrite(blueLEDPin, blueValue);

}
