#define PIN_CHECK_WEIGHT 11
#define LED_3_LV 10
#define LED_2_LV 9
#define LED_1_LV 8
#define MX1508_O1 7
#define MX1508_O2 6
#define PIN_WEIGHT 5
#define GERC_DETECT 18
#define BTN_LV3 19
#define BTN_LV2 20
#define BTN_LV1 21

bool isRunning = false;
bool isGainedWeight = false;
int level_list[10];
int spid = 120;
var direction "None";
int levelsToGo = 0; //Если не 1, а больше, то после срабатывания датчика едем в этом же направлении еще этаж.
int arrayLevel = 0;//На каком элементе массива на данный момент висит лифт
volatile boolean actionState = LOW;//что-то нужное

void setup() {
  
  // put your setup code here, to run once:
  pinMode(MX1508_O1, OUTPUT);    // Устанавливаем MX1508_O1 как выход
  pinMode(MX1508_O2, OUTPUT);    // Устанавливаем MX1508_O2 как выход
  attachInterrupt(2, when_BTN_LV1, RISING);
  attachInterrupt(3, when_BTN_LV2, RISING);
  attachInterrupt(4, when_BTN_LV3, RISING);
  attachInterrupt(5, when_GERC_DETECT, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (isRunning=true){
    switch(direction){
      case "Up":
      while(levlsToGo > 0){
    analogWrite(MX1508_O1,LOW);  //ехаем вперед
    analogWrite(MX1508_O2 ,spid); 
        
      }
      break;
      case "Down":
      
      break;
      default:

      break;
    }
  }
}

void when_BTN_LV1() {
actionState != actionState; //
     addToList(1);
}

void when_BTN_LV2() {
actionState != actionState; //
     addToList(2);
}
void when_BTN_LV3() {
actionState != actionState; //
     addToList(3);
}
void when_GERC_DETECT() {
actionState != actionState; //
          // Уменьшаем levelsToGo.
        levelsToGo--;
        if(levelToGo<=0){
          levelToGo=0;
          isRunning=false;
          delay(7000);
        }
        
digitalWrite(PIN_LED, actionState);
}

void addToList(int newLevelTask){
  
}

  
