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
#define llength 10

bool isRunning = false;
bool isGainedWeight = false;
int level_list[llength];
int spid = 120;
int direction = 0;//default
volatile int levelsToGo = 0; //Если не 1, а больше, то после срабатывания датчика едем в этом же направлении еще этаж.
int arrayLevel = 0;//На каком элементе массива на данный момент висит лифт
volatile boolean actionState = LOW;//что-то нужное

void setup() {
  
  // put your setup code here, to run once:
  pinMode(MX1508_O1, OUTPUT);    // Устанавливаем MX1508_O1 как выход
  pinMode(MX1508_O2, OUTPUT);    // Устанавливаем MX1508_O2 как выход
  pinMode(GERC_DETECT, INPUT);
  pinMode(BTN_LV3, INPUT);
  pinMode(BTN_LV2, INPUT);
  pinMode(BTN_LV1, INPUT);
  attachInterrupt(2, when_BTN_LV1, HIGH);
  attachInterrupt(3, when_BTN_LV2, HIGH);
  attachInterrupt(4, when_BTN_LV3, HIGH);
  attachInterrupt(5, when_GERC_DETECT, HIGH);
  Serial.begin(9600);
  Serial.println("Setup finished.");
  Serial.println(" ");
}

void loop() {
  // put your main code here, to run repeatedly:
  while (isRunning=true){
    switch(direction){
      case 1://Up
      while(levelsToGo > 0){
    analogWrite(MX1508_O1,LOW);  //ехаем вверх
    analogWrite(MX1508_O2 ,spid); 
        Serial.println("Going up");
      }
      break;
      case 2://Down
      while(levelsToGo > 0){
    analogWrite(MX1508_O2,LOW);  //ехаем вниз
    analogWrite(MX1508_O1 ,spid); 
        Serial.println("Going down");
      }
      break;
      default:
      //вот этого быть не должно
      Serial.println("ERR: direction > 2 or < 0");
      delay(500);
      break;
    }
  }
}

void when_BTN_LV1() {
actionState != actionState; //
     addToList(1);
     Serial.println("Level 1 called");
}

void when_BTN_LV2() {
actionState != actionState; //
     addToList(2);
     Serial.println("Level 2 called");
}
void when_BTN_LV3() {
actionState != actionState; //
     addToList(3);
     Serial.println("Level 3 called");
}
void when_GERC_DETECT() {
  Serial.println("Reached level: " + level_list[0]);
actionState != actionState; //
          // Уменьшаем levelsToGo.
        levelsToGo--;
        if(levelsToGo<=0){
          levelsToGo=0;
          isRunning=false;
          delay(7000);
        }
        
        switch(level_list[1]>level_list[0]){
          case true:
          direction = 1;//up
          break;
          case false:
          direction = 2;//down
          break;
        }
        removeToListShift();
        //Serial.println("Next levels:");
digitalWrite(PIN_LED, actionState);
}

void addToList(int newLevelTask){
  //туду
  level_list[arrayLevel] = newLevelTask;
  arrayLevel++;
  if(arrayLevel >= llength){
    arrayLevel=0;
  }
  Serial.print("Level ");
   Serial.print(level_list[newLevelTask]);
   Serial.print(" added \n");
}
int compare(int previousLevel, int nextLevel){
  return abs(nextLevel-previousLevel);
  //модуль разницы предыдущего и текущего этажа
  //
  Serial.println("Comparison between levels: " + abs(nextLevel-previousLevel));
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
  Serial.println("Next level added: " + newLevelTask);
}
void removeToListShift(){//удаляем первый элемент
  int counter =0;
  while(counter < llength){
    counter++;
    level_list[counter -1]=level_list[counter];
    level_list[counter] = -1;
    }
    Serial.println("Previous level removed.");
}
