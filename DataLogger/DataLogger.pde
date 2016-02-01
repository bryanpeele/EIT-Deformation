import processing.serial.*;
import java.util.LinkedList;
import java.util.ListIterator;

Serial portPmodIA;

String data;
String resistance;
String reactance;
String freq;
Float magnitude;
int time;
int startTime;
int recordTime;
int interval = 200;
boolean record = false;
PrintWriter output;

float maxRes = 20000.0;

LinkedList resData = new LinkedList();
LinkedList reacData = new LinkedList();
LinkedList magData = new LinkedList();

void setup() {
  //size(1200,950,P2D);
  fullScreen();
  println(Serial.list());
  portPmodIA = new Serial(this, Serial.list()[0], 115200);
  portPmodIA.bufferUntil('\n');
  time = millis();
  
  for (int i = 0; i<50; i++) {
    resData.add(0.0);
    reacData.add(0.0);
    magData.add(0.0);
  }
  
  portPmodIA.write("A");

}

void draw() {  
  
   
  
   if(millis() - time >= interval) {
      portPmodIA.write("C");
      time = millis();
      delay(50);
     if(record  && data!= null) {
        output.println(millis()+","+freq+","+resistance+","+reactance+","+magnitude);
       }
       if (data !=null) {
        resData.removeFirst();
        resData.add(float(resistance));
        reacData.removeFirst();
        reacData.add(float(reactance));
        magData.removeFirst();
        magData.add(magnitude);
        System.out.println(magnitude);
       }
        
        noFill();
        background(50);
         strokeWeight(3);
         
         // Plot resistance
         stroke(250,50,250);
         float newRes= 0.0;
         ListIterator iter = resData.listIterator();
         float oldRes = ((Float) iter.next()).floatValue();
         int index = 1;
         while (iter.hasNext()) {
           newRes = ((Float) iter.next()).floatValue();
           float xPosNew = map(index,0,50,0,width);
           float yPosNew = map(newRes,-maxRes,maxRes,height-75,75);
           float xPosOld = map(index-1,0,50,0,width);
           float yPosOld = map(oldRes,-maxRes,maxRes,height-75,75);
           line(xPosOld,yPosOld,xPosNew,yPosNew);
           index++;
           oldRes = newRes;
         }
         textSize(30);
         fill(250,50,250);
         text("Resistance: "+newRes, 10, 50);

         // Plot reactance
         stroke(50,50,250);
         float newReac= 0.0;
         ListIterator iter2 = reacData.listIterator();
         float oldReac = ((Float) iter2.next()).floatValue();
         index = 1;
         while (iter2.hasNext()) {
           newReac = ((Float) iter2.next()).floatValue();
           float xPosNew = map(index,0,50,0,width);
           float yPosNew = map(newReac,-maxRes,maxRes,height-75,75);
           float xPosOld = map(index-1,0,50,0,width);
           float yPosOld = map(oldReac,-maxRes,maxRes,height-75,75);
           line(xPosOld,yPosOld,xPosNew,yPosNew);
           index++;
           oldReac = newReac;
         }
         textSize(30);
         fill(50,50,250);
         text("Reactance: "+newReac, 360, 50);


         // Plot magnitdue
         stroke(250,50,50);
         float newMag= 0.0;
         ListIterator iter3 = magData.listIterator();
         float oldMag = ((Float) iter3.next()).floatValue();
         index = 1;
         while (iter3.hasNext()) {
           newMag = ((Float) iter3.next()).floatValue();
           float xPosNew = map(index,0,50,0,width);
           float yPosNew = map(newMag,-maxRes,maxRes,height-75,75);
           float xPosOld = map(index-1,0,50,0,width);
           float yPosOld = map(oldMag,-maxRes,maxRes,height-75,75);
           line(xPosOld,yPosOld,xPosNew,yPosNew);
           index++;
           oldMag = newMag;
         }
         textSize(30);
         fill(250,50,50);
         text("Magnitude: "+newMag, 710, 50);


  
         stroke(100,250,100,75);
         strokeWeight(1);
         line(0,75,width,75);
         line(0,height/2,width,height/2);
         line(0,height-75,width,height-75);
   
  
         fill(100,250,100,200);
         textSize(15);
         text("Max: "+maxRes, width-200, 70);
         
         if (record==true) {
                   textSize(30);
                   fill(250,250,250);
                   text("RECORDING", 60, height-30);
                   ellipse(30,height-40,30,30);
                   fill(200,50,50);
                   ellipse(30,height-40,25,25);
         }

   }
   
}

void serialEvent(Serial portPmodIA) {
  data = portPmodIA.readStringUntil('\n');
  String[] dataList = split(data,";");
  freq = dataList[0];  
  resistance = dataList[1];
  reactance = dataList[2];
  magnitude = sqrt(pow(float(resistance),2)+pow(float(reactance),2));
}

void keyPressed() {

  if (key == 'r' || key == 'R') {
    record = true;
    println("Recording Started!");
    int year = year();
    int month = month();
    int day = day();
    int hour = hour();
    int minute = minute();
    int seconds = second();
    String filename = "ImpedanceData";  
    output = createWriter(filename+"-"+str(year)+"-"+str(month)+"-"+str(day)+"-"+str(hour)+"-"+str(minute)+"-"+str(seconds)+".csv"); 
    output.println("millis,frequency,resistance,reactance,magnitude");

    
    
  } else if (key == 's' || key == 'S') {
      endFile();
  } else if (key == 'p' || key == 'P') {
      maxRes += 1000;
  } else if (key == 'l' || key == 'L') {
      maxRes -= 1000;
  } else if (key == 'o' || key == 'O') {
      maxRes += 100;
  } else if (key == 'k' || key == 'K') {
      maxRes -= 100;
  } else if (key == 'i' || key == 'I') {
      maxRes += 10;
  } else if (key == 'j' || key == 'J') {
      maxRes -= 10;
  }
  
}

void endFile() {
    record = false;
    output.flush();
    output.close(); 
    println("Recording Ended!");
  
}