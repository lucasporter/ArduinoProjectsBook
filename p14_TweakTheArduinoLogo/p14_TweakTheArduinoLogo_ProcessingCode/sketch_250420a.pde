import processing.serial.*;
Serial myPort;
PImage logo;
int bgcolor = 0;

void setup() {
  size(1, 1);
  surface.setResizable(true);
  colorMode(HSB, 255);
  logo = loadImage("https://upload.wikimedia.org/wikipedia/commons/thumb/8/87/Arduino_Logo.svg/720px-Arduino_Logo.svg.png?20200922062315");
  surface.setSize(logo.width, logo.height);
  
  println("Available serial ports:");
  println(Serial.list());

  myPort = new Serial(this, Serial.list()[0], 9600);
}

void draw() {
  if ( myPort.available() > 0) {
    bgcolor = myPort.read();
    println(bgcolor);
  }
  
  background(bgcolor, 255, 255);
  image(logo, 0, 0);
}
