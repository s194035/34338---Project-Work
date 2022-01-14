int checkbutton(int but_pin) {
  if (digitalRead(but_pin) == 1) {
    return 1;
  }
  else {
    return 0;
  }
}
