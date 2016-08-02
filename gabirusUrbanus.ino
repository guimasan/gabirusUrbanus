
/*
***************************************<<>>><<<<<<
* GypsyLab 8 - gypsylab8.wordpress.com
* Oficina Gabirus Urbanus
*201607 - SESCSP Santana.
*********************************<<<<>>><<<
*/

int motor1A = 2;
int motor1B = 3;
int motor2A = 4;
int motor2B = 5;
int led = 9;
int eye1 = A0;
int eye2 = A1;
int pot = A3;

int potX, eye1X, eye2X;

//configuracoes
void setup() {                
  // initialize the digital pin as an output.
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(pot, INPUT);
  pinMode(eye1, INPUT);  
  pinMode(eye2, INPUT);
  Serial.begin(9600);
  potX = analogRead(pot);
  eye1X = analogRead(eye1);
  eye2X = analogRead(eye2);
  //Brilho LED 
  analogWrite(led, potX/4);
}
//parte do codigo q fica em execucao constante
void loop() {
  int potY = analogRead(pot);
  int eye1Y = analogRead(eye1);
  int eye2Y = analogRead(eye2);
  
  analogWrite(led, pot/4);

//escreve na porta serial para leitura dos valores e calibraçao do numero de constraste quando detecta obstculo ou o interesse, adotamos como exemplo 500 nesse codigo;
  Serial.print(eye1Y);
  Serial.print("\t");
  Serial.println(eye2Y);

//para superficies claras e linha escura  
  if(eye1Y < 500){
    digitalWrite(motor1A, HIGH);
    digitalWrite(motor1B, LOW);
    digitalWrite(motor2A, LOW);
    digitalWrite(motor2B, HIGH);
  } else if(eye2Y < 500){
    digitalWrite(motor1A, LOW);
    digitalWrite(motor1B, HIGH);
    digitalWrite(motor2A, HIGH);
    digitalWrite(motor2B, LOW);
  }else if(eye1Y <500 && eye2Y <500){
    //caso os dois olhos escureçam (ou clareiem basta mudar o sentido) vai pra tras
    digitalWrite(motor1A, HIGH);
    digitalWrite(motor1B, LOW);
    digitalWrite(motor2A, HIGH);
    digitalWrite(motor2B, LOW);
  } else{
  //por padrao os motores apontam pra frente
    digitalWrite(motor1A, HIGH);
    digitalWrite(motor1B, LOW);
    digitalWrite(motor2A, HIGH);
    digitalWrite(motor2B, LOW);
  }
}
