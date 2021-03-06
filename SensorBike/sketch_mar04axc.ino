long dis;
long tiem;
int LED = 11;
int buzzer = 6; 
int LDR = A0;
int valor;    // Variable que acumula el valor de la entrada analógica A0
  
// Ajuste de los valores propios, máximo y mínimo, del LDR.
int maximo = 1000;  // Valor máximo que da la foto-resistencia en A0 (con plena luz)
int minimo = 0;  // Valor mínimo que da la foto-resistencia en A0 (sin luz)
  
void setup( ){ 
Serial.begin(9600);
pinMode(10, OUTPUT); //salida del pulso generado por el sensor ultrasónico
pinMode(9, INPUT);//entrada del pulso generado por el sensor ultrasónico
pinMode(11, OUTPUT);//alarma de la distancia(encenderá el led)
pinMode(6, OUTPUT);
pinMode(LDR, INPUT);
}
void loop(){
digitalWrite(10,LOW);//recibimiento del pulso.
delayMicroseconds(5);
digitalWrite(10, HIGH);//envió del pulso.
delayMicroseconds(10);
tiem=pulseIn(9, HIGH);//fórmula para medir el pulso entrante.
dis= long(0.017*tiem);//fórmula para calcular la distancia del sensor ultrasónico.
if(dis>100){ //comparativo para la alarma se ingresa la distancia en la que encenderá o apagara.
digitalWrite(11, LOW);
digitalWrite(6, LOW);
}
else
{
digitalWrite(11,HIGH);
digitalWrite(6, HIGH);
}
// Leemos el valor del LDR
       valor = analogRead(LDR);     
       // Limitamos el valor entre el máximo y el mínimo
       valor = constrain(valor, minimo, maximo);
       // Mostramos a través del monitor serie el valor para ajustar máx y min.
       Serial.println(valor);
       // Acomodamos el valor leido y ajustado, a un valor proporcional entre 0 y 255
       // - Cuando hay plena luz (máximo) --> Valor = 0
       // - Cuando no hay luz (mínimo) --> Valor = 255
       Serial.println("LA DISTANCIA MEDIDA ES:");
       Serial.println(dis);
       Serial.println("valor");
       delay(500); 
       valor = map(valor, maximo, minimo, 0, 1000);
       // Aplicamos el valor obtenido a un LED mediante PWM
       analogWrite(LED, valor);  
      }       
