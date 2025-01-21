const byte POWER_LED = 2;
const byte POWER_BUTTON = 3;
const byte SENSOR_PIR = 4; 
const byte BUZZER = 5;

const byte STANDBY = 0;
const byte POWER_ON = 1;
const byte ALARM_ON = 2;
const byte PIR_DETECT = 3;

const byte DEBUG = true;

byte alarmState;

void setup() {
  Serial.begin(9600);
  
  if(DEBUG) Serial.println("A inicializar o alarme...")
  
  pinMode(POWER_LED, OUTPUT);
  pinMode(POWER_BUTTON, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(PIR_SENSOR, INPUT);

  alarmState = STANDBY;
  
  digitalWrite(POWER_LED, LOW);
  
  if(DEBUG) Serial.println("Alarme Inicializando...)
}

void loop() {
  switch(alarmState)
    case STANDBY;
  	 if(DEBUG) Serial.println("Standby");
  
  	 if(digitalRead(POWER_BUTTON) == false) alarmState = POWER_ON;
     break;
	}
	case POWER_ON: {
      if(DEBUG) Serial.println("Power ON");
      
      digitalWrite(POWER_LED, LOW);
      delay(3000);
      alarmState = ALARM_ON;
      break;
    }
	case ALARM_ON: {
      if(DEBUG) Serial.println("Alarm ON");
      
      if(digitalRead(PIR_SENSOR) == true) {
      	alarmState = PIR_DETECT;
      }
      
      break;
    }
	case PIR_DETECT: {
      if(DEBUG) Serial.println("PIR Detect");
      
      for(int i = 700; i<800; i++){
        tone(BUZZER, i);
        delay(15);
      }
      for(int i = 800; i> 700; i--){
        tone(BUZZER, i);
        delay(15);
      }
      
      noTone(BUZZER);
      
      alarmState = ALARM_ON;
      
      break;
    }
   }
  }