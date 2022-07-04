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
#define llength 10;

bool isRunning = false;
bool isGainedWeight = false;
int level_list[llength];
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
    analogWrite(MX1508_O1,LOW);  //ехаем вверх
    analogWrite(MX1508_O2 ,spid); 
        
      }
      break;
      case "Down":
      while(levlsToGo > 0){
    analogWrite(MX1508_O2,LOW);  //ехаем вниз
    analogWrite(MX1508_O1 ,spid); 
        
      }
      break;
      default:
      //вот этого быть не должно
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
  //туду
  level_list[arrayLevel] = newLevelTask;
  arrayLevel++
  if(arrayLevel >= llength){
    arrayLevel=0;
  }
  
}
void compare(){
  
  //модуль разницы предыдущего и текущего этажа
  //
}

void addToListShift(int newLevelTask){//добовляем элемент
  int counter = 0;
  bool addFlag = false;
  while(counter < llength && !addFlag){
    if(level_list[counter] == -1){
      level_list[counter] = newLevelTask;
      addFlag = true; 
    }
  }
  if(!addFlag){
    removeToListShift();
    level_list[llength -1] = newLevelTask;
  }
}
void removeToListShift(){//удаляем первый элемент
  int counter =0;
  while(counter < llength){
    counter++;
    level_list[counter -1]=level_list[counter];
    level_list[counter] = -1;
    }
}
