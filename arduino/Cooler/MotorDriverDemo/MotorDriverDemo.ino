// motor one
#define ENA 3
#define IN1 0
#define IN2 1
// motor two
#define ENB 6
#define IN3 4
#define IN4 5

void demoOne()
{
  // Test motor A
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(2000);
  digitalWrite(IN1, LOW);
  
//Test motor B
digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(2000);
  digitalWrite(IN3, LOW);
   //Test both
digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(2000);
  digitalWrite(IN1, LOW);
  digitalWrite(IN3, LOW);
}

void setup()
{
  // set all the motor control pins to outputs
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void loop()
{
  demoOne();
  delay(1000);
}
