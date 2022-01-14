
//Read temperature inside
int humid_in() {
  
  int h_in = dht_in.readHumidity();
  
  if (isnan(h_in)) {
    return 0; //failed to read humidity
  }
  return h_in; //return inside humidity
}

//Read temperature outside
int humid_out() {
  
  int h_out = dht_out.readHumidity();
  
  if (isnan(h_out)) {
    return 0; //failed to read humidity
  }
  return h_out; //return outside humidity
}
