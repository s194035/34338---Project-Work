
//setting a write function for the stepper to take input
void write(int a, int b, int c, int d) {
  digitalWrite(stepper1, a);
  digitalWrite(stepper2, b);
  digitalWrite(stepper3, c);
  digitalWrite(stepper4, d);
}

//defining sequence for one step clockwise
void onestep_cw() {

  write(1, 1, 0, 0);
  delay(5);
  write(0, 1, 1, 0);
  delay(5);
  write(0, 0, 1, 1);
  delay(5);
  write(1, 0, 0, 1);
  delay(5);
}

//defining sequesnce for one step counter clockwise
void onestep_ccw() {

  write(1, 0, 0, 1);
  delay(5);
  write(0, 0, 1, 1);
  delay(5);
  write(0, 1, 1, 0);
  delay(5);
  write(1, 1, 0, 0);
  delay(5);
}
