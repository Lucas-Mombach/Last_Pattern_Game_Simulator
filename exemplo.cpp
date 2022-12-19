#include "fx.cpp"
#include <ctime> 
#define LED_PIN 6
#define LED_COUNT 144
#define UP	7
#define DOWN	6

Adafruit_NeoPixel LED(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
//left
int bolaL[24]={45,49,50,51,70,69,68,72,73,74,75,76,91,92,93,94,95,97,98,99,116,117,118,122};
int coracaoL[15]={25,27,46,45,44,49,50,51,70,69,68,73,74,75,93};
int teL[12]={46,45,44,49,50,51,69,74,93,98,117,122};
int quadradoL[16]={25,26,27,28,46,45,44,43,49,50,51,52,70,69,68,67};

int correto[19]={19,18,17,28,29,30,44,51,68,75,92,99,116,124,125,126,139,138,137};
int errado[13]={38,44,52,56,64,66,78,88,90,100,104,110,116};

//right
int bolaR[24]={38,56,57,58,61,62,63,79,80,81,82,83,84,85,86,87,88,104,105,106,109,110,111,129};
int coracaoR[15]={32,34,39,38,37,56,57,58,63,62,61,80,81,82,86};
int teR[12]={39,38,37,56,57,58,62,81,86,105,110,129};
int quadradoR[16]{31,32,33,34,40,39,38,37,55,56,57,58,64,63,62,61};

//vars
int last = 0;
int next = 0;
bool choise;
int left = last;

int right = next;

void showupR(){
	
	if (right==0){
		int i =0;
		while(i<16){
			// violet 		rgb(150,80,150)
			LED.setPixelColor( quadradoR[i], 150, 80, 150);
			LED.show();
			i++;
		}
	}
	if (right==1){
		int i =0;
		while(i<12){
			//lime 			rgb(0,150,0)
			LED.setPixelColor( teR[i], 0, 150, 0);
			LED.show();
			i++;
			
		}
	}
	if (right==2){
		int i =0;
		while(i<15){
			//red
			LED.setPixelColor( coracaoR[i], 150, 0, 0);
			LED.show();
			i++;
		}
	}
	if (right==3){
		int i =0;
		while(i<24){
			// 		orange 	rgb(150,100,0)
			LED.setPixelColor( bolaR[i], 0, 100, 0);
			LED.show();
			i++;
		}
	}
		delay(10);
	
}
void showupL(){
	
	if (left==0){
		int i =0;
		while(i<16){
			// violet 		rgb(150,80,150)
			LED.setPixelColor( quadradoL[i], 150, 80, 150);
			LED.show();
			i++;
		}
	}
	if (left==1){
		int i =0;
		while(i<12){
			//lime 			rgb(0,150,0)
			LED.setPixelColor( teL[i], 0, 150, 0);
			LED.show();
			i++;
		}
	}
	if (left==2){
		int i =0;
		while(i<15){
			//red
			LED.setPixelColor( coracaoL[i], 150, 0, 0);
			LED.show();
			i++;
		}
	}
	if (left==3){
		int i =0;
		while(i<24){
			// 		orange 	rgb(150,100,0)
			LED.setPixelColor( bolaL[i], 0, 100, 0);
			LED.show();
			i++;
		}
	}
	delay(10);
	
}
void choose(){
	srand((unsigned)time(0)); 
	int x;
	x= rand()%4; 
	next = x;
	if(x%2==0){
		left = next;
		right = last;
	}
	else{
		left = last;
		right = next;
	}
}
void showResult(bool result){
	int i = 0;
	LED.clear();
	
	if (result == 1){
		//correto
		while(i<19){
			// violet 		rgb(150,80,150)
			
			LED.setPixelColor( correto[i], 0, 150, 0);
			LED.show();
			i++;

		}
	}
	if (result == 0){
		// errado
		while(i<13){
			// violet 		rgb(150,80,150)
			
			LED.setPixelColor( errado[i], 150, 0, 0);
			LED.show();
			i++;

		}
	}
	delay(100);
}


void setup()
{

	LED.begin();
	LED.show();
	pinMode(UP, INPUT);
	pinMode(DOWN, INPUT);
	
}

void loop()
{
	choose();
	showupL();
	showupR();

	bool n = 0;
	while (n == 0){
	if(digitalRead(UP) == HIGH) {
		bool r = (left==last);
		showResult(r);
		n = 1;
	} 

	if (digitalRead(DOWN) == HIGH) {
		bool r = (right==last);
		showResult(r);
		n = 1;
	}
}

LED.clear();
last = next;


}

