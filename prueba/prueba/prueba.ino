#include <LiquidCrystal.h>
LiquidCrystal lcd(11, 10, 5, 6, 7, 8);//(rs,enable,d4,d5,d6,d7)
int lectura=0;
int ledPin1 = 2;
int ledPin2 = 3;
int ledPin3 = 4;
int buzzer=9;
int tonos[]={2200, 523, 2093};

void setup() {
  Serial.begin(9600);//abre el puerto serie y fija la velocidad  en baudios para la transmision de datos en serie
                      // velicidad 9600bps
  pinMode(ledPin1, OUTPUT);//establece el ledPin1 como una salida
  pinMode(ledPin2, OUTPUT);//establece el ledPin2 como una salida
  pinMode(ledPin3, OUTPUT);//establece el ledPin3 como una salida
  pinMode(buzzer, OUTPUT);// establece el buzzer como una salida
  lcd.begin(16, 2); //inicializa la interface para el LCD screen, y determina sus dimensiones (ancho y alto) del display
}

void loop() {
  lectura=analogRead(A0);
  //Serial.println(lectura);// envia el valor "lectura" al puerto
  lcd.print("proyeco de tele");// imprime "proyeco de tele"
  lcd.setCursor(0,1);// setea la ubicacion del cursor columna 0 linea 1 en el lcd
  lcd.print("comunicaciones");// imprime "comunicaciones"
  delay(4000);//4 segundos tiempo de espera
  lcd.clear();//limpia pantalla
  //lcd.print(lectura);//imprime la lectura
  if(lectura < 500){
  digitalWrite(ledPin1, LOW);//led apagado
  digitalWrite(ledPin2, LOW);//led apagado
  digitalWrite(ledPin3, LOW);//led apagado 
  //lcd.print("no tomo");// imprime "no tomo"
  //lcd.setCursor(0,1);
  //lcd.print(lectura);// imprime el nivel de alcohol
  }
  else if(lectura >= 500 && lectura < 700){
  digitalWrite(ledPin1, HIGH);//led encendido
  digitalWrite(ledPin2, LOW);//led apagado
  digitalWrite(ledPin3, LOW);//led apagadoj
  if(digitalRead(ledPin1)==HIGH){
    tone(buzzer, tonos[0]);//enciende el buzzer con el tono de la frecuencia   
    delay(1000);
  }
  lcd.print("a tomado ");//imprime "a tomado cerveza"
  lcd.print("cerveza");
  lcd.setCursor(0,1);
  lcd.print(lectura);//imprime el nivel de alcohol
  Serial.print("A tomado" + lectura);
  }
  else if(lectura >= 700 && lectura < 800){
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, LOW);
  if(digitalRead(ledPin2)==HIGH){
    tone(buzzer, tonos[1]);//enciende el buzzer con el tono de la frecuencia   
    delay(1000);
  }
  lcd.print("tomo muchas cervezas");//imprime "tomo muchas cervezas"
  tone(buzzer, tonos[1]);//enciende el buzzer con el tono de la frecuencia 
  lcd.setCursor(0,1);
  lcd.print(lectura);//imprime el nivel de alcohol
  Serial.print("tomo mucho" + lectura);
  }
  else if(lectura >= 800){
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  if(digitalRead(ledPin3)==HIGH){
    tone(buzzer, tonos[2]);//enciende el buzzer con el tono de la frecuencia   
    delay(1000);
  }
  tone(buzzer, tonos[2]);//enciende el buzzer con el tono de la frecuencia 
  lcd.print("estas borracho");//imprime "estas borracho"
  lcd.setCursor(0,1);
  lcd.print(lectura);//imprime el nivel de alcohol
  Serial.print("Esta borracho" + lectura);
  }
  delay(3000);
  noTone(buzzer);//silencia el buzzer
  lcd.clear();
}
